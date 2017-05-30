#include "opacityrectangleentity.h"

OpacityRectangleEntity::OpacityRectangleEntity()
    : RectangleEntity()
{
}

void OpacityRectangleEntity::addShaders()
{
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/stereo/overlap.vert");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/stereo/opacity.frag");
}

void OpacityRectangleEntity::setDefaultUniforms()
{
    m_program->setUniformValue("uTextureLeft", 0);
    m_program->setUniformValue("uTextureRight", 1);
    setHorizontalShift(0.0f);
}

void OpacityRectangleEntity::setHorizontalShift(float shift) {
    m_program->setUniformValue("uHorizontalShift", shift/2.0f);
}
