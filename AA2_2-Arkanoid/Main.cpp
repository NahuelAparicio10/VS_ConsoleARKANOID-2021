// actualització sleep -> miliseconds (windows.h)
#pragma once
#include "Inputs.h"
#include "Blocs.h"
#include "Ball.h"
#include "Score.h"
#include "GameState.h"

int main(int argc, char *argv[]) {
	
	Player player;
	Score score;
	Board board;
	Ball ball;
	GameStateC gameState;
	InputData inputs;
	Block blocks(board.blockVal1, board.blockVal2, (board.rowsWithBlocks * (board.rows - 2)));
	
	
	while (gameState.gState == GameState::PLAYING) {
		//--INPUTS
		inputs.Update(); 
		//--UPDATE
		if (inputs.Keyboard[(int)InputKey::LEFT]) { player.UpdateLeft(board); }
		else if (inputs.Keyboard[(int)InputKey::RIGHT]) { player.UpdateRight(board);  }
		else if (inputs.Keyboard[(int)InputKey::ESCAPE]) gameState.SetExit();
		
		board.ClearBall(ball.pos.posY, ball.pos.posX);

		ball.MoveBall(board, player);

		if (ball.GetNextPos(board) == CellType::BLOCK) { score.SetScore(blocks.GetValue()); }

		board.UpdateBoard(player.pos.posY, player.pos.posX, ball.pos.posY, ball.pos.posX);

		//--DRAW
		system("cls");
		score.DrawScore();

		board.PrintBoard();

		//--CHECK
		if (gameState.CheckLoose(ball.pos.posY, player.pos.posY)) gameState.SetLose();
		if (blocks.values.empty()) gameState.SetWin();
		Sleep(100);
	}

	if (gameState.gState == GameState::LOSE) std::cout << std::endl << "~~YOU LOSED~~" << std::endl;
	else if (gameState.gState == GameState::WIN) {
		std::cout << std::endl << "~~YOU WIN~~" << std::endl;
		score.DrawScore();
	}
}

