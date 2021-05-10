#pragma once
#include "Vector.h"
class Player
{
public:
	Player() {
		pos.posY = 17;
		pos.posX = 10;
	}
	~Player() {}

	int moveRight() {	return pos.posX++;	}
	int moveLeft() {	return pos.posY--;	}
	Vec2 pos;
};

