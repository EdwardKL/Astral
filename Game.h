#pragma once
#ifndef __Game_h_
#define __Game_h_

#include "BaseApplication.h"
#include "Landscape.h"

class ChunkManager;

class Game : public BaseApplication
{
public:
    Game(void);
    virtual ~Game(void);
    static void log(const Ogre::String &tag, const Ogre::String &message);
    Ogre::SceneNode* createSceneNode(const Ogre::Vector3& position = Ogre::Vector3::ZERO,
                                     const Ogre::Quaternion& orientation =
                                             Ogre::Quaternion::IDENTITY);
    Ogre::SceneNode* createSceneNode(const Ogre::String& name, const Ogre::Vector3& position =
                                             Ogre::Vector3::ZERO,
                                     const Ogre::Quaternion& orientation =
                                             Ogre::Quaternion::IDENTITY);
    Landscape* getLandscape();

protected:
    virtual void createScene(void);
//    virtual void createCamera(void);

private:
    ChunkManager* mChunkManager;
    Landscape* mLandscape;
};

#endif // #ifndef __Game_h_
