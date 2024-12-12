%{
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include "../inc/parser.hpp"
using namespace std;
int line_num = 1;
%}


digit         [0-9]
letter        [a-zA-Z_]
hex           0[xX][0-9a-fA-F]+


%%
"#".*         { /* DO NOTHING */ }
\n                    {++line_num; return ENDL;}
"+"                  { return PLUS;       }
"-"                  { return MINUS;      }
"$"         {return DOLLAR;}

"," {return COMMA;}
"[" {return LBRACK;}
"]" {return RBRACK;}
".global"              { return GLOBALDIR;   }
".extern"               { return EXTERNDIR;    }
".section"              { return SECTIONDIR;   }
".word"                 { return WORDDIR;      }
".skip"                { return SKIPDIR;     }
".end"                 { return ENDDIR;      }
"halt"                { return HALT;     }
"int"          { return INT;    }
"iret"               { return IRET;    }
"call"                { return CALL;     }
"ret"              { return RET;   }
"jmp"              { return JMP;   }
"beq"              { return BEQ;   }
"bne"              { return BNE;   }
"bgt"              { return BGT;   }
"push"              { return PUSH;   }
"pop"              { return POP;   }
"xchg"              { return XCHG;   }
"add"              { return ADD;   }
"sub"              { return SUB;   }
"mul"              { return MUL;   }
"div"              { return DIV;   }
"not"              { return NOT;   }
"and"              { return AND;   }
"or"              { return OR;   }
"xor"              { return XOR;   }
"shl"              { return SHL;   }
"shr"              { return SHR;   }
"ld"              { return LD;   }
"st"              { return ST;   }
"csrrd"              { return CSRRD;   }
"csrwr"              { return CSRWR;   }
"."                  { return PERIOD;     }
":"                  { return COL;}
%r[0-9] {yylval.reg_num = atoi(yytext+2); return REG;}
%r1[0-3] {yylval.reg_num = atoi(yytext+3); return REG;}
"%r14"  {yylval.reg_num = 14; return REG;}
"%r15"  {yylval.reg_num = 15; return REG;}
"%sp"  {yylval.reg_num = 14; return REG;}
"%pc"  {yylval.reg_num = 15; return REG;}
"%status"    {yylval.csr_num=0; return CSR;}
"%handler"   {yylval.csr_num=1; return CSR;}
"%cause"     {yylval.csr_num=2; return CSR;}

{letter}({letter}|{digit})* {
                       yylval.ident = strdup(yytext);
                       return IDENT;      }
{digit}+             { yylval.number = atoi(yytext);
                       return NUMBER;     }
{hex}                 {yylval.number = stoul(yytext,nullptr,16); return NUMBER;}
[ \t\r]            /* skip whitespace */
.                    { printf("Unknown character [%c]\n",yytext[0]);
                       return UNKNOWN;    }
%%

int yywrap(void){return 1;}