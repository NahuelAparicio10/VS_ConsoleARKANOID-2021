#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

enum class CellType : char { EMPTY = ' ', FLOOR = '_', WALL = '|', BLOCK = '@', PLAYER = '-', BALL = '*'};

class Board
{
public:
	Board(); //constructor declaration
	~Board(); //destructor declaration
	void PrintBoard(); 
	void ClearBall(int posY, int posX);
	void UpdateBoard(int playerPosY, int playerPosX, int ballPosY, int ballPosX);
	char CellToChar(CellType currentCell);

	//Vars
	int rows, columns, rowsWithBlocks; 
	int blockVal1, blockVal2; // TEMP FOR RANDOM VALUE TO BLOCK CLASS
	CellType** boardMatrix;

private:
	void SetBaseMatrix();
	void ReadFile(); 

};
