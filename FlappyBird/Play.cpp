#include "Play.h"
#include <iostream>

Play::Play() 
{
	Rectangle rec;
	Color color;
	Color color2;

	Rectangle recTop;
	Rectangle recBot;
	int gap = 90;
	
	rec.x = GetScreenWidth() / 2;
	rec.y = GetScreenHeight() / 2;
	rec.width = 40;
	rec.height = 40;
	color = GREEN;

	
	recTop.width = GetScreenWidth() / 10;
	recTop.height = (GetScreenHeight() / 2) - gap;
	recTop.x = GetScreenWidth() + 100;
	recTop.y = 0;

	recBot.width = GetScreenWidth() / 10;
	recBot.height = (GetScreenHeight() / 2) + gap;
	recBot.x = GetScreenWidth() + 100;
	recBot.y = (GetScreenHeight() / 2) + gap;
	color2 = WHITE;
	this->player = new Player(rec, color);
	this->obstacle = new Obstacle(recTop, recBot,color2);

	std::cout << rec.x << std::endl;
	std::cout << rec.y << std::endl;

}

void Play::setSceneManager(sceneManager* manager)
{
	this->manager = manager;
}

Play::~Play()
{
	delete player;
	delete obstacle;
}

void Play::playUpdate(){
	if (IsKeyPressed('P')) pause = !pause;

	if (!pause)
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
}

void Play::playDraw()
{
	BeginDrawing();
	ClearBackground(RED);
	player->draw();
	obstacle->draw();

	EndDrawing();
}