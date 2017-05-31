#include "openglwidget.h"

#include <QOpenGLShaderProgram>

#include "vertex.h"
#include "entity/stereo/anaglyphrectangleentity.h"
#include "entity/stereo/anaglyphrectangleentity.h"
#include "entity/stereo/opacityrectangleentity.h"
#include "entity/stereo/interlacedrectangleentity.h"
#include "entity/stereo/stereosidebysideentity.h"
#include "entity/stereo/leftrectangleentity.h"
#include "entity/stereo/rightrectangleentity.h"

#include <cassert>

#include <QDebug>

OpenGLWidget::~OpenGLWidget() {
    makeCurrent();

    for (auto *texture : m_textures) {
        delete texture;
    }

    for (auto *entity : m_stereoEntities) {
        delete entity;
    }

    doneCurrent();
}

void OpenGLWidget::initializeGL()
{
    // Initialize OpenGL Backend
    initializeOpenGLFunctions();

    // Set global information
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    initTextures();
    initEntities();
}

void OpenGLWidget::resizeGL(int w, int h)
{
    // remember viewport size for drawing with correct aspect ratio
    viewportSize.setWidth(w);
    viewportSize.setHeight(h);
}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawEntities();
}

void OpenGLWidget::displayModeChanged(OpenGLWidget::DisplayMode mode)
{
    m_currentMode = mode;
    update();
}

void OpenGLWidget::initTextures()
{
    auto *texture = new QOpenGLTexture(QImage(":/images/left.jpg").mirrored());
    texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    texture->setMagnificationFilter(QOpenGLTexture::Linear);
    m_textures.push_back(texture);

    texture = new QOpenGLTexture(QImage(":/images/right.jpg").mirrored());
    texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    texture->setMagnificationFilter(QOpenGLTexture::Linear);
    m_textures.push_back(texture);
}

void OpenGLWidget::initEntities()
{
    createEntity<AnaglyphRectangleEntity>(DisplayMode::Anaglyph);
    createEntity<OpacityRectangleEntity>(DisplayMode::Opacity);
    createEntity<InterlacedRectangleEntity>(DisplayMode::Interlaced);
    createEntity<StereoSideBySideEntity>(DisplayMode::SideBySide);
    createEntity<LeftRectangleEntity>(DisplayMode::Left);
    createEntity<RightRectangleEntity>(DisplayMode::Right);

    m_currentMode = DisplayMode::Anaglyph;
}

void OpenGLWidget::drawEntities()
{
    auto *currentEntity = m_stereoEntities[static_cast<int>(m_currentMode)];
    currentEntity->setAspectRatio(computeImageAspectRatio());
    currentEntity->draw();
}

float OpenGLWidget::computeImageAspectRatio()
{
    if (m_textures.empty() || m_textures[0] == nullptr) {
        return 1.0f;
    }

    QSize imageSize(m_textures[0]->width(), m_textures[0]->height());
    float vW = viewportSize.width(), vH = viewportSize.height(),
          iW = imageSize.width(), iH = imageSize.height();
    return (vW / vH) / (iW / iH);
}

template<class T>
void OpenGLWidget::createEntity(DisplayMode mode)
{
    StereoImageEntity *stereoImageEntity = new T;
    stereoImageEntity->init();
    stereoImageEntity->setTextureLeft(m_textures[0]);
    stereoImageEntity->setTextureRight(m_textures[1]);
    m_stereoEntities[static_cast<int>(mode)] = stereoImageEntity;
}
