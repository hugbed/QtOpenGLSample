#ifndef INTERLACEDRECTANGLEENTITY_H
#define INTERLACEDRECTANGLEENTITY_H

#include "rectangleentity.h"

class InterlacedRectangleEntity : public RectangleEntity
{
public:
    InterlacedRectangleEntity();

    void addShaders() override;
    void setDefaultUniforms() override;

    // shift in % of viewport
    void setHorizontalShift(float shift);
};

#endif // INTERLACEDRECTANGLEENTITY_H
