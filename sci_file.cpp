#include "sci_file.h"


namespace scicore {

sci_file::sci_file(std::string name,sci_file* parent):_name(name)
{
    _parent = parent;
}

char sci_file::type(){
    return 0;
}

std::string sci_file::get_name(){
    return _name;
}

bool sci_file::set_name(std::string name){
    this->_name = name;
}

sci_file* sci_file::get_child(int index){
    return NULL;
}

int sci_file::child_count(){
    return 0;
}

sci_file* sci_file::get_parent(){
    return _parent;
}

void sci_file::set_parent(sci_file* parent){
    this->_parent = parent;
}

int sci_file::match_child(sci_file *file){
    return -1;
}

bool sci_file::insert_file(sci_file* file,int index){
    return false;
}

sci_file* sci_file::remove_file(int index){
    return NULL;
}

bool sci_file::add_file(sci_file *file){
    insert_file(file,child_count());
}

}
