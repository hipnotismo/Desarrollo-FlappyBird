#include "Play.h"

Play::Play() 
{
	Rectangle rec;
	Color color;
	

	rec.x = GetScreenWidth() / 20;
	rec.y = GetScreenHeight() / 2;
	rec.width = 40;
	rec.height = 40;
	color = GREEN;

	Player* player = new Player(rec, color);
}

void Play::setSceneManager(sceneManager* manager)
{
	this->manager = manager;
}

Play::~Play()
{

}

void Play::playUpdate()
{
	
}

void Play::playDraw()
{
	BeginDrawing();
	ClearBackground(RED);
	player->draw();
	DrawTextEx(GetFontDefault(), "Funco", { (float)GetScreenWidth() / 4, (float)GetScreenHeight() / 6 }, 30.0f, 5.0f, YELLOW);
	
	EndDrawing();
}