#ifndef SCI_LIBRARY_H
#define SCI_LIBRARY_H

#include "sci_file.h"

namespace scicore {

/**
 * @brief 图书馆类，用于储存文件树并完成一系列操作（目前啥操作都没有
 */
class sci_library
{
public:
    sci_library();

    /**
     * @brief 设置根节点
     * @param root:根文件（推荐为文件夹folder）
     */
    void set_root(sci_file *root);

    /**
     * @brief 获取根节点
     * @return
     */
    sci_file* get_root();
protected:
    sci_file* _root;
};

}


#endif // SCI_LIBRARY_H
