#-------------------------------------------------
#
# Project created by QtCreator 2015-05-04T18:00:13
#
#-------------------------------------------------

QT       += core\
            network
QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4) {
    QT       += serialport
} else {
    include($$QTSERIALPORT_PROJECT_ROOT/src/serialport/qt4support/serialport.prf)
}

TARGET = stationG
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    serialportreader.cpp

HEADERS += \
    serialportreader.h
