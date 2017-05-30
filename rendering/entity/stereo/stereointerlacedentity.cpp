#include "stereointerlacedentity.h"

StereoInterlacedEntity::StereoInterlacedEntity()
{
    m_rectangle.init();
}

void StereoInterlacedEntity::setTextureLeft(QOpenGLTexture *texture)
{
    m_rectangle.setTexture(0, texture);
}

void StereoInterlacedEntity::setTextureRight(QOpenGLTexture *texture)
{
    m_rectangle.setTexture(1, texture);
}

void StereoInterlacedEntity::draw()
{
    m_rectangle.draw();
}

void StereoInterlacedEntity::setHorizontalShift(float shift)
{
    m_rectangle.setHorizontalShift(shift);
}
