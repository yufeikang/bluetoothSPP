#-------------------------------------------------
#
# Project created by QtCreator 2016-07-20T11:45:49
#
#-------------------------------------------------

QT       += core gui
QT += bluetooth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = blueToothSPP
TEMPLATE = app

CONFIG(release,debug|release):OBJECTS_DIR = ../tmp/release
else:CONFIG(debug,debug|release):OBJECTS_DIR = ../tmp/debug

CONFIG(release,debug|release):DESTDIR = ../bin/release
else:CONFIG(debug,debug|release):DESTDIR = ../bin/debug

SOURCES += main.cpp\
        mainwindow.cpp \
    deviceinfo.cpp \
    chatclient.cpp \

HEADERS  += mainwindow.h \
    deviceinfo.h \
    chatclient.h \

FORMS    += mainwindow.ui \
    deviceinfo.ui \


