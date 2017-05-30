#include "interlacedrectangleentity.h"

InterlacedRectangleEntity::InterlacedRectangleEntity()
    : RectangleEntity()
{
}

void InterlacedRectangleEntity::addShaders()
{
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/stereo/overlap.vert");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/stereo/interlaced.frag");
}

void InterlacedRectangleEntity::setDefaultUniforms()
{
    m_program->setUniformValue("uTextureLeft", 0);
    m_program->setUniformValue("uTextureRight", 1);
    setHorizontalShift(0.0f);
}

void InterlacedRectangleEntity::setHorizontalShift(float shift) {
    m_program->setUniformValue("uHorizontalShift", shift/2.0f);
}
