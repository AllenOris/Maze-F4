#-------------------------------------------------
#
# Project created by QtCreator 2018-07-16T19:49:37
#
#-------------------------------------------------

QT       += core gui
QT+=multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MazeF4
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    f4mazemap.cpp \
    f4point.cpp \
    f4edge.cpp \
    f4mazescene.cpp \
    f4mazemapplus.cpp \
    f4rect.cpp \
    f4player.cpp \
    f4mazedemo.cpp \
    f4setitem.cpp \
    f4setscene.cpp \
    music.cpp \
    myitem.cpp \
    myloading.cpp \
    myscene.cpp \
    myview.cpp

HEADERS += \
    f4mazemap.h \
    f4point.h \
    f4edge.h \
    f4mazescene.h \
    f4mazemapplus.h \
    f4rect.h \
    f4player.h \
    f4mazedemo.h \
    f4setitem.h \
    f4setscene.h \
    music.h \
    myitem.h \
    myloading.h \
    myscene.h \
    myview.h \
    f4overall.h

FORMS +=

RESOURCES += \
    res.qrc \
    f4resource.qrc
RC_ICONS=myico.ico
