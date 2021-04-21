#pragma once

enum class MOVES { UP_RIGHT, UP_LEFT, DOWN_RIGHT, DOWN_LEFT, COUNT };

class Ball
{
public:
	Ball();
	~Ball();
	void Move(MOVES move);
	void CollidedChangeDir(Board board);
	MOVES ChangeDirectionSides(MOVES move);
	MOVES ChangeDirectionFloor(MOVES move);
	MOVES moves;
	int ballPosX, ballPosY;

private:
};

Ball::Ball()
{
	moves = MOVES::UP_RIGHT;
	ballPosX = 10;
	ballPosY = 10;
}

Ball::~Ball(){}


void Ball::Move(MOVES move) {
	switch (move)
	{
	case MOVES::UP_RIGHT:
		ballPosX++;
		ballPosY++;
		break;
	case MOVES::UP_LEFT:
		ballPosX--;
		ballPosY++;
		break;
	case MOVES::DOWN_RIGHT:
		ballPosX++;
		ballPosY--;
		break;
	case MOVES::DOWN_LEFT:
		ballPosX--;
		ballPosY--;
		break;
	case MOVES::COUNT:
		break;
	default:
		break;
	}
}

MOVES Ball::ChangeDirectionSides(MOVES move) {
	if (move == MOVES::UP_RIGHT) return MOVES::UP_LEFT;
	else if (move == MOVES::UP_LEFT) return MOVES::UP_RIGHT;
	else if (move == MOVES::DOWN_LEFT) return MOVES::DOWN_RIGHT;
	else if (move == MOVES::DOWN_RIGHT) return MOVES::DOWN_LEFT;
}

MOVES Ball::ChangeDirectionFloor(MOVES move) {
	if (move == MOVES::UP_RIGHT) return MOVES::DOWN_RIGHT;
	else if (move == MOVES::UP_LEFT) return MOVES::DOWN_LEFT;
	else if (move == MOVES::DOWN_LEFT) return MOVES::UP_LEFT;
	else if (move == MOVES::DOWN_RIGHT) return MOVES::UP_RIGHT;
	//lets see
}

//Detects the collide and changes the direction
void Ball::CollidedChangeDir(Board board) {
	if (ballPosY > board.columns - 2 || ballPosX > board.rows - 2) moves = ChangeDirectionSides(moves);
	
	else if (ballPosY < 2 || ballPosX < 2)	moves = ChangeDirectionFloor(moves);
}
