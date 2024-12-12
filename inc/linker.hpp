#include <iostream>
#include <cstdio>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include "data_structures.hpp"
using namespace std;

class Linker{
public:
  Linker(){
  }

  int readInputFiles();
  int readArgs(char* args[], int cnt);
  void addFilename(string name);
  bool symbolInSymTab(string sym);
  void generateHexFile(const char* output_name);
  string getOutputFileName(){return output_file_name;}
  void resolveRelocations();
private:
  void updateSectionAddrMap();
  symtable_entry lineToSymtableEntry(string line);
  string output_file_name;
  vector<unsigned char> lineToBytes(string line);
  void addBytesToSection(vector<unsigned char> bytes, string section);
  string lineToSectionName(string line);
  bool sectionAdded(string section);
  bool sectionRelocAdded(string section);
  bool sectionInPlaces(string section);
  void addRelocToTable(RelocationTableEntry reloc, string section, bool sect_added);
  int checkForErrors();
  void generateHexBytes();
  vector<string> filenames;

  
  RelocationTableEntry lineToRelocation(string line);
    unordered_map<string, symtable_entry> global_symbol_table;
    unordered_map<string, Sect_Addr> section_addr_map;
    unordered_map<string, Sect_Addr> places;
    unordered_map<string, SectionContentLinker> section_name_content;
    unordered_map<string, vector<RelocationTableEntry>> relocation_tables;
    unordered_map<string, symtable_entry> all_sections;
    vector<pair<uint32_t, unsigned char>> hex_content;

};
