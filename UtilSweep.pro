#-------------------------------------------------
#
# Project created by QtCreator 2014-07-14T15:13:18
#
#-------------------------------------------------

QT       += core gui webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = UtilSweep
TEMPLATE = app


SOURCES += main.cpp\
        utilsweep.cpp \
    agilentsweeper.cpp \
    qcustomplot.cpp \
    lockin7265.cpp \
    keithley2k.cpp \
    lockin7270.cpp \
    daqlakeshoremag.cpp

HEADERS  += utilsweep.h \
    agilentsweeper.h \
    qcustomplot.h \
    keithley2k.h \
    lockin7265.h \
    lockin7270.h \
    ni488.h \
    NIDAQmx.h \
    daqlakeshoremag.h

FORMS    += utilsweep.ui \
    agilentsweeper.ui

win32: LIBS += -L$$PWD/ -lNIDAQmx
LIBS += $$PWD/libgpib.a

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
