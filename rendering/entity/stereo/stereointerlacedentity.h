#ifndef STEREOINTERLACEDENTITY_H
#define STEREOINTERLACEDENTITY_H

#include "../interlacedrectangleentity.h"
#include "stereoimageentity.h"

class StereoInterlacedEntity : public StereoImageEntity
{
public:
    StereoInterlacedEntity();

    void setTextureLeft(QOpenGLTexture *texture) override;
    void setTextureRight(QOpenGLTexture *texture) override;
    void draw() override;
    void setHorizontalShift(float shift) override;

private:
    InterlacedRectangleEntity m_rectangle;
};

#endif // STEREOINTERLACEDENTITY_H
