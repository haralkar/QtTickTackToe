QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_playttt.cpp

unix|win32: LIBS += -L$$OUT_PWD/../Play/ -lPlay

INCLUDEPATH += $$PWD/../Play
DEPENDPATH += $$PWD/../Play
