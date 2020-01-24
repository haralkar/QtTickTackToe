QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    tst_tickTackToe.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-bcTTT-Desktop_Qt_5_14_0_MinGW_32_bit-Debug/ -lbcTTT
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-bcTTT-Desktop_Qt_5_14_0_MinGW_32_bit-Debug/ -lbcTTT

INCLUDEPATH += $$PWD/../../bcTTT
DEPENDPATH += $$PWD/../../bcTTT
