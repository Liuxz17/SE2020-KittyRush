#include "sci_library.h"

namespace scicore {
sci_library::sci_library()
{

}

void sci_library::set_root(sci_file *root){
    this->_root = root;
}

sci_file* sci_library::get_root(){
    return _root;
}
}

