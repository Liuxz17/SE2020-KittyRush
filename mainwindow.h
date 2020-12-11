#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace scigui {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_new_library_clicked();

    void on_pushButton_open_library_clicked();

    void on_pushButton_add_library_clicked();

private:
    Ui::MainWindow *ui;
};

}

#endif // MAINWINDOW_H
