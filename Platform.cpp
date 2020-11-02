#include "Platform.h"

Platform::Platform(Ogre::SceneManager* scnMan, Ogre::Vector3 _pos, float xScale, float yScale, float zScale)
{
	mPosition = _pos;
	pPlatform = scnMan->createEntity(Ogre::SceneManager::PrefabType::PT_PLANE);
	pPlatformNode = scnMan->getRootSceneNode()->createChildSceneNode();
	pPlatformNode->setPosition(mPosition);
	pPlatformNode->setScale(xScale, yScale, zScale);
	pPlatformNode->attachObject(pPlatform);
	//mPlatformBoundingBox = pPlatform->getWorldBoundingBox(true);
}







