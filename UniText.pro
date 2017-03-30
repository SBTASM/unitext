#-------------------------------------------------
#
# Project created by QtCreator 2017-03-29T14:00:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UniText
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    row.cpp \
    dict.cpp \
    addrow.cpp

HEADERS  += mainwindow.h \
    row.h \
    dict.h \
    addrow.h

FORMS    += mainwindow.ui \
    dict.ui \
    addrow.ui
