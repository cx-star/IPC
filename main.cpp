#include "vediowidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vedioWidget w;
    w.show();
//    vedioWidget w2("2");
//    w2.show();

    return a.exec();
}
