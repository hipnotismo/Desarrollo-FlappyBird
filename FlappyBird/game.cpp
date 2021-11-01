#include "game.h"

void playGame()
{
	const int windowWidth = 1280;
	const int windowHeight = 720;
	InitWindow(windowWidth, windowHeight, "Flappy Loli");
	sceneManager* manager =  new sceneManager();
	MainMenu* mainMenuScene = new MainMenu();
	Credits* creditsScene = new Credits();
	Play* playScene = new Play();
	bool mainMenuInited = false;
	bool creditsInited = false;
	bool playInited = false;
	manager->changeScene(Scene::MainMenu);
	while (!WindowShouldClose())
	{
		switch (manager->getCurrentScene())
		{
		case Scene::MainMenu:
			if (!mainMenuInited)
			{
				mainMenuScene->setSceneManager(manager);
				mainMenuInited = true;
			}
			mainMenuScene->mainMenuUpdate();
			mainMenuScene->mainMenuDraw();
			break;
		case Scene::Credits:
			if (!creditsInited)
			{				
				creditsScene->setSceneManager(manager);
				creditsInited = true;
			}
			creditsScene->creditsUpdate();
			creditsScene->creditsDraw();
			break;
		case Scene::Play:
			if (!playInited)
			{
				playScene->setSceneManager(manager);
				playInited = true;
			}
			playScene->playUpdate();
			playScene->playDraw();
			break;
		case Scene::Exit:
			break;
		default:
			break;
		}
	}
	delete manager;
	delete creditsScene;
	delete mainMenuScene;
}