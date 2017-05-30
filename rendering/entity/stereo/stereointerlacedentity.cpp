#include "stereointerlacedentity.h"

StereoInterlacedEntity::StereoInterlacedEntity()
    : StereoRectangleEntity()
{
}

std::unique_ptr<RectangleEntity> StereoInterlacedEntity::createRectangle()
{
    return std::make_unique<InterlacedRectangleEntity>();
}
