#pragma once
enum class GameState { WIN, LOSE, PLAYING, EXIT, COUNT };

class GameStateC
{
public:
	GameStateC();
	~GameStateC();
	GameState GetLose();
	GameState GetWin();
	GameState GetExit();
	GameState gState;

private:
};

GameStateC::GameStateC() { gState = GameState::PLAYING; }

GameStateC::~GameStateC() {}

GameState GameStateC::GetWin() { return GameState::WIN; }

GameState GameStateC::GetExit() { return GameState::EXIT; }

GameState GameStateC::GetLose() { return GameState::LOSE; }

