#include "library_widget.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QFont font("KaiTi");
    QApplication::setFont(font);

    // w;
    //w.show();
    library_widget w1;
    w1.show();
    return a.exec();
}
