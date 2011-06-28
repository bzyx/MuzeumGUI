#-------------------------------------------------
#
# Project created by QtCreator 2011-05-12T23:09:37
#
#-------------------------------------------------

QT       += core gui xml

TARGET = MuzeumGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    src/muzeumkontener.cpp \
    src/eksponatmuzealny.cpp \
    src/eobraz.cpp \
    src/eprzemiotuzytkowy.cpp \
    src/erzezba.cpp \
    src/emebel.cpp \
    src/erekopis.cpp \
    src/estarodruk.cpp \
    eksponatmodel.cpp \
    src/meta.cpp \
    src/mktyp.cpp \
    src/material.cpp \
    src/materialmodel.cpp \
    materialdialog.cpp

HEADERS  += mainwindow.h \
    src/muzeumkontener.h \
    src/eksponatmuzealny.h \
    src/eobraz.h \
    src/eprzemiotuzytkowy.h \
    src/erzezba.h \
    src/emebel.h \
    src/erekopis.h \
    src/estarodruk.h \
    eksponatmodel.h \
    src/meta.h \
    src/mktyp.h \
    src/material.h \
    src/materialmodel.h \
    materialdialog.h

FORMS    += mainwindow.ui \
    materialdialog.ui

RESOURCES += \
    zasoby.qrc

RC_FILE = ico.rc
