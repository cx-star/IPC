#include "vediowidget.h"
#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWidgetT mw;
    mw.show();
    //    vedioWidget w;
//    w.show();
//    vedioWidget w2("2");
//    w2.show();

    return a.exec();
}
