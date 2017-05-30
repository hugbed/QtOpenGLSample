#include "stereorectangleentity.h"

StereoRectangleEntity::StereoRectangleEntity()
{
}

void StereoRectangleEntity::init()
{
    m_rectangle = createRectangle();
    m_rectangle->init();
}

void StereoRectangleEntity::setTextureLeft(QOpenGLTexture *texture)
{
    m_rectangle->setTexture(0, texture);
}

void StereoRectangleEntity::setTextureRight(QOpenGLTexture *texture)
{
    m_rectangle->setTexture(1, texture);
}

void StereoRectangleEntity::draw()
{
    m_rectangle->draw();
}

void StereoRectangleEntity::setHorizontalShift(float shift)
{
    m_rectangle->setHorizontalShift(shift);
}
