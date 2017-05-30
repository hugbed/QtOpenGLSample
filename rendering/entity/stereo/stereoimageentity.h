#ifndef STEREOIMAGEENTITY_H
#define STEREOIMAGEENTITY_H

#include "../entity.h"

#include <QOpenGLTexture>

class StereoImageEntity : public Entity {
public:
    virtual void init() = 0;
    virtual void setHorizontalShift(float shift) = 0;
    virtual void setTextureLeft(QOpenGLTexture* image) = 0;
    virtual void setTextureRight(QOpenGLTexture* image) = 0;
};

#endif // STEREOIMAGEENTITY_H
