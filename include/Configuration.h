#pragma once
#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

struct GAME {
    static const int SEED = 100;
};

struct SIZES {
    static const int MAX_TERRAIN_HEIGHT = 100;
    static const int CHUNK_SIZE = 100; // Defines the length of a chunk's side. The chunk is a cube.
    static const int CHUNK_TEXTURE_TILE = 50;
};


#endif // CONFIGURATION_H_
