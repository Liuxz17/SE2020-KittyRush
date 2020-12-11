#ifndef SCI_UI_ADD_ITEM_DIALOG_H
#define SCI_UI_ADD_ITEM_DIALOG_H

#include <QDialog>

#include "sci_folder.h"

namespace Ui {
class sci_ui_add_item_dialog;
}


namespace scigui {

class sci_ui_add_item_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit sci_ui_add_item_dialog(QWidget *parent = nullptr);
    ~sci_ui_add_item_dialog();

signals:
    void emit_item( scicore::sci_file* item);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::sci_ui_add_item_dialog *ui;
};

}


#endif // SCI_UI_ADD_ITEM_DIALOG_H
