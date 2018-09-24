TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    ftokenizer.cpp \
    ../build-FTokenizer-Desktop_Qt_5_11_1_MinGW_32bit-Debug/stokenizer.cpp \
    ../build-FTokenizer-Desktop_Qt_5_11_1_MinGW_32bit-Debug/token.cpp \
    ../build-FTokenizer-Desktop_Qt_5_11_1_MinGW_32bit-Debug/state_machine_functions.cpp

HEADERS += \
    ftokenizer.h
