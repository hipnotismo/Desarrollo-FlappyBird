#include "Play.h"
#include <iostream>

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
	std::cout << rec.x << std::endl;
	std::cout << rec.y << std::endl;

	this->obstacle = new Obstacle();

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
	obstacle->movement();
	obstacle->respawn();
	/*
	if (CheckCollisionRecs(player->getRec(), obstacle->getRecTop()))
		manager->changeScene(Scene::MainMenu);

	if (CheckCollisionRecs(player->getRec(), obstacle->getRecBot()))
		manager->changeScene(Scene::MainMenu);
	*/
}

void Play::playDraw()
{
	BeginDrawing();
	ClearBackground(RED);
	player->draw();
	obstacle->draw();
	DrawTextEx(GetFontDefault(), "Funco", { (float)GetScreenWidth() / 4, (float)GetScreenHeight() / 6 }, 30.0f, 5.0f, YELLOW);
	
	EndDrawing();
}