#ifndef OPACITYRECTANGLEENTITY_H
#define OPACITYRECTANGLEENTITY_H

#include "rectangleentity.h"

class OpacityRectangleEntity : public RectangleEntity
{
public:
    OpacityRectangleEntity();

    void addShaders() override;
    void setDefaultUniforms() override;

    // shift in % of viewport
    void setHorizontalShift(float shift);
};

#endif // ANAGLYPHRECTANGLEENTITY_H
