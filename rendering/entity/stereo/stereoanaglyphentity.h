#ifndef STEREOANAGLYPHENTITY_H
#define STEREOANAGLYPHENTITY_H

#include "stereorectangleentity.h"

#include "../anaglyphrectangleentity.h"

#include <memory>

class StereoAnaglyphEntity : public StereoRectangleEntity
{
public:
    StereoAnaglyphEntity();
    std::unique_ptr<RectangleEntity> createRectangle() override;
};

#endif // STEREOANAGLYPHENTITY_H
