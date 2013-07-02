#-------------------------------------------------
#
# Project created by QtCreator 2013-06-25T17:22:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cowriter-letters-extractor
TEMPLATE = app


SOURCES += main.cpp\
        letterswindow.cpp \
    lettercanvas.cpp \
    lettersmanager.cpp \
    letterselector.cpp \
    lettersscene.cpp \
    lettersaver.cpp

HEADERS  += letterswindow.h \
    lettercanvas.h \
    lettersmanager.h \
    letterselector.h \
    lettersscene.h \
    lettersaver.h

FORMS    += letterswindow.ui

RESOURCES += \
    res.qrc
