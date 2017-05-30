#ifndef STEREOINTERLACEDENTITY_H
#define STEREOINTERLACEDENTITY_H

#include "stereorectangleentity.h"

#include "../interlacedrectangleentity.h"

#include <memory>

class StereoInterlacedEntity : public StereoRectangleEntity
{
public:
    StereoInterlacedEntity();
    std::unique_ptr<RectangleEntity> createRectangle() override;
};

#endif // STEREOINTERLACEDENTITY_H
