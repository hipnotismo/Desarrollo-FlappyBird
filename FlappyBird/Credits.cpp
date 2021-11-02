#include "Credits.h"


Credits::Credits()
{
	this->backButton = new Button(200.0f, 60.0f, 1280 / 2 - 100.0f, 720 - 200.0f, BLUE, RED);
	this->cover = LoadImage("Res/convine.png");
	ImageResize(&cover, 1280, 720);
	this->texture = LoadTextureFromImage(cover);
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
	DrawTexture(texture, 0, 0, WHITE);

	DrawTextEx(GetFontDefault(), "Dev 0.1,0.2: Francisco Sanchez", { (float)GetScreenWidth() / 4, (float)GetScreenHeight() / 6 }, 30.0f, 5.0f, YELLOW);
	DrawTextEx(GetFontDefault(), "Dev V0.3,1.0: Martin Concetti", { (float)GetScreenWidth() / 4, (float)GetScreenHeight() / 6 + 30 }, 30.0f, 5.0f, YELLOW);

	DrawTextEx(GetFontDefault(), "Art: itch.io", { (float)GetScreenWidth() / 4, (float)GetScreenHeight() / 6 + (float)GetScreenHeight() / 6 }, 30.0f, 5.0f, YELLOW);
	backButton->drawButton();	
	DrawTextEx(GetFontDefault(), "Back", { backButton->getButtonX() + 30.0f, backButton->getButtonY() }, 60.0f, 5.0f, YELLOW);
	EndDrawing();
}
