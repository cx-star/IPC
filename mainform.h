#ifndef MAINFORM_H
#define MAINFORM_H

#include <QSettings>
#include <QWidget>
#include <QMenu>
#include <QMouseEvent>
#include <QTimer>
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

#define INI_SHOW_TRUE true
#define INI_SHOW_FALSE false

#define INI_NAMES "names"   //通道名称list
#define INI_NUM "num"       //通道数量

#define INI_IPC_LEVEL "ipc_level"       //要显示的通道号
#define INI_IPC_LEVEL_DEF 0
#define INI_IPC_SHOW "ipc_show"     //通道是否显示

#define INI_NVR_LEVELs "nvr_level"      //
#define INI_NVR_LEVEL_DEF 0
#define INI_NVR_SHOWs "nvr_show"

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
    void m_vw_saveLoc(vedioWidget *vw, const QPoint& p, const QSize& s);
    void m_vw_loadLoc(vedioWidget *vw);
    void m_vw_login(vedioWidget *vw);
    void m_vw_recentedClicked(vedioWidget *vw);

    void on_pushButtonQuit_clicked();

    void m_RaiseTimerOver();
    void m_ApplicationStateChange(Qt::ApplicationState state);

private:
    Ui::MainForm *ui;

    QList<vedioWidget*> list;
    void readIni();
    void initVW(vedioWidgetRef ref);
    QSettings *m_setting;
    vedioWidget* m_contextAtVediowidget;

    bool isRealQuit=false;

    QTimer *m_RaiseWindowsTimer;
};

#endif // MAINFORM_H
