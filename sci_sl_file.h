#ifndef SCI_SL_FILE_H
#define SCI_SL_FILE_H

#include "sci_folder.h"

class sci_sl_file
{
public:
    sci_sl_file();

    void save(scicore::sci_file* root,std::string path);

    scicore::sci_file* load(std::string path);
};

#endif // SCI_SL_FILE_H
