#ifndef OGREBULLETCONVERTER_H_INCLUDED
#define OGREBULLETCONVERTER_H_INCLUDED

class OgreBulletConverter {

public:
    OgreBulletConverter(){};
    ~OgreBulletConverter(){};
    static btVector3 convert(const Ogre::Vector3& V) {
        return btVector3(V.x, V.y, V.z);
    };


};

#endif // OGREBULLETCONVERTER_H_INCLUDED
