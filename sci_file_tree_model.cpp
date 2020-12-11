#include "sci_file_tree_model.h"

sci_file_tree_model::sci_file_tree_model(QObject *parent):QAbstractItemModel(parent)
{
}

sci_file_tree_model::sci_file_tree_model(QStringList headers,QObject *parent):QAbstractItemModel(parent),_headers(headers){

}

QVariant sci_file_tree_model::headerData(int section, Qt::Orientation orientation,int role) const {
    //返回 section列处的列名
    if(role == Qt::DisplayRole && section == 0 && orientation == Qt::Horizontal)
        return QVariant("file");
    return QVariant();
}

QVariant sci_file_tree_model::data(const QModelIndex &index, int role) const{
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case Qt::TextAlignmentRole:{
        return int(Qt::AlignRight | Qt::AlignVCenter);
        break;
    }

    case Qt::DisplayRole:{
        sci_file_tree_node* node = itemFromIndex(index);
        return QString::fromStdString(node->get_data()->name);
        break;
    }

    default:{
        return QVariant();
    }
    }

    return QVariant();
}

bool sci_file_tree_model::setData(const QModelIndex &index,
                            const QVariant &value, int role)
{
    if(!index.isValid())
        return false;

    if(index.column()>0)
        return false;

    if(role == Qt::DisplayRole){
        sci_file_tree_node* node = itemFromIndex(index);
        node->get_data()->name = value.toString().toStdString();
        return true;
    }

    return false;
}

Qt::ItemFlags sci_file_tree_model::flags(const QModelIndex &index) const {
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    if(itemFromIndex(index)!=root){
        flags |= Qt::ItemIsEditable;
    }

    return flags;
}

QModelIndex sci_file_tree_model::index(int row, int column,const QModelIndex &parent) const {
    if(!this->get_root()||row<0||column<0){
        return QModelIndex();
    }
    sci_file_tree_node * node = itemFromIndex(parent);
    sci_file_tree_node *childNode = node->get_child(row);
    if (!childNode)
        return QModelIndex();
    return createIndex(row, column, childNode);
}

QModelIndex sci_file_tree_model::parent(const QModelIndex &index) const{
    sci_file_tree_node *node = itemFromIndex(index);
    if (!node)
        return QModelIndex();
    sci_file_tree_node *parentNode = node->get_parent();
    if (!parentNode)
        return QModelIndex();

    int row = parentNode->get_index();
    return createIndex(row, 0, parentNode);
}

int sci_file_tree_model::rowCount(const QModelIndex &parent) const{
    return 1;
}

int sci_file_tree_model::columnCount(const QModelIndex &parent) const {
    if (parent.column() > 0)
        return 0;
    sci_file_tree_node *parentNode = itemFromIndex(parent);
    if (!parentNode)
        return 0;
    return parentNode->child_count();
}

sci_file_tree_node* sci_file_tree_model::itemFromIndex(const QModelIndex &index) const{
    if (index.isValid()) {
        return static_cast<sci_file_tree_node *>(index.internalPointer());
    } else {
        return this->root;
    }
}
