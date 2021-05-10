#pragma once
#include "Player.h"
#include "Board.h"
enum class MOVES { UP_RIGHT, UP_LEFT, DOWN_RIGHT, DOWN_LEFT, COUNT };

class Ball
{
public:
	Ball();
	~Ball();
	void CollidedChangeDir(Board, Player);
	MOVES moves;
	Vec2 pos;

private:
	//moves the ball
	void Move(MOVES move);

	//Change direction of the Ball
	MOVES ChangeDirectionSides();
	MOVES ChangeDirectionFloor();

	//CollidersCheck
	bool CheckMinCollide(int ballPos, int val);
	bool CheckMaxCollide(int ballPos, int val);
	bool BallCheckPlayerCollide(Player player);
};
