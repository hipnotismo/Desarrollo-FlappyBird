#include "Player.h"

Player::Player(Rectangle rec, Color color)
{


	this->rec = rec;
	this->color = color;
	
}

Player::~Player()
{
}

void Player::movementOnePlayer()
{
	if (IsKeyDown(KEY_SPACE))
	{
		rec.y -= GetFrameTime() * 300;
		falling = true;
	}
	else
	{
		rec.y += GetFrameTime() * 170;
		falling = false;
	}
}

void Player::movementTwoPlayers()
{
	if (IsKeyDown(KEY_ENTER))
	{
		rec.y -= GetFrameTime() * 300;
		falling = true;
	}
	else
	{
		rec.y += GetFrameTime() * 170;
		falling = false;
	}
}

void Player::draw()
{
	if (falling)
		DrawRectangle(rec.x, rec.y, rec.width, rec.height, color );
	else
		DrawRectangle(rec.x, rec.y, rec.width, rec.height, color);
}

void Player::reset()
{
	rec.x = GetScreenWidth() / 2;
	rec.y = GetScreenHeight() / 2;
}

Rectangle Player::getRec()
{
	return rec;
}
