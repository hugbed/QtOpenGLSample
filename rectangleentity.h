#ifndef RECTANGLEENTITY_H
#define RECTANGLEENTITY_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

#include "vertex.h"

class Entity {
public:
    virtual void draw() = 0;
    virtual ~Entity() {}
};

class RectangleEntity : public Entity, QOpenGLFunctions
{
public:
    static const int NB_VERTICES = 6;

    RectangleEntity();
    ~RectangleEntity() override;

    void init();
    void init(float left, float top, float right, float bottom);
    void setCorners(float left, float top, float right, float bottom);

    void draw() override;
    virtual void addShaders();
    virtual void setDefaultUniforms();

    void addTexture(QOpenGLTexture* texture);
    void clearTextures();

protected:
    QOpenGLShaderProgram* m_program;

private:
    static std::vector<Vertex> fullscreenVertices();
    static std::vector<Vertex> cornersVertices(float left = -1.0f,
                                               float top = 1.0f,
                                               float right = 1.0f,
                                               float bottom = -1.0f);

    void init(const std::vector<Vertex> &vertices);
    void createShader();
    void createBuffer(const std::vector<Vertex> &vertices);
    void createVertexArrayObject();
    void releaseAll();

    // OpenGL State Information
    QOpenGLBuffer m_vertex;
    QOpenGLVertexArrayObject m_object;
    std::vector<QOpenGLTexture*> m_textures;

    std::vector<Vertex> m_vertices;
};

#endif // RECTANGLEENTITY_H
