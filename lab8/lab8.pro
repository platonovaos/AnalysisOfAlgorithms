TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    standartSearch.cpp \
    strFunc.cpp \
    kmpSearch.cpp \
    bmSearch.cpp

HEADERS += \
    standartSearch.h \
    strFunc.h \
    kmpSearch.h \
    bmSearch.h
