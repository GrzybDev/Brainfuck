TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        src/error.cpp \
        src/help.cpp \
        src/interpreter.cpp \
        src/main.cpp

HEADERS += \
    src/config.h \
    src/error.h \
    src/help.h \
    src/interpreter.h \
    src/main.h
