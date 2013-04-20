# -------------------------------------------------
# Project created by QtCreator 2010-04-16T11:31:47
# -------------------------------------------------
TARGET = agre
TEMPLATE = app
SOURCES += src/wii_inf.cpp \
    src/mgmt.cpp \
    src/mainwindow.cpp \
    src/main.cpp \
    src/algo.cpp
HEADERS += src/wiiuse.h \
    src/mgmt.h \
    src/mainwindow.h \
    src/algo.h
FORMS += src/mainwindow.ui

win32:CONFIG += console
LIBS += wiiuse.lib
