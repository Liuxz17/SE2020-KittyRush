#include "library_widget.h"
#include "welcome_widget.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QFont font("FangSong");
    QApplication::setFont(font);

    welcome_widget w0;
    library_widget w1;
    welcome_thread t0;
    QObject::connect(&t0, SIGNAL(finish()), &w0, SLOT(hide()));
    QObject::connect(&t0, SIGNAL(finish()), &w1, SLOT(show()));

    return a.exec();
}
