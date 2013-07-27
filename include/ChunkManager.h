#ifndef CHUNKMANAGER_H
#define CHUNKMANAGER_H

#include "Configuration.h"
#include "Landscape.h"
#include "Game.h";

class ChunkManager
{
    public:
        ChunkManager(Game* game);
        virtual ~ChunkManager();
        /*** createChunk creates a chunk at (x,y,z), which defines a point in chunk space.
        ***/
        void createChunk(int x, int y, int z);
    protected:
    private:
        Ogre::ManualObject* createChunkMeshAt(Ogre::Vector3& position);

        Ogre::Vector3* chunkToRealCoords(int x, int y, int z);
        Ogre::Vector3* realToChunkCoords(int x, int y, int z);

        Game* mGame;
        Ogre::String* mName;
};

#endif // CHUNKMANAGER_H
