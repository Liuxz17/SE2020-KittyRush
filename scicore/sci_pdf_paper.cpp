#include "sci_pdf_paper.h"

#include "sci_file_visitor.h"

namespace scicore{
sci_pdf_paper::sci_pdf_paper(std::string name, sci_file* parent):sci_pdf_file(name,parent)
{
    //论文信息
    database.clear();
    title.clear();
    authors.clear();
    key_words.clear();
    origin.clear();//来源
    date.clear();
    citation_times = 0;
    id.clear();
    abstract.clear();
}

sci_pdf_paper::sci_pdf_paper(std::string name,std::string path, sci_file* parent):sci_pdf_file(name,path,parent){
    //论文信息
    database.clear();
    title.clear();
    authors.clear();
    key_words.clear();
    origin.clear();//来源
    date.clear();
    citation_times = 0;
    id.clear();
    abstract.clear();
}


std::string sci_pdf_paper::write(){
    return "pdf";
}

void sci_pdf_paper::read(std::string data){

}

void sci_pdf_paper::accept_file_visitor(sci_file_visitor *visitor){
    visitor->visit(this);
}

}


