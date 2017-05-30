#include "stereoanaglyphentity.h"

StereoAnaglyphEntity::StereoAnaglyphEntity()
    : StereoRectangleEntity()
{
}

std::unique_ptr<RectangleEntity> StereoAnaglyphEntity::createRectangle()
{
    return std::make_unique<AnaglyphRectangleEntity>();
}
