#-------------------------------------------------
#
# Project created by QtCreator 2016-01-19T14:24:09
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JPMeteo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    xmlreader.cpp \
    dataframe.cpp

HEADERS  += mainwindow.h \
    xmlreader.h \
    dataframe.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    example.xml

