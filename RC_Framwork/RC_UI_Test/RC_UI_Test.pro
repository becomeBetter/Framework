#-------------------------------------------------
#
# Project created by QtCreator 2016-03-02T16:09:18
#
#-------------------------------------------------
INCLUDEPATH += ../RC_Global\
    ../RC_Interface/

QT       += gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RC_UI_Test
TEMPLATE = lib

DEFINES += RC_TEMPLATE_LIBRARY

SOURCES += \
    CService.cpp \
    ../RC_Global/CModuleBase.cpp \
    CModule.cpp \
    CConfig.cpp \
    CMainWindow.cpp \
    ../RC_Global/CConfigBase.cpp

HEADERS += \
    CService.h \
    ../RC_Global/CModuleBase.h \
    CModule.h \
    EComponentType.h \
    ../RC_Interface/IConfig.h \
    CConfigBase.h \
    CConfig.h \
    CMainWindow.h \
    ../RC_Interface/IWidget.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
DLLDESTDIR = ../Debug
