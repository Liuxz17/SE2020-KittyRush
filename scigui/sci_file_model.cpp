#include "sci_file_model.h"

#include "sci_file_visitor_adaptor.h"

namespace scigui {

sci_file_model::sci_file_model(QObject *parent):QAbstractItemModel(parent)
{
    _root = NULL;
}

sci_file_model::~sci_file_model()
{
    delete _root;
}


scicore::sci_file* sci_file_model::file_from_index(const QModelIndex &index) const{
    if (index.isValid()) {
        scicore::sci_file* file = static_cast<scicore::sci_file *>(index.internalPointer());
        if(file)
            return file;
    }

    return _root;

}

QModelIndex sci_file_model::index_of(scicore::sci_file* file){
    if(file){
        scicore::sci_file* parent = file->get_parent();
        if(parent){
            int row = file->get_parent()->match_child(file);
            return createIndex(row,0,file);
        }
    }
    return QModelIndex();
}


QModelIndex sci_file_model::index(int row, int column, const QModelIndex &parent) const{
    if (parent.isValid() && column != 0)
        return QModelIndex();
    scicore::sci_file *parent_file = file_from_index(parent);
    if(!parent_file){
        return QModelIndex();
    }
    scicore::sci_file *child_file = parent_file->get_child(row);

    if (child_file)
        return createIndex(row, column, child_file);
    return QModelIndex();

}



QModelIndex sci_file_model::parent(const QModelIndex &child) const{
    if(!child.isValid()){
        return QModelIndex();
    }
    scicore::sci_file *node = file_from_index(child);
    if (!node)
        return QModelIndex();
    scicore::sci_file *parentNode = node->get_parent();
    if (!parentNode)
        return QModelIndex();
    scicore::sci_file *grandparentNode = parentNode->get_parent();
    if (!grandparentNode)
        return QModelIndex();

    int row = grandparentNode->match_child(parentNode);
    return createIndex(row, 0, parentNode);
}

int sci_file_model::rowCount(const QModelIndex &parent) const{

    scicore::sci_file *parent_file = file_from_index(parent);
    if (!parent_file)
        return 0;
    return parent_file->child_count();
}

int sci_file_model::columnCount(const QModelIndex &parent) const{
    return 1;
}

QVariant sci_file_model::data(const QModelIndex &index, int role) const{
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case Qt::TextAlignmentRole:{
        return int(Qt::AlignLeft | Qt::AlignVCenter);
        break;
    }

    case Qt::DisplayRole:{

        scicore::sci_file* node = file_from_index(index);

        return QString::fromStdString(node->get_name());
        break;
    }

    case Qt::DecorationRole:{
        scicore::sci_file* node = file_from_index(index);

        return QVariant(*(ui_of_file(node)->file_icon()));
    }

    default:{
        return QVariant();
    }
    }

    return QVariant();
}

QVariant sci_file_model::headerData(int section, Qt::Orientation orientation, int role) const{
    //返回 section列处的列名
    if(role == Qt::DisplayRole && section == 0 && orientation == Qt::Horizontal)
        return QVariant("file name");
    return QVariant();
}

Qt::ItemFlags sci_file_model::flags(const QModelIndex &index) const{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    if (index.column()==0) {
        flags |= Qt::ItemIsEditable;
    }
    return flags;
}

bool sci_file_model::setData(const QModelIndex &index, const QVariant &value, int role){
    if(!index.isValid())
        return false;

    if(index.column()>0)
        return false;

    if(role == Qt::DisplayRole){
        scicore::sci_file* node = file_from_index(index);
        node->set_name( value.toString().toStdString() );
        emit dataChanged(index,index,{Qt::DisplayRole, Qt::EditRole});
        return true;
    }

    return false;
}

void sci_file_model::clear(){
    if(_root){
        _root->delete_self();
        delete _root;
        _root = NULL;
    }

}

void sci_file_model::set_root(scicore::sci_file *root){
    clear();
    this->_root = root;
    qDebug()<<"virtual set root";
    emit dataChanged(index_of(root),index_of(root),{Qt::DisplayRole, Qt::EditRole});
    emit layoutChanged();
}

bool sci_file_model::insert_file(int row, scicore::sci_file* file, scicore::sci_file *parent) {
    return insert_file(row,file,index_of(parent));
}

bool sci_file_model::insert_file(int row, scicore::sci_file* file, const QModelIndex &parent) {
    if(rowCount(parent)<row||0>row){
        return false;
    }

    beginInsertRows(parent, row, row);

    scicore::sci_file* parent_file = file_from_index(parent);
    parent_file->insert_file(file,row);

    endInsertRows();
    return true;
}

scicore::sci_file* sci_file_model::remove_file(int row,const QModelIndex &parent){
    if(rowCount(parent)<=row||0>row){
        return NULL;
    }
    beginRemoveRows(parent, row, row);

    scicore::sci_file* parent_file = file_from_index(parent);
    scicore::sci_file* file = parent_file->remove_file(row);

    endRemoveRows();

    return file;
}
scicore::sci_file* sci_file_model::remove_file(int row, scicore::sci_file *parent){
    if(parent->child_count()<=row||0>row){
        return NULL;
    }

    scicore::sci_file* file = parent->remove_file(row);

    emit layoutChanged();

    return file;
}

bool sci_file_model::add_file(scicore::sci_file* file, scicore::sci_file* parent){

    insert_file(parent->child_count(),file,index_of(parent));
    return true;
}

}
