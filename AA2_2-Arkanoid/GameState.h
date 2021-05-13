#pragma once
enum class GameState { WIN, LOSE, PLAYING, EXIT, COUNT };

class GameStateC
{
public:
	GameStateC();
	~GameStateC();
	void SetLose();
	void SetWin();
	void SetExit();
	GameState gState;
	bool CheckWin();
	bool CheckLoose(int, int);

private:
};

GameStateC::GameStateC() { gState = GameState::PLAYING; }

GameStateC::~GameStateC() {}

void GameStateC::SetWin() { gState = GameState::WIN; }

void GameStateC::SetExit() { gState = GameState::EXIT; }

void GameStateC::SetLose() { gState = GameState::LOSE; }

bool GameStateC::CheckLoose(int ballPosY, int pPosY) { return ballPosY > pPosY ? true : false;  }


