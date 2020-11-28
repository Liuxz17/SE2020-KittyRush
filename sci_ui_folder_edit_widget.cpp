#include "sci_ui_folder_edit_widget.h"
#include "ui_sci_ui_folder_edit_widget.h"

sci_ui_folder_edit_widget::sci_ui_folder_edit_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sci_ui_folder_edit_widget)
{
    ui->setupUi(this);
}

sci_ui_folder_edit_widget::sci_ui_folder_edit_widget(sci_ui_file* file,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sci_ui_folder_edit_widget)
{
    ui->setupUi(this);
}

sci_ui_folder_edit_widget::~sci_ui_folder_edit_widget()
{
    delete ui;
}
