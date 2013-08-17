#include "Landscape.h"
#include "Configuration.h"

Landscape::Landscape() {
}

Landscape::~Landscape() {
}

float Landscape::getAltitude(int x, int z) {
    float height = octave_noise_3d(3, 0.5, 0.005, GAME::SEED, x, z);
    return height;
}

float Landscape::getAdjustedAltitude(int worldX, int worldZ) {
//    if ((150<worldX) && (worldX < 250) && (150<worldZ) && (worldZ < 250)) {
//        return 20;
//    }
//    return 0;
    //return worldX/10;
    return getAltitude(worldX, worldZ) * SIZES::MAX_TERRAIN_HEIGHT;
}
