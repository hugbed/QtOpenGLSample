#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>

#include <vector>
#include <memory>

class QOpenGLShaderProgram;

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    ~OpenGLWidget();
    explicit OpenGLWidget(QWidget* parent) : QOpenGLWidget(parent) {}

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    void initTextures();

    void initTextureRectangle();
    void initStereoTextureRectangle();

    void drawTextureRectangle();
    void drawStereoTextureRectangle();

    void printVersionInformation();

    // OpenGL State Information
    QOpenGLBuffer m_vertex;
    QOpenGLVertexArrayObject m_object;
    std::vector<QOpenGLTexture*> m_textures;
    QOpenGLShaderProgram* m_program;
};

#endif // GLWIDGET_H
