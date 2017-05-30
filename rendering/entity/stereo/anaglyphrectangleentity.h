#ifndef ANAGLYPHRECTANGLEENTITY_H
#define ANAGLYPHRECTANGLEENTITY_H

#include "rectangleentity.h"

class AnaglyphRectangleEntity : public RectangleEntity
{
public:
    AnaglyphRectangleEntity();
    void addShaders() override;
};

#endif // ANAGLYPHRECTANGLEENTITY_H
