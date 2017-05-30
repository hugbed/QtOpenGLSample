#ifndef STEREOLEFTENTITY_H
#define STEREOLEFTENTITY_H

#include "stereorectangleentity.h"

#include "../rectangleentity.h"

class StereoLeftEntity : public StereoRectangleEntity
{
public:
    StereoLeftEntity();
    std::unique_ptr<RectangleEntity> createRectangle() override;
    void setTextureRight(QOpenGLTexture *texture) override;
};

#endif // STEREOLEFTENTITY_H
