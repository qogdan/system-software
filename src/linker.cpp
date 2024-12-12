#include "../inc/linker.hpp"
#include <iomanip>


int main(int argc, char* argv[]){
  Linker linker = Linker();
  if(linker.readArgs(argv, argc))
    return -1;
  if(linker.readInputFiles())
    return -1;
  linker.resolveRelocations();

  linker.generateHexFile(linker.getOutputFileName().c_str());
  return 0;
}
int Linker::readInputFiles(){
  for(auto & filename :filenames){
    char finput[128];
    strcpy(finput, filename.c_str());
    ifstream file;
    string line;
    string skip;
    vector<symtable_entry> sections_in_table;
    file.open(finput);
    if(file.is_open()){

      while(getline(file, line)){
        if(line.find("Symbol table") != string::npos){
          //get to first row of sym table
          for(int i = 0; i < 3; i++)
            getline(file, skip);
          getline(file, line);
          while(line.find("--------") == string::npos){
            symtable_entry newEntry = lineToSymtableEntry(line);
            if(newEntry.label == newEntry.section && newEntry.section_size > 0){

              sections_in_table.push_back(newEntry);
            }
            if(!newEntry.is_local){
              if(newEntry.section=="UNDEF"){
                if(!symbolInSymTab(newEntry.label)){
                  global_symbol_table[newEntry.label] = newEntry;
                }
              }else{
                if(symbolInSymTab(newEntry.label) && global_symbol_table[newEntry.label].section !="UNDEF"){
                  cout<<"Visestruka definicija simbola " + newEntry.label;
                  return -1;
                }else{
                  global_symbol_table[newEntry.label] = newEntry;
                  if(symbolInSymTab(newEntry.section)){
                    global_symbol_table[newEntry.label].offset += global_symbol_table[newEntry.section].section_size;
                  }
                }
              }
            }
          
            getline(file, line); 
          }
          //now go through sections
          for(auto & sect : sections_in_table){
            if(symbolInSymTab(sect.label)){
              global_symbol_table[sect.label].section_size += sect.section_size;
            }else{
              global_symbol_table[sect.label] = sect;
            }
          }
        }else if(line.find("Sections content:") != string::npos){
          //skip line
          string current_section;
          getline(file, skip); // skip = -------
          getline(file, line); //line = section:
          current_section = lineToSectionName(line);
          getline(file, line); 
          while(line.find("--------") == string::npos){
            while(line.find("Section:") == string::npos){              
              vector<unsigned char> bytesInLine = lineToBytes(line);
              // for(auto & a : bytesInLine){
              //   cout << a << " ";
              // }cout<< endl;
              addBytesToSection(bytesInLine, current_section);
              getline(file, line);
              if(line.find("--------")!=string::npos)
              break;
            }
            if(line.find("--------")!=string::npos)
              break;
            current_section = lineToSectionName(line); 
            getline(file, line);
          }
        }
        else if(line.find("Relocation records") != string::npos){
          string current_section;
          getline(file, skip);
          getline(file, skip);
          getline(file, skip);
          getline(file, line); //line = .rela.section_name
          if(line.find("-------") != string::npos){
            continue;
          }
          current_section = lineToSectionName(line);
          getline(file,line);
          bool sect_added = sectionAdded(current_section);
          while(line.find("-------") == string::npos){
            while(line.find(".rela.") == string::npos){
              RelocationTableEntry newEntry = lineToRelocation(line);

              addRelocToTable(newEntry, current_section, sect_added);
              getline(file, line);
              if(line.find("-------") != string::npos)
                break;
            }

            if(line.find("-------") != string::npos){
              
                break;
            }

            current_section = lineToSectionName(line);
            sect_added = sectionAdded(current_section);

            getline(file, line);
          }
        }
      }
    }
  }

  return checkForErrors();
}

/*
  string section;
  int offset;
  string type;
  string symbol;
  int addend;*/

RelocationTableEntry Linker::lineToRelocation(string line){
  string result;
  stringstream ss (line);
  vector<string> cols;
  while(ss >> result)
    cols.push_back(result);
  //my_code 104  R_X86_64_32  handler  0
  
  RelocationTableEntry entry ={
    cols[0], // section
    stoi(cols[1]), //offset
    cols[2], //type
    cols[3], //symbol
    stoi(cols[4]) // addend
  };
  if(cols[0] == "isr"){
    cout << "MMM" << entry.offset << endl;
  }
  return entry;

}
void Linker::addRelocToTable(RelocationTableEntry entry, string section, bool sect_added){
  if(section == "isr")
  cout << "OOOOOOOO " <<entry.offset <<entry.symbol<< endl;
  relocation_tables[section].push_back(entry);
  if(sect_added){
    relocation_tables[section].back().offset += global_symbol_table[section].section_size;
    cout << "AFTER " << relocation_tables[section].back().offset << endl;
  }
  if(symbolInSymTab(relocation_tables[section].back().symbol)
  && global_symbol_table[relocation_tables[section].back().symbol].section_size>0){
    relocation_tables[section].back().addend += global_symbol_table[relocation_tables[section].back().symbol].section_size;
  }
}
void Linker::addBytesToSection(vector<unsigned char>bytes, string section){
  if(sectionAdded(section)){
    section_name_content[section].bytes.insert(section_name_content[section].bytes.end(),bytes.begin(),bytes.end());
  }else{
    section_name_content[section] = {section, bytes};
  }
}

bool Linker::sectionAdded(string section){
  return section_name_content.count(section) != 0;
}
bool Linker::sectionRelocAdded(string section){
  return relocation_tables.count(section) != 0;
}

bool Linker::symbolInSymTab(string label){
  return global_symbol_table.count(label)!=0;
}

int Linker::readArgs(char* argv[], int argc){
  vector<string> args;

  // string output_file_name = "";
  bool output_name_given = false;
  bool hex_found = false;
  for(int i = 1; i < argc; i++)
    args.push_back(string(argv[i]));
  
  for(auto & arg : args){
    if(arg == "-hex"){
      hex_found = true;
    }else if(arg == "-o"){
      output_name_given = true;
    }else if(arg.find("-place")!=string::npos){
      string section = arg.substr(arg.find("=")+1, arg.find("@")-arg.find("=")-1);
      uint32_t address = stoul(arg.substr(arg.find("@")+1),nullptr, 16);
      places[section] = {
        section,
        address
      };
    }else{
      if(output_name_given){
        output_file_name = arg;
        output_name_given = false;
      }
      else{
        // addFilename(arg);
        filenames.push_back(arg);

      }
    }
  }
  if(!hex_found){
    cout<<"-hex opcija je obavezna, a nije navedena!";
    return -1;
  }
    return 0;
}

// void Linker::addFilename(string file){
//   filenames.push_back(file);
// }

void Linker::updateSectionAddrMap(){
  //find last places addr
  uint32_t last_addr = 0;
  for(auto & place : places){
    if(place.second.newOffset + global_symbol_table[place.first].section_size >= last_addr){
      last_addr = place.second.newOffset + global_symbol_table[place.first].section_size;

    }
    section_addr_map[place.first] = place.second;
  }
  for(auto & sect : global_symbol_table){
    if(sect.second.section_size > 0){
    if(section_addr_map.count(sect.second.section)==0){
      section_addr_map[sect.second.section] = {sect.second.section, last_addr};
      last_addr += sect.second.section_size;
    }
      cout << section_addr_map[sect.first].section << "  " <<hex<< section_addr_map[sect.first].newOffset << "  " << sect.second.section_size << endl;
    }
  }
  // hex_content.resize(7);
}

void Linker::resolveRelocations(){

  updateSectionAddrMap();
  for(auto & table : relocation_tables){
    cout << "rel tablala" << table.first << endl;
    for(auto & reloc : table.second){
      if(section_addr_map.count(reloc.symbol) != 0){
        uint32_t newVal = section_addr_map[reloc.symbol].newOffset + reloc.addend;
        section_name_content[table.first].bytes[reloc.offset] = newVal;
        section_name_content[table.first].bytes[reloc.offset + 1] = newVal >> 8;
        section_name_content[table.first].bytes[reloc.offset + 2] = newVal >> 16;
        section_name_content[table.first].bytes[reloc.offset + 3] = newVal >> 24;
      }else{
        // cout << "TTT" << table.first << " " <<reloc.offset<< " "<< reloc.symbol<< " " << section_addr_map[global_symbol_table[reloc.symbol].section].newOffset << " " << global_symbol_table[reloc.symbol].offset << endl;
        cout << "newnew " << reloc.symbol << "  " << reloc.offset;
        uint32_t newVal = section_addr_map[global_symbol_table[reloc.symbol].section].newOffset + global_symbol_table[reloc.symbol].offset + reloc.addend;
        // cout << "newVal " << newVal << endl;
        section_name_content[table.first].bytes[reloc.offset] = newVal;
        section_name_content[table.first].bytes[reloc.offset + 1] = newVal >> 8;
        section_name_content[table.first].bytes[reloc.offset + 2] = newVal >> 16;
        section_name_content[table.first].bytes[reloc.offset + 3] = newVal >> 24;
        // if(table.first == "isr"){
        //   cout << "newVal " << newVal << endl;
        //   for(auto & i:section_name_content["isr"].bytes){
        //     cout << hex << +i << endl;
        //   }
        // }

      }
    }
  }

}

/*
struct symtable_entry{
  string label;
  string section;
  int offset;
  bool is_local;
  bool defined;*/

string Linker::lineToSectionName(string line){
  string result;
  stringstream ss (line);
  ss >> result;
  ss >> result;
  return result;
}
vector<unsigned char> Linker::lineToBytes(string line){
  vector<unsigned char> bytes;
  string result;
  stringstream ss (line);
  while(ss>>result){
    bytes.push_back(stoi(result, nullptr, 16));
  }
  return bytes;
}
symtable_entry Linker::lineToSymtableEntry(string line){
  string result;
  stringstream ss (line);
  vector<string> cols;
  while(ss >> result)
    cols.push_back(result);

  symtable_entry entry ={
    cols[0], // label
    cols[1], //section
    stoi(cols[2]), //offset
    cols[3]=="LOCAL"?true:false, //local
    cols[4]=="true"?true:false, //defined
    {},
    0,
    stoi(cols[5]) //section size
  };
  return entry;
}

bool Linker::sectionInPlaces(string section){
  return places.count(section) != 0;
}

int Linker::checkForErrors(){
  for(auto & sym : global_symbol_table){
    if(sym.second.section == "UNDEF"){
      cout << "Simbol " + sym.first + " je nerazresen!";
      return -1;
    }
  }
  for(auto & place1 : places){
    for(auto & place2 : places){
      if(place1.second.newOffset != place2.second.newOffset){
        if(place1.second.newOffset <= place2.second.newOffset && place1.second.newOffset + global_symbol_table[place1.first].section_size > place2.second.newOffset){
          cout << "GRESKA : Sekcije " + place1.first + " i " + place2.first + " se preklapaju!";
          return -2;
        }
      }
    }
  }
  return 0;
}

void Linker::generateHexBytes(){
  for(unordered_map<string, Sect_Addr>::iterator sect = section_addr_map.begin(); sect != section_addr_map.end(); ++sect){
    for(int i = 0; i < section_name_content[sect->first].bytes.size(); i++){
      unsigned char byte = section_name_content[sect->first].bytes[i];
      // cout << hex << byte << endl;
      hex_content.push_back(make_pair(sect->second.newOffset + i,byte));
    }
    // hex_content.push_back(make_pair(0,0));
  }
}

void Linker::generateHexFile(const char* output_file){
  generateHexBytes();
  char foutput[128];
  strcpy(foutput, output_file);

  ofstream output;
  output.open(foutput, ios::trunc | ios::ate);


  output << "----------------------------------" << endl; 
  output << "Symbol table: " << endl;
  output << "----------------------------------" << endl;
  output <<  "Label: |  Section:  |   Offset:  |  Local:   |  Defined:  |  Section Size: " << endl;
  output << "----------------------------------" << endl;

  vector<symtable_entry> symbols;
  for(unordered_map<string, symtable_entry>::iterator it = global_symbol_table.begin(); it != global_symbol_table.end(); ++it){
    symbols.push_back(it->second);
  }
  sort(symbols.begin(), symbols.end());
  

  for(auto & sym : symbols){
    output << sym.label << "  " << sym.section << " " << sym.offset << "  " << (sym.is_local?"LOCAL":"GLOBAL") << "  " << (sym.defined?"true":"false") << " " << sym.section_size << endl;
  }

  output << "----------------------------------" << endl; 
  output << "Relocation records: " << endl;
  output << "----------------------------------" << endl;
  output <<  "Section:  |   Offset:  |  Type:   |  Symbol:  |  Addend: " << endl;
  output << "----------------------------------" << endl;

  for(unordered_map<string, vector<RelocationTableEntry>>::iterator rel = relocation_tables.begin(); rel != relocation_tables.end(); ++rel){
    output<< ".rela. "<<rel->first<<endl;
    for(auto & ent : rel->second)
      output<<ent.section <<" "<<ent.offset<<"  "<<ent.type<<"  "<<ent.symbol<<"  "<< ent.addend<<endl;
  }
  output << "--------------------------------" << endl;
  output << " HEX: " << endl;
  output << "--------------------------------" << endl;
  sort(hex_content.begin(), hex_content.end(), [](auto &left, auto &right){
    return left.first < right.first;
  });
  for(int i = 0; i < hex_content.size(); i++){
    if(hex_content[i].first % 8 == 0){
      output << setw(4)<<setfill('0') << hex << hex_content[i].first << setw(0) << ": ";
    }
    output << hex << setfill('0') << setw(2) << +(hex_content[i].second) << " ";
    if(((hex_content[i+1].first - hex_content[i].first) > 1)) {
      output << hex << setfill('0') << setw(2) << +(unsigned char)0x00 << " ";
      output << hex << setfill('0') << setw(2) << +(unsigned char)0x00 << " ";
      output << hex << setfill('0') << setw(2) << +(unsigned char)0x00 << " ";
      output << hex << setfill('0') << setw(2) << +(unsigned char)0x00;

    }
    if(hex_content[i+1].first%8 == 0) output << endl;
    // if((i + 1) % 8 == 0) output << endl;
  }

  output.close();
}

