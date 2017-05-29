#-------------------------------------------------
#
# Project created by QtCreator 2015-01-11T15:14:10
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtOpenGLSample
TEMPLATE = app
CONFIG += console
CONFIG += cpp14

SOURCES += \
    main.cpp \
    window.cpp \
    mainwindow.cpp \
    openglwidget.cpp \
    rectangleentity.cpp \
    anaglyphrectangleentity.cpp

HEADERS += \
    window.h \
    vertex.h \
    mainwindow.h \
    openglwidget.h \
    vertex.h \
    rectangleentity.h \
    anaglyphrectangleentity.h

RESOURCES += \
    resources.qrc

FORMS += \
        mainwindow.ui

DISTFILES += \
    shaders/anaglyph.frag \
    shaders/stereo.vert \
    shaders/stereo/sidebyside.vert
