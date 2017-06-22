#-------------------------------------------------
#
# Project created by QtCreator 2017-06-21T21:36:38
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DatasportRetriever
TEMPLATE = app

LIBS += -lhtmlcxx
QMAKE_CXXFLAGS += -std=c++14

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    DatasportParser.cpp \
    DatasportHtmlGetter.cpp \
    DatasportModel.cpp

HEADERS += \
        mainwindow.h \
    DatasportParser.h \
    DatasportHtmlGetter.h \
    DatasportModel.h

FORMS += \
        mainwindow.ui
