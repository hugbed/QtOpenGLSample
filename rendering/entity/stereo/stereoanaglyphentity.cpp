#include "stereoanaglyphentity.h"

StereoAnaglyphEntity::StereoAnaglyphEntity()
{
    m_rectangle.init();
}

void StereoAnaglyphEntity::setTextureLeft(QOpenGLTexture *texture)
{
    m_rectangle.setTexture(0, texture);
}

void StereoAnaglyphEntity::setTextureRight(QOpenGLTexture *texture)
{
    m_rectangle.setTexture(1, texture);
}

void StereoAnaglyphEntity::draw()
{
    m_rectangle.draw();
}

void StereoAnaglyphEntity::setHorizontalShift(float shift)
{
    m_rectangle.setHorizontalShift(shift);
}
