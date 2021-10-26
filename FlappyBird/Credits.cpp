#include "Credits.h"


Credits::Credits()
{
	this->backButton = new Button(200.0f, 60.0f, 1280 / 2 - 100.0f, 720 - 200.0f, BLUE, RED);
}

void Credits::setSceneManager(sceneManager* manager)
{
	this->manager = manager;
}

Credits::~Credits()
{
	delete backButton;
}

void Credits::creditsUpdate()
{
	if (backButton->isButtonPressed())
	{
		manager->changeScene(Scene::MainMenu);
	}
}

void Credits::creditsDraw()
{
	BeginDrawing();
	ClearBackground(DARKGREEN);
	DrawTextEx(GetFontDefault(), "Dev: Francisco Sanchez", { (float)GetScreenWidth() / 4, (float)GetScreenHeight() / 6 }, 30.0f, 5.0f, YELLOW);
	DrawTextEx(GetFontDefault(), "Dev V0.3: Martin Concetti", { (float)GetScreenWidth() / 4, (float)GetScreenHeight() / 6 + 30 }, 30.0f, 5.0f, YELLOW);

	DrawTextEx(GetFontDefault(), "Art: Nashe", { (float)GetScreenWidth() / 4, (float)GetScreenHeight() / 6 + (float)GetScreenHeight() / 6 }, 30.0f, 5.0f, YELLOW);
	DrawTextEx(GetFontDefault(), "Voice: Juan Ignacio Ranedo", { (float)GetScreenWidth() / 4, (float)GetScreenHeight() / 6 + ((float)GetScreenHeight() / 6)*2 }, 30.0f, 5.0f, YELLOW);
	backButton->drawButton();	
	DrawTextEx(GetFontDefault(), "Back", { backButton->getButtonX() + 30.0f, backButton->getButtonY() }, 60.0f, 5.0f, YELLOW);
	EndDrawing();
}
