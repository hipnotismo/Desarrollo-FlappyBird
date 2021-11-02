#pragma once
#include "raylib.h"
class Player {
private:
	Rectangle rec;
	Color color;
	Texture2D texture;
	Texture2D texture2;
	bool falling;
public:
	Player(Rectangle rec, Color color, Texture2D texture, Texture2D texture2);
	~Player();
	void movementOnePlayer();
	void movementTwoPlayers();
	void draw();
	void reset();

	Rectangle getRec();
};