#pragma once
#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

struct GAME {
    static const int SEED = 120;
};

struct SIZES {
    static const int MAX_TERRAIN_HEIGHT = 200;
    static const int CHUNK_SIZE = 1000; // Defines the length of a chunk's side. The chunk is a cube.
};


#endif // CONFIGURATION_H_
