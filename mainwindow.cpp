#include "mainwindow.h"
#include "ui_mainwindow.h"

//sci ui includes
#include "sci_ui_open_library_dialog.h"
#include "sci_ui_library_widget.h"
//qt ui includes
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_new_library_clicked()
{
    sci_ui_open_library_dialog* dialog = new sci_ui_open_library_dialog();
    dialog->show();
}

void MainWindow::on_pushButton_open_library_clicked()
{
    sci_ui_library_widget* widget = new sci_ui_library_widget();
    widget->show();
}

void MainWindow::on_pushButton_add_library_clicked()
{
    QFileDialog* dialog = new QFileDialog();
    dialog->show();
}