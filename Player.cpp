#include "Player.h"
#include "Platform.h"

Player::Player(Ogre::SceneManager* scnMan, Ogre::Vector3 _pos)
{
	mPlayerSpeed = 1.5f;
	mPosition = _pos;
	pPlayer = scnMan->createEntity("penguin.mesh");
	pPlayerNode = scnMan->getRootSceneNode()->createChildSceneNode();
	pPlayerNode->setPosition(mPosition);
	pPlayerNode->setScale(0.03, 0.03, 0.0f);
	pPlayerNode->attachObject(pPlayer);
	//mPlayerBoundingBox = pPlayer->getWorldBoundingBox(true);
}



void Player::MoveLeft()
{
	Ogre::Vector3 newPosition = pPlayerNode->getPosition() - Ogre::Vector3(0.5 * mPlayerSpeed, 0, 0);
	pPlayerNode->setPosition(newPosition);
}

void Player::MoveRight()
{
	Ogre::Vector3 newPosition = pPlayerNode->getPosition() - Ogre::Vector3(-0.5 * mPlayerSpeed, 0, 0);
	pPlayerNode->setPosition(newPosition);
}

void Player::Jump()
{
	Ogre::Vector3 newPosition = pPlayerNode->getPosition() + Ogre::Vector3(0, 0.7 * mPlayerSpeed, 0);
	pPlayerNode->setPosition(newPosition);
}

bool Player::getIsFalling()
{
	return isFalling;
}

bool Player::getIsAllowedToJump()
{
	return allowedToJump;
}

bool Player::getIsJumping()
{
	return isJumping;
}

float Player::getXVelocity()
{
	return xVelocity;
}

float Player::getYVelocity()
{
	return yVelocity;
}

Ogre::Vector3 Player::getPosition()
{
	return Ogre::Vector3();
}

Ogre::AxisAlignedBox Player::getAABB()
{
	return pPlayer->getWorldBoundingBox(true);
}

void Player::setXVelocity(float xVol)
{
	xVol = xVelocity;
}

void Player::setYVelocity(float yVol)
{
	yVol = yVelocity;
}

void Player::setIsFalling(bool boolean)
{
	isFalling = boolean;
}

void Player::setAllowedToJump(bool boolean)
{
	allowedToJump = boolean;
}

void Player::setisJumping(bool boolean)
{
	isJumping = boolean; 
}



void Player::Update()
{
	if (pPlayerNode->getPosition().x < -11) 
	{

		pPlayerNode->setPosition(-10.9, pPlayerNode->getPosition().y, pPlayerNode->getPosition().z);
	}

	if (pPlayerNode->getPosition().x > 11)
	{
		pPlayerNode->setPosition(10.9, pPlayerNode->getPosition().y, pPlayerNode->getPosition().z);
	}

	//This code will never execute because there is no gravity yet. 
	if (pPlayerNode->getPosition().y <= -5)
	{
		isOnGround = true;
		pPlayerNode->setPosition(pPlayerNode->getPosition().x, 4.99, pPlayerNode->getPosition().z);
	}
}
