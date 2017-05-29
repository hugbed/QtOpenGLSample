#include "stereoleftentity.h"

StereoLeftEntity::StereoLeftEntity()
{
    m_rectangle.init();
}

void StereoLeftEntity::setTextureLeft(QOpenGLTexture *texture)
{
    m_rectangle.setTexture(0, texture);
}

void StereoLeftEntity::setTextureRight(QOpenGLTexture */*texture*/)
{
}

void StereoLeftEntity::draw()
{
    m_rectangle.draw();
}

void StereoLeftEntity::setHorizontalShift(float shift)
{
    m_rectangle.setHorizontalShift(shift);
}
