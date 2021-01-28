TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    levMatr.cpp \
    levRec.cpp \
    levRecMatr.cpp \
    demLevMatr.cpp \
    matrix.cpp \
    timeMeasure.cpp

HEADERS += \
    levMatr.h \
    levRec.h \
    levRecMatr.h \
    demLevMatr.h \
    matrix.h \
    timeMeasure.h
