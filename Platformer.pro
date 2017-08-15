TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

LIBS += -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL2_ttf -ldl -lpthread
INCLUDES += /usr/local/include

SOURCES += \
    src/main.cpp \
    test/test1.cpp \
    src/render.cpp \
    src/rectangle.cpp \
    src/window.cpp \
    src/rectanglecollision.cpp \
    src/player.cpp \
    src/gamestatemachine.cpp \
    src/gameengine.cpp \
    src/states/maingamestate.cpp \
    src/gameobjectmanager.cpp \
    src/gameobjects/player.cpp \
    src/imageloader.cpp


SUBDIRS += \
    Platformer.pro \

DISTFILES += \
    bin/Platformer \

HEADERS += \
    include/vectro2.h \
    include/render.h \
    include/rectangle.h \
    include/window.h \
    include/rectanglecollision.h \
    include/player.h \
    include/gamestate.h \
    include/gamestatemachine.h \
    include/gameengine.h \
    include/states/maingamestate.h \
    include/gameobjectmanager.h \
    include/gameobject.h \
    include/gameobjects/player.h \
    include/imageloader.h
