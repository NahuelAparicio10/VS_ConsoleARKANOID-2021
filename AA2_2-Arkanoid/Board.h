#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Player.h"

//enum GameState {WIN, LOSE, UNFINISHED, COUNT};

//mapa matriz dinamica, especificadas en el txt, solo habrá información de los limites y las filas de los bloques.

class Board
{
public:
	Board(); //constructor declaration
	~Board(); //destructor declaration
	void setBaseMatrix();
	void Debug(); //For debugging things
	void ReadFile(); 
	void PrintBoard(); 
	void ClearPlayerPos(int playerPosX, int playerPosY);
	void UpdateBoard(int playerPosX, int playerPosY);
	int rows, columns, rowsWithBlocks; 


private:
	char** boardMatrix;
};
