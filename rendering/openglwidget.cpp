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

    for (auto & texture : m_textures) {
        delete texture;
    }

    for (auto &entity : m_stereoEntities) {
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
    switch (mode) {
    case DisplayMode::Anaglyph:
        m_currentEntity = m_stereoEntities[static_cast<int>(DisplayMode::Anaglyph)];
        break;
    case DisplayMode::Opacity:
        m_currentEntity = m_stereoEntities[static_cast<int>(DisplayMode::Opacity)];
        break;
    case DisplayMode::Interlaced:
        m_currentEntity = m_stereoEntities[static_cast<int>(DisplayMode::Interlaced)];
        break;
    case DisplayMode::SideBySide:
        m_currentEntity = m_stereoEntities[static_cast<int>(DisplayMode::SideBySide)];
        break;
    case DisplayMode::Left:
        m_currentEntity = m_stereoEntities[static_cast<int>(DisplayMode::Left)];
        break;
    case DisplayMode::Right:
        m_currentEntity = m_stereoEntities[static_cast<int>(DisplayMode::Right)];
        break;
    default:
        break;
    }
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
    StereoImageEntity *stereoImageEntity = new AnaglyphRectangleEntity;
    stereoImageEntity->init();
    stereoImageEntity->setTextureLeft(m_textures[0]);
    stereoImageEntity->setTextureRight(m_textures[1]);
    m_stereoEntities[static_cast<int>(DisplayMode::Anaglyph)] = stereoImageEntity;

    stereoImageEntity = new OpacityRectangleEntity;
    stereoImageEntity->init();
    stereoImageEntity->setTextureLeft(m_textures[0]);
    stereoImageEntity->setTextureRight(m_textures[1]);
    m_stereoEntities[static_cast<int>(DisplayMode::Opacity)] = stereoImageEntity;

    stereoImageEntity = new InterlacedRectangleEntity;
    stereoImageEntity->init();
    stereoImageEntity->setTextureLeft(m_textures[0]);
    stereoImageEntity->setTextureRight(m_textures[1]);
    m_stereoEntities[static_cast<int>(DisplayMode::Interlaced)] = stereoImageEntity;

    stereoImageEntity = new StereoSideBySideEntity;
    stereoImageEntity->init();
    stereoImageEntity->setTextureLeft(m_textures[0]);
    stereoImageEntity->setTextureRight(m_textures[1]);
    m_stereoEntities[static_cast<int>(DisplayMode::SideBySide)] = stereoImageEntity;

    stereoImageEntity = new LeftRectangleEntity;
    stereoImageEntity->init();
    stereoImageEntity->setTextureLeft(m_textures[0]);
    m_stereoEntities[static_cast<int>(DisplayMode::Left)] = stereoImageEntity;

    stereoImageEntity = new RightRectangleEntity;
    stereoImageEntity->init();
    stereoImageEntity->setTextureRight(m_textures[1]);
    m_stereoEntities[static_cast<int>(DisplayMode::Right)] = stereoImageEntity;

    m_currentEntity = m_stereoEntities[0];
}

void OpenGLWidget::drawEntities()
{
    m_currentEntity->setAspectRatio(computeImageAspectRatio());
    m_currentEntity->draw();
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
