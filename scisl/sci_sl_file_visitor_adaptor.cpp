#include "sci_sl_file_visitor_adaptor.h"

#include "sci_sl_folder.h"
#include "sci_sl_pdf_paper.h"

namespace scisl {

sci_sl_file_visitor_adaptor::sci_sl_file_visitor_adaptor()
{

}

void sci_sl_file_visitor_adaptor::visit(scicore::sci_folder *file){
    _file = new sci_sl_folder(file);
}

void sci_sl_file_visitor_adaptor::visit(scicore::sci_pdf_file *file){
    //_file = file;
}

void sci_sl_file_visitor_adaptor::visit(scicore::sci_pdf_paper *file){
    _file = new sci_sl_pdf_paper(file);
}

sci_sl_file* sci_sl_file_visitor_adaptor::get_sl_file(scicore::sci_file *file){
    file->accept_file_visitor(this);
    return _file;
}

}

