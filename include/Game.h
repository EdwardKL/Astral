#pragma once
#ifndef __Game_h_
#define __Game_h_

#include <CEGUIImageset.h>
#include <CEGUIFont.h>
#include <CEGUISystem.h>
#include <CEGUISchemeManager.h>
#include <CEGUIWindowManager.h>
#include <falagard/CEGUIFalWidgetLookManager.h>
#include <RendererModules/Ogre/CEGUIOgreRenderer.h>

#include "BulletDynamics/Dynamics/btRigidBody.h"
#include "BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h"
#include "btBulletDynamicsCommon.h"

#include "DebugDraw.hpp"

#include "Utils/OgreBulletConverter.h"

#include "BaseApplication.h"
#include "Landscape.h"

class ChunkManager;
class Player;

class Game : public BaseApplication
{
public:
    Game(void);
    virtual ~Game(void);
    static void log(const Ogre::String &tag, const Ogre::String &message);
    Ogre::Entity* createEntity(const Ogre::String& meshName);
    Ogre::SceneNode* createSceneNode(const Ogre::Vector3& position = Ogre::Vector3::ZERO,
                                     const Ogre::Quaternion& orientation =
                                             Ogre::Quaternion::IDENTITY);
    Ogre::SceneNode* createSceneNode(const Ogre::String& name, const Ogre::Vector3& position =
                                             Ogre::Vector3::ZERO,
                                     const Ogre::Quaternion& orientation =
                                             Ogre::Quaternion::IDENTITY);
    Landscape* getLandscape();
    void addRigidBody(btRigidBody* rb);
    void destroySceneNode(Ogre::SceneNode* node);
    btDiscreteDynamicsWorld* getDynamicsWorld();
    void bulletTickCallback(btScalar timeStep);

protected:
    virtual void createScene(void);
    virtual void createCamera(void);
    virtual bool frameStarted(const Ogre::FrameEvent& evt);
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
    virtual bool frameEnded(const Ogre::FrameEvent& evt);
    virtual bool keyPressed(const OIS::KeyEvent &evt);
    virtual bool keyReleased(const OIS::KeyEvent &evt);
    virtual bool unbufferedKeyPressed(const Ogre::FrameEvent& evt);
    virtual bool mouseMoved(const OIS::MouseEvent &evt);
    virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );

private:
    void bulletSetup(void);

    ChunkManager* mChunkManager;
    Landscape* mLandscape;
    Player* mPlayer;

    // Bullet stuff
    btBroadphaseInterface* mBroadphase;
    btDefaultCollisionConfiguration* mCollisionConfiguration;
    btCollisionDispatcher* mDispatcher;
    btSequentialImpulseConstraintSolver* mSolver;
    btDiscreteDynamicsWorld* mDynamicsWorld;

    CDebugDraw* mDebugDrawer;
    CEGUI::Renderer* mGUIRenderer;  // CEGUI renderer
};

#endif // #ifndef __Game_h_
