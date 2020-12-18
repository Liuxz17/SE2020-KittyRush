#ifndef SCI_LIBRARY_DISPLAY_WIDGET_H
#define SCI_LIBRARY_DISPLAY_WIDGET_H

#include <QTabWidget>

class sci_library_display_widget: public QTabWidget
{
    Q_OBJECT

public:
    explicit sci_library_display_widget(QWidget *parent = nullptr);
    ~sci_library_display_widget();


public slots:
    /**
     * @brief 关闭index处的展示窗口
     * @param index
     */
    void close_page(int index);
};

#endif // SCI_LIBRARY_DISPLAY_WIDGET_H
