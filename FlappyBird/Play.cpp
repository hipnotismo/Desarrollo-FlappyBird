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
	UnloadImage(bird);

	this->bird2 = LoadImage("Res/Transparent PNG/frame-2.png");
	ImageResize(&bird2, 40, 40);
	this->texture2 = LoadTextureFromImage(bird2);
	UnloadImage(bird2);

	int gap = 50;
	//moving background
	this->back = LoadImage("Res/11_background.png");
	ImageResize(&back, 1280, 720);
	this->background = LoadTextureFromImage(back);
	UnloadImage(back);

	this->mid = LoadImage("Res/03_distant_trees.png");
	ImageResize(&mid, 1280, 720);
	this->midground = LoadTextureFromImage(mid);
	UnloadImage(mid);


	this->mod = LoadImage("Res/02_trees and bushes.png");
	ImageResize(&mod, 1280, 720);
	this->modground = LoadTextureFromImage(mod);
	UnloadImage(mod);

	this->fore = LoadImage("Res/01_ground.png");
	ImageResize(&fore, 1280, 720);
	this->foreground = LoadTextureFromImage(fore);
	UnloadImage(fore);

	scrollingBack = 0.0f;
	scrollingMid = 0.0f;
	scrollingFore = 0.0f;


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
	this->player2 = new Player(rec2, RED, texture, texture2);

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

	recTop3.width = GetScreenWidth() / 10;
	recTop3.height = (GetScreenHeight() / 2) - gap;
	recTop3.x = GetScreenWidth() + 1100;
	recTop3.y = -100;

	recBot3.width = GetScreenWidth() / 10;
	recBot3.height = (GetScreenHeight() / 2) + gap;
	recBot3.x = GetScreenWidth() + 1100;
	recBot3.y = (GetScreenHeight() / 2) - 100 + gap;
	color2 = WHITE;


	this->obstacle = new Obstacle(recTop, recBot,color2);
	this->obstacle2 = new Obstacle(recTop2, recBot2, color2);
	this->obstacle3 = new Obstacle(recTop3, recBot3, color2);

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
	delete obstacle3;
}

void Play::playUpdate() {
	if (IsKeyPressed('P')) pause = !pause;
		
	if (IsKeyPressed('M')) multy = !multy;

	if (pause)
	{
		scrollingBack -= 0.1f;
		scrollingMid -= 0.5f;
		scrollingFore -= 1.0f;

		if (scrollingBack <= -background.width * 2) scrollingBack = 0;
		if (scrollingMid <= -midground.width * 2) scrollingMid = 0;
		if (scrollingFore <= -foreground.width * 2) scrollingFore = 0;

		player->movementOnePlayer();
		obstacle->movement();
		obstacle2->movement();
		obstacle->respawn();
		obstacle2->respawn();
		if (multy) {
			player2->movementTwoPlayers();
			if (CheckCollisionRecs(player->getRec(), obstacle->getRecTop()))
			{

				manager->changeScene(Scene::MainMenu);
			}

			if (CheckCollisionRecs(player->getRec(), obstacle->getRecBot())) {
				manager->changeScene(Scene::MainMenu);
			}
			if (CheckCollisionRecs(player->getRec(), obstacle2->getRecTop()))
			{

				manager->changeScene(Scene::MainMenu);
			}

			if (CheckCollisionRecs(player->getRec(), obstacle2->getRecBot())) {
				manager->changeScene(Scene::MainMenu);
			}
			if (CheckCollisionRecs(player->getRec(), obstacle3->getRecTop()))
			{

				manager->changeScene(Scene::MainMenu);
			}

			if (CheckCollisionRecs(player->getRec(), obstacle3->getRecBot())) {
				manager->changeScene(Scene::MainMenu);
			}
		}
		
		if (CheckCollisionRecs(player->getRec(), obstacle->getRecTop()))
		{
			
			manager->changeScene(Scene::MainMenu);
		}

		if (CheckCollisionRecs(player->getRec(), obstacle->getRecBot())) {
			manager->changeScene(Scene::MainMenu);
		}

		if (CheckCollisionRecs(player->getRec(), obstacle2->getRecTop()))
		{

			manager->changeScene(Scene::MainMenu);
		}

		if (CheckCollisionRecs(player->getRec(), obstacle2->getRecBot())) {
			manager->changeScene(Scene::MainMenu);
		}

		if (CheckCollisionRecs(player->getRec(), obstacle3->getRecTop()))
		{

			manager->changeScene(Scene::MainMenu);
		}

		if (CheckCollisionRecs(player->getRec(), obstacle3->getRecBot())) {
			manager->changeScene(Scene::MainMenu);
		}

	}

	
}

void Play::playDraw()
{
	BeginDrawing();
	ClearBackground(RED);
	DrawTextureEx(background, {scrollingBack, 0 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(background, { background.width * 2 + scrollingBack, 0 }, 0.0f, 2.0f, WHITE);

	DrawTextureEx(midground,  { scrollingMid, -500 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(midground,  { midground.width * 2 + scrollingMid, -500 }, 0.0f, 2.0f, WHITE);

	DrawTextureEx(modground, { scrollingMid, -500 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(modground, { modground.width * 2 + scrollingMid, -500 }, 0.0f, 2.0f, WHITE);

	//DrawTextureEx(foreground,  { scrollingFore, -700 }, 0.0f, 0.0f, WHITE);
//	DrawTextureEx(foreground,  { foreground.width * 2 + scrollingFore, -700 }, 0.0f, 2.0f, WHITE);

	player->draw();
	obstacle->draw();
	obstacle2->draw();
	obstacle3->draw();

	if (!pause) {
		DrawText("Pres P to start the game", 10, 10, 20, RED);
		DrawText("Use Q to control the first character", 10, 30, 20, RED);
		DrawText("Use E to control the second character", 10, 50, 20, RED);
		DrawText("Pres M to activate two palyer mode", 10, 70, 20, RED);

	}
	if (multy) {
		player2->draw();

	}
	EndDrawing();
}
