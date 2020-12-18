#ifndef SCI_SL_LIB_BUFFER_H
#define SCI_SL_LIB_BUFFER_H

#include <QJsonDocument>
#include <QJsonParseError>
#include <QFile>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>

#include <vector>
#include <string>

#include "sci_sl.h"

namespace scisl {

class sci_sl_lib_buffer:public sci_sl
{
public:
    sci_sl_lib_buffer();

    ~sci_sl_lib_buffer();

    sci_sl_lib_buffer(std::string path);

    bool add_library(std::string path);

    void save();

    void load();

    std::vector<std::string> _name_list;

};

}


#endif // SCI_SL_LIB_BUFFER_H
