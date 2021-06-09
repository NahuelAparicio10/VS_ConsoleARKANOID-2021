#pragma once
#include "Player.h"
#include "Blocs.h"
#include "Score.h"

enum class MOVES { UP_RIGHT, UP_LEFT, DOWN_RIGHT, DOWN_LEFT, COUNT };

class Ball
{
public:
	Ball();
	~Ball();
	void BallCheckCollide(CellType, Board);

	MOVES moves;
	Vec2 pos;
	//moves the ball
	void Move(MOVES move);
	void MoveBall(Board, Player);
	void ResetBallOnDie();
	CellType GetNextPos(Board);

private:

	//Change direction of the Ball
	MOVES ChangeDirectionSides();
	MOVES ChangeDirectionFloor();

	//CollidersCheck
	bool BallCheckPlayerCollide(Player player);
};
