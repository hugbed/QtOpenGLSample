#ifndef RIGHTRECTANGLEENTITY_H
#define RIGHTRECTANGLEENTITY_H

#include "rectangleentity.h"

class RightRectangleEntity : public RectangleEntity
{
public:
    RightRectangleEntity();
    void setTextureLeft(QOpenGLTexture *texture) override;
    void setTextureRight(QOpenGLTexture *texture) override;
};

#endif // RIGHTRECTANGLEENTITY_H
