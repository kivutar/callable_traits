TEMPLATE = app
CONFIG += console -std=c++14
#CONFIG += console -std=c++1y
CONFIG -= qt app_bundle

QMAKE_CXXFLAGS += -std=c++14 -Wall -Wextra -pedantic
#QMAKE_CXXFLAGS += -std=c++1y -Wall -Wextra -pedantic

INCLUDEPATH += ../../include
INCLUDEPATH += C:/local/boost_1_59_0

SOURCES += ./main.cpp
