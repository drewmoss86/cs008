TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    token.cpp \
    stokenizer.cpp \
    state_machine_functions.cpp

HEADERS += \
    token.h \
    stokenizer.h \
    state_machine_functions.h \
    constants.h
