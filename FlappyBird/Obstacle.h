#pragma once
#include "raylib.h"

class Obstacle {
private:
	int gap;
	Rectangle recTop;
	Rectangle recBot;
	Color color;
public:
	Obstacle(Rectangle rec,Rectangle rec2, Color color);
	~Obstacle();
	void movement();
	void respawn();
	void draw();
	void reset();
	Rectangle getRecTop();
	Rectangle getRecBot();
};