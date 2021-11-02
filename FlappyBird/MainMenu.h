#pragma once
#include "button.h"
#include "sceneManager.h"

class MainMenu
{
private:
	sceneManager* manager;
	Button* playButton;
	Button* creditsButton;
	Button* exitButton;
	Image cover;
	Texture2D texture;
public:
	MainMenu();
	~MainMenu();
	void setSceneManager(sceneManager* manager);
	void mainMenuUpdate();
	void mainMenuDraw();
};

