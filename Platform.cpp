#include "Platform.h"

Platform::Platform(Ogre::SceneManager* scnMan, Ogre::Vector3 _pos)
{
	mPosition = _pos;
	pPlatform = scnMan->createEntity(Ogre::SceneManager::PrefabType::PT_PLANE);
	pPlatformNode = scnMan->getRootSceneNode()->createChildSceneNode();
	pPlatformNode->setPosition(mPosition);
	pPlatformNode->setScale(0.02, 0.001f, 0.0f);
	pPlatformNode->attachObject(pPlatform);
	mPlatformBoundingBox = pPlatform->getWorldBoundingBox(true);
}

Platform::Platform()
{
}





