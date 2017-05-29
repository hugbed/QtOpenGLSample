#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>

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
    void initTexture();
    void initColorTriangle();
    void initTexturedTriangle();
    void initTexturedRectangle();
    void drawColorTriangle();
    void drawTexturedTriangle();
    void drawTexturedRectangle();

    void printVersionInformation();

    // OpenGL State Information
    QOpenGLBuffer m_vertex;
    QOpenGLVertexArrayObject m_object;
    QOpenGLTexture *m_texture;
    QOpenGLShaderProgram *m_program;
};

#endif // GLWIDGET_H
