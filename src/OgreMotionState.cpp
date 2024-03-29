#include "OgreMotionState.h"

OgreMotionState::OgreMotionState(const btTransform &initialpos, Ogre::SceneNode *node) {
    mVisibleobj = node;
    mPos1 = initialpos;
}

OgreMotionState::~OgreMotionState() {
}

void OgreMotionState::setNode(Ogre::SceneNode *node) {
    mVisibleobj = node;
}

void OgreMotionState::getWorldTransform(btTransform &worldTrans) const {
    worldTrans = mPos1;
}

void OgreMotionState::setWorldTransform(const btTransform &worldTrans) {
    if(NULL == mVisibleobj)
        return; // silently return before we set a node
    btQuaternion rot = worldTrans.getRotation();
    mVisibleobj->setOrientation(rot.w(), rot.x(), rot.y(), rot.z());
    btVector3 pos = worldTrans.getOrigin();
    mVisibleobj->setPosition(pos.x(), pos.y(), pos.z());
}
