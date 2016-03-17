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
    HighScores.cpp

HEADERS  += mainwindow.h \
    GameModel.h \
    HighScores.h

FORMS    += mainwindow.ui
