#ifndef SCI_FILE_H
#define SCI_FILE_H

#include <QDebug>
#include <QVariant>
#include <QMenu>
#include <QStandardItem>

class sci_ui_file:public QObject
{
    Q_OBJECT
public:
    sci_ui_file();
    sci_ui_file(QStandardItem* item):_ui_model_item(item){};

    virtual QMenu* context_menu(QWidget* parent)=0;
    virtual QWidget* edit_widget(QWidget* parent)=0;
protected:
    QStandardItem* _ui_model_item;
private:

};

Q_DECLARE_METATYPE(sci_ui_file*);

#endif // SCI_FILE_H
