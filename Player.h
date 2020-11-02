#pragma once
#include<Ogre.h>
#include "Physics.h"

class Player : public Physics
{

private:

	float mPlayerSpeed;
	float xVelocity;
	float yVelocity;
	float maxJump = 1;
	bool isJumping = false;
	bool isFalling = false;
	bool allowedToJump = true;
	bool isOnGround = false; 

	Ogre::Vector3 mPosition;
	Ogre::Entity* pPlayer;
	Ogre::MaterialPtr pPlayerM; 
	Ogre::SceneNode* pPlayerNode;
	Ogre::AxisAlignedBox mPlayerBoundingBox;



public:

	Player() {};
	Player(Ogre::SceneManager* scnMan, Ogre::Vector3 _pos);
	~Player() {};

	void MoveLeft();
	void MoveRight();
	void Jump();
	void Update();

	bool getIsFalling();
	bool getIsAllowedToJump();
	bool getIsJumping();
	float getXVelocity();
	float getYVelocity();
	Ogre::Vector3 getPosition();
	Ogre::AxisAlignedBox getAABB();

	void setXVelocity(float xVol);
	void setYVelocity(float yVol);
	void setIsFalling(bool boolean);
	void setAllowedToJump(bool boolean);
	void setisJumping(bool boolean);

};

