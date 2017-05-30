#include "openglwidget.h"

#include <QOpenGLShaderProgram>

#include "vertex.h"
#include "entity/anaglyphrectangleentity.h"

#include "entity/stereo/stereoanaglyphentity.h"
#include "entity/stereo/stereosidebysideentity.h"
#include "entity/stereo/stereoleftentity.h"
#include "entity/stereo/stereorightentity.h"

#include <cassert>

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
    // adjust image ratio somehow
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
    case DisplayMode::SideBySide:
        m_currentEntity = m_stereoEntities[static_cast<int>(DisplayMode::SideBySide)];
        break;
    case DisplayMode::Left:
        m_currentEntity = m_stereoEntities[static_cast<int>(DisplayMode::Left)];
        break;
    case DisplayMode::Right:
        m_currentEntity = m_stereoEntities[static_cast<int>(DisplayMode::Right)];
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
    StereoImageEntity *stereoImageEntity = new StereoAnaglyphEntity;
    stereoImageEntity->setTextureLeft(m_textures[0]);
    stereoImageEntity->setTextureRight(m_textures[1]);
    m_stereoEntities[static_cast<int>(DisplayMode::Anaglyph)] = stereoImageEntity;

    stereoImageEntity = new StereoSideBySideEntity;
    stereoImageEntity->setTextureLeft(m_textures[0]);
    stereoImageEntity->setTextureRight(m_textures[1]);
    m_stereoEntities[static_cast<int>(DisplayMode::SideBySide)] = stereoImageEntity;

    stereoImageEntity = new StereoLeftEntity;
    stereoImageEntity->setTextureLeft(m_textures[0]);
    m_stereoEntities[static_cast<int>(DisplayMode::Left)] = stereoImageEntity;

    stereoImageEntity = new StereoRightEntity;
    stereoImageEntity->setTextureRight(m_textures[1]);
    m_stereoEntities[static_cast<int>(DisplayMode::Right)] = stereoImageEntity;

    m_currentEntity = m_stereoEntities[0];
}

void OpenGLWidget::drawEntities()
{
    m_currentEntity->draw();
}