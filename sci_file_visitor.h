#ifndef SCI_FILE_VISITOR_H
#define SCI_FILE_VISITOR_H


//以下为子类名单-----------------------------
#include "sci_folder.h"
//-----------------------------------------

namespace scicore {

/**
 * @brief file的访问者类，用于在外部增加操作
 */
class sci_file_visitor{
public:
    virtual void visit(sci_folder *file) = 0;

    virtual ~sci_file_visitor(){};
};

}


#endif // SCI_FILE_VISITOR_H
