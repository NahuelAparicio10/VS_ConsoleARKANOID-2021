#pragma once
enum class MOVES { UP_RIGHT, UP_LEFT, DOWN_RIGHT, DOWN_LEFT, COUNT };

class Ball
{
public:
	Ball();
	~Ball();
	void CollidedChangeDir(Board board, Player player);
	MOVES moves;
	int ballPosX, ballPosY;


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

MOVES Ball::ChangeDirectionSides() {
	if (moves == MOVES::UP_RIGHT) return MOVES::UP_LEFT;
	else if (moves == MOVES::UP_LEFT) return MOVES::UP_RIGHT;
	else if (moves == MOVES::DOWN_LEFT) return MOVES::DOWN_RIGHT;
	else if (moves == MOVES::DOWN_RIGHT) return MOVES::DOWN_LEFT;
	else return MOVES::COUNT;
}

MOVES Ball::ChangeDirectionFloor() {
	if (moves == MOVES::UP_RIGHT) return MOVES::DOWN_RIGHT;
	else if (moves == MOVES::UP_LEFT) return MOVES::DOWN_LEFT;
	else if (moves == MOVES::DOWN_LEFT) return MOVES::UP_LEFT;
	else if (moves == MOVES::DOWN_RIGHT) return MOVES::UP_RIGHT;
	else return MOVES::COUNT;
}

//Detects the collide and changes the direction
void Ball::CollidedChangeDir(Board board, Player player) {

	if (CheckMaxCollide(ballPosX, board.rows - 1)) {
		ballPosX = board.rows - 1;
		moves = ChangeDirectionSides();
		Move(moves);
	}
	else if (CheckMinCollide(ballPosX, 1)) {
		ballPosX = 1;
		moves = ChangeDirectionSides();
		Move(moves);
	}
	else if (CheckMaxCollide(ballPosY, board.columns - 1)) {
		ballPosY = board.columns - 1;
		moves = ChangeDirectionFloor();
		Move(moves);
	}
	else if (CheckMinCollide(ballPosY, 1)) {
		ballPosY = 1;
		moves = ChangeDirectionFloor();
		Move(moves);
	}
	else if (BallCheckPlayerCollide(player)) {
		moves = ChangeDirectionFloor();
		Move(moves);
	}

	else Move(moves);

}

bool Ball::CheckMaxCollide(int ballPos, int val) { return ballPos >= val ? true : false; }

bool Ball::CheckMinCollide(int ballPos, int val) { return ballPos <= val ? true : false; }

bool Ball::BallCheckPlayerCollide(Player player) { return ((ballPosX == player.positionX - 1 || ballPosX == player.positionX || ballPosX == player.positionX + 1) && ballPosY >= player.positionY) ? true : false; }
