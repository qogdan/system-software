%{
  #include <cstdio>
  #include <iostream>
  #include "../inc/assembler.hpp"
  using namespace std;

  extern int yylex();
  extern int yyparse();
  extern FILE *yyin;
  extern int line_num;

  

  list<symbol_container> *symbol_list = new list<symbol_container>();

  Assembler assembler = Assembler();

  int location_counter = 0;
  string current_section="";
  unsigned char BBBB = 0;
  unsigned char MMMM = 0;
  unsigned char OP = 0;

  bool mem_ind = false;

  void yyerror(const char *s);
%}

%union{
  int number;
  char* ident;
  int reg_num;
  int csr_num;
}

//Tokeni

%token <reg_num> REG
%token <csr_num> CSR

%token PLUS MINUS PERIOD COL DOLLAR
%token GLOBALDIR EXTERNDIR SECTIONDIR WORDDIR SKIPDIR ENDDIR
%token HALT INT IRET CALL RET
%token JMP BEQ BNE BGT
%token PUSH POP XCHG
%token ADD SUB MUL DIV NOT AND OR XOR SHL SHR
%token LD ST
%token CSRRD CSRWR
%token UNKNOWN
%token ENDL
%token RBRACK LBRACK
%token    COMMA

// Terminalni simboli.
%token <number> NUMBER
%token <ident> IDENT

%type<ident> symbol;
%type<number> literal;

%%
prog: line
  |
  line prog;

line: directive_or_instruction
  |
  label directive_or_instruction
  ;

label: IDENT COL{
  //addSymbol(string label, string section, int loc_cnt, bool is_local, bool defined)
  assembler.addSymbol($1, current_section, location_counter, true, true);
};

directive_or_instruction:
  directive
  |
  instruction
  |
  ENDL;

directive:
  GLOBALDIR symbols{
    // assembler.globaldir(symbol_list,"UNDEF");//
    // string a = "undef";
    
    // assembler.addSymbols(symbol_list,"UNDEF");
    assembler.__global(symbol_list);
    // assembler.__skip(symbol_list);
  }
  |
  EXTERNDIR symbols{
    assembler.addSymbols(symbol_list, "UNDEF");
  }
  |
  SECTIONDIR symbol{
    if(current_section != ""){
      assembler.updateSectionSize(current_section, location_counter);
      assembler.addPoolBytes(current_section);
      assembler.backpatching(current_section);
    }
    cout<<"end of section. section size : "<<location_counter<<endl;
    location_counter = 0;
    //void Assembler::addSymbol(string symbol, string section,
    // int loc_cnt, bool is_local, bool defined)
    assembler.addSymbol($2, $2, location_counter, true, true);
    assembler.createSection($2);
    current_section = $2;
  }
  |
  WORDDIR symbols_literals{

  }
  |
  SKIPDIR literal{
    location_counter += $2;
    assembler.addBytesToSection(current_section,0,$2);
  }
  |
  ENDDIR{
    if(current_section != ""){
      assembler.updateSectionSize(current_section, location_counter);
      assembler.addPoolBytes(current_section);
      assembler.backpatching(current_section);
    }
    cout<<"end of section. section size : "<<location_counter<<endl;

    location_counter = 0;
    // assembler.printSectionBytes(current_section);
  }
  ;

instruction:
  no_param_instr
  |
  CALL operand_jmp{
    OP = 2;
    MMMM = 1;
    // if(mem_ind){
    //   MMMM++;
    //   mem_ind = false;
    // }

    assembler.addByteToSection(current_section, 0xf0);
    assembler.addByteToSection(current_section, (OP<<4) | MMMM);
    location_counter += 2;
  }
  |
  JMP operand_jmp{
    OP = 3;
    MMMM = 0;
    if(mem_ind){
      MMMM += 8;
      mem_ind = false;
    }
    assembler.addByteToSection(current_section, 0xf0);
    assembler.addByteToSection(current_section, (OP<<4) | MMMM);
    location_counter += 2;
  }
  |
  branch_instr   REG COMMA   REG COMMA operand_jmp{
    if(mem_ind){
      MMMM += 8;
      mem_ind = false;
    }
    unsigned char last = assembler.popLastByte(current_section);
    assembler.addByteToSection(current_section,($4 << 4) | last);
    assembler.addByteToSection(current_section, (0xf<<4) | (unsigned char)$2);
    assembler.addByteToSection(current_section, (OP<<4) | MMMM);
    location_counter += 2;
  }
  |
  stack_instr
  |
  arithmetic_gpr2   REG COMMA   REG{
    assembler.addByteToSection(current_section, 0x00);
    assembler.addByteToSection(current_section, ($2 << 4));
    assembler.addByteToSection(current_section, ($4 << 4)|$4);
    assembler.addByteToSection(current_section, (OP << 4) | MMMM); 
    location_counter += 4;
  }
  |
  arithmetic_gpr1   REG{
    assembler.addByteToSection(current_section, 0x00);
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, ($2 << 4)|$2);
    assembler.addByteToSection(current_section, (OP << 4) | MMMM); 
    location_counter += 4;
  }
  |
  ld_st_instr
  |
  csr_instr
  |
  atomic_swap
  ;

no_param_instr:
  HALT{
    location_counter += 4;
    assembler.addBytesToSection(current_section, 0x00, 4);
  }
  |
  INT{
    location_counter += 4;
    assembler.addBytesToSection(current_section, 0x00, 3);
    assembler.addByteToSection(current_section, 0x10);
  }
  |
  IRET{
    //pop pc; pop status;
    //status <= mem32[sp+4]
    assembler.addByteToSection(current_section, 4);
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, 0x0e);
    assembler.addByteToSection(current_section, 0x96);

    //pc <= mem32[sp]
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, 0xfe);
    assembler.addByteToSection(current_section, 0x92);

    //sp <= sp + 8
    assembler.addByteToSection(current_section,8);
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, 0xEE);
    assembler.addByteToSection(current_section, 0x91);

    location_counter += 12;
    // assembler.addByteToSection(current_section, )
  }
  |
  RET{
    // pc <= mem32[sp]
    assembler.addByteToSection(current_section,0);
    assembler.addByteToSection(current_section, 0xe0);
    assembler.addByteToSection(current_section, 0xf0);
    assembler.addByteToSection(current_section, 0x92);
    // sp <= sp + 4
    assembler.addByteToSection(current_section,4);
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, 0xEE);
    assembler.addByteToSection(current_section, 0x91);
    location_counter += 8;
  }
  ;

branch_instr:
  BEQ{
    OP = 3;
    MMMM = 1;
  }
  |
  BNE{
    OP = 3;
    MMMM = 2;
  }
  |
  BGT{
    OP = 3;
    MMMM = 3;
  }
  ;

  operand_jmp:
  literal{
    assembler.addLiteralToPool($1, location_counter, current_section);
    assembler.addBytesToSection(current_section,0,2);
    location_counter += 2;
  }
  |
  symbol{
    mem_ind = true;
    cout << "operand_jmp " << $1 << " " << current_section << "  " << location_counter << endl;
    assembler.foundSymbol(current_section, $1, location_counter);
    assembler.addSymbolToPool($1, location_counter, current_section);
    assembler.addBytesToSection(current_section, 0, 2);
    location_counter += 2;
  }
  ;


stack_instr:
  POP   REG{
    // // reg <= mem32[sp]
    // assembler.addByteToSection(current_section,0);
    // assembler.addByteToSection(current_section, 0xe0);
    // assembler.addByteToSection(current_section, $2<<4);
    // assembler.addByteToSection(current_section, 0x92);
    // // sp <= sp + 4
    // assembler.addByteToSection(current_section,4);
    // assembler.addByteToSection(current_section, 0);
    // assembler.addByteToSection(current_section, 0xEE);
    // assembler.addByteToSection(current_section, 0x91);
    // location_counter += 8;
    /*

    // pc <= mem32[sp]
    assembler.addByteToSection(current_section,0);
    assembler.addByteToSection(current_section, 0xe0);
    assembler.addByteToSection(current_section, 0xf0);
    assembler.addByteToSection(current_section, 0x92);
    // sp <= sp + 4
    assembler.addByteToSection(current_section,4);
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, 0xEE);
    assembler.addByteToSection(current_section, 0x91);
    location_counter += 8;
    */

    assembler.addByteToSection(current_section,0x04);
    assembler.addByteToSection(current_section,0x00);
    assembler.addByteToSection(current_section,($2 << 4) | 0xe);
    assembler.addByteToSection(current_section,0x93);
    location_counter += 4;

  }
  |
  PUSH   REG{
    // // sp <= sp - 4;
    // assembler.addByteToSection(current_section,0xfc);
    // assembler.addByteToSection(current_section, 0xff);
    // assembler.addByteToSection(current_section, 0xee);
    // assembler.addByteToSection(current_section, 0x91);
    // // mem[sp] <= reg
    // assembler.addByteToSection(current_section,0);
    // assembler.addByteToSection(current_section, $2 << 4);
    // assembler.addByteToSection(current_section, 0x0e);
    // assembler.addByteToSection(current_section, 0x80);
    // location_counter += 8;
    assembler.addByteToSection(current_section, 0xfc);
    assembler.addByteToSection(current_section, ($2<<4 )| 0xf);
    assembler.addByteToSection(current_section, 0xe0);
    assembler.addByteToSection(current_section, 0x81);
    location_counter += 4;
  }
  ;

atomic_swap:
  XCHG   REG COMMA   REG{
    assembler.addByteToSection(current_section,0);
    assembler.addByteToSection(current_section, ($4 << 4));
    assembler.addByteToSection(current_section, $2);
    assembler.addByteToSection(current_section, 0x40);
    location_counter += 4;
  }

arithmetic_gpr2:
  ADD{
    OP = 5;
    MMMM = 0;
  }
  |
  SUB{
    OP = 5;
    MMMM = 1;
  }
  |
  MUL{
    OP = 5;
    MMMM = 2;
  }
  |
  DIV{
    OP = 5;
    MMMM = 3;
  }
  |
  AND{
    OP = 6;
    MMMM = 1;
  }
  |
  OR{
    OP = 6;
    MMMM = 2;
  }
  |
  XOR{
    OP = 6;
    MMMM = 3;
  }
  |
  SHL{
    OP = 7;
    MMMM = 0;
  }
  |
  SHR{
    OP = 7;
    MMMM = 1;
  }
  ;

arithmetic_gpr1:
  NOT{
    OP = 6;
    MMMM = 0;
  }
  ;

ld_st_instr:
  LD operand_data COMMA   REG{
    if(mem_ind){
      unsigned char AAAABBBB = ($4<<4)|BBBB;
      assembler.addByteToSection(current_section, AAAABBBB);
      unsigned char OPMMMM = (0x9<<4)|MMMM;
      assembler.addByteToSection(current_section, OPMMMM);
      location_counter += 2;

      assembler.addBytesToSection(current_section, 0 ,2);
      assembler.addByteToSection(current_section, $4 << 4 | $4);
      assembler.addByteToSection(current_section, OPMMMM);
      location_counter += 4;

      mem_ind = false;
    }else{
      unsigned char AAAABBBB = ($4<<4)|BBBB;
      assembler.addByteToSection(current_section, AAAABBBB);
      unsigned char OPMMMM = (0x9<<4)|MMMM;
      assembler.addByteToSection(current_section, OPMMMM);
      location_counter += 2;
    }
  }
  |
  ST   REG COMMA operand_data{
    //zamena pushovanih nula, registrom u CCCC bite
    if(mem_ind){
      mem_ind = false;
      
    }else{
      MMMM = 0;
    }
    unsigned char CCCCDDDD = assembler.popLastByte(current_section);
    CCCCDDDD |= ($2 << 4);
    assembler.addByteToSection(current_section, CCCCDDDD);
    unsigned char AAAABBBB = BBBB;
    assembler.addByteToSection(current_section, AAAABBBB);
    assembler.addByteToSection(current_section, (8 << 4) | MMMM);
    location_counter += 2;
  }
  ;

csr_instr:
  CSRRD   CSR COMMA   REG{
    //gpr <= csr
    assembler.addByteToSection(current_section,0);
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, ($4 << 4) | $2);
    assembler.addByteToSection(current_section, 0x90);
    location_counter += 4;
  }
  |
  CSRWR   REG COMMA   CSR{
    //csr <= gpr
    assembler.addByteToSection(current_section,0);
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, ($4 << 4) | $2);
    assembler.addByteToSection(current_section, 0x94);
    location_counter += 4;
  }
  ;


operand_data:
  DOLLAR literal{
    BBBB = 0xf;
    MMMM = 0b0010;
    assembler.addLiteralToPool($2, location_counter, current_section);
    assembler.addBytesToSection(current_section,0,2);

    location_counter+=2;
  }
  |
  DOLLAR symbol{
    BBBB = 0xf;
    MMMM = 0b0010;
    assembler.foundSymbol(current_section, $2, location_counter);
    assembler.addSymbolToPool($2, location_counter, current_section);
    assembler.addBytesToSection(current_section,0,2); 
    location_counter+=2;
  }
  |
  literal{
    assembler.addLiteralToPool($1, location_counter, current_section);
    assembler.addBytesToSection(current_section,0,2);
    location_counter+=2;
    BBBB = 0xf;
    MMMM = 0b0010;
    mem_ind = true;
  }
  |
  symbol{
    assembler.foundSymbol(current_section, $1, location_counter);
    assembler.addSymbolToPool($1, location_counter, current_section);
    assembler.addBytesToSection(current_section, 0, 2);
    location_counter += 2;
    BBBB = 0xf;
    MMMM = 0b0010;
    mem_ind = true;
  }
  |
    REG{
    assembler.addBytesToSection(current_section, 0, 2);
    location_counter +=2;
    BBBB = $1;
    MMMM = 0b0001;
  }
  |
  LBRACK   REG RBRACK{
    assembler.addBytesToSection(current_section, 0, 2);
    location_counter +=2;
    BBBB = $2;
    MMMM = 0b0010;
  }
  |
  LBRACK   REG PLUS literal RBRACK{
    if($4>0xFFF){
      //ERROR RETURN
    }else{
    assembler.addByteToSection(current_section, (unsigned char)$4);
    assembler.addByteToSection(current_section, (unsigned char)($4>>8));
    location_counter += 2;
    BBBB = $2;
    MMMM = 2;
    }
  }
  |
  LBRACK   REG PLUS symbol RBRACK{
    int sym_val = assembler.getSymbolValue($4);
    if(sym_val > 0xFFF || sym_val == -1){
      //ERROR RETURN
    }else{
      //relokacija sym_val
    assembler.addByteToSection(current_section, 0);
    assembler.addByteToSection(current_section, 0);
    location_counter += 2;
    BBBB = $2;
    MMMM = 2;
    }
  }
  ;



symbol: IDENT{

}
;

symbols: 
  symbol{
    symbol_container cont;
    cont.symbol_name = $1;
    cont.cur_loc_cnt = location_counter;
    symbol_list->push_back(cont);
  }
  |
  symbols COMMA symbol{
    symbol_container cont;
    cont.symbol_name = $3;
    cont.cur_loc_cnt = location_counter;
    symbol_list->push_back(cont);
  }
;
literals:
  literal{
    location_counter += 4;
    for(int i = 0; i < 4; i++){
      assembler.addByteToSection(current_section, $1 >> i * 8);
    }
  }
  |
  literals COMMA literal{

  }
  ;

literal: NUMBER {$$ = $1;}
  |
  PLUS NUMBER {$$ = $2;}
  |
  MINUS NUMBER {$$ = -1*$2;}
  ;

  symbols_literals:
    symbols{
      location_counter += 4 * (symbol_list->size());
      assembler.__word(current_section, symbol_list);
    }
    |
    literals{

    }
    ;

%%

int main(int argc, char* argv[]){
  char finput[128];
  strcpy(finput, argv[3]);

  FILE *file = fopen(finput, "r");

  if(!file){
    cout<<"File doesn't exist!  " <<argv[3] <<endl;
    return -1;
  }
  yyin = file;
  do{
    yyparse();
  }while(!feof(yyin));
  // assembler.printSymbolTable();
  // assembler.printSectionBytes();
  // assembler.printRelocations();
  assembler.makeOutputFile(argv[2]);
  fclose(file);
  return 0;
}

void yyerror(const char *s) {
  cout << "Greska u parsiranju na liniji " << line_num << "! Poruka: " << s <<endl;
  exit(-1);
}