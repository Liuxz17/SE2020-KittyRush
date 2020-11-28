#ifndef SCI_UI_FOLDER_H
#define SCI_UI_FOLDER_H

#include "sci_ui_add_item_dialog.h"
#include "sci_ui_folder_edit_widget.h"
#include "sci_ui_file.h"

class sci_ui_folder:public sci_ui_file
{
    Q_OBJECT
public:
    sci_ui_folder();
    sci_ui_folder(QStandardItem* item):sci_ui_file(item){};

    QMenu* context_menu(QWidget* parent){
        QMenu *qMenu = new QMenu(parent);

        QAction* exampleAction = new QAction("&Example");
        connect(exampleAction, SIGNAL(triggered()), this, SLOT(example()));

        //QAction* unfoldAction = new QAction("&Unfold");
        //connect(unfoldAction, SIGNAL(triggered()), this, SLOT(unfold()));

        QAction* addTreeItemAction = new QAction("&AddItem");
        connect(addTreeItemAction, SIGNAL(triggered()), this, SLOT(openAddItemWindow()));

        qMenu->addAction(exampleAction);
        qMenu->addAction(addTreeItemAction);


        return qMenu;
    }

    QWidget * edit_widget(QWidget *parent){
        sci_ui_file* file = _ui_model_item->data(Qt::UserRole+1).value<sci_ui_file*>();
        sci_ui_folder_edit_widget * edit_widget = new sci_ui_folder_edit_widget(parent);
        return edit_widget;
    }


public slots:
    void example(){
        qDebug()<<"this is a QMenu Action example"<<endl;
    }
    void unfold(){
        qDebug()<<"Unfold"<<endl;
    }
    void openAddItemWindow(){
        sci_ui_add_item_dialog* dialog = new sci_ui_add_item_dialog;
        dialog->show();
        connect(dialog,SIGNAL(emit_item_name(QString)),this,SLOT(addItem(QString)));
    }
    void addItem(QString name){
        QStandardItem* new_item = new QStandardItem(name);

        sci_ui_folder *object = new sci_ui_folder(new_item);
        QVariant variant;
        variant.setValue(object);

        new_item->setData(variant);
        this->_ui_model_item->appendRow(new_item);
    }
};

#endif // SCI_UI_FOLDER_H
