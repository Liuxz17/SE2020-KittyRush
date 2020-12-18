#ifndef LIBRARY_WIDGET_H
#define LIBRARY_WIDGET_H

#include <QMainWindow>
#include <QTreeView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

#include <QSplitter>
#include "sci_library_display_widget.h"

#include "scigui/sci_file_model.h"
#include "scigui/sci_ui_file.h"

#include "scisl/sci_sl_lib_buffer.h"
#include "scisl/sci_sl_lib.h"

namespace Ui {
class library_widget;
}

class library_widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit library_widget(QWidget *parent = nullptr);
    ~library_widget();

private:
    Ui::library_widget *ui;

    //上方菜单栏
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *recentlyAccessedFileMenu;
    QMenu *editMenu;
    QMenu *webMenu;
    QMenu *sciManagerMenu;

    //图书馆左侧树状文件窗口
    QTreeView *treeView;
    scigui::sci_file_model *model;

    //图书馆右侧细节窗口
    sci_library_display_widget *tab_widget;
    //分裂器
    QSplitter * splitter;
    //最近文档
    scisl::sci_sl_lib_buffer _library_buffer;
    scisl::sci_sl_lib _lib;

private:
    void set_up_menu_bar();
    void set_up_tree_view();
    void set_up_tab_widget();
    void set_up_layout();

public slots:
    void on_treeView_library_file_tree_doubleClicked(const QModelIndex &index);

    void newLibrary();
    void openLibrary();
    void parseDocument();
    void onlineImportDocument();
    //void localImportDocument();
    void exportDocument();
    void save();
    void clearRAFRecord();
    void edit();
    void undo();
    void redo();
    void _delete();
    void search();
    void filter();
    void selectAll();
    void newWebDatabase();
    void openWebDatabase();
    void aboutSciManager();
    void instruction();
    void searchLine();

};

#endif // LIBRARY_WIDGET_H
