#include "stereorightentity.h"

StereoRightEntity::StereoRightEntity()
    : StereoRectangleEntity()
{
}

std::unique_ptr<RectangleEntity> StereoRightEntity::createRectangle()
{
    return std::make_unique<RectangleEntity>();
}

void StereoRightEntity::setTextureLeft(QOpenGLTexture */*texture*/)
{
}

void StereoRightEntity::setTextureRight(QOpenGLTexture *texture)
{
    m_rectangle->setTexture(0, texture);
}

