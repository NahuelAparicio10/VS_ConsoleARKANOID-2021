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

	void DrawLives();

	Vec2 pos;
	int lifes;

private:
	void ClearPlayer(Board currentBoard);
};

