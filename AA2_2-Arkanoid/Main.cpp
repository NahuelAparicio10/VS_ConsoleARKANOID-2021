// actualització sleep -> miliseconds (windows.h)
#pragma once
#include "Ball.h"
#include "GameState.h"

int main(int argc, char *argv[]) {
	
	Player player1;
	Board board;
	Ball ball;
	GameStateC gameState;
	InputData inputs;
	
	while (gameState.gState == GameState::PLAYING) {
		//--INPUTS
		inputs.Update(); 

		//--UPDATE

		if (inputs.Keyboard[(int)InputKey::ESCAPE]) gameState.gState = gameState.GetExit();

		board.ClearBall(ball.pos.posY, ball.pos.posX);

		ball.CollidedChangeDir(board, player1); 

		board.UpdateBoard(player1, ball.pos.posY, ball.pos.posX, inputs);

		//--DRAW
		system("cls");
		board.PrintBoard();
		Sleep(100);
	}
}

