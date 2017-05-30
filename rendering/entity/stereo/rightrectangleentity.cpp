#include "rightrectangleentity.h"

RightRectangleEntity::RightRectangleEntity()
    : RectangleEntity()
{

}

void RightRectangleEntity::setTextureLeft(QOpenGLTexture *texture)
{
}

void RightRectangleEntity::setTextureRight(QOpenGLTexture *texture)
{
    setTexture(0, texture);
}
