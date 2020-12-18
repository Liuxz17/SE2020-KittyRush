#ifndef SCI_SL_FILE_H
#define SCI_SL_FILE_H


#include "../scicore/sci_file.h"

namespace scisl {
/**
 * @brief 存储和读取功能的抽象类
 */
class sci_sl_file
{
public:
    sci_sl_file();

    virtual char* write()=0;

    virtual void read(char*)=0;

    virtual int type()=0;

    virtual char* path()=0;

    virtual char* desc()=0;
protected:
};

}


#endif // SCI_SL_FILE_H
