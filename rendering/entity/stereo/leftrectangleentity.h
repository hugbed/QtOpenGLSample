#ifndef LEFTRECTANGLEENTITY_H
#define LEFTRECTANGLEENTITY_H

#include "rectangleentity.h"

class LeftRectangleEntity : public RectangleEntity
{
public:
    LeftRectangleEntity();
    void setTextureRight(QOpenGLTexture */*texture*/) override;
    void setHorizontalShift(float shift) override;
};

#endif // LEFTRECTANGLEENTITY_H
