#include "Play.h"

Play::Play() 
{
	Rectangle rec;
	Color color;
	

	rec.x = GetScreenWidth() / 2;
	rec.y = GetScreenHeight() / 2;
	rec.width = 40;
	rec.height = 40;
	color = GREEN;

	this->player = new Player(rec, color);
}

void Play::setSceneManager(sceneManager* manager)
{
	this->manager = manager;
}

Play::~Play()
{
	delete player;
}

void Play::playUpdate()
{
	player->movementOnePlayer();
}

void Play::playDraw()
{
	BeginDrawing();
	ClearBackground(RED);
	player->draw();
	DrawTextEx(GetFontDefault(), "Funco", { (float)GetScreenWidth() / 4, (float)GetScreenHeight() / 6 }, 30.0f, 5.0f, YELLOW);
	
	EndDrawing();
}