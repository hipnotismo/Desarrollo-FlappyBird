#include "MainMenu.h"

MainMenu::MainMenu()
{
	this->playButton = new Button(200.0f, 60.0f, 1280 / 2 - 100.0f, 720 - 300.0f, BLUE, RED);
	this->creditsButton = new Button(260.0f, 60.0f, 1280 / 2 - 130.0f, 720 - 200.0f, BLUE, RED);
	this->exitButton = new Button(200.0f, 60.0f, 1280 / 2 - 100.0f, 720 - 100.0f, BLUE, RED);
	this->cover = LoadImage("Res/convine.png");
	ImageResize(&cover, 1280, 720);
	this->texture = LoadTextureFromImage(cover);
}
MainMenu::~MainMenu()
{
	delete playButton;
	delete creditsButton;
	delete exitButton;
}
void MainMenu::setSceneManager(sceneManager* manager)
{
	this->manager = manager;
}
void MainMenu::mainMenuUpdate()
{
	if (playButton->isButtonPressed())
	{
		manager->changeScene(Scene::Play);
	}
	else if (creditsButton->isButtonPressed())
	{
		manager->changeScene(Scene::Credits);
	}
	else if (exitButton->isButtonPressed())
	{
		manager->changeScene(Scene::Exit);
	}
}
void MainMenu::mainMenuDraw()
{
	BeginDrawing();
	ClearBackground(DARKGREEN);
	DrawTexture(texture,0, 0, WHITE);
	playButton->drawButton();
	DrawTextEx(GetFontDefault(), "Play", { playButton->getButtonX() + 40.0f, playButton->getButtonY() }, 60.0f, 5.0f, YELLOW);
	creditsButton->drawButton();
	DrawTextEx(GetFontDefault(), "Credits", { creditsButton->getButtonX() + 30.0f, creditsButton->getButtonY() }, 60.0f, 5.0f, YELLOW);
	exitButton->drawButton();
	DrawTextEx(GetFontDefault(), "Exit", { exitButton->getButtonX() + 40.0f, exitButton->getButtonY() }, 60.0f, 5.0f, YELLOW);
	EndDrawing();
}