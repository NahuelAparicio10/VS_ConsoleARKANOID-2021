#pragma once
#include "Ball.h"

//Ball Constructor
Ball::Ball()
{
	moves = MOVES::UP_RIGHT;
	pos.posX = 10;
	pos.posY = 10;
}
//Ball Destructor
Ball::~Ball(){}
//Changes pos X y Y depending on the direction
void Ball::Move(MOVES move) {
	switch (move)
	{
		case MOVES::DOWN_RIGHT:
			pos.posX++;
			pos.posY++;
			break;
		case MOVES::DOWN_LEFT:
			pos.posX--;
			pos.posY++;
			break;
		case MOVES::UP_RIGHT:
			pos.posX++;
			pos.posY--;
			break;
		case MOVES::UP_LEFT:
			pos.posX--;
			pos.posY--;
			break;
		case MOVES::COUNT:
			break;
		default:
			break;
	}
}

//Changes de direction of the ball
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

//Move the ball and check nextPos
void Ball::MoveBall(Board cB, Player actualPlayer) {
	//Check Player Collider
	if (BallCheckPlayerCollide(actualPlayer)) moves = ChangeDirectionFloor();
	//moves the ball
	Move(moves); 
	//check next pos collider
	BallCheckCollide(GetNextPos(cB), cB);
}

CellType Ball::GetNextPos(Board cBoard) { return cBoard.boardMatrix[pos.posY][pos.posX]; }

void Ball::BallCheckCollide(CellType currentCell, Board cBoard) {
	if (currentCell == CellType::WALL) {
		if (pos.posX < 2) pos.posX = 2;
		else if (pos.posX > cBoard.rows - 2) pos.posX = cBoard.rows - 2;
		moves = ChangeDirectionSides();
	}
	else if (currentCell == CellType::FLOOR) {
		if (pos.posY < 2) pos.posY = 2;
		else if (pos.posY > cBoard.columns - 2) pos.posY = cBoard.columns - 2;
		moves = ChangeDirectionFloor();
	}
}

//optimize
bool Ball::BallCheckPlayerCollide(Player player) { return ((pos.posX == player.pos.posX - 1 || pos.posX == player.pos.posX || pos.posX == player.pos.posX + 1 ) && pos.posY >= player.pos.posY) ? true : false; }

void Ball::ResetBallOnDie() {
	pos.posX = 10;
	pos.posY = 10;
	moves = MOVES(rand() % 2);
}