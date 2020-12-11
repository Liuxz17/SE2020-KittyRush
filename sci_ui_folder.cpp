#include "sci_ui_folder.h"

namespace scigui {

sci_ui_folder::sci_ui_folder(std::string name, sci_file_model* model, scicore::sci_file* parent):sci_ui_file(model)
{
    this->_folder=new scicore::sci_folder(name,parent);
}

sci_ui_folder::sci_ui_folder(scicore::sci_folder* folder, sci_file_model* model):sci_ui_file(model){
    this->_folder = folder;
}

}
