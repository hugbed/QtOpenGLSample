#include "stereoopacityentity.h"

StereoOpacityEntity::StereoOpacityEntity()
{
    m_rectangle.init();
}

void StereoOpacityEntity::setTextureLeft(QOpenGLTexture *texture)
{
    m_rectangle.setTexture(0, texture);
}

void StereoOpacityEntity::setTextureRight(QOpenGLTexture *texture)
{
    m_rectangle.setTexture(1, texture);
}

void StereoOpacityEntity::draw()
{
    m_rectangle.draw();
}

void StereoOpacityEntity::setHorizontalShift(float shift)
{
    m_rectangle.setHorizontalShift(shift);
}
