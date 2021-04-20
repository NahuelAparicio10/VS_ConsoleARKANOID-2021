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
	//void playerMovement(int position_x);
	int positionX, positionY;
private:
};

/*
void Player::playerMovement(int position_x) {

	//si hay limites no se movera, pero debe salir por la otr banda


}

*/
