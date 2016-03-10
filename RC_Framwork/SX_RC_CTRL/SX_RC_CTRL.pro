#-------------------------------------------------
#
# Project created by QtCreator 2016-03-02T16:09:18
#
#-------------------------------------------------
INCLUDEPATH += ../RC_Global\
    ../RC_Interface/

QT       -= gui

QT       += xml

TARGET = SX_RC_CTRL
TEMPLATE = lib

DEFINES += RC_TEMPLATE_LIBRARY

SOURCES += \
    CService.cpp \
    ../RC_Global/CModuleBase.cpp \
    CModule.cpp \
    CConfig.cpp \
    ../RC_Global/CConfigBase.cpp

HEADERS += \
    CService.h \
    ../RC_Global/CModuleBase.h \
    CModule.h \
    EComponentType.h \
    ../RC_Interface/IConfig.h \
    CConfigBase.h \
    CConfig.h\
    CConfigBase.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
DLLDESTDIR = ../Debug

