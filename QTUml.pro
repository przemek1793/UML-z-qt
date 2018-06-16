#-------------------------------------------------
#
# Project created by QtCreator 2018-06-07T11:59:40
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTUml
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    rejestracja.cpp \
    niezalogowany.cpp \
    logowanie.cpp \
    organizator.cpp \
    obsluga.cpp \
    doradca.cpp \
    administrator.cpp \
    wiadomosci.cpp \
    noweprzyjecie.cpp \
    kalendarz.cpp \
    detaleprzyjeciaorganizator.cpp \
    detaleprzyjeciaadmin.cpp \
    detaleprzyjeciapracownicy.cpp \
    zmiendaneprzyjecia.cpp \
    zatrudnijpracownikow.cpp \
    nowawiadomosc.cpp \
    listawiadomosci.cpp \
    listaprzyjec.cpp \
    listauzytkownikow.cpp

HEADERS += \
        mainwindow.h \
    rejestracja.h \
    niezalogowany.h \
    logowanie.h \
    organizator.h \
    obsluga.h \
    doradca.h \
    administrator.h \
    wiadomosci.h \
    noweprzyjecie.h \
    kalendarz.h \
    detaleprzyjeciaorganizator.h \
    detaleprzyjeciaadmin.h \
    detaleprzyjeciapracownicy.h \
    zmiendaneprzyjecia.h \
    zatrudnijpracownikow.h \
    nowawiadomosc.h \
    listawiadomosci.h \
    listaprzyjec.h \
    listauzytkownikow.h

FORMS += \
        mainwindow.ui \
    rejestracja.ui \
    niezalogowany.ui \
    logowanie.ui \
    organizator.ui \
    obsluga.ui \
    doradca.ui \
    administrator.ui \
    wiadomosci.ui \
    noweprzyjecie.ui \
    kalendarz.ui \
    detaleprzyjeciaorganizator.ui \
    detaleprzyjeciaadmin.ui \
    detaleprzyjeciapracownicy.ui \
    zmiendaneprzyjecia.ui \
    zatrudnijpracownikow.ui \
    nowawiadomosc.ui \
    listawiadomosci.ui \
    listaprzyjec.ui \
    listauzytkownikow.ui
