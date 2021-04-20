// actualització sleep -> miliseconds (windows.h)
#include "Board.h"
#include "Inputs.h"

int main(int argc, char *argv[]) {
	
	Player player1;
	Board board;
	//board.Debug();
	//InputsWorking
	InputData inputs;
	
	while (!inputs.Keyboard[(int)InputKey::ESCAPE]) {
		//--INPUTS
		inputs.Update();
		//--UPDATE

		if (inputs.Keyboard[(int)InputKey::LEFT]) {
			board.ClearPlayerPos(player1.positionX, player1.positionY);
			player1.moveLeft();
			if (player1.positionX > board.rows - 2) {
				player1.positionX = 2 ;
			}
			else if (player1.positionX < 2) {
				player1.positionX = board.rows - 2;
			}
		}
		else if (inputs.Keyboard[(int)InputKey::RIGHT]) {
			board.ClearPlayerPos(player1.positionX, player1.positionY);
			player1.moveRight();
			if (player1.positionX > board.rows - 2) {
				player1.positionX = 2;
			}
			else if (player1.positionX < 2) {
				player1.positionX = board.rows - 2;
			}
		}
		board.UpdateBoard(player1.positionX, player1.positionY);
		//--DRAW
		system("cls");
		board.PrintBoard();

	}
}

