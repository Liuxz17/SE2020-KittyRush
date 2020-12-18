#include "sci_library_display_widget.h"

sci_library_display_widget::sci_library_display_widget(QWidget *parent) :
    QTabWidget(parent)
{
    this->setTabsClosable(true);
    connect(this,SIGNAL(tabCloseRequested(int)),this,SLOT(close_page(int)));
}

sci_library_display_widget::~sci_library_display_widget()
{

}

void sci_library_display_widget::close_page(int index){
    QWidget* widget = this->widget(index);

    if(widget){
        //this->removeTab(index);
        delete widget;
        this->removeTab(index);
    }
}
