#ifndef SCI_FILE_VISITOR_ADAPTOR_H
#define SCI_FILE_VISITOR_ADAPTOR_H


#include "sci_ui_file.h"

#include "sci_ui_folder.h"


namespace scigui{

/**
 * @brief 用作file系统visitor的适配器层，当增加file的子类并且需要ui显示时，需在本类中增加对应visit函数的重载，函数参数为对应子类（同时在file的visitor中也要增加visit函数的重载
 */
class sci_file_visitor_adaptor:public scicore::sci_file_visitor{
public:
    sci_file_visitor_adaptor();

    void visit(scicore::sci_folder *file) override{
        this->_ui_file = new sci_ui_folder(file);
    }

    sci_ui_file* operator()(scicore::sci_file* file){
        file->accept_file_visitor(this);
        return _ui_file;
    }

    sci_ui_file* operator()(scicore::sci_file* file,sci_file_model* model){
        file->accept_file_visitor(this);
        _ui_file->set_model(model);
        return _ui_file;
    }

private:
    sci_ui_file* _ui_file;
};

static sci_file_visitor_adaptor ui_of_file;

}



#endif // SCI_FILE_VISITOR_ADAPTOR_H
