#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"
#include "OgreMotionState.h"

class Player
{
    public:
        Player(Ogre::Camera* camera, Game* game);
        virtual ~Player();
        void init(const Ogre::Vector3& spawnPoint);
        void mouseMoved(const OIS::MouseEvent &evt);
        void handleUnbufferedInputs(const Ogre::FrameEvent& evt, OIS::Keyboard* keyboard);
        void update(Ogre::Real deltaTime);

    protected:
    private:
        Game* mGame;

        Ogre::Vector3* mDirection;
        Ogre::Vector3* mSpeed;

        Ogre::Camera* mCamera;
        Ogre::SceneNode* mPlayerRBSN;
        Ogre::SceneNode* mPlayerSN;
        Ogre::Entity* mPlayerEntity;
        Ogre::SceneNode* mCamSN;

        btRigidBody* mRigidBody;


};

#endif // PLAYER_H
