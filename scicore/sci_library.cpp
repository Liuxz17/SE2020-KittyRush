#include "sci_library.h"

namespace scicore {

sci_library::sci_library(){

}

void sci_library::set_root(sci_file *root){
    this->_root = root;
}


sci_file* sci_library::get_root(){
    return this->_root;
}

long long sci_library::total_file(sci_file* root){
    int count = 1;
    for(int i = 0; i<root->child_count(); i++){
        count+=total_file(root->get_child(i));
    }
    return count;
}

}
