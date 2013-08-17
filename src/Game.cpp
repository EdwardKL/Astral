#include "Game.h"
#include "ChunkManager.h"
#include "Player.h"

static const Ogre::String TAG = "Game";

//-------------------------------------------------------------------------------------
Game::Game(void) :
    mLandscape(new Landscape()) {
}
//-------------------------------------------------------------------------------------
Game::~Game(void) {
//    delete mDynamicsWorld;
//    delete mSolver;
//    delete mDispatcher;
//    delete mCollisionConfiguration;
//    delete mBroadphase;

}

void tickCallback(btDynamicsWorld *world, btScalar timeStep) {
    Game *w = static_cast<Game *>(world->getWorldUserInfo());
    w->bulletTickCallback(timeStep);
}

void Game::bulletSetup(void) {
    // A Dynamic AABB Tree broadphase is better here than a SAP broadphase because we want infinite terrain gen
    mBroadphase = new btDbvtBroadphase();
    mCollisionConfiguration = new btDefaultCollisionConfiguration();
    mDispatcher = new btCollisionDispatcher(mCollisionConfiguration);
    mSolver = new btSequentialImpulseConstraintSolver;
    mDynamicsWorld = new btDiscreteDynamicsWorld(mDispatcher,mBroadphase,mSolver,mCollisionConfiguration);
    mDynamicsWorld->setGravity(btVector3(0,-100,0));
    mDynamicsWorld->setInternalTickCallback(tickCallback, static_cast<void *>(this));

    mDebugDrawer = new CDebugDraw(mSceneMgr, mDynamicsWorld);
}

void Game::bulletTickCallback(btScalar timeStep) {
    mPlayer->update(timeStep);
}

void Game::createCamera(void) {

    // Create the camera
    mCamera = mSceneMgr->createCamera("PlayerCam");
    // Look back along -Z
    mCamera->lookAt(Ogre::Vector3(0,0,-300));
    mCamera->setNearClipDistance(1);
    mCamera->setFarClipDistance(1000);

}


//-------------------------------------------------------------------------------------
void Game::createScene(void) {
    log(TAG, "Creating scene...");
    // Setup Bullet
    bulletSetup();

    // CEGUI setup
    mGUIRenderer = &CEGUI::OgreRenderer::bootstrapSystem();
    CEGUI::Imageset::setDefaultResourceGroup("Imagesets");
    CEGUI::Font::setDefaultResourceGroup("Fonts");
    CEGUI::Scheme::setDefaultResourceGroup("Schemes");
    CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
    CEGUI::WindowManager::setDefaultResourceGroup("Layouts");
    // Mouse
    CEGUI::SchemeManager::getSingleton().create("TaharezLook.scheme");
    CEGUI::System::getSingleton().setDefaultFont("DejaVuSans-10");
    CEGUI::System::getSingleton().setDefaultMouseCursor("TaharezLook", "MouseArrow");
    CEGUI::Window* mRootWindow = CEGUI::WindowManager::getSingleton().createWindow("DefaultWindow",
                                                                                   "_MasterRoot");
    CEGUI::System::getSingleton().setGUISheet(mRootWindow);
CEGUI::MouseCursor::getSingleton().setImage( CEGUI::System::getSingleton().getDefaultMouseCursor());

    // Chunkmanager
    mChunkManager = new ChunkManager(this);
    // Ambient light
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.0f, 0.0f, 0.0f));
    // Sky
    mSceneMgr->setSkyDome(true, "Examples/CloudySky", 5, 8, 300);
    //mSceneMgr->setSkyBox(true, "Examples/EveningSkyBox",100, false);
    // Fog
//    mSceneMgr->setFog(Ogre::FOG_LINEAR, Ogre::ColourValue(0.8, 0.8, 1), 0.0, 10, 200);
//     Sun

    Ogre::Light* directionalLight = mSceneMgr->createLight("directionalLight");
    directionalLight->setType(Ogre::Light::LT_DIRECTIONAL);
    //directionalLight->setDiffuseColour(Ogre::ColourValue(.8, .8, .8));
    //directionalLight->setSpecularColour(Ogre::ColourValue(.8, .8, .8));
    directionalLight->setDirection(Ogre::Vector3(0, -1, -1));
    // Shadow
//    mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_MODULATIVE);

    mChunkManager->createChunk(0,0,0);
//    mChunkManager->createChunk(SIZES::CHUNK_SIZE,0,0);
//    mChunkManager->createChunk(0,0,SIZES::CHUNK_SIZE);

    mPlayer = new Player(mCamera, this);
    mPlayer->init(Ogre::Vector3(SIZES::CHUNK_SIZE/2,110,SIZES::CHUNK_SIZE/2));

    log(TAG, "Done creating scene...");
}

Ogre::Entity* Game::createEntity(const Ogre::String& meshName) {
    log(TAG, "Creating mesh: " + meshName);
    return mSceneMgr->createEntity(meshName);
}

Ogre::SceneNode* Game::createSceneNode(const Ogre::Vector3& position,
                                       const Ogre::Quaternion& orientation) {
    return mSceneMgr->getRootSceneNode()->createChildSceneNode(position, orientation);
}

Ogre::SceneNode* Game::createSceneNode(const Ogre::String& name, const Ogre::Vector3& position,
                                       const Ogre::Quaternion& orientation) {
    return mSceneMgr->getRootSceneNode()->createChildSceneNode(name, position, orientation);
}

void Game::addRigidBody(btRigidBody* rb) {
    log(TAG, "Adding rigidbody...");
    mDynamicsWorld->addRigidBody(rb);
}

void Game::destroySceneNode(Ogre::SceneNode* node) {
    mSceneMgr->destroySceneNode(node);
}

Landscape* Game::getLandscape() {
    return mLandscape;
}

btDiscreteDynamicsWorld* Game::getDynamicsWorld() {
    return mDynamicsWorld;
}
/**********************************************************************************************/
/************************************* FRAME HANDLERS *****************************************/
/**********************************************************************************************/



bool Game::frameStarted(const Ogre::FrameEvent& evt) {
    return true;
}

bool Game::frameRenderingQueued(const Ogre::FrameEvent& evt) {
    bool ret = BaseApplication::frameRenderingQueued(evt);
    //mDebugDrawer->Update();
    unbufferedKeyPressed(evt);
    return ret;
}

bool Game::frameEnded(const Ogre::FrameEvent& evt) {
    mDynamicsWorld->stepSimulation(evt.timeSinceLastFrame);  // update Bullet Physics animation
    return true;
}

/**********************************************************************************************/
/************************************* INPUT HANDLERS *****************************************/
/**********************************************************************************************/



bool Game::unbufferedKeyPressed(const Ogre::FrameEvent& evt) {
    mPlayer->handleUnbufferedInputs(evt, mKeyboard);
    return true;
}

bool Game::keyPressed(const OIS::KeyEvent& evt) {

    if (mTrayMgr->isDialogVisible())
        // don't process any more keys if dialog is up
        return true;

    if (evt.key == OIS::KC_F) {
        // toggle visibility of advanced frame stats
        mTrayMgr->toggleAdvancedFrameStats();

    } else if (evt.key == OIS::KC_G) {
        // toggle visibility of even rarer debugging details
        if (mDetailsPanel->getTrayLocation() == OgreBites::TL_NONE) {
            mTrayMgr->moveWidgetToTray(mDetailsPanel, OgreBites::TL_TOPRIGHT, 0);
            mDetailsPanel->show();
        } else {
            mTrayMgr->removeWidgetFromTray(mDetailsPanel);
            mDetailsPanel->hide();
        }

    } else if (evt.key == OIS::KC_T) {
        // cycle polygon rendering mode
        Ogre::String newVal;
        Ogre::TextureFilterOptions tfo;
        unsigned int aniso;

        switch (mDetailsPanel->getParamValue(9).asUTF8()[0]) {
            case 'B':
                newVal = "Trilinear";
                tfo = Ogre::TFO_TRILINEAR;
                aniso = 1;
                break;
            case 'T':
                newVal = "Anisotropic";
                tfo = Ogre::TFO_ANISOTROPIC;
                aniso = 8;
                break;
            case 'A':
                newVal = "None";
                tfo = Ogre::TFO_NONE;
                aniso = 1;
                break;
            default:
                newVal = "Bilinear";
                tfo = Ogre::TFO_BILINEAR;
                aniso = 1;
                break;
        }

        Ogre::MaterialManager::getSingleton().setDefaultTextureFiltering(tfo);
        Ogre::MaterialManager::getSingleton().setDefaultAnisotropy(aniso);
        mDetailsPanel->setParamValue(9, newVal);

    } else if (evt.key == OIS::KC_R) {
        // cycle polygon rendering mode
        Ogre::String newVal;
        Ogre::PolygonMode pm;

        switch (mCamera->getPolygonMode()) {
            case Ogre::PM_SOLID:
                newVal = "Wireframe";
                pm = Ogre::PM_WIREFRAME;
                break;
            case Ogre::PM_WIREFRAME:
                newVal = "Points";
                pm = Ogre::PM_POINTS;
                break;
            default:
                newVal = "Solid";
                pm = Ogre::PM_SOLID;
                break;
        }

        mCamera->setPolygonMode(pm);
        mDetailsPanel->setParamValue(10, newVal);

    } else if (evt.key == OIS::KC_F5) {
        // refresh all textures
        Ogre::TextureManager::getSingleton().reloadAll();

    } else if (evt.key == OIS::KC_SYSRQ) {
        // take a screenshot
        mWindow->writeContentsToTimestampedFile("screenshot", ".jpg");

    } else if (evt.key == OIS::KC_ESCAPE) {
        mShutDown = true;
    }

    return true;
}

bool Game::keyReleased(const OIS::KeyEvent &evt) {
    return true;
}

bool Game::mouseMoved(const OIS::MouseEvent &evt) {
    mPlayer->mouseMoved(evt);
    return true;
}

bool Game::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id ) {
//    CEGUI::Point mousePos = CEGUI::MouseCursor::getSingleton().getPosition();
//    Ogre::Vector2 rayPos(mousePos.d_x, mousePos.d_y);
//    Ogre::Real screenWidth = Ogre::Root::getSingleton().getAutoCreatedWindow()->getWidth();
//    Ogre::Real screenHeight = Ogre::Root::getSingleton().getAutoCreatedWindow()->getHeight();
//    Ogre::Ray mouseRay = mCamera->getCameraToViewportRay(rayPos.x / screenWidth,
//                                                         rayPos.y / screenHeight);
//
//    Ogre::Real playerReach = 100;
//
//    btVector3 start = OgreBulletConverter::convert(mouseRay.getOrigin());
//    btVector3 end = OgreBulletConverter::convert(mouseRay.getPoint(playerReach));
//    btCollisionWorld::ClosestRayResultCallback btRayCallback(start, end);
    ////btRayCallback->m_collisionFilterMask = COLLISIONS::BLOCK;
//    mDynamicsWorld->rayTest(start, end, btRayCallback);
//
//    if (btRayCallback->hasHit()) {
//        btVector3 hitPoint = btRayCallback->m_hitPointWorld;
//        btVector3 hitNormal = btRayCallback->m_hitNormalWorld;
//        mChunkManager->selectBlock(toOgreVector3(hitPoint),toOgreVector3(hitNormal));
//    }
    return true;
}


void Game::log(const Ogre::String &tag, const Ogre::String &message) {
    Ogre::LogManager::getSingletonPtr()->logMessage("ATTN: " + tag + ">>>>>  "+ message);
}


#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        Game app;

        try {
            app.go();
        } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occured: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif
