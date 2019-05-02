#-------------------------------------------------
#
# Project created by QtCreator 2019-03-23T16:49:17
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = $$PWD/bin
TARGET = IPC
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    vediowidget.cpp \
    mainform.cpp \
    testform.cpp \
    vediowidgeth264.cpp

PRECOMPILED_HEADER += utf8.h

HEADERS += \
    inc/NS_DECODER.h \
    inc/NS_DECODER_define.h \
    inc/NS_MP4.h \
    inc/NS_MP4_define.h \
    inc/NS_NET.h \
    inc/NS_NET_define.h \
    inc/NS_PLAYER.h \
    inc/NS_PLAYER_define.h \
    inc/NS_SOUND.h \
    inc/NVR_NET.h \
    inc/NVR_NET_define.h \
    inc/nvr_sdk.h \
    vediowidget.h \
    utf8.h \
    mainform.h \
    testform.h \
    vediowidgeth264.h \
    inc/H264Play.h \
    inc/netsdk.h

QMAKE_LFLAGS_WINDOWS= /SUBSYSTEM:WINDOWS,5.01

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib -lns_net -lns_player -lUser32 -lH264Play -lNetSdk
else:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib -lns_netD  -lns_playerD -lUser32 -lH264Play -lNetSdk

FORMS += \
    mainform.ui \
    testform.ui
