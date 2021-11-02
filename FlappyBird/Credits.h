#pragma once
#include "button.h"
#include "sceneManager.h"

class Credits
{
private:
	sceneManager* manager;
	Button* backButton;
	Image cover;
	Texture2D texture;
public:
	Credits();
	~Credits();
	void setSceneManager(sceneManager* manager);
	void creditsUpdate();
	void creditsDraw();	
};

