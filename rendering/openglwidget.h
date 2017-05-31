#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>

#include "entity/stereo/rectangleentity.h"
#include "entity/stereo/stereoimageentity.h"

#include <vector>
#include <memory>

class QOpenGLShaderProgram;

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    enum class DisplayMode {
        Anaglyph = 0,
        Opacity = 1,
        Interlaced = 2,
        SideBySide = 3,
        Left = 4,
        Right = 5,
        NB_DISPLAY_MODES = 6
    };

    ~OpenGLWidget();
    explicit OpenGLWidget(QWidget* parent) : QOpenGLWidget(parent) {}

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void setHorizontalShift(float shift);

public slots:
    void displayModeChanged(DisplayMode mode);

private:
    void initTextures();
    void addTexture(const QString &filename);
    void initEntities();
    void drawEntities();
    float computeImageAspectRatio();

    template <class T>
    void createEntity(DisplayMode mode);

    QSize m_viewportSize;
    float m_horizontalShift;

    std::vector<std::unique_ptr<QOpenGLTexture>> m_textures;
    DisplayMode m_currentMode;
    std::unique_ptr<StereoImageEntity> m_stereoEntities[static_cast<int>(DisplayMode::NB_DISPLAY_MODES)];
};

#endif // GLWIDGET_H
