#ifndef STEREORECTANGLEENTITY_H
#define STEREORECTANGLEENTITY_H

#include "stereoimageentity.h"
#include "../rectangleentity.h"

#include <memory>

// Allows StereoImageEntity with different RectangleEntity (different shaders)
class StereoRectangleEntity : public StereoImageEntity
{
public:
    StereoRectangleEntity();

    virtual std::unique_ptr<RectangleEntity> createRectangle() = 0;

    void init() override;
    void setTextureLeft(QOpenGLTexture *texture) override;
    void setTextureRight(QOpenGLTexture *texture) override;
    void draw() override;
    void setHorizontalShift(float shift) override;

protected:
    std::unique_ptr<RectangleEntity> m_rectangle;
};

#endif // STEREORECTANGLEENTITY_H
