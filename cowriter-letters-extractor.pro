#-------------------------------------------------
#
# Project created by QtCreator 2013-06-25T17:22:52
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cowriter-letters-extractor
TEMPLATE = app


SOURCES += main.cpp\
        letterswindow.cpp \
    lettercanvas.cpp \
    lettersmanager.cpp \
    letterselector.cpp \
    lettersscene.cpp \
    lettersaver.cpp \
    sheets.cpp \
    letters.cpp

HEADERS  += letterswindow.h \
    lettercanvas.h \
    lettersmanager.h \
    letterselector.h \
    lettersscene.h \
    lettersaver.h \
    sheets.h \
    letters.h

FORMS    += letterswindow.ui

RESOURCES += \
    letters.qrc

