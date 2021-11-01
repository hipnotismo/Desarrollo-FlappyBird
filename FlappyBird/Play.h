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
	Obstacle* obstacle;
public:
	Play();
	~Play();
	void setSceneManager(sceneManager* manager);
	void playUpdate();
	void playDraw();
};

