#include "openglwidget.h"

#include <QOpenGLShaderProgram>

#include "vertex.h"

#include <cassert>

// Create a colored triangle
static const Vertex triangle_vertices[] = {
  Vertex( QVector3D( 0.00f,  0.75f, 1.0f), QVector3D(1.0f, 0.0f, 0.0f), QVector2D(0.5f,  1.0f) ),
  Vertex( QVector3D(-0.75f, -0.75f, 1.0f), QVector3D(0.0f, 1.0f, 0.0f), QVector2D(0.0f,  0.0f) ),
  Vertex( QVector3D( 0.75f, -0.75f, 1.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(1.0f, 0.0f) )
};

// Create a texture rectangle
static const Vertex rectangle_vertices[] = {
  Vertex( QVector3D(-1.0f,  1.0f, 1.0f), QVector2D(0.0f, 1.0f) ),
  Vertex( QVector3D( 1.0f,  1.0f, 1.0f), QVector2D(1.0f, 1.0f) ),
  Vertex( QVector3D( 1.0f, -1.0f, 1.0f), QVector2D(1.0f, 0.0f) ),
  Vertex( QVector3D(-1.0f,  1.0f, 1.0f), QVector2D(0.0f, 1.0f) ),
  Vertex( QVector3D( 1.0f, -1.0f, 1.0f), QVector2D(1.0f, 0.0f) ),
  Vertex( QVector3D(-1.0f, -1.0f, 1.0f), QVector2D(0.0f, 0.0f) )
};

OpenGLWidget::~OpenGLWidget() {
    makeCurrent();
    m_object.destroy();
    m_vertex.destroy();
    delete m_program;
    doneCurrent();
}

void OpenGLWidget::initializeGL()
{
    // Initialize OpenGL Backend
    initializeOpenGLFunctions();
    printVersionInformation();

    // Set global information
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    initTexture();
    initTexturedRectangle();
}

void OpenGLWidget::resizeGL(int w, int h)
{

}

void OpenGLWidget::paintGL()
{
    // Clear
    glClear(GL_COLOR_BUFFER_BIT);

    drawTexturedRectangle();
}

void OpenGLWidget::initTexture()
{
    // Create Texture
    m_texture = new QOpenGLTexture(QImage(":/images/photo.jpg").mirrored());
    m_texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    m_texture->setMagnificationFilter(QOpenGLTexture::Linear);
//    m_texture->setWrapMode(QOpenGLTexture::ClampToEdge);
}

void OpenGLWidget::initColorTriangle()
{
    // Create Shader (Do not release until VAO is created)
    m_program = new QOpenGLShaderProgram();
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/simple.vert");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/simple.frag");
    m_program->link();
    m_program->bind();

    // Create Buffer (Do not release until VAO is created)
    m_vertex.create();
    m_vertex.bind();
    m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_vertex.allocate(triangle_vertices, sizeof(triangle_vertices));

    // Create Vertex Array Object
    m_object.create();
    m_object.bind();
    m_program->enableAttributeArray(0);
    m_program->enableAttributeArray(1);
    m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
    m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

    // Release (unbind) all
    m_object.release();
    m_vertex.release();
    m_program->release();
}

void OpenGLWidget::initTexturedTriangle()
{
    // Create Shader (Do not release until VAO is created)
    m_program = new QOpenGLShaderProgram();
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/texture.vert");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/texture.frag");
    m_program->link();
    m_program->bind();

    // Create Buffer (Do not release until VAO is created)
    m_vertex.create();
    m_vertex.bind();
    m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_vertex.allocate(triangle_vertices, sizeof(triangle_vertices));

    // Create Vertex Array Object
    m_object.create();
    m_object.bind();
    m_program->enableAttributeArray(0);
    m_program->enableAttributeArray(1);
    m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
    m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::texCoordOffset(), Vertex::TexCoordTupleSize, Vertex::stride());
    m_program->setUniformValue("uTexture", 0);

    // Release (unbind) all
    m_object.release();
    m_vertex.release();
    m_program->release();
}

void OpenGLWidget::initTexturedRectangle()
{
    // Create Shader (Do not release until VAO is created)
    m_program = new QOpenGLShaderProgram();
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/texture.vert");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/texture.frag");
    m_program->link();
    m_program->bind();

    // Create Buffer (Do not release until VAO is created)
    m_vertex.create();
    m_vertex.bind();
    m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_vertex.allocate(rectangle_vertices, sizeof(rectangle_vertices));

    // Create Vertex Array Object
    m_object.create();
    m_object.bind();
    m_program->enableAttributeArray(0);
    m_program->enableAttributeArray(1);
    m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
    m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::texCoordOffset(), Vertex::TexCoordTupleSize, Vertex::stride());
    m_program->setUniformValue("uTexture", 0);

    // Release (unbind) all
    m_object.release();
    m_vertex.release();
    m_program->release();
}

void OpenGLWidget::drawColorTriangle()
{
    // Render using our shader
    m_program->bind();
    {
      m_object.bind();
      glDrawArrays(GL_TRIANGLES, 0, sizeof(triangle_vertices) / sizeof(triangle_vertices[0]));
      m_object.release();
    }
    m_program->release();
}

void OpenGLWidget::drawTexturedTriangle()
{
    // Render using our shader
    assert(m_program->bind());
    {
      m_texture->bind();
      m_object.bind();
      glDrawArrays(GL_TRIANGLES, 0, sizeof(triangle_vertices) / sizeof(triangle_vertices[0]));
      m_object.release();
    }
    m_program->release();
}

void OpenGLWidget::drawTexturedRectangle()
{
    // Render using our shader
    assert(m_program->bind());
    {
      m_texture->bind();
      m_object.bind();
      glDrawArrays(GL_TRIANGLES, 0, sizeof(rectangle_vertices) / sizeof(rectangle_vertices[0]));
      m_object.release();
    }
    m_program->release();
}

void OpenGLWidget::printVersionInformation()
{
  QString glType;
  QString glVersion;
  QString glProfile;

  // Get Version Information
  glType = (context()->isOpenGLES()) ? "OpenGL ES" : "OpenGL";
  glVersion = reinterpret_cast<const char*>(glGetString(GL_VERSION));

  // Get Profile Information
#define CASE(c) case QSurfaceFormat::c: glProfile = #c; break
  switch (format().profile())
  {
    CASE(NoProfile);
    CASE(CoreProfile);
    CASE(CompatibilityProfile);
  }
#undef CASE

  // qPrintable() will print our QString w/o quotes around it.
  qDebug() << qPrintable(glType) << qPrintable(glVersion) << "(" << qPrintable(glProfile) << ")";
}

