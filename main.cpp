#include "vediowidget.h"
#include "mainform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainForm mw;
    mw.show();

//    //test
//    vedioWidgetRef ref;
//    ref.devType = DEV_TYPE_NVR;
//    vedioWidget w(ref);
//    w.show();

    return a.exec();
}
