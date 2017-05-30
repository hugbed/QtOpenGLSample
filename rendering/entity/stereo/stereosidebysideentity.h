#ifndef STEREOSIDEBYSIDEENTITY_H
#define STEREOSIDEBYSIDEENTITY_H

#include "../rectangleentity.h"
#include "stereoimageentity.h"

class StereoSideBySideEntity : public StereoImageEntity
{
public:
    StereoSideBySideEntity();

    void init() override;
    void setTextureLeft(QOpenGLTexture *texture) override;
    void setTextureRight(QOpenGLTexture *texture) override;
    void draw() override;
    void setHorizontalShift(float shift) override;

private:
    RectangleEntity m_rectangles[2];
};

#endif // STEREOSIDEBYSIDEENTITY_H
