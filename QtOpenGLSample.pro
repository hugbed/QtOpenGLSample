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
CONFIG += c++14

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    rendering/openglwindow.cpp \
    rendering/openglwidget.cpp \
    rendering/entity/stereo/rectangleentity.cpp \
    rendering/entity/stereo/anaglyphrectangleentity.cpp \
    rendering/entity/stereo/stereosidebysideentity.cpp \
    rendering/entity/stereo/opacityrectangleentity.cpp \
    rendering/entity/stereo/interlacedrectangleentity.cpp \
    rendering/entity/stereo/leftrectangleentity.cpp \
    rendering/entity/stereo/rightrectangleentity.cpp \
    widgets/parameterslistview.cpp \
    widgets/parameterwidget.cpp \
    widgets/hitwidget.cpp \
    widgets/lineeditnocursor.cpp \
    widgets/convergenceindicatorwidget.cpp \
    widgets/depthwidget.cpp \
    widgets/depthvolumeindicator.cpp

HEADERS += \
    rendering/vertex.h \
    mainwindow.h \
    rendering/openglwindow.h \
    rendering/openglwidget.h \
    rendering/vertex.h \
    rendering/entity/entity.h \
    rendering/entity/stereo/rectangleentity.h \
    rendering/entity/stereo/anaglyphrectangleentity.h \
    rendering/entity/stereo/stereoimageentity.h \
    rendering/entity/stereo/stereosidebysideentity.h \
    rendering/entity/stereo/opacityrectangleentity.h \
    rendering/entity/stereo/interlacedrectangleentity.h \
    rendering/entity/stereo/leftrectangleentity.h \
    rendering/entity/stereo/rightrectangleentity.h \
    widgets/parameterslistview.h \
    widgets/parameterwidget.h \
    widgets/hitwidget.h \
    widgets/lineeditnocursor.h \
    widgets/convergenceindicatorwidget.h \
    widgets/depthwidget.h \
    widgets/depthvolumeindicator.h

RESOURCES += \
    resources.qrc \
    style/style.qrc

FORMS += \
    mainwindow.ui

