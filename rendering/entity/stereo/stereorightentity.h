#ifndef STEREORIGHTENTITY_H
#define STEREORIGHTENTITY_H

#include "stereorectangleentity.h"

#include "../rectangleentity.h"

class StereoRightEntity : public StereoRectangleEntity
{
public:
    StereoRightEntity();
    std::unique_ptr<RectangleEntity> createRectangle() override;
    void setTextureLeft(QOpenGLTexture *texture) override;
    void setTextureRight(QOpenGLTexture *texture) override;
};

#endif // STEREORIGHTENTITY_H
