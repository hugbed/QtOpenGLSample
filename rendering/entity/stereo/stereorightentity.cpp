#include "stereorightentity.h"

StereoRightEntity::StereoRightEntity()
{
    m_rectangle.init();
}

void StereoRightEntity::setTextureLeft(QOpenGLTexture */*texture*/)
{
}

void StereoRightEntity::setTextureRight(QOpenGLTexture *texture)
{
    m_rectangle.setTexture(0, texture);
}

void StereoRightEntity::draw()
{
    m_rectangle.draw();
}

void StereoRightEntity::setHorizontalShift(float shift)
{
    m_rectangle.setHorizontalShift(shift);
}
