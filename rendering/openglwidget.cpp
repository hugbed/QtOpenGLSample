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

    // OpenGL related objects must be cleared
    // with their related current
    for (auto &&texture : m_textures) {
        texture.reset();
    }

    for (auto &&entity : m_stereoEntities) {
        entity.reset();
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
    m_viewportSize.setWidth(w);
    m_viewportSize.setHeight(h);
}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawEntities();
}

void OpenGLWidget::setImageLeft(const QImage &image)
{
    auto &&texture = m_textures[0];
    texture->destroy();
    texture->create();
    texture->setData(image.mirrored(false, true));
    setTextureDefaultProperties(texture.get());
}

void OpenGLWidget::setImageRight(const QImage &image)
{
    auto &&texture = m_textures[1];
    texture->destroy();
    texture->create();
    texture->setData(image.mirrored(false, true));
    setTextureDefaultProperties(texture.get());
}

void OpenGLWidget::setHorizontalShift(float shift)
{
    m_horizontalShift = shift;
    update();
}

void OpenGLWidget::displayModeChanged(OpenGLWidget::DisplayMode mode)
{
    m_currentMode = mode;
    update();
}

void OpenGLWidget::initTextures()
{
    addTexture(":/images/left.jpg");
    addTexture(":/images/right.jpg");
}

void OpenGLWidget::addTexture(const QString &filename)
{
    auto texture = std::make_unique<QOpenGLTexture>((QImage(filename).mirrored()));
    setTextureDefaultProperties(texture.get());
    m_textures.push_back(std::move(texture));
}

void OpenGLWidget::setTextureDefaultProperties(QOpenGLTexture *texture)
{
    texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    texture->setMagnificationFilter(QOpenGLTexture::Linear);
    texture->setWrapMode(QOpenGLTexture::ClampToBorder);
    texture->setBorderColor(Qt::black);
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
    auto &&currentEntity = m_stereoEntities[static_cast<int>(m_currentMode)];
    currentEntity->setAspectRatio(computeImageAspectRatio());
    currentEntity->setHorizontalShift(m_horizontalShift);
    currentEntity->draw();
}

float OpenGLWidget::computeImageAspectRatio()
{
    if (m_textures.empty() || m_textures[0] == nullptr) {
        return 1.0f;
    }

    float vW = m_viewportSize.width(),
            vH = m_viewportSize.height(),
            iW = m_textures[0]->width(),
            iH = m_textures[0]->height();

    return (vW / vH) / (iW / iH);
}

template<class T>
void OpenGLWidget::createEntity(DisplayMode mode)
{
    std::unique_ptr<StereoImageEntity> stereoImageEntity = std::make_unique<T>();
    stereoImageEntity->init();
    stereoImageEntity->setTextureLeft(m_textures[0].get());
    stereoImageEntity->setTextureRight(m_textures[1].get());
    m_stereoEntities[static_cast<int>(mode)] = std::move(stereoImageEntity);
}
