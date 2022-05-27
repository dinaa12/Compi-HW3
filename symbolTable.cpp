#include "symbolTable.h"

void SymbolTable::insertEntry(SymbolTableEntry* e) {
    this->table.push_back(e);
}

void SymbolTable::printTable() {
    for (vector<SymbolTableEntry*>::iterator it = this->table.begin(); it != this->table.end(); ++it) {
        SymbolTableEntry* current_entry = *it;
        string current_entry_name = current_entry->name;
        string current_entry_type = current_entry->type[0];
        int current_entry_offset = current_entry->offset;
        if (current_entry->is_func) {
            vector<string> current_entry_args = vector<SemTypeName>(current_entry->type.begin() + 1, current_entry->type.begin() + (current_entry->type.size() - 2));
            string current_entry_ret_type = current_entry->type[current_entry->type.size()-1];
            current_entry_type = output::makeFunctionType(current_entry_ret_type, current_entry_args);
        }
        output::printID(current_entry_name, current_entry_offset, current_entry_type);
    }
}

SymbolTableEntry* SymbolTable::getEntryByNameInTable(string name) {
    for (vector<SymbolTableEntry*>::iterator it = this->table.begin(); it != this->table.end(); ++it) {
        if((*it)->name == name){
            return (*it);
        }
    }
    return nullptr;
}