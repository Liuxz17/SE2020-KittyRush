#ifndef SCI_UI_LIBRARY_WIDGET_H
#define SCI_UI_LIBRARY_WIDGET_H

#include <QMainWindow>

#include <QTreeView>
#include <QStandardItemModel>

#include "sci_ui_folder.h"

namespace Ui {
class sci_ui_library_widget;
}

class sci_ui_library_widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit sci_ui_library_widget(QWidget *parent = nullptr);
    ~sci_ui_library_widget();

private slots:
    void on_treeView_library_file_tree_doubleClicked(const QModelIndex &index);

    void on_treeView_library_file_tree_clicked(const QModelIndex &index);

    void on_treeView_library_file_tree_customContextMenuRequested(const QPoint &pos);

protected:
    void mousePressEvent(QMouseEvent * event);

private:
    Ui::sci_ui_library_widget *ui;

    QTreeView *treeView_library_file_tree;
    QStandardItemModel* model;//创建模型

};

#endif // SCI_UI_LIBRARY_WIDGET_H
