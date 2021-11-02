#include "Play.h"
#include <iostream>

Play::Play() 
{
	//player
	Rectangle rec;
	Rectangle rec2;
	Color color;
	Color color2;
	//obstacles
	Rectangle recTop;
	Rectangle recBot;

	Rectangle recTop2;
	Rectangle recBot2;

	Rectangle recTop3;
	Rectangle recBot3;
	//textures
	this->bird = LoadImage("Res/Transparent PNG/frame-1.png");
	ImageResize(&bird, 40, 40);
	this->texture = LoadTextureFromImage(bird);

	this->bird2 = LoadImage("Res/Transparent PNG/frame-2.png");
	ImageResize(&bird2, 40, 40);
	this->texture2 = LoadTextureFromImage(bird2);

	int gap = 90;
	//player 1
	rec.x = GetScreenWidth() / 2;
	rec.y = GetScreenHeight() / 2;
	rec.width = 40;
	rec.height = 40;
	color = GREEN;
	this->player = new Player(rec, color, texture, texture2);

	//player 2
	rec2.x = GetScreenWidth() / 3;
	rec2.y = GetScreenHeight() / 2;
	rec2.width = 40;
	rec2.height = 40;
	color = GREEN;
	this->player2 = new Player(rec2, color, texture, texture2);
	//obs 1
	recTop.width = GetScreenWidth() / 10;
	recTop.height = (GetScreenHeight() / 2) - gap;
	recTop.x = GetScreenWidth() + 100;
	recTop.y = 0;

	recBot.width = GetScreenWidth() / 10;
	recBot.height = (GetScreenHeight() / 2) + gap;
	recBot.x = GetScreenWidth() + 100;
	recBot.y = (GetScreenHeight() / 2) + gap;
	color2 = WHITE;

	//obs 2
	recTop2.width = GetScreenWidth() / 10;
	recTop2.height = (GetScreenHeight() / 2) - gap;
	recTop2.x = GetScreenWidth() + 600;
	recTop2.y = -100;

	recBot2.width = GetScreenWidth() / 10;
	recBot2.height = (GetScreenHeight() / 2) + gap;
	recBot2.x = GetScreenWidth() + 600;
	recBot2.y = (GetScreenHeight() / 2) - 100 + gap;
	color2 = WHITE;

	this->obstacle = new Obstacle(recTop, recBot,color2);
	this->obstacle2 = new Obstacle(recTop2, recBot2, color2);
	//this->obstacle3 = new Obstacle(recTop3, recBot3, color2);

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
	delete player2;
	delete obstacle;
	delete obstacle2;
	//delete obstacle3;
}

void Play::playUpdate(){
	if (IsKeyPressed('P')) pause = !pause;

	if (!pause)
	{
		player->movementOnePlayer();
		player2->movementTwoPlayers();
		obstacle->movement();
		obstacle2->movement();
		obstacle->respawn();
		obstacle2->respawn();

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
	player2->draw();
	obstacle->draw();
	obstacle2->draw();

	EndDrawing();
}