#ifndef INTERLACEDRECTANGLEENTITY_H
#define INTERLACEDRECTANGLEENTITY_H

#include "rectangleentity.h"

class InterlacedRectangleEntity : public RectangleEntity
{
public:
    InterlacedRectangleEntity();
    void addShaders() override;
};

#endif // INTERLACEDRECTANGLEENTITY_H
