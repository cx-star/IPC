#include <QDateTime>
#include "testform.h"
#include "ui_testform.h"

testForm::testForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testForm)
{
    ui->setupUi(this);
    ui->spinBox_4->setValue(static_cast<int>(QDateTime::currentSecsSinceEpoch()));
    ui->dateTimeEditS->setDateTime(QDateTime::fromString("2019-03-26 00:00:00","yyyy-MM-dd hh:mm:ss"));
    ui->dateTimeEditE->setDateTime(QDateTime::fromString("2019-03-26 23:59:59","yyyy-MM-dd hh:mm:ss"));
}

testForm::~testForm()
{
    delete ui;
}

void testForm::on_pushButton_clicked()
{
    emit ss(static_cast<uint>(ui->spinBox->value()),static_cast<uint>(ui->spinBox_2->value()),
            static_cast<uint>(ui->checkBox->isChecked()?ui->dateTimeEditS->dateTime().toSecsSinceEpoch():ui->spinBox_3->value()),
            static_cast<uint>(ui->checkBox->isChecked()?ui->dateTimeEditE->dateTime().toSecsSinceEpoch()  :ui->spinBox_4->value()),
            static_cast<uint>(ui->spinBox_5->value()));
}
