#pragma once
#include "button.h"

#include "sceneManager.h"

#include "Player.h"

class Play
{
private:
	sceneManager* manager;

public:
	Play();
	~Play();
	void setSceneManager(sceneManager* manager);
	void playUpdate();
	void playDraw();
};

