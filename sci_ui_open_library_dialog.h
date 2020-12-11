#ifndef SCI_UI_OPEN_LIBRARY_DIALOG_H
#define SCI_UI_OPEN_LIBRARY_DIALOG_H

#include <QDialog>

namespace Ui {
class sci_ui_open_library_dialog;
}

namespace scigui{

/**
 * @brief 打开图书馆界面：用来显示电脑文件系统并选取并读取其中图书馆储存文件
 */
class sci_ui_open_library_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit sci_ui_open_library_dialog(QWidget *parent = nullptr);
    ~sci_ui_open_library_dialog();

private:
    Ui::sci_ui_open_library_dialog *ui;
};

}


#endif // SCI_UI_OPEN_LIBRARY_DIALOG_H
