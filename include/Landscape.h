#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include "external/simplexnoise/simplexnoise.h"


class Landscape
{
    public:
        Landscape();
        virtual ~Landscape();
        float getAltitude(int worldX, int worldZ);
        int getAdjustedAltitude(int worldX, int worldZ);
    protected:
    private:
};

#endif // LANDSCAPE_H
