#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Board
{
public:
	Board(); //constructor declaration
	~Board(); //destructor declaration
	void PrintBoard(); 
	void ClearBall(int posY, int posX);
	void UpdateBoard(int playerPosY, int playerPosX, int ballPosY, int ballPosX);
	int rows, columns, rowsWithBlocks; 
	int blockVal1, blockVal2; // TEMP FOR RANDOM VALUE TO BLOCK CLASS
	char** boardMatrix;

private:
	void SetBaseMatrix();
	void ReadFile(); 

};
