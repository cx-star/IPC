#ifndef TEXTFORM_H
#define TEXTFORM_H

#include <QWidget>

namespace Ui {
class testForm;
}

class testForm : public QWidget
{
    Q_OBJECT

public:
    explicit testForm(QWidget *parent = nullptr);
    ~testForm();
signals:
    void ss(uint ,uint,uint,uint,uint);
private slots:
    void on_pushButton_clicked();

private:
    Ui::testForm *ui;
};

#endif // TEXTFORM_H
