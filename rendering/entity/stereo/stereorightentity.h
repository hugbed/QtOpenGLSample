#ifndef STEREORIGHTENTITY_H
#define STEREORIGHTENTITY_H

#include "../rectangleentity.h"
#include "stereoimageentity.h"

class StereoRightEntity : public StereoImageEntity
{
public:
    StereoRightEntity();

    void setTextureLeft(QOpenGLTexture *texture) override;
    void setTextureRight(QOpenGLTexture *texture) override;
    void draw() override;
    void setHorizontalShift(float shift) override;

private:
    RectangleEntity m_rectangle;
};

#endif // STEREORIGHTENTITY_H
