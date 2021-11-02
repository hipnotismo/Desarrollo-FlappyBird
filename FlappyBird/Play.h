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

	Image back;
	Image mid;
	Image mod;
	Image fore;
	Texture2D background;
	Texture2D midground;
	Texture2D modground;
	Texture2D foreground;

	bool pause = false;
	bool multy = false;
	bool win = false;

	float scrollingBack;
	float scrollingMid;
	float scrollingFore;
public:
	Play();
	~Play();
	void setSceneManager(sceneManager* manager);
	void playUpdate();
	void playDraw();
};