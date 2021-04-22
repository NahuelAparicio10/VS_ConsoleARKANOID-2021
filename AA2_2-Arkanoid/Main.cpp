// actualització sleep -> miliseconds (windows.h)
#include "Board.h"
#include "Ball.h"
#include "Inputs.h"
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

		if (inputs.Keyboard[(int)InputKey::LEFT]) {
			board.ClearPlayer(player1.positionX, player1.positionY);
			player1.moveLeft();
			if (player1.positionX > board.rows - 2)	player1.positionX = 2 ;
			else if (player1.positionX < 2) player1.positionX = board.rows - 2;
		}

		else if (inputs.Keyboard[(int)InputKey::RIGHT]) {
			board.ClearPlayer(player1.positionX, player1.positionY);
			player1.moveRight();
			if (player1.positionX > board.rows - 2) player1.positionX = 2;
			else if (player1.positionX < 2) player1.positionX = board.rows - 2;
		}

		else if (inputs.Keyboard[(int)InputKey::ESCAPE]) gameState.gState = gameState.GetExit();

		board.ClearBall(ball.ballPosX, ball.ballPosY);

		ball.CollidedChangeDir(board, player1); 

		board.UpdateBoard(player1.positionX, player1.positionY, ball.ballPosX, ball.ballPosY);

		//--DRAW
		system("cls");
		board.PrintBoard();
		Sleep(100);
	}
}

