#include "sci_ui_open_library_dialog.h"
#include "ui_sci_ui_open_library_dialog.h"

namespace scigui {

sci_ui_open_library_dialog::sci_ui_open_library_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sci_ui_open_library_dialog)
{
    ui->setupUi(this);
}

sci_ui_open_library_dialog::~sci_ui_open_library_dialog()
{
    delete ui;
}

}

