#ifndef STEREOLEFTENTITY_H
#define STEREOLEFTENTITY_H

#include "../rectangleentity.h"
#include "stereoimageentity.h"

class StereoLeftEntity : public StereoImageEntity
{
public:
    StereoLeftEntity();

    void setTextureLeft(QOpenGLTexture *texture) override;
    void setTextureRight(QOpenGLTexture *texture) override;
    void draw() override;
    void setHorizontalShift(float shift) override;

private:
    RectangleEntity m_rectangle;
};

#endif // STEREOLEFTENTITY_H
