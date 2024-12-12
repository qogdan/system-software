#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <unordered_map>
#include <iomanip>

using namespace std;

class Emulator{

  public:
  Emulator(){
    reg[pc] = 0x40000000;
  }
  typedef enum {
    HALT = 0x0,
    INT = 0x1,
    CALL = 0x2,
    JMP_BEQ_BNE_BGT = 0x3,
    XCHG = 0x4,
    ADD_SUB_MUL_DIV = 0x5,
    NOT_AND_OR_XOR = 0x6,
    SHL_SHR = 0x7,
    ST = 0x8,
    LD = 0x9
  } OpCode;

  OpCode op_code;

  void loadHexFile(const char *);
  void emulate();

  static const unsigned char pc;
  static const unsigned char sp;
  static const unsigned char status;
  static const unsigned char cause;
  static const unsigned char handler;

  private:
  unsigned int reg[16] = {};
  unsigned int csr[3] = {};
  unordered_map<uint32_t, uint32_t> memory;
  void execute(unsigned char bytes[4]);
  bool end_emulation = false;

  // ypedef enum {
  //   HALT = 0x0,
  //   INT = 0x1,
  //   CALL = 0x2,
  //   JMP_BEQ_BNE_BGT = 0x3,
  //   XCHG = 0x4,
  //   ADD_SUB_MUL_DIV = 0x5,
  //   NOT_AND_OR_XOR = 0x6,
  //   SHL_SHR = 0x7,
  //   ST = 0x8,
  //   LD = 0x9
  void _halt();
  void _int();
  void _call(unsigned char[]);
  void _jmp_beq_bne_bgt(unsigned char[]);
  void _xchg(unsigned char[]);
  void _add_sub_mul_div(unsigned char[]);
  void _not_and_or_xor(unsigned char[]);
  void _shl_shr(unsigned char[]);
  void _st(unsigned char[]);
  void _ld(unsigned char[]);
  void _push(uint32_t);
  uint32_t _pop();
};