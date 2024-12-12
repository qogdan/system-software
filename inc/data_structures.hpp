#include <string>
#include <list>
#include <vector>
using namespace std;

struct symtable_entry{
  string label;
  string section;
  int offset;
  bool is_local;
  bool defined;
  list<int>*flink;
  int order;
  int section_size = 0;
  bool operator<(const symtable_entry& ent){
    return (order < ent.order);
  }
};

struct literalData{
  int value;
  list<int> patch_list;
  string sym_name;
  int index;
  bool is_symbol = false;
};

 struct symbol_container{
    string symbol_name;
    int cur_loc_cnt;
  };

struct SectionContent{
  int poolIndex = 0;
  int section_size = 0;
  int poolAddress = 0;
  vector<literalData> literal_pool;
  vector<unsigned char> section_bytes;
  string section_name;
};

struct SectionContentLinker{
  string section;
  vector<unsigned char> bytes;
};

struct RelocationTableEntry{
  string section;
  uint32_t offset;
  string type;
  string symbol;
  int addend;
};

typedef struct{
  int patch;
}forward_ref_entry;

struct Sect_Addr{
  string section;
  uint32_t newOffset;
};
