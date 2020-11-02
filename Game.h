/***********************************************************************;
* Project            : Single Player Paddle Game
*
* Program name       : "Game.h"
*
* Author             : David Gasinec
*
* Student Number     : 101187910
*
* Date created       : 20/10/09
*
* Description        : Methods and attributes of the Game.
*
* Last modified      : 20/10/28
*
* Revision History   :
*
* Date        Author Ref    Revision (Date in YYYYMMDD format)
* 20/10/28    David Gasinec       Created script
*
|**********************************************************************/
#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include "OgreFont.h"
#include "OgreTrays.h"
#include <iostream>
#include <string>
#include "Platform.h"
#include "Player.h"



class Game : public OgreBites::ApplicationContext, public OgreBites::InputListener {

private: 

    int mFpsNum;
    int mThrottleFPSChange;
    int mThrottleTPUChange;
    int mTpuNum;
    int mPlayerScore = 0;

    Ogre::Root* root;
   
    OgreBites::TrayManager* mTrayMgr;
    OgreBites::TrayListener myTrayListener;
    OgreBites::Label* pTpuLabel;
    OgreBites::Label* pTpu;
    OgreBites::Label* pFpsLabel;
    OgreBites::Label* pFps; 
    OgreBites::Label* playerLb;
    OgreBites::Label* playerSc;

    Ogre::MaterialPtr backGroundImage;
    Ogre::Rectangle2D* rect;
    Ogre::SceneNode* rectNode;
    Ogre::AxisAlignedBox aabInf;

    Player* playerCharacter;
    Platform* floor;
    Platform* platformA;
    Platform* platformB;

public:
    Game();
    ~Game();
   // virtual ~Game() {}

    void setup();
    bool keyPressed(const OgreBites::KeyboardEvent& evt);
    bool frameRenderingQueued(const Ogre::FrameEvent& evt);
    void processEvents();
    void run();
    void update();
};
