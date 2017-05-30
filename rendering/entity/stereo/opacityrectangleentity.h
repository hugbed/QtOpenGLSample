#ifndef OPACITYRECTANGLEENTITY_H
#define OPACITYRECTANGLEENTITY_H

#include "rectangleentity.h"

class OpacityRectangleEntity : public RectangleEntity
{
public:
    OpacityRectangleEntity();
    void addShaders() override;
};

#endif // ANAGLYPHRECTANGLEENTITY_H
