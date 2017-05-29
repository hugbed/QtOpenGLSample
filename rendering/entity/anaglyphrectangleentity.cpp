#include "anaglyphrectangleentity.h"

AnaglyphRectangleEntity::AnaglyphRectangleEntity()
    : RectangleEntity()
{
}

void AnaglyphRectangleEntity::addShaders()
{
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/stereo/overlap.vert");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/stereo/anaglyph.frag");
}

void AnaglyphRectangleEntity::setDefaultUniforms()
{
    m_program->setUniformValue("uTextureLeft", 0);
    m_program->setUniformValue("uTextureRight", 1);
    setHorizontalShift(0.02f);
}

void AnaglyphRectangleEntity::setHorizontalShift(float shift) {
    m_program->setUniformValue("uHorizontalShift", shift/2.0f);
}
