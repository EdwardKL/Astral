#include "Landscape.h"
#include "Configuration.h"

Landscape::Landscape() {
}

Landscape::~Landscape() {
}

float Landscape::getAltitude(int x, int z) {
    float height = octave_noise_3d(6, 0.5, 0.005, GAME::SEED, x, z);
    return height;
}

int Landscape::getAdjustedAltitude(int worldX, int worldZ) {
    return static_cast<int>(getAltitude(worldX, worldZ) * SIZES::MAX_TERRAIN_HEIGHT);
}
