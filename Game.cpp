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
#include "Game.h"
#include "OgreRectangle2D.h"


using namespace std::chrono;

Game::Game() : OgreBites::ApplicationContext("Simple Platform Game"){

}


void Game::setup(){
	// call the base first.
	OgreBites::ApplicationContext::setup();
	
	//register for input events.
	addInputListener(this);

	//get a pointer to the already created root.
	Ogre::Root* root = getRoot();
	Ogre::SceneManager* scnMgr = root->createSceneManager();

	// Register our scxene with RTSS
	Ogre::RTShader::ShaderGenerator* shaderGen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
	shaderGen->addSceneManager(scnMgr);

	scnMgr->setAmbientLight(Ogre::ColourValue(0.1, 0.7, 0.5));

	//without light we would just get a black screen.
	Ogre::Light* light = scnMgr->createLight("Mainlight");
	Ogre::SceneNode* lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	lightNode->setPosition(0, 0, 15);
	lightNode->attachObject(light);

	//need to tell where we are.
	Ogre::SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	camNode->setPosition(0, 0, 15);
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);
	
	// create the camera
	Ogre::Camera* cam = scnMgr->createCamera("myCam");
	cam->setNearClipDistance(5); // specific to this sample
	cam->setAutoAspectRatio(true);
	camNode->attachObject(cam);
	
	// and tell it to render into the main window
	Ogre::Viewport* vp = getRenderWindow()->addViewport(cam);



	// finally something to render
	/*Ogre::Entity* ent = scnMgr->createEntity("Sinbad.mesh");
	Ogre::SceneNode* node = scnMgr->getRootSceneNode()->createChildSceneNode();
	node->attachObject(ent);*/

	

	//// Create background material
	backGroundImage = Ogre::MaterialManager::getSingleton().create("Background", "General");
	backGroundImage->getTechnique(0)->getPass(0)->createTextureUnitState("Panels_reflection.png");
	backGroundImage->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
	backGroundImage->getTechnique(0)->getPass(0)->setDepthWriteEnabled(false);
	backGroundImage->getTechnique(0)->getPass(0)->setLightingEnabled(false);

	// Create background rectangle covering the whole screen
	rect = new Ogre::Rectangle2D(true);
	rect->setCorners(-1.0, 1.0, 1.0, -1.0);
	rect->setMaterial(backGroundImage);

	// Render the background before everything else
	rect->setRenderQueueGroup(Ogre::RENDER_QUEUE_BACKGROUND);

	// Use infinite AAB to always stay visible
	aabInf.setInfinite();
	rect->setBoundingBox(aabInf);

	// Attach background to the scene
	rectNode = scnMgr->getRootSceneNode()->createChildSceneNode("Background");
	rectNode->attachObject(rect);

	// Intialize game stats.
	
	mThrottleFPSChange = 0;
	mThrottleTPUChange = 0;

	// Instantiate Platforms.

	
	Ogre::Vector3 paddlePos = Ogre::Vector3(0, -2, 0);
	platformA = new Platform(scnMgr, paddlePos);
	
	Ogre::Vector3 paddlePos1 = Ogre::Vector3(2, 2, 0);
	platformB = new Platform(scnMgr, paddlePos1);

	// Instantiate game stats.

	mTrayMgr = new OgreBites::TrayManager("UI", getRenderWindow());
	scnMgr->addRenderQueueListener(Game::getOverlaySystem());

	pFpsLabel = mTrayMgr->createLabel(OgreBites::TrayLocation::TL_TOPLEFT, "FPS", "FPS:", 100);
	pFps = mTrayMgr->createLabel(OgreBites::TrayLocation::TL_TOPLEFT, "fps", "59", 50);
	pTpuLabel = mTrayMgr->createLabel(OgreBites::TrayLocation::TL_TOPLEFT, "Time/Update", "Time/Update:", 100);
	pTpu = mTrayMgr->createLabel(OgreBites::TrayLocation::TL_TOPLEFT, "tpu", "0", 50);

}

bool Game::keyPressed(const OgreBites::KeyboardEvent &evt)
{
	if (evt.keysym.sym == OgreBites::SDLK_ESCAPE)
	{
		getRoot()->queueEndRendering();
		Exit();
	}
	return true;
}

bool Game::frameRenderingQueued(const Ogre::FrameEvent& evt)
{

	mFpsNum = 1 / evt.timeSinceLastFrame;
	mThrottleFPSChange++;
	if (mThrottleFPSChange > 240)
	{
		pFps->setCaption(Ogre::StringConverter::toString(mFpsNum));
		mThrottleFPSChange = 0;
	}
	run();
	return true;
}

void Game::processEvents()
{

}

void Game::run(){
	
	processEvents();
	update();
}

void Game::update(){

	auto start = high_resolution_clock::now();

	// update stuff

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	mTpuNum = duration.count();
	mThrottleTPUChange++;
	if (mThrottleTPUChange > 240)
	{

		pTpu->setCaption(Ogre::StringConverter::toString(mTpuNum));
		mThrottleTPUChange = 0;
	}
}

void Game::Exit()
{
	delete[] rect;
	delete[] mTrayMgr;
}

int main(int argc, char *argv[])
{
	try 
	{
		Game app;
		app.initApp();
		app.getRoot()->startRendering();
		app.closeApp();
	}

	catch(const std::exception& e ) 
	{
		std::cerr << "Error occured during execution: " << e.what() << '\n';
		return 1;
	}
	return 0;
}
