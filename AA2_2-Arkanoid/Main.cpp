// actualització sleep -> miliseconds (windows.h)
#include "Board.h"
#include "Player.h"
#include "Inputs.h"

int main(int argc, char *argv[]) {
	
	//Player player;
	//Board board;
	//board.Debug();
	//board.PrintBoard();


	//InputsWorking
	InputData inputs;

	while (!inputs.Keyboard[(int)InputKey::ESCAPE]) {
		//--INPUTS
		inputs.Update();
		//--UPDATE
		
		//--DRAW
		system("cls");
	}


}

