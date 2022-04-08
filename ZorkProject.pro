QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNING
CONFIG += c++11
SOURCES += \
    main.cpp \
    Character.cpp \
    Command.cpp \
    CommandWords.cpp \
    item.cpp \
    MainWindow.cpp \
    Room.cpp \
    ZorkUL.cpp \

HEADERS += \
    Character.h \
    Command.h \
    CommandWords.h \
    item.h \
    MainWindow.h \
    Room.h \
    ZorkUL.h

FORMS += \
    MainWindow.ui
