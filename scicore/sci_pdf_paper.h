#ifndef SCI_PDF_PAPER_H
#define SCI_PDF_PAPER_H

#include "sci_pdf_file.h"

namespace scicore {

class sci_pdf_paper:public sci_pdf_file
{
public:
    sci_pdf_paper(std::string name="untitiled", sci_file* parent = NULL);
    sci_pdf_paper(std::string name,std::string path, sci_file* parent = NULL);

    std::string write() override;

    void read(std::string data) override;

    void accept_file_visitor(sci_file_visitor* visitor) override;

    std::string database;
    std::string title;
    std::string author;
    std::string key_words;
    std::string origin;//来源
    std::string date;
    int reference;
    std::string id;
    std::string abstract;
};

}



#endif // SCI_PDF_PAPER_H
