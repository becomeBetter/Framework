#-------------------------------------------------
#
# Project created by QtCreator 2016-03-03T00:05:36
#
#-------------------------------------------------
INCLUDEPATH += ../RC_Global\
    ../RC_Interface/
QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RC_Application
TEMPLATE = app


SOURCES += main.cpp \
    CConfig.cpp \
    ../RC_Global/CConfigBase.cpp \
    CAppLauncher.cpp

HEADERS  += \
    CConfig.h \
    CAppLauncher.h

DLLDESTDIR = ../Debug
