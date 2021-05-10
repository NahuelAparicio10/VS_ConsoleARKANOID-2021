#pragma once
#include "Ball.h"

Ball::Ball()
{
	moves = MOVES::UP_RIGHT;
	pos.posX = 10;
	pos.posY = 10;
}

Ball::~Ball(){}

void Ball::Move(MOVES move) {
	switch (move)
	{
	case MOVES::UP_RIGHT:
		pos.posX++;
		pos.posY++;
		break;
	case MOVES::UP_LEFT:
		pos.posX--;
		pos.posY++;
		break;
	case MOVES::DOWN_RIGHT:
		pos.posX++;
		pos.posY--;
		break;
	case MOVES::DOWN_LEFT:
		pos.posX--;
		pos.posY--;
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
void Ball::CollidedChangeDir(Board actualBoard, Player actualPlayer) {

	if (CheckMaxCollide(pos.posX, actualBoard.rows - 1)) {
		pos.posY = actualBoard.rows - 1;
		moves = ChangeDirectionSides();
		Move(moves);
	}
	else if (CheckMinCollide(pos.posY, 1)) {
		pos.posY = 1;
		moves = ChangeDirectionSides();
		Move(moves);
	}
	else if (CheckMaxCollide(pos.posX, actualBoard.columns - 1)) {
		pos.posY = actualBoard.columns - 1;
		moves = ChangeDirectionFloor();
		Move(moves);
	}
	else if (CheckMinCollide(pos.posY, 1)) {
		pos.posY = 1;
		moves = ChangeDirectionFloor();
		Move(moves);
	}
	else if (BallCheckPlayerCollide(actualPlayer)) {
		moves = ChangeDirectionFloor();
		Move(moves);
	}

	else Move(moves);

}

bool Ball::CheckMaxCollide(int ballPos, int val) { return ballPos >= val ? true : false; }

bool Ball::CheckMinCollide(int ballPos, int val) { return ballPos <= val ? true : false; }

bool Ball::BallCheckPlayerCollide(Player player) { return ((pos.posX == player.pos.posX - 1 || pos.posX == player.pos.posX || pos.posX == player.pos.posX + 1) && pos.posX >= player.pos.posX) ? true : false; }
