#include "stereoleftentity.h"

StereoLeftEntity::StereoLeftEntity()
    : StereoRectangleEntity()
{
}

std::unique_ptr<RectangleEntity> StereoLeftEntity::createRectangle()
{
    return std::make_unique<RectangleEntity>();
}

void StereoLeftEntity::setTextureRight(QOpenGLTexture */*texture*/)
{
}
