#-------------------------------------------------
#
# Project created by QtCreator 2013-04-14T18:08:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gscalc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mathlib.cpp \
    controller.cpp \
    help.cpp

HEADERS  += mainwindow.h \
    controller.h \
    mathlib.h \
    help.h

FORMS    += mainwindow.ui \
    help.ui
