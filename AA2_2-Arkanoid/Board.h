#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Ball.h"
#include "Inputs.h"

class Board
{
public:
	Board(); //constructor declaration
	~Board(); //destructor declaration
	void PrintBoard(); 
	void ClearPlayer(int posY, int posX);
	void ClearBall(int posY, int posX);
	void UpdateBoard(Player, int ballPosY, int ballPosX, InputData);
	int rows, columns, rowsWithBlocks; 


private:
	void SetBaseMatrix();
	void ReadFile(); 
	char** boardMatrix;
};
