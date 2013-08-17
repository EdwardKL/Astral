#include "Player.h"

Player::Player(Ogre::Camera* camera, Game* game) :
    mCamera(camera),
    mGame(game),
    mDirection(new Ogre::Vector3(0,0,0)),
    mSpeed(new Ogre::Vector3(500,100,500)) {
}

Player::~Player() {
}

void Player::init(const Ogre::Vector3& spawnPoint) {
    // For the player's rigidbody
    mPlayerRBSN = mGame->createSceneNode(spawnPoint);
    // For the player's mesh
    mPlayerSN = mPlayerRBSN->createChildSceneNode(Ogre::Vector3(0,-4,0));
    // Create the player's mesh
    mPlayerEntity = mGame->createEntity("robot.mesh");
    mPlayerSN->attachObject(mPlayerEntity);
    mPlayerSN->scale(Ogre::Vector3(0.1f,0.1f,0.1f));
    // Put the cam node slightly behind the player
    mCamSN = mPlayerSN->createChildSceneNode(Ogre::Vector3(0, mPlayerEntity->getBoundingBox().getSize().y * 7 / 10, 0));
    // the following is an attempt at a 3rd person view, but it isn't working atm.
    //mCamSN = mPlayerSN->createChildSceneNode(Ogre::Vector3(-100, mPlayerEntity->getBoundingBox().getSize().y, 0));
    mCamSN->yaw(Ogre::Degree(-90), Ogre::Node::TS_WORLD);
    mCamSN->attachObject(mCamera);
    // Now for the bullet stuff
    btCapsuleShape* cs = new btCapsuleShape(1, // radius
                                            6); // height
    btVector3 inertia = btVector3(0,0,0);
    int mass = 100;
    cs->calculateLocalInertia(mass, inertia);
    OgreMotionState* ms = new OgreMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(spawnPoint.x,spawnPoint.y,spawnPoint.z)), mPlayerRBSN);
    mRigidBody = new btRigidBody(btRigidBody::btRigidBodyConstructionInfo(mass,ms,cs,inertia));
    mRigidBody->setAngularFactor(0.0);
    mRigidBody->setActivationState(DISABLE_DEACTIVATION);
    mGame->addRigidBody(mRigidBody);

}


void Player::mouseMoved(const OIS::MouseEvent &evt) {
    static Ogre::Real rotationSpeed = 0.13;

    mPlayerSN->yaw(Ogre::Degree(-rotationSpeed * evt.state.X.rel), Ogre::Node::TS_WORLD);
    //mHeadNode->pitch(Ogre::Degree(-mRotate * evt.state.Y.rel), Ogre::Node::TS_LOCAL);
    mCamSN->pitch(Ogre::Degree(-rotationSpeed * evt.state.Y.rel), Ogre::Node::TS_LOCAL);
}

void Player::handleUnbufferedInputs(const Ogre::FrameEvent& evt, OIS::Keyboard* keyboard) {
    mDirection->x = 0;
    mDirection->y = 0;
    mDirection->z = 0;
    if (keyboard->isKeyDown(OIS::KC_W)) {
        mDirection->z = -1;
    }
    if (keyboard->isKeyDown(OIS::KC_A)) {
        mDirection->x = -1;
    }
    if (keyboard->isKeyDown(OIS::KC_D)) {
        mDirection->x = 1;
    }
    if (keyboard->isKeyDown(OIS::KC_S)) {
        mDirection->z = 1;
    }
//    if (keyboard->isKeyDown(OIS::KC_LSHIFT)) {
//        mCharacterState->setKeyDirectionY(-1);
//        mIsMoving = true;
//    }
    if (keyboard->isKeyDown(OIS::KC_SPACE)) {
        // Jump
        mDirection->y = 1;
    }
}

void Player::update(Ogre::Real deltaTime) {
    Ogre::Vector3 direction(mPlayerSN->getOrientation() * Ogre::Quaternion(Ogre::Degree(-90), Ogre::Vector3::UNIT_Y) * (*mDirection * *mSpeed) * deltaTime*10);
    mRigidBody->setLinearVelocity(btVector3(direction.x, mRigidBody->getLinearVelocity().getY(), direction.z));
}
