#ifndef STEREOOPACITYENTITY_H
#define STEREOOPACITYENTITY_H

#include "../opacityrectangleentity.h"
#include "stereoimageentity.h"

// todo: could work with generic RectangleEntity and another class for 2 rectangles

class StereoOpacityEntity : public StereoImageEntity
{
public:
    StereoOpacityEntity();

    void setTextureLeft(QOpenGLTexture *texture) override;
    void setTextureRight(QOpenGLTexture *texture) override;
    void draw() override;
    void setHorizontalShift(float shift) override;

private:
    OpacityRectangleEntity m_rectangle;
};

#endif // STEREOOPACITYENTITY_H
