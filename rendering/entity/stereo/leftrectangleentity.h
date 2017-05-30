#ifndef LEFTRECTANGLEENTITY_H
#define LEFTRECTANGLEENTITY_H

#include "rectangleentity.h"

class LeftRectangleEntity : public RectangleEntity
{
public:
    LeftRectangleEntity();
    void setTextureRight(QOpenGLTexture *texture) override;
};

#endif // LEFTRECTANGLEENTITY_H
