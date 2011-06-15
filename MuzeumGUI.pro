#-------------------------------------------------
#
# Project created by QtCreator 2011-05-12T23:09:37
#
#-------------------------------------------------

QT       += core gui

TARGET = MuzeumGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    src/file.cpp \
    src/muzeumkontener.cpp \
    src/eksponatmuzealny.cpp \
    src/eobraz.cpp \
    src/eprzemiotuzytkowy.cpp \
    src/erzezba.cpp \
    src/emebel.cpp \
    src/erekopis.cpp \
    src/estarodruk.cpp

HEADERS  += mainwindow.h \
    src/file.h \
    src/muzeumkontener.h \
    src/eksponatmuzealny.h \
    src/eobraz.h \
    src/eprzemiotuzytkowy.h \
    src/erzezba.h \
    src/emebel.h \
    src/erekopis.h \
    src/estarodruk.h

FORMS    += mainwindow.ui

RESOURCES += \
    zasoby.qrc

RC_FILE = ico.rc
