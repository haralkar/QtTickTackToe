TEMPLATE = subdirs

SUBDIRS += \
    Display \
    Play \
    TestPlay

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/Play/ -lPlay
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/Play/ -lPlayd
else:unix: LIBS += -L$$OUT_PWD/Play/ -lPlay

INCLUDEPATH += $$PWD/Play
DEPENDPATH += $$PWD/Play
