#ifndef STEREOOPACITYENTITY_H
#define STEREOOPACITYENTITY_H

#include "stereorectangleentity.h"

#include "../opacityrectangleentity.h"

#include <memory>

class StereoOpacityEntity : public StereoRectangleEntity
{
public:
    StereoOpacityEntity();
    std::unique_ptr<RectangleEntity> createRectangle() override;
};

#endif // STEREOOPACITYENTITY_H
