#-------------------------------------------------
#
# Project created by QtCreator 2016-03-02T16:09:18
#
#-------------------------------------------------
INCLUDEPATH += ../RC_Global\
    ../RC_Interface/

QT       -= gui

QT       += xml

TARGET = RC_Platform
TEMPLATE = lib

DEFINES += RC_TEMPLATE_LIBRARY

SOURCES += \
    CService.cpp \
    ../RC_Global/CModuleBase.cpp \
    CModule.cpp \
    CConfig.cpp \
    ../RC_Global/CConfigBase.cpp \
    CObjectManager.cpp

HEADERS += \
    CService.h \
    ../RC_Global/CModuleBase.h \
    CModule.h \
    EComponentType.h \
    ../RC_Interface/IConfig.h \
    CConfig.h \
    ../RC_Global/CConfigBase.h \
    CObjectManager.h \
    ../RC_Global/IInterfaceHandler.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
DLLDESTDIR = ../Debug

