#pragma once
#include "button.h"

#include "sceneManager.h"

#include "Player.h"
#include "Obstacle.h"

class Play
{
private:
	sceneManager* manager;
	Player* player;
	Player* player2;
	Obstacle* obstacle;
	Obstacle* obstacle2;
	Obstacle* obstacle3;

	Image bird;
	Image bird2;
	Texture2D texture;
	Texture2D texture2;

	bool pause = false;
public:
	Play();
	~Play();
	void setSceneManager(sceneManager* manager);
	void playUpdate();
	void playDraw();
};