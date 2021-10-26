#pragma once
#include "raylib.h"
class Player {
private:
	Rectangle rec;
	Color color;
	
	bool falling;
public:
	Player(Rectangle rec, Color color);
	~Player();
	void movementOnePlayer();
	void movementTwoPlayers();
	void draw();
	void reset();

	Rectangle getRec();
};