#ifndef OGREMOTIONSTATE_H
#define OGREMOTIONSTATE_H

#include <OgreSceneNode.h>
#include "LinearMath/btMotionState.h"

class OgreMotionState : public btMotionState
{
    public:
        OgreMotionState(const btTransform &initialpos, Ogre::SceneNode *node);
        virtual ~OgreMotionState();
        virtual void setWorldTransform(const btTransform &worldTrans);
        virtual void getWorldTransform(btTransform &worldTrans) const;
        void setNode(Ogre::SceneNode *node);
    protected:
        Ogre::SceneNode *mVisibleobj;
        btTransform mPos1;
    private:
};

#endif // OGREMOTIONSTATE_H
