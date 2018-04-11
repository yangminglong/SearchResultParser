#-------------------------------------------------
#
# Project created by QtCreator 2018-04-11T03:06:51
#
#-------------------------------------------------

QT       += core gui xml network

TARGET = ParserBaiduPhone
TEMPLATE = lib
CONFIG += plugin

DESTDIR = $$[QT_INSTALL_PLUGINS]/generic

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
        ParserBaiduPhone.cpp \
    ../../ProjectGlobal/httpmanager.cpp

HEADERS += \
        ParserBaiduPhone.h \
    isearchresultparser.h \
    ../../ProjectGlobal/httpmanager.h

DISTFILES += ParserBaiduPhone.json 

unix {
    target.path = /usr/lib
    INSTALLS += target
}