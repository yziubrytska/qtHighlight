#-------------------------------------------------
#
# Project created by QtCreator 2019-04-05T10:21:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SearchHighlight
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        widget.cpp \
    highlight.cpp

HEADERS  += widget.h \
   highlight.h

FORMS    += \
    widget.ui
