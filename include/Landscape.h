#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include "external/simplexnoise/simplexnoise.h"


class Landscape
{
    public:
        Landscape();
        virtual ~Landscape();
        float getAltitude(int worldX, int worldZ);
        float getAdjustedAltitude(int worldX, int worldZ);
    protected:
    private:
};

#endif // LANDSCAPE_H
