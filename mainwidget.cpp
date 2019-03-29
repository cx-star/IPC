#include <QDebug>
#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidgetT::MainWidgetT(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    this->setWindowFlag(Qt::FramelessWindowHint);
    ui->setupUi(this);
}

MainWidgetT::~MainWidgetT()
{
    delete ui;
}

void MainWidgetT::on_pushButton_clicked()
{
    qDebug()<<"push";
}
