#ifndef MAINFORM_H
#define MAINFORM_H

#include <QSettings>
#include <QWidget>
#include <QMenu>
#include <QMouseEvent>
#include "vediowidget.h"

namespace Ui {
class MainForm;
}

#define INI_HOST "host"
#define INI_NAME "name"
#define INI_PWD "pwd"
#define INI_PORT "port"
#define INI_HOST_DEF "192.168.1.1"
#define INI_NAME_DEF "admin"
#define INI_PWD_DEF "admin"
#define INI_PORT_DEF 554
#define INI_SIZE "size"
#define INI_POS "pos"
#define INI_TITLE "title"
#define INI_TITLE_DEF "未命名"
#define INI_CHANNEL_NAMES "names"
#define INI_CHANNEL_ID "channel"
#define INI_CHANNEL_ID_DEF 0
#define INI_DEV_TYPE "type"
#define INI_DEV_TYPE_DEF DEV_TYPE_NUL

#define INI_ID_LIST "widgetIdList"

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm();

signals:
    void m_close();

protected:
    void closeEvent(QCloseEvent *event);//重载关闭事件，使一般情况下为最小化

private slots:
    //获取当前vedioWidget
    void m_vw_saveLoc(const QString& id,const QPoint& p,const QSize& s);
    void m_vw_readLoc(vedioWidget *vw);
    void m_vw_channelNames(const QString& id,const QStringList& names);

    void on_pushButtonQuit_clicked();

private:
    Ui::MainForm *ui;

    void initContextMenu();
    QSettings *m_setting;
    vedioWidget* m_contextAtVediowidget;


    bool isRealQuit=false;
};

#endif // MAINFORM_H
