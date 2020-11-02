/***********************************************************************;
* Project            : Simple Platform Game
*
* Program name       : "Jump Jump"
*
* Author             : David Gasinec
*
* Student Number     : 101187910
*
* Date created       : 20/10/28
*
* Description        : Simple pong game in OGRE.
*
* Last modified      : 20/10/28
*
* Revision History   :
*
* Date        Author Ref    Revision (Date in YYYYMMDD format)
* 20/10/10    David Gasinec        Created Script.
*
|**********************************************************************/
#pragma once
#include "Ogre.h"

class Platform
{
private:
	
	Ogre::Vector3 mPosition;
	Ogre::Entity* pPlatform;
	Ogre::SceneNode* pPlatformNode;
	Ogre::AxisAlignedBox mPlatformBoundingBox;

public:

	Platform();
	Platform(Ogre::SceneManager* scnMan, Ogre::Vector3 pos, float xScale, float yScale, float zScale);
	~Platform(){}

	Ogre::Vector3 getPosition();


};

