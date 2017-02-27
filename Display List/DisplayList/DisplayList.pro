TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11


LIBS += -L"..\..\SFML-2.2\lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics  -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics  -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "..\..\SFML-2.2\include"
DEPENDPATH += "..\..\SFML-2.2\include"


SOURCES += main.cpp

HEADERS += \
    linkedlistfunctions.h \
    constants.h \
    displaylist.h \
    doublearrow.h
