QT += core
QT += gui
QT +=sql
QT += printsupport
QT += script
CONFIG += c++11

TARGET = sql_test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    main.h

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#unix:QMAKE_RPATHDIR += $$PWD/libs/limereport/lib_unix
#win32:QMAKE_RPATHDIR += $$PWD/libs/limereport/lib_win
#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/limereport/lib_win -llimereport
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/limereport/lib_win -llimereport
#else:unix: LIBS += -L$$PWD/libs/limereport/lib_unix -llimereport

#INCLUDEPATH += $$PWD/libs/limereport/include
#DEPENDPATH += $$PWD/libs/limereport/include
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -llimereport
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -llimereport
else:unix: LIBS += -L$$PWD/lib/ -llimereport

INCLUDEPATH += $$PWD/lib/include
DEPENDPATH += $$PWD/lib/include




