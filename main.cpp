#include "vediowidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vedioWidget w;
    w.show();

    return a.exec();
}
