#include "Player.h"

Player::Player(Rectangle rec, Color color, Texture2D texture, Texture2D texture2)
{


	this->rec = rec;
	this->color = color;
	this->texture = texture;
	this->texture2 = texture2;
	
}

Player::~Player()
{
}

void Player::movementOnePlayer()
{
	if (IsKeyDown(KEY_Q))
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
	if (IsKeyDown(KEY_E))
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
		//DrawRectangle(rec.x, rec.y, rec.width, rec.height, color );
		DrawTexture(texture,rec.x,rec.y,color);
	else
		//DrawRectangle(rec.x, rec.y, rec.width, rec.height, color);
		DrawTexture(texture2, rec.x, rec.y, color);
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
