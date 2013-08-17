#ifndef CHUNKMANAGER_H
#define CHUNKMANAGER_H

#include <map>

#include "BulletCollision/CollisionShapes/btTriangleMesh.h"
#include "BulletCollision/CollisionShapes/btShapeHull.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"

#include "Configuration.h"
#include "Landscape.h"
#include "Game.h";

struct Chunk
{
    Ogre::SceneNode* mSceneNode;
    Ogre::ManualObject* mManualObject;
    btTriangleMesh* mTriangleMesh;
    btBvhTriangleMeshShape* mTriangleMeshShape;
    btDefaultMotionState* mMotionState;
    btRigidBody* mRigidBody;
    Chunk(Ogre::SceneNode* sceneNode, Ogre::ManualObject* manualObject,
          btTriangleMesh* triangleMesh, btBvhTriangleMeshShape* triangleMeshShape,
          btDefaultMotionState* motionState, btRigidBody* rigidBody) :
        mSceneNode(sceneNode), mManualObject(manualObject), mTriangleMesh(triangleMesh),
        mTriangleMeshShape(triangleMeshShape), mMotionState(motionState), mRigidBody(rigidBody) {}

    /***
    Do not call this destructor directly. If you want to delete a chunk, use ChunkManager::deleteChunk
    ***/
    ~Chunk() {
        delete mManualObject;
        delete mRigidBody;
        delete mTriangleMesh;
        delete mTriangleMeshShape;
        delete mMotionState;
    }
};

class ChunkManager
{
    public:
        ChunkManager(Game* game);
        virtual ~ChunkManager();
        bool hasChunkAtChunkCoords(int chunk_x, int chunk_y, int chunk_z);
        bool hasChunkAtRealCoords(int x, int y, int z);
        /*** createChunk creates a chunk at (chunk_x,chunk_y,chunk_z), which defines a point in chunk space.
        ***/
        void createChunk(int chunk_x, int chunk_y, int chunk_z);
        void deleteChunk(int chunk_x, int chunk_y, int chunk_z);

    protected:
    private:
        Ogre::Vector3 chunkToRealCoords(int chunk_x, int chunk_y, int chunk_z);
        Ogre::Vector3 realToChunkCoords(int x, int y, int z);

        std::map<int, std::map<int, std::map<int, Chunk*> > > mChunks;
        Game* mGame;
        Ogre::String* mName;
};


#endif // CHUNKMANAGER_H
