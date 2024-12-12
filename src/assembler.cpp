#include "../inc/assembler.hpp"
#include <iomanip>
#include <algorithm>
using namespace std;
int Assembler::symbol_table_size = 0;

void Assembler::__global(list<symbol_container> *l){
  while(l->size()>0){
    if(symbolInSymTab(l->front().symbol_name)){
      setGlobal(l->front().symbol_name);
    }else{
      addSymbol(l->front().symbol_name,"UNDEF",l->front().cur_loc_cnt,false,false);
    }
    l->pop_front();
  }
}


void Assembler::__word(string section, list<symbol_container> *symbol_list){
  for(auto &sym : *symbol_list){
    if(!symbolInSymTab(sym.symbol_name)){
      addSymbol(sym.symbol_name, section, sym.cur_loc_cnt, true, false);
      newFlinkEntry(sym.cur_loc_cnt, sym.symbol_name);
      addBytesToSection(section, 0, 4);
      updateSectionSize(section, 4);
    }else{
      if(checkDefinedLabel(sym.symbol_name)){
        int value = getSymbolValue(sym.symbol_name);
        for(int i = 0; i < 4; i++){
          this->addByteToSection(section, value >> i * 8);
        }
        updateSectionSize(section, 4);
      }else{
        newFlinkEntry(sym.cur_loc_cnt, sym.symbol_name);
        addBytesToSection(section, 0, 4);
        updateSectionSize(section, 4);
      }
    }
  }
}
// struct symtable_entry{
//   string label;
//   string section;
//   int offset;
//   bool is_local;
//   bool defined;
//   list<int>*flink;
// };

void Assembler::createSection(string section){
  section_name_content[section] = {0, 0, {}, {}};
  cout<<"added new section "<<section<<endl;
}

void Assembler::addSymbol(string symbol, string section, int loc_cnt, bool is_local, bool defined){
  if(symbolInSymTab(symbol) && isGlobal(symbol)){
    setDefinedSymbol(symbol);
    setSymbolSection(symbol, section);
    setSymbolValue(symbol, loc_cnt);
  }else{
    symbol_table[symbol]={
      symbol,
      section,
      loc_cnt,
      is_local,
      defined,
      {},
      symbol_table_size
    };
    symbol_table_size++;
  }
}

void Assembler::addSymbols(list<symbol_container> *l, string section){
  while(l->size()>0){
    addSymbol(l->front().symbol_name,section,l->front().cur_loc_cnt,false,false);
    l->pop_front();
  }
}



void Assembler::addLiteralToPool(int value, int location_counter, string section){

  bool literal_in_list = false;
  
  for(auto & litData : section_name_content[section].literal_pool){
    if(litData.value == value && !litData.is_symbol){
      literal_in_list = true;
      litData.patch_list.push_back(location_counter);
      break;
    }
  }
  if(!literal_in_list){
    int ind = section_name_content[section].poolIndex;
    section_name_content[section].literal_pool.push_back({value, {location_counter},"", ind,false});
    section_name_content[section].poolIndex++;
  }
}

void Assembler::addSymbolToPool(string name, int loc_cnt, string section){
  bool symbol_in_list = false;
    for(auto & litData : section_name_content[section].literal_pool){
      if(litData.sym_name == name)
      {
        symbol_in_list = true;
        litData.patch_list.push_back(loc_cnt);
        break;
      }
    }
    if(!symbol_in_list){
      int ind = section_name_content[section].poolIndex;
      section_name_content[section].literal_pool.push_back((literalData){0, {loc_cnt},name,ind,true});
      section_name_content[section].poolIndex++;
    }
}


bool Assembler::checkDefinedLabel(string label){

  return symbol_table[label].defined;
}

string Assembler::getSymSection(string symbol){
  return symbol_table[symbol].section;
}

bool Assembler::isGlobal(string sym){
  return !symbol_table[sym].is_local;
}

void Assembler::newFlinkEntry(int patch, string label){
  symbol_table[label].flink->push_back(patch);
}

bool Assembler::symbolInSymTab(string label){
  return symbol_table.count(label)!=0;
}

int Assembler::getSymbolValue(string label){
  if(!symbolInSymTab(label))
    return -1;
  else
    return symbol_table[label].offset;
}

void Assembler::foundSymbol(string section, string symbol, int loc_cnt){
  if(!symbolInSymTab(symbol)){
      addSymbol(symbol, section, loc_cnt,false, false);
  }
}

void Assembler::addByteToSection(string section, unsigned char byte){
  section_name_content[section].section_bytes.push_back(byte);
}

void Assembler::addBytesToSection(string section, unsigned char byte, int cnt){
  for(int i = 0; i < cnt; i++){
    section_name_content[section].section_bytes.push_back(byte);
  }
}

unsigned char Assembler::popLastByte(string section){
  unsigned char last = section_name_content[section].section_bytes.back();
  section_name_content[section].section_bytes.pop_back();
  return last;
}

void Assembler::printSectionBytes(){
  
  for(auto & elem : section_name_content){
    cout<< elem.first<<endl;
    int i = 1;
    for(auto & byte : elem.second.section_bytes){
      i%4==0?cout<<hex<<setfill('0')<<setw(2)<<+byte<<endl:cout<<hex<<setfill('0')<<setw(2)<<+byte<<"  ";
      i++;
    }
  }
}

/*
struct RelocationTableEntry{
  string section;
  int offset;
  string type;
  string symbol;
  int addend;*/

// void Assembler::printRelocations(){
//   cout << "----------------------------------" << endl; 
//   cout << "Relocation records: " << endl;
//   cout << "----------------------------------" << endl;
//   cout <<  "Section:  |   Offset:  |  Type:   |  Symbol:  |  Addend: " << endl;
//   cout << "----------------------------------" << endl;

//   for(auto & rel : relocation_table){
//     cout<<rel.section <<" "<<rel.offset<<"  "<<rel.type<<"  "<<rel.symbol<<"  "<< rel.addend<<endl;
//   }
// }

void Assembler::updateSectionSize(string section, int size){
  section_name_content[section].section_size += size;
  symbol_table[section].section_size += size;
}
int Assembler::getSectionSize(string section){
  return section_name_content[section].section_size;
}
void Assembler::setGlobal(string sym){
  symbol_table[sym].is_local = false;
}

void Assembler::setSymbolSection(string sym, string section){
  symbol_table[sym].section = section;
}

void Assembler::setDefinedSymbol(string sym){
  symbol_table[sym].defined = true;
}

void Assembler::setSymbolValue(string sym, int val){
  symbol_table[sym].offset = val;
}

int Assembler::getAddend(string symbol){
  return symbol_table[symbol].is_local?symbol_table[symbol].offset:0;
}

void Assembler::addPoolBytes(string section){
  section_name_content[section].poolAddress = getSectionSize(section);
  
  for(auto & literal : section_name_content[section].literal_pool){
    if(literal.is_symbol){
      // u bajtove za pool se upisuje relokacioni zapis
      addRelocation(section, section_name_content[section].poolAddress + literal.index*4, "R_X86_64_32", symbol_table[literal.sym_name].is_local?getSymSection(literal.sym_name):literal.sym_name, getAddend(literal.sym_name));
      addBytesToSection(section, 0, 4);
    }else{
     for(int i = 0; i < 4; i++){
      addByteToSection(section, literal.value >> (8 * i));
     } 
    }
    // section_name_content[section].section_size += 4;
    updateSectionSize(section, 4);

  }
}

void Assembler::backpatching(string section){
  cout << section_name_content[section].poolAddress;
  for(auto & lit : section_name_content[section].literal_pool){
    cout << "HEY " << lit.index << " " << lit.sym_name << " " << lit.value << endl;
    for(auto & patch : lit.patch_list){
      cout << patch << " ";
      int disp = lit.index * 4 + section_name_content[section].poolAddress - patch - 4;
      section_name_content[section].section_bytes[patch] |= disp;
      section_name_content[section].section_bytes[patch + 1] |= disp >> 8;
    }
    cout << endl;
  }
}

/*
struct RelocationTableEntry{
  string section;
  int offset;
  string type;
  string symbol;
  int addend;
};*/

void Assembler::addRelocation(string section, uint32_t offset, string type, string symbol, int addend){
  relocation_table[section].push_back({
    section,
    offset,
    type,
    symbol,
    addend
  });
}

void Assembler::printSymbolTable(){
    cout << "----------------------------------" << endl; 
  cout << "Symbol table: " << endl;
  cout << "----------------------------------" << endl;
  cout <<  "Label: |  Section:  |   Offset:  |  Local:   |  Defined:  |  Section Size: " << endl;
  cout << "----------------------------------" << endl;

  vector<symtable_entry> symbols;
  for(unordered_map<string, symtable_entry>::iterator it = symbol_table.begin(); it != symbol_table.end(); ++it){
    symbols.push_back(it->second);
  }
  sort(symbols.begin(), symbols.end());
  

  for(auto & sym : symbols){
    cout << sym.label << "  " << sym.section << " " << sym.offset << "  " << (sym.is_local?"LOCAL":"GLOBAL") << "  " << (sym.defined?"true":"false") << " " << section_name_content[sym.label].section_size << endl;
  }
  
}

void Assembler::makeOutputFile(const char *file){
  char foutput[128];
  strcpy(foutput, file);

  ofstream output;
  output.open(foutput, ios::trunc | ios::ate);

    output << "----------------------------------" << endl; 
  output << "Relocation records: " << endl;
  output << "----------------------------------" << endl;
  output <<  "Section:  |   Offset:  |  Type:   |  Symbol:  |  Addend: " << endl;
  output << "----------------------------------" << endl;

  for(auto & rel : relocation_table){
    output<< ".rela. "<<rel.first<<endl;
    for(auto & ent : rel.second)
      output<<ent.section <<" "<<ent.offset<<"  "<<ent.type<<"  "<<ent.symbol<<"  "<< ent.addend<<endl;
  }

  output << "----------------------------------" << endl; 
  output << "Symbol table: " << endl;
  output << "----------------------------------" << endl;
  output <<  "Label: |  Section:  |   Offset:  |  Local:   |  Defined:  |  Section Size: " << endl;
  output << "----------------------------------" << endl;

  vector<symtable_entry> symbols;
  for(unordered_map<string, symtable_entry>::iterator it = symbol_table.begin(); it != symbol_table.end(); ++it){
    symbols.push_back(it->second);
  }
  sort(symbols.begin(), symbols.end());
  

  for(auto & sym : symbols){
    output << sym.label << "  " << sym.section << " " << sym.offset << "  " << (sym.is_local?"LOCAL":"GLOBAL") << "  " << (sym.defined?"true":"false") << " " << sym.section_size << endl;
  }

  output << "----------------------------------" << endl;
  output << "Sections content: " << endl;
  output << "----------------------------------" << endl;

  
  for(auto & elem : section_name_content){
    output<<"Section: "<< elem.first<<endl;
    int i = 1;
    for(auto & byte : elem.second.section_bytes){
      i%4==0?output<<hex<<setfill('0')<<setw(2)<<+byte<<endl:output<<hex<<setfill('0')<<setw(2)<<+byte<<"  ";
      i++;
    }
  }
 

  output << "----------------------------------" << endl; 

  output.close();
  
}