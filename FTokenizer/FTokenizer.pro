TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    ftokenizer.cpp \
    ../STokenizer/stokenizer.cpp \
    ../includes/token.cpp \
    ../STokenizer/state_machine_functions.cpp

HEADERS += \
    ftokenizer.h \
    ../includes/stokenizer.h
