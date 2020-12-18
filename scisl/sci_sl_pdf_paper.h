#ifndef SCI_SL_PDF_PAPER_H
#define SCI_SL_PDF_PAPER_H

#include "sci_sl_file.h"
#include "scicore/sci_pdf_paper.h"

namespace scisl{

class sci_sl_pdf_paper:public sci_sl_file
{
public:
    sci_sl_pdf_paper(scicore::sci_pdf_paper* paper){
        _paper = paper;
    }

    char* write(){
        std::string content;

    }

    void read(char* path){

    }

    int type(){
        return 2;
    }

    char* path(){
        return (char*)std::string(_paper->get_name()+".pp").c_str();
    }

    char* desc(){
        return (char*)_paper->get_path().c_str();
    }

private:
    scicore::sci_pdf_paper* _paper;

};


}


#endif // SCI_SL_PDF_PAPER_H
