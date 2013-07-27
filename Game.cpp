#include "Game.h"
#include "ChunkManager.h"

static const Ogre::String TAG = "Game";

//-------------------------------------------------------------------------------------
Game::Game(void) :
    mLandscape(new Landscape()),
    mChunkManager(new ChunkManager(this)) {
}
//-------------------------------------------------------------------------------------
Game::~Game(void) {
}

//void Game::createCamera(void) {
//    mCamera = mSceneMgr->createCamera("PlayerCam");
//    mCamera->setNearClipDistance(0.5f);
//    mCamera->setFarClipDistance(600);
//    mCamera->lookAt(0, 0, -300);
//}

//-------------------------------------------------------------------------------------
void Game::createScene(void) {
    log(TAG, "Creating scene...");
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
    directionalLight->setDiffuseColour(Ogre::ColourValue(.8, .8, .8));
    directionalLight->setSpecularColour(Ogre::ColourValue(.8, .8, .8));
    directionalLight->setDirection(Ogre::Vector3(0, -1, 0));
    directionalLight->setPosition(0, 1000000, 0);
    // Shadow
//    mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_MODULATIVE);

    mChunkManager->createChunk(0,0,0);

    log(TAG, "Done creating scene...");
}

Ogre::SceneNode* Game::createSceneNode(const Ogre::Vector3& position,
                                       const Ogre::Quaternion& orientation) {
    return mSceneMgr->getRootSceneNode()->createChildSceneNode(position, orientation);
}

Ogre::SceneNode* Game::createSceneNode(const Ogre::String& name, const Ogre::Vector3& position,
                                       const Ogre::Quaternion& orientation) {
    return mSceneMgr->getRootSceneNode()->createChildSceneNode(name, position, orientation);
}

Landscape* Game::getLandscape() {
    return mLandscape;
}

void Game::log(const Ogre::String &tag, const Ogre::String &message) {
    Ogre::LogManager::getSingletonPtr()->logMessage(tag + message);
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
