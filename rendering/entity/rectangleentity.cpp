#include "rectangleentity.h"

#include <cassert>

namespace {
// Create a texture rectangle
static const Vertex rectangle_vertices_fullscreen[] = {
  Vertex( QVector3D(-1.0f,  1.0f, 1.0f), QVector2D(0.0f, 1.0f) ),
  Vertex( QVector3D( 1.0f,  1.0f, 1.0f), QVector2D(1.0f, 1.0f) ),
  Vertex( QVector3D( 1.0f, -1.0f, 1.0f), QVector2D(1.0f, 0.0f) ),
  Vertex( QVector3D(-1.0f,  1.0f, 1.0f), QVector2D(0.0f, 1.0f) ),
  Vertex( QVector3D( 1.0f, -1.0f, 1.0f), QVector2D(1.0f, 0.0f) ),
  Vertex( QVector3D(-1.0f, -1.0f, 1.0f), QVector2D(0.0f, 0.0f) )
};
}

RectangleEntity::RectangleEntity() {
    initializeOpenGLFunctions();
}

void RectangleEntity::init()
{
    init(fullscreenVertices());
}

void RectangleEntity::init(float left, float top, float right, float bottom)
{
    init(cornersVertices(left, top, right, bottom));
}

void RectangleEntity::init(const std::vector<Vertex> &vertices)
{
    createShader();
    createBuffer(vertices);
    createVertexArrayObject();
    releaseAll();
}

void RectangleEntity::createShader()
{
    m_program = new QOpenGLShaderProgram;
    addShaders();
    m_program->link();
    m_program->bind();
}

void RectangleEntity::createBuffer(const std::vector<Vertex> &vertices)
{
    m_vertex.create();
    m_vertex.bind();
    m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_vertex.allocate(&vertices[0], vertices.size() * sizeof(Vertex));
}

void RectangleEntity::createVertexArrayObject()
{
    m_object.create();
    m_object.bind();
    m_program->enableAttributeArray(0);
    m_program->enableAttributeArray(1);
    m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
    m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::texCoordOffset(), Vertex::TexCoordTupleSize, Vertex::stride());
    setDefaultUniforms();
}

void RectangleEntity::releaseAll()
{
    m_object.release();
    m_vertex.release();
    m_program->release();
}

RectangleEntity::~RectangleEntity()
{
    // todo: replace delete with reset(nullptr)
    m_object.destroy();
    m_vertex.destroy();
    delete m_program;
}

void RectangleEntity::setTexture(int index, QOpenGLTexture *texture)
{
    auto it = m_textures.find(index);

    // replace if already in map
    if(it != m_textures.end()) {
       it->second = texture;
    } else { // add it to the map
       m_textures.insert(std::pair<int, QOpenGLTexture*>(index, texture));
    }
}

void RectangleEntity::setHorizontalShift(float shift)
{
    m_program->setUniformValue("uHorizontalShift", shift);
}

void RectangleEntity::setCorners(float left, float top, float right, float bottom)
{
    m_vertex.bind();
    {
        m_object.bind();
        {
            auto vertices = cornersVertices(left, top, right, bottom);
            m_vertex.write(0, &vertices[0], vertices.size() * sizeof(Vertex));
        }
        m_object.release();
    }
    m_vertex.release();
}

void RectangleEntity::draw()
{
    // Render using our shader
    m_program->bind();
    {
      for (auto textureIt = std::begin(m_textures); textureIt != std::end(m_textures); ++textureIt) {
        glActiveTexture(GL_TEXTURE0 + (*textureIt).first);
        (*textureIt).second->bind();
      }
      m_object.bind();
      {
          glDrawArrays(GL_TRIANGLES, 0, NB_VERTICES);
      }
      m_object.release();
    }
    m_program->release();
}

void RectangleEntity::addShaders()
{
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/textureshift.vert");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/texture.frag");
}

void RectangleEntity::setDefaultUniforms()
{
    m_program->setUniformValue("uTexture", 0);
    m_program->setUniformValue("uHorizontalShift", 0.0f);
}

// static
std::vector<Vertex> RectangleEntity::fullscreenVertices()
{
    constexpr float left = -1.0f;
    constexpr float top = 1.0f;
    constexpr float right = 1.0f;
    constexpr float bottom = -1.0f;
    return cornersVertices(left, top, right, bottom);
}

// static
std::vector<Vertex> RectangleEntity::cornersVertices(float left, float top, float right, float bottom)
{
    std::vector<Vertex> vertices;
    vertices.emplace_back(QVector3D(left,  top,    1.0f), QVector2D(0.0f, 1.0f));
    vertices.emplace_back(QVector3D(right, top,    1.0f), QVector2D(1.0f, 1.0f));
    vertices.emplace_back(QVector3D(right, bottom, 1.0f), QVector2D(1.0f, 0.0f));
    vertices.emplace_back(QVector3D(left,  top,    1.0f), QVector2D(0.0f, 1.0f));
    vertices.emplace_back(QVector3D(right, bottom, 1.0f), QVector2D(1.0f, 0.0f));
    vertices.emplace_back(QVector3D(left,  bottom, 1.0f), QVector2D(0.0f, 0.0f));
    return vertices;
}
