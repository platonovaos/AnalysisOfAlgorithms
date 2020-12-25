TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_LFLAGS += -pthread

SOURCES += \
        main.cpp \
    vinogradMul.cpp \
    timeMeasurments.cpp \
    matr.cpp \
    formMatr.cpp \
    parallelCycle.cpp \
    parallelVectors.cpp

HEADERS += \
    vinogradMul.h \
    timeMeasurments.h \
    matr.h \
    formMatr.h \
    parallelCycle.h \
    parallelVectors.h
