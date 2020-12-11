#ifndef SCI_FILE_TREE_MODEL_H
#define SCI_FILE_TREE_MODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

#include "sci_file_tree.h"

class sci_file_tree_model :public QAbstractItemModel, public sci_file_tree
{
    Q_OBJECT
public:
    sci_file_tree_model(QObject *parent = 0);
    explicit sci_file_tree_model(QStringList headers,QObject *parent = 0);

    //只读模型的虚函数重载
    QVariant headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex index(int row, int column,const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    //可编辑模型的虚函数重载
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    sci_file_tree_node *itemFromIndex(const QModelIndex &index) const;


protected:
    QStringList _headers;//表头内容
};

#endif // SCI_FILE_TREE_MODEL_H
