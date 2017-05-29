#ifndef STEREOANAGLYPHENTITY_H
#define STEREOANAGLYPHENTITY_H

#include "../anaglyphrectangleentity.h"
#include "stereoimageentity.h"

class StereoAnaglyphEntity : public StereoImageEntity
{
public:
    StereoAnaglyphEntity();

    void setTextureLeft(QOpenGLTexture *texture) override;
    void setTextureRight(QOpenGLTexture *texture) override;
    void draw() override;
    void setHorizontalShift(float shift) override;

private:
    AnaglyphRectangleEntity m_rectangle;
};

#endif // STEREOANAGLYPHENTITY_H
