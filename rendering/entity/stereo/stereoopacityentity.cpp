#include "stereoopacityentity.h"

StereoOpacityEntity::StereoOpacityEntity()
    : StereoRectangleEntity()
{
}

std::unique_ptr<RectangleEntity> StereoOpacityEntity::createRectangle()
{
    return std::make_unique<OpacityRectangleEntity>();
}
