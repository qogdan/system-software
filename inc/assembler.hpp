#ifndef ASSEMBLER_HPP_
#define ASSEMBLER_HPP_

#include "data_structures.hpp"
#include <list>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string.h>
#include <fstream>

class Assembler{
  public:
    Assembler(){
    }
    unordered_map<string,SectionContent>section_name_content;
    // struct symtable_entry{
    //   string label;
    //   string section;
    //   int offset;
    //   bool is_local;
    //   bool defined;
    //   list<int>*flink;
    // };

    void createSection(string section);
    void addSymbols(list<symbol_container>* l, string section);
    void addSymbol(string label, string section, int loc_cnt, bool is_local, bool defined);
    void updateSectionSize(string name, int size);
    bool checkDefinedLabel(string label);
    void setDefinedSymbol(string sym);
    void newFlinkEntry(int, string);
    int getSymbolValue(string);
    void foundSymbol(string section, string symbol, int loc_cnt);
    bool symbolInSymTab(string symbol);
    void addByteToSection(string section, unsigned char byte);
    unsigned char popLastByte(string section);
    void addBytesToSection(string, unsigned char, int);
    void addLiteralToPool(int value, int loc_cnt, string section);
    void addSymbolToPool(string name, int loc_cnt, string section);
    void printSectionBytes();
    void printSymbolTable();
    void printRelocations();
    void setGlobal(string symbol);
    bool isGlobal(string symbol);
    void setSymbolSection(string sym, string sect);
    void setSymbolValue(string sym, int val);
    string getSymSection(string symbol);
    void __global(list<symbol_container> *l);
    void __word(string section, list<symbol_container> *symbol_list);
    void backpatching(string section);
    void addRelocation(string, uint32_t, string, string, int);
    void addPoolBytes(string section);
    int getSectionSize(string section);
    int getAddend(string symbol);
    void printSections();
    void makeOutputFile(const char* file);

  private:

    // struct symtable_entry{
    //   string label;
    //   string section;
    //   int offset;
    //   bool is_local;
    //   bool defined;
    //   list<int>*flink;
    // };
    std::unordered_map<string, symtable_entry> symbol_table;
    unordered_map<string, vector<RelocationTableEntry>> relocation_table;
    static int lit_tab_index;
    static int symbol_table_size;

};

#endif