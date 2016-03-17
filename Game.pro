#-------------------------------------------------
#
# Project created by QtCreator 2016-03-11T07:27:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    GameModel.cpp \
    Background.cpp \
    Runner.cpp \
    Scenery.cpp \
    Obstacles.cpp

HEADERS  += mainwindow.h \
    GameModel.h \
    Background.h \
    Runner.h \
    Scenery.h \
    Obstacles.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

QMAKE_CXXFLAGS += -std=c++0x
