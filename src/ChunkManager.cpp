#include "ChunkManager.h"

static const Ogre::String TAG = "ChunkManager";

ChunkManager::ChunkManager(Game* game)
: mGame(game) {
}

ChunkManager::~ChunkManager() {
}

void ChunkManager::createChunk(int x, int y, int z) {
    mName = new Ogre::String("Chunk_"+Ogre::StringConverter::toString(x)+"_"+Ogre::StringConverter::toString(y)+"_"+Ogre::StringConverter::toString(z));
    Ogre::Vector3* pos = chunkToRealCoords(x,y,z);
    Ogre::SceneNode* sn = mGame->createSceneNode(*pos);
    Ogre::ManualObject* mo = createChunkMeshAt(*pos);
    sn->attachObject(mo);
    //TODO: Add chunk to storage
    delete pos;
}

Ogre::ManualObject* ChunkManager::createChunkMeshAt(Ogre::Vector3& position) {
    Game::log(TAG, "Creating chunk mesh...");
    Landscape* landscape = mGame->getLandscape();
    Ogre::ManualObject* mo = new Ogre::ManualObject("ChunkManualObject" + *mName);

    /*** The following code is to memoize the mesh creation process. I don't know if it will make things faster, but
    I'll keep it here for now to test later in case the speed of this function is slow.

    Ogre::Vector3* vertices = new Ogre::Vector3 [(SIZES::CHUNK_SIZE+2)*(SIZES::CHUNK_SIZE+2)]; // + 2 to account for the edge vertices

    for (int i = 0; i < (SIZES::CHUNK_SIZE+2)*(SIZES::CHUNK_SIZE+2); i++) {
        vertices[i] = NULL;
    }
    ***/
    mo->begin("Glass");
    for (int x = 0; x < SIZES::CHUNK_SIZE; x++) {
        for (int z = 0; z < SIZES::CHUNK_SIZE; z++) {
            // vx, vy, vz define the next vertex we want to add to the manualobject.
            int vx = x + position.x;
            int vz = z + position.z;
            int vy = landscape->getAdjustedAltitude(vx,vz);
            Ogre::Vector3 v = Ogre::Vector3(vx,vy,vz);
            // add the vertex
            mo->position(v);

            // now we need to find the faces this vertex touches
            Ogre::Vector3 ll = Ogre::Vector3(vx-1,landscape->getAdjustedAltitude(vx-1,vz-1),vz-1);
            Ogre::Vector3 lm = Ogre::Vector3(vx,landscape->getAdjustedAltitude(vx,vz-1),vz-1);
            Ogre::Vector3 lr = Ogre::Vector3(vx+1,landscape->getAdjustedAltitude(vx+1,vz-1),vz-1);
            Ogre::Vector3 ml = Ogre::Vector3(vx-1,landscape->getAdjustedAltitude(vx-1,vz),vz);
            Ogre::Vector3 mr = Ogre::Vector3(vx+1,landscape->getAdjustedAltitude(vx+1,vz),vz);
            Ogre::Vector3 ul = Ogre::Vector3(vx-1,landscape->getAdjustedAltitude(vx-1,vz+1),vz+1);
            Ogre::Vector3 um = Ogre::Vector3(vx,landscape->getAdjustedAltitude(vx,vz+1),vz+1);
            Ogre::Vector3 ur = Ogre::Vector3(vx+1,landscape->getAdjustedAltitude(vx+1,vz+1),vz+1);

            Ogre::Vector3 normal = Ogre::Vector3(0,0,0);

            normal += (v - ll).crossProduct(lm - ll).normalisedCopy();
            normal += (ml - ll).crossProduct(v - ll).normalisedCopy();
            normal += (um - ml).crossProduct(v - ml).normalisedCopy();
            normal += (ul - ml).crossProduct(um - ml).normalisedCopy();
            normal += (um - v).crossProduct(ur - v).normalisedCopy();
            normal += (ur - v).crossProduct(mr - v).normalisedCopy();
            normal += (v - lm).crossProduct(mr - lm).normalisedCopy();
            normal += (mr - lm).crossProduct(lr - lm).normalisedCopy();

            mo->normal(normal.normalisedCopy());


        }
    }
    for (int x = 0; x < SIZES::CHUNK_SIZE - 1; x++) {
        for (int z = 0; z < SIZES::CHUNK_SIZE - 1; z++) {
            mo->triangle((x * SIZES::CHUNK_SIZE) + z + 1,
                         ((x + 1) * SIZES::CHUNK_SIZE) + z,
                         (x * SIZES::CHUNK_SIZE) + z);

            mo->triangle((x * SIZES::CHUNK_SIZE) + z + 1,
                         ((x + 1) * SIZES::CHUNK_SIZE) + z + 1,
                         ((x + 1) * SIZES::CHUNK_SIZE) + z);
        }
    }
    mo->end();

    Game::log(TAG, "Done creating chunk mesh...");
    return mo;
}

Ogre::Vector3* ChunkManager::chunkToRealCoords(int x, int y, int z) {
    return new Ogre::Vector3(x * SIZES::CHUNK_SIZE, y * SIZES::CHUNK_SIZE, z * SIZES::CHUNK_SIZE);
}

Ogre::Vector3* ChunkManager::realToChunkCoords(int x, int y, int z) {
    return new Ogre::Vector3(x / SIZES::CHUNK_SIZE, y / SIZES::CHUNK_SIZE, z / SIZES::CHUNK_SIZE);
}
