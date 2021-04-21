#pragma once
class Player
{
public:
	Player() {
		//position Y is fixed
		positionY = 17;
		positionX = 10;
	}
	~Player() {}

	int moveRight() {
		return positionX++;
	}
	int moveLeft() {
		return positionX--;
	}
	int positionX, positionY;
private:
};

