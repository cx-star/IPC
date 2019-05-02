#include "vediowidget.h"
#include "mainform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w;
    w.setWindowFlags(Qt::WindowStaysOnTopHint);
    w.show();
    w.close();

    MainForm mw;
    mw.show();

//    //test
//    vedioWidgetRef ref;
//    ref.devType = DEV_TYPE_NVR;
//    vedioWidget w(ref);
//    w.show();

    return a.exec();
}
