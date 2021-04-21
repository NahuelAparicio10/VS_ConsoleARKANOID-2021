// actualització sleep -> miliseconds (windows.h)
#include "Board.h"
#include "Ball.h"
#include "Inputs.h"

int main(int argc, char *argv[]) {
	
	Player player1;
	Board board;
	Ball ball;
	
	//InputsWorking
	InputData inputs;
	
	while (!inputs.Keyboard[(int)InputKey::ESCAPE]) {
		board.ClearBall(ball.ballPosX, ball.ballPosY);
		//--INPUTS
		inputs.Update(); //works

		//--UPDATE

		//works
		if (inputs.Keyboard[(int)InputKey::LEFT]) {
			board.ClearPlayer(player1.positionX, player1.positionY);
			player1.moveLeft();
			if (player1.positionX > board.rows - 2)	player1.positionX = 2 ;
			else if (player1.positionX < 2) player1.positionX = board.rows - 2;
		}

		//works
		else if (inputs.Keyboard[(int)InputKey::RIGHT]) {
			board.ClearPlayer(player1.positionX, player1.positionY);
			player1.moveRight();
			if (player1.positionX > board.rows - 2) player1.positionX = 2;
			else if (player1.positionX < 2) player1.positionX = board.rows - 2;
		}


		ball.CollidedChangeDir(board); //works

		board.UpdateBoard(player1.positionX, player1.positionY, ball.ballPosX, ball.ballPosY);



		//--DRAW
		system("cls");
		//works
		board.PrintBoard();
		Sleep(80);
	}
}

