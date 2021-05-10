#pragma once
#include "Vector.h"
#include "Board.h"
class Player
{
public:
	Player();
	~Player();

	int moveRight();
	int moveLeft();

	void UpdateLeft(Board currentBoard);
	void UpdateRight(Board currentBoard);

	Vec2 pos;

private:
	void ClearPlayer(Board currentBoard);
};

