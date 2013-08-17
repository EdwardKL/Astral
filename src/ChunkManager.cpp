#include "ChunkManager.h"
#include <time.h>


static const Ogre::String TAG = "ChunkManager";

ChunkManager::ChunkManager(Game* game)
: mGame(game) {
}

ChunkManager::~ChunkManager() {
    mChunks.clear();
}

bool ChunkManager::hasChunkAtChunkCoords(int chunk_x, int chunk_y, int chunk_z) {
    if (mChunks.count(chunk_x) == 0) {
        return false;
    }
    if (mChunks[chunk_x].count(chunk_y) == 0) {
        return false;
    }
    if (mChunks[chunk_x][chunk_y].count(chunk_z) == 0) {
        return false;
    }
    return true;
}

bool ChunkManager::hasChunkAtRealCoords(int x, int y, int z) {
    Ogre::Vector3 coords = realToChunkCoords(x,y,z);
    return hasChunkAtChunkCoords(coords.x, coords.y, coords.z);
}

// Helper function for memoization in chunk mesh creation
int vxvz2vi(int vx,int vz) {
    return (vx+1)*(SIZES::CHUNK_SIZE+2)+vz+1;
}

Ogre::Vector3* getVector(int vx, int vz, Landscape* landscape, Ogre::Vector3** vertices) {
    if (vertices[vxvz2vi(vx,vz)] == NULL) {
        float vy = landscape->getAdjustedAltitude(vx,vz);
        vertices[vxvz2vi(vx,vz)] = new Ogre::Vector3(vx,vy,vz);
    }
    return vertices[vxvz2vi(vx,vz)];
}

/***
Creates a chunk at (chunk_x,chunk_y,chunk_z) in chunk coordinates.
Allocations:
 - pos: position of chunk in real coordinates
 - sn: chunk's scenenode
 - mo: chunk's mesh (manualobject)
 - vertices: memoization of mesh's vertices
 - trimesh: holds triangle data for bullet
 - tms: collision shape using trimesh
 - ms: motion state
 - rb: chunk's rigidbody

***/
void ChunkManager::createChunk(int chunk_x, int chunk_y, int chunk_z) {
    if (hasChunkAtChunkCoords(chunk_x, chunk_y, chunk_z)) {
        // Don't do anything if we already have a chunk there.
        return;
    }
    mName = new Ogre::String("Chunk_"+Ogre::StringConverter::toString(chunk_x)+"_"+Ogre::StringConverter::toString(chunk_y)+"_"+Ogre::StringConverter::toString(chunk_z));
    Ogre::Vector3 pos = chunkToRealCoords(chunk_x,chunk_y,chunk_z);
    Ogre::SceneNode* sn = mGame->createSceneNode(pos);
    clock_t t;
    Game::log(TAG, "Creating chunk...");
    t = clock();
    Landscape* landscape = mGame->getLandscape();
    Ogre::ManualObject* mo = new Ogre::ManualObject("ChunkManualObject" + *mName);

    /*** The following code is to memoize the mesh creation process. I don't know if it will make things faster (most likely will), but
    I'll keep it here for now to test later in case the speed of this function is slow.***/

    Ogre::Vector3** vertices = new Ogre::Vector3* [(SIZES::CHUNK_SIZE+2)*(SIZES::CHUNK_SIZE+2)]; // + 2 to account for the edge vertices

    for (int i = 0; i < (SIZES::CHUNK_SIZE+2)*(SIZES::CHUNK_SIZE+2); i++) {
        vertices[i] = NULL;
    }

    // Create the meshes
    //mo->begin("Astral/Grass");
    mo->begin("Examples/GrassFloor");
    for (int x = 0; x < SIZES::CHUNK_SIZE; x++) {
        for (int z = 0; z < SIZES::CHUNK_SIZE; z++) {
            // vx, vy, vz define the next vertex we want to add to the manualobject.
            int vx = x + pos.x;
            int vz = z + pos.z;
            Ogre::Vector3 v = *getVector(vx,vz,landscape,vertices);
            // add the vertex
            mo->position(v);

            // now we need to find the faces this vertex touches
            Ogre::Vector3 ll = *getVector(vx-1,vz-1,landscape,vertices);
            Ogre::Vector3 lm = *getVector(vx,vz-1,landscape,vertices);
            Ogre::Vector3 lr = *getVector(vx+1,vz-1,landscape,vertices);
            Ogre::Vector3 ml = *getVector(vx-1,vz,landscape,vertices);
            Ogre::Vector3 mr = *getVector(vx+1,vz,landscape,vertices);
            Ogre::Vector3 ul = *getVector(vx-1,vz+1,landscape,vertices);
            Ogre::Vector3 um = *getVector(vx,vz+1,landscape,vertices);
            Ogre::Vector3 ur = *getVector(vx+1,vz+1,landscape,vertices);


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

            mo->textureCoord((float)x/(float)SIZES::CHUNK_TEXTURE_TILE,(float)z/(float)SIZES::CHUNK_TEXTURE_TILE);

        }
    }
    Game::log(TAG, "Vertices created");

    btTriangleMesh* trimesh = new btTriangleMesh();
    for (int x = 0; x < SIZES::CHUNK_SIZE - 1; x++) {
        for (int z = 0; z < SIZES::CHUNK_SIZE - 1; z++) {
            mo->triangle((x * SIZES::CHUNK_SIZE) + z + 1,
                         ((x + 1) * SIZES::CHUNK_SIZE) + z,
                         (x * SIZES::CHUNK_SIZE) + z);

            mo->triangle((x * SIZES::CHUNK_SIZE) + z + 1,
                         ((x + 1) * SIZES::CHUNK_SIZE) + z + 1,
                         ((x + 1) * SIZES::CHUNK_SIZE) + z);

            Ogre::Vector3* a = vertices[(x+1)*(SIZES::CHUNK_SIZE+2)+z+2];
            Ogre::Vector3* b = vertices[(x+2)*(SIZES::CHUNK_SIZE+2)+z+1];
            Ogre::Vector3* c = vertices[(x+1)*(SIZES::CHUNK_SIZE+2)+z+1];
            Ogre::Vector3* d = vertices[(x+2)*(SIZES::CHUNK_SIZE+2)+z+2];
            trimesh->addTriangle(btVector3(a->x,a->y,a->z),
                                 btVector3(b->x,b->y,b->z),
                                 btVector3(c->x,c->y,c->z));
            trimesh->addTriangle(btVector3(a->x,a->y,a->z),
                                 btVector3(d->x,d->y,d->z),
                                 btVector3(b->x,b->y,b->z));
        }
    }
    mo->end();
    sn->attachObject(mo);
    Game::log(TAG, "mo attached");

    btBvhTriangleMeshShape* tms = new btBvhTriangleMeshShape(trimesh,
                                                             true); //useQuantizedAabbCompression
//    btShapeHull* hull = new btShapeHull(tms);
//    btScalar margin = tms->getMargin();
//    hull->buildHull(margin);
//    btConvexHullShape* chs = new btConvexHullShape((btScalar*)hull->getVertexPointer(), hull->numVertices());
    // I give it this motionstate and not an Ogre one because chunks shouldn't move anyways
    btDefaultMotionState* ms = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(pos.x,pos.y,pos.z)));
    btRigidBody::btRigidBodyConstructionInfo info(0,ms,tms);
    btRigidBody* rb = new btRigidBody(info);
    Game::log(TAG, "rb created");

    mGame->addRigidBody(rb);
    Game::log(TAG, "rb added");

    // Clean up
    for (int i = 0; i < (SIZES::CHUNK_SIZE+2)*(SIZES::CHUNK_SIZE+2); i++) {
        delete vertices[i];
    }
    delete [] vertices;

    // Time stats
    t = clock() - t;
    Game::log(TAG, "Done creating chunk mesh.");
    Game::log(TAG, "Mesh created in "+Ogre::StringConverter::toString((long)t)+" ticks.");
    mChunks[chunk_x][chunk_y][chunk_z] = new Chunk(sn, mo, trimesh, tms, ms, rb);
}

void ChunkManager::deleteChunk(int chunk_x, int chunk_y, int chunk_z) {
    if (!hasChunkAtChunkCoords(chunk_x, chunk_y, chunk_z)) {
        // Don't do anything if we don't have a chunk there.
        return;
    }
    //TODO: serialize the chunk before deletion
    Chunk* chunk = mChunks[chunk_x][chunk_y][chunk_z];
    mGame->getDynamicsWorld()->removeRigidBody(chunk->mRigidBody);
    Ogre::SceneNode* sceneNode = chunk->mSceneNode;
    sceneNode->removeAndDestroyAllChildren();
    mGame->destroySceneNode(sceneNode);
    delete chunk;
}

Ogre::Vector3 ChunkManager::chunkToRealCoords(int x, int y, int z) {
    return Ogre::Vector3(x * SIZES::CHUNK_SIZE, y * SIZES::CHUNK_SIZE, z * SIZES::CHUNK_SIZE);
}

Ogre::Vector3 ChunkManager::realToChunkCoords(int x, int y, int z) {
    return Ogre::Vector3(x / SIZES::CHUNK_SIZE, y / SIZES::CHUNK_SIZE, z / SIZES::CHUNK_SIZE);
}

