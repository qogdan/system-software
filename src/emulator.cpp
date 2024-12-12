#include "../inc/emulator.hpp"

const unsigned char Emulator::pc = 15;
const unsigned char Emulator::sp = 14;
const unsigned char Emulator::status = 0;
const unsigned char Emulator::handler = 1;
const unsigned char Emulator::cause = 2;



int main (int argc, char *argv[]){
  Emulator emulator = Emulator();
  char* finput = argv[1];
  emulator.loadHexFile(finput);
  emulator.emulate();
  return 0;
}

void Emulator::loadHexFile(const char* filename){

  char finput[128];
  strcpy(finput, filename);

  ifstream file;
  string line;
  file.open(finput);

  if(file.is_open()){
    while(getline(file, line)){
      if(line.find("HEX") != string::npos){
        getline(file,line);
        while(getline(file,line)){
          if(!line.empty()){
            // AA BB CC DD 11 22 33 44
            uint32_t address = stoul(line.substr(0, 8), nullptr, 16);
            unsigned char buffer[8];
            for(int i = 0; i < 8; i++){
                buffer[i] = (unsigned char)(stoi(line.substr(i*3+10,2),nullptr,16));
            }
            memory[address] = uint32_t((unsigned char)(buffer[3]) << 24 |
            (unsigned char)(buffer[2]) << 16 |
            (unsigned char)(buffer[1]) << 8 |
            (unsigned char)(buffer[0]));
            memory[address+4] = uint32_t((unsigned char)(buffer[7]) << 24 |
            (unsigned char)(buffer[6]) << 16 |
            (unsigned char)(buffer[5]) << 8 |
            (unsigned char)(buffer[4]));
          }
        }
      }else continue;
    }
  }
}

void Emulator::emulate(){
  // cout << "CSR ::::::::::::: " << csr[0] << csr[1] << csr[2];
  unsigned char instruction[4]; //big endian
  while(!end_emulation){
    // cout << hex << +memory[reg[pc]] << endl;
    instruction[3] = memory[reg[pc]] >> 24;
    instruction[2] = memory[reg[pc]] >> 16;
    instruction[1] = (memory[reg[pc]] >> 8);
    instruction[0] = memory[reg[pc]];
    reg[pc]+=4;
    cout <<hex<< +instruction[0]<<" " <<hex<< +instruction[1]<<" " <<hex<<+instruction[2]<<" " <<hex<<+instruction[3] << endl;
    
    execute(instruction);
    cout << "Emulated processor state:" << endl;
  for(int i = 0; i < 16; i++){
    cout << "r" << i << "=0x" << setfill('0') << setw(8) << hex << reg[i];
    if(i % 4 == 3)
      cout << endl;
    else
      cout << "\t";
  }
  }
}

void Emulator::execute(unsigned char bytes[4]){
  unsigned char op_mod = bytes[3];
  unsigned char ab = bytes[2];
  unsigned char cd = bytes[1];
  unsigned char dd = bytes[0];
  op_code = (OpCode)(op_mod>>4);
  switch(op_code){
    case HALT:
      _halt();
      break;
    case INT:
      _int();
      break;
    case CALL:
      _call(bytes);
      break;
    case JMP_BEQ_BNE_BGT:
      _jmp_beq_bne_bgt(bytes);
      break;
    case XCHG:
      _xchg(bytes);
      break;
    case ADD_SUB_MUL_DIV:
      _add_sub_mul_div(bytes);
      break;
    case NOT_AND_OR_XOR:
      _not_and_or_xor(bytes);
      break;
    case SHL_SHR:
      _shl_shr(bytes);
      break;
    case ST:
      _st(bytes);
      break;
    case LD:
      _ld(bytes);
      break;
    default:
      cout << "Instrukcija ne postoji!" <<endl;
      end_emulation = true;
      break;
  }
  
}

void Emulator::_halt(){
  cout << "Emulated processor executed halt instruction" << endl;
  end_emulation = true;
}

void Emulator::_int(){
      cout << "int" << endl;
  _push(csr[status]);
  _push(reg[pc]);
  csr[cause] = 4;
  csr[status] = csr[status] & (~0x1);
  reg[pc] = csr[handler];
}

void Emulator::_call(unsigned char bytes[4]){
      cout << "call" << endl;
  unsigned char op_mod = bytes[3];
  unsigned char a = bytes[2]>>4;
  unsigned char b = bytes[2] & 0x0f;
  unsigned char c = bytes[1]>>4;
  int d = bytes[0] | (bytes[1]&0x0f)<<8;
  uint32_t adr = memory[reg[a] + reg[b] + d];

  switch(op_mod & 0x0f){
    case 0:
      _push(reg[pc]);
      reg[pc] = reg[a] + reg[b] + d;
      break;
    case 1:
      _push(reg[pc]);
      reg[pc] = adr;
      break;
    default:
      cout << "Ne postoji mod instrukcije" << endl;
      break;
  }
}

void Emulator::_jmp_beq_bne_bgt(unsigned char bytes[]){
  unsigned char op_mod = bytes[3];
  unsigned char a = bytes[2]>>4;
  unsigned char b = bytes[2] & 0x0f;
  unsigned char c = bytes[1]>>4;
  int d = bytes[0] | (bytes[1]&0x0f)<<8;
  switch(op_mod & 0x0f){
    case 0:
  cout << "[pc] = reg[a] + d;" << endl;
      reg[pc] = reg[a] + d;
      break;
    case 1:
      cout << "beq" << endl;
      if(reg[b]==reg[c])
        reg[pc] = reg[a] + d;
      break;
    case 2:
      cout << "bne" << endl;
      if(reg[b] != reg[c])
        reg[pc] = reg[a] + d;
    case 3:
      cout << "bgr" << endl;
      if(reg[b]>reg[c])
        reg[pc] = reg[a] + d;
      break;
    case 8:
      cout << "reg[pc] = memory[reg[a] + d];" << endl;
      reg[pc] = memory[reg[a] + d];
      break;
    case 9:
      cout << "beq reg[pc] = memory[reg[a] + d];" << endl;
      if(reg[b]==reg[c])
        reg[pc] = memory[reg[a] + d];
      break;
    case 10:
      cout << "bne reg[pc] = memory[reg[a] + d];" << endl;
      if(reg[b]!=reg[c])
        reg[pc] = memory[reg[a] + d];
      break;
    case 11:
      cout << "bgr reg[pc] = memory[reg[a] + d];" << endl;
    if(reg[b]>reg[c])
      reg[pc] = memory[reg[a] + d];
    break;
    default:
      cout << "Ne postoji mod instrukcije" << endl;
      break;
  }
}

void Emulator::_xchg(unsigned char bytes[4]){
  cout << "xcgh" << endl;
  unsigned char b = bytes[2] & 0x0f;
  unsigned char c = bytes[1]>>4;
  uint32_t tmp = reg[b];
  reg[b] = reg[c];
  reg[c] = tmp;
}

void Emulator::_add_sub_mul_div(unsigned char bytes[4]){
  unsigned char op_mod = bytes[3];
  unsigned char a = bytes[2]>>4;
  unsigned char b = bytes[2] & 0x0f;
  unsigned char c = bytes[1]>>4;
  int d = bytes[0] | (bytes[1]&0x0f)<<8;
  switch(op_mod & 0x0f){
    case 0:
  cout << "add" << endl;
      reg[a] = reg[b] + reg[c];
      break;
    case 1:
  cout << "sub" << endl;
      reg[a] = reg[b] - reg[c];
      break;
    case 2:
      reg[a] = reg[b] * reg[c];
      break;
    case 3:
      reg[a] = reg[b] / reg[c];            
      break;
    default:
      cout << "Ne postoji mod instrukcije" << endl;
      break;
  }
}

void Emulator::_not_and_or_xor(unsigned char bytes[4]){
  unsigned char op_mod = bytes[3];
  unsigned char a = bytes[2]>>4;
  unsigned char b = bytes[2] & 0x0f;
  unsigned char c = bytes[1]>>4;
  int d = bytes[0] | (bytes[1]&0x0f)<<8;

  switch(op_mod & 0x0f){
    case 0:
      reg[a] = ~reg[b];
      break;
    case 1:
      reg[a] = reg[b] & reg[c];
      break;
    case 2:
      reg[a] = reg[b] | reg[c];
      break;
    case 3:
      reg[a] = reg[b] ^ reg[c];            
      break;
    default:
      cout << "Ne postoji mod instrukcije" << endl;
      break;
  }
}

void Emulator::_shl_shr(unsigned char bytes[4]){
  unsigned char op_mod = bytes[3];
  unsigned char a = bytes[2]>>4;
  unsigned char b = bytes[2] & 0x0f;
  unsigned char c = bytes[1]>>4;
  int d = bytes[0] | (bytes[1]&0x0f)<<8;

  switch(op_mod & 0x0f){
    case 0:
      reg[a] = reg[b] << reg[c];
      break;
    case 1:
      reg[a] = reg[b] >> reg[c];
      break;
    default:
      cout << "Ne postoji mod instrukcije" << endl;
      break;
  }
}

void Emulator::_ld(unsigned char bytes[4]){
  cout << "ld" << endl;
  unsigned char op_mod = bytes[3];
  unsigned char a = bytes[2]>>4;
  unsigned char b = bytes[2] & 0x0f;
  unsigned char c = bytes[1]>>4;
  uint32_t d = bytes[0] | (bytes[1]&0x0f)<<8;
  if(d==0xffc) d = 0xfffffffc;
  switch(op_mod & 0x0f){
    case 0:
    reg[a] = csr[b];
    break;
  case 1:  
    if(a == b && a == 0xe && d!=4)
      d = 0xfffffffc;
    reg[a] = reg[b] + d;
    break;
  case 2:
    cout <<"balaL "<< reg[a] << " " << d << " "<< memory[reg[b] + reg[c] + d];
    reg[a] = memory[reg[b] + reg[c] + d];

    if(a==0xf && c==0xe){
      reg[sp]+=4;
    }
    if(a==0xf && b==0xe && c==0x0){
      reg[sp]+=8;
    }
    break;
  case 3:
    reg[a] = memory[reg[b]];
    reg[b] = reg[b] + d;
    break;
  case 4:
    csr[a] = reg[b];
    break;
  case 5:
    csr[a] = csr[b] | d;
    break;
  case 6:
    csr[a] = memory[reg[b] + reg[c] + d];
    break;
  case 7:
    csr[a] = memory[reg[b]];
    reg[b] = reg[b] + d;
    break;
  default:
    cout << "Ne postoji mod instrukcije" << endl;
    break;
  }
  
}

void Emulator::_st(unsigned char bytes[4]){
  cout << "st" << endl;
  unsigned char op_mod = bytes[3];
  unsigned char a = bytes[2]>>4;
  unsigned char b = bytes[2] & 0x0f;
  unsigned char c = bytes[1]>>4;
  int d = bytes[0] | (bytes[1]&0x0f)<<8;
  if(d == 0xffc) d = 0xfffffffc;
  uint32_t adr = memory[reg[a] + reg[b] + d];
  switch(op_mod & 0x0f){
    case 0:
      memory[reg[a] + reg[b] + d] = reg[c];
      break;
    case 1:
      reg[a] = reg[a] + d;
      memory[reg[a]] = reg[c];
      break;
    case 2:
      memory[adr] = reg[c];
      break;
    default:
      cout << "Ne postoji mod instrukcije" << endl;
      break;
  }
}

void Emulator::_push(uint32_t r){
  cout << "push" << endl;

  reg[sp] -= 4;
  memory[reg[sp]] = r;
}

uint32_t Emulator::_pop(){
  cout << "pop" << endl;
  uint32_t r = memory[reg[sp]];
  reg[sp] += 4;
  return r;
}