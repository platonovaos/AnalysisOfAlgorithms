TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_LFLAGS += -pthread

SOURCES += \
        main.cpp \
    func.cpp

HEADERS += \
    func.h
