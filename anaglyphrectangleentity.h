#ifndef ANAGLYPHRECTANGLEENTITY_H
#define ANAGLYPHRECTANGLEENTITY_H

#include "rectangleentity.h"

class AnaglyphRectangleEntity : public RectangleEntity
{
public:
    AnaglyphRectangleEntity();

    void addShaders() override;
    void setDefaultUniforms() override;

    // shift in % of viewport
    void setHorizontalShift(float shift);
};

#endif // ANAGLYPHRECTANGLEENTITY_H
