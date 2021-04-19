#pragma once
class Player
{
public:
	Player();
	~Player();
	void playerMovement(int position_x);
private:
	int positionX, positionY;
};

Player::Player()
{
	//position Y is fixed
	positionY = 3;
}

Player::~Player()
{
}

void Player::playerMovement(int position_x) {

	//si hay limites no se movera, pero debe salir por la otr banda


}