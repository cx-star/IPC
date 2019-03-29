#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidgetT : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidgetT(QWidget *parent = 0);
    ~MainWidgetT();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
