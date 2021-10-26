#include "Play.h"

Play::Play() 
{

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
	DrawTextEx(GetFontDefault(), "Funco", { (float)GetScreenWidth() / 4, (float)GetScreenHeight() / 6 }, 30.0f, 5.0f, YELLOW);
	
	EndDrawing();
}