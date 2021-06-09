#include "Player.h"

Player::Player() {
	pos.posY = 17;
	pos.posX = 10;
	lifes = 3;
}

Player::~Player() {}

void Player::UpdateLeft(Board currentBoard) {
	ClearPlayer(currentBoard);
	moveLeft();
	if (pos.posX > currentBoard.rows - 2) pos.posX = 3;
	else if (pos.posX < 2) pos.posX = currentBoard.rows - 3;
}

void Player::UpdateRight(Board currentBoard) {
	ClearPlayer(currentBoard);
	moveRight();
	if (pos.posX > currentBoard.rows - 3) pos.posX = 2;
	else if (pos.posX < 2) pos.posX = currentBoard.rows - 3;
}

void Player::ClearPlayer(Board cBoard) {
	cBoard.boardMatrix[pos.posY][pos.posX] = CellType::EMPTY;
	cBoard.boardMatrix[pos.posY][pos.posX + 1] = CellType::EMPTY;
	cBoard.boardMatrix[pos.posY][pos.posX - 1] = CellType::EMPTY;
}

void Player::DrawLives() { std::cout << std::endl << std::endl << "Lives ~> " << lifes << std::endl; }

int Player::moveRight() { return pos.posX++; }
int Player::moveLeft() { return pos.posX--; }