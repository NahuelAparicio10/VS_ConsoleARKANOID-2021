// actualització sleep -> miliseconds (windows.h)
#pragma once
#include "Inputs.h"
#include "Ball.h"
#include "Score.h"
#include "GameState.h"

int main(int argc, char *argv[]) {
	
	Player player1;
	Score score1;
	Board board;
	Ball ball;
	GameStateC gameState;
	InputData inputs;
	
	while (gameState.gState == GameState::PLAYING) {
		//--INPUTS
		inputs.Update(); 

		//--UPDATE

		if (inputs.Keyboard[(int)InputKey::LEFT]) { player1.UpdateLeft(board); }
		else if (inputs.Keyboard[(int)InputKey::RIGHT]) { player1.UpdateRight(board);  }
		else if (inputs.Keyboard[(int)InputKey::ESCAPE]) gameState.gState = gameState.GetExit();
		
		board.ClearBall(ball.pos.posY, ball.pos.posX);

		ball.CollidedChangeDir(board, player1); 

		board.UpdateBoard(player1.pos.posY, player1.pos.posX, ball.pos.posY, ball.pos.posX);

		//--DRAW
		system("cls");
		score1.DrawScore();

		board.PrintBoard();
		Sleep(100);
	}
}

