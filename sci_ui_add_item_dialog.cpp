#include "sci_ui_add_item_dialog.h"
#include "ui_sci_ui_add_item_dialog.h"

sci_ui_add_item_dialog::sci_ui_add_item_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sci_ui_add_item_dialog)
{
    ui->setupUi(this);
}

sci_ui_add_item_dialog::~sci_ui_add_item_dialog()
{
    delete ui;
}


void sci_ui_add_item_dialog::on_buttonBox_accepted()
{
    emit emit_item_name(ui->textEdit_item_name->toPlainText());
}
