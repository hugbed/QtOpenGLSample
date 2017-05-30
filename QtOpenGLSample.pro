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
    mainwindow.cpp \
    rendering/openglwidget.cpp \
    rendering/entity/rectangleentity.cpp \
    rendering/entity/anaglyphrectangleentity.cpp \
    rendering/entity/stereo/stereosidebysideentity.cpp \
    rendering/entity/stereo/stereoanaglyphentity.cpp \
    rendering/openglwindow.cpp \
    rendering/entity/stereo/stereoleftentity.cpp \
    rendering/entity/stereo/stereorightentity.cpp \
    widgets/parameterslistview.cpp \
    widgets/parameterwidget.cpp

HEADERS += \
    rendering/vertex.h \
    mainwindow.h \
    rendering/openglwidget.h \
    rendering/vertex.h \
    rendering/entity/rectangleentity.h \
    rendering/entity/anaglyphrectangleentity.h \
    rendering/entity/stereo/stereoimageentity.h \
    rendering/entity/entity.h \
    rendering/entity/stereo/stereosidebysideentity.h \
    rendering/entity/stereo/stereoanaglyphentity.h \
    rendering/openglwindow.h \
    rendering/entity/stereo/stereoleftentity.h \
    rendering/entity/stereo/stereorightentity.h \
    widgets/parameterslistview.h \
    widgets/parameterwidget.h

RESOURCES += \
    resources.qrc \
    style/style.qrc

FORMS += \
    mainwindow.ui

DISTFILES += \
    shaders/stereo/textureshift.vert \
    shaders/textureshift.vert
