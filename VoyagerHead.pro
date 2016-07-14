#-------------------------------------------------
#
# Project created by QtCreator 2016-07-13T19:05:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VoyagerHead
TEMPLATE = app
LIBS += -LwiringPi

SOURCES += main.cpp\
        cmainwindow.cpp \
    ccommanager.cpp

HEADERS  += cmainwindow.h \
    ccommanager.h

FORMS    += cmainwindow.ui
