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

SOURCES += Sources/main.cpp\
        Sources/widget.cpp \
    Sources/highlight.cpp

HEADERS  += Headers/widget.h \
   Headers/highlight.h

FORMS    += \
    Forms/widget.ui
