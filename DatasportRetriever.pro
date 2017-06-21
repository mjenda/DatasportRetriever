#-------------------------------------------------
#
# Project created by QtCreator 2017-06-21T21:36:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DatasportRetriever
TEMPLATE = app

LIBS += -lhtmlcxx
QMAKE_CXXFLAGS += -std=c++14

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    DatasportParser.cpp \
    DatasportHtmlGetter.cpp

HEADERS += \
        mainwindow.h \
    DatasportParser.h \
    DatasportHtmlGetter.h

FORMS += \
        mainwindow.ui
