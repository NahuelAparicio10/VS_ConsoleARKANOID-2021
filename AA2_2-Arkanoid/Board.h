#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Player.h"



class Board
{
public:
	Board(); //constructor declaration
	~Board(); //destructor declaration
	void SetBaseMatrix();
	void ReadFile(); 
	void PrintBoard(); 
	void ClearPlayer(int playerPosX, int playerPosY);
	void ClearBall(int BallPosX, int BallPosY);
	void UpdateBoard(int playerPosX, int playerPosY, int ballPosX, int ballPosY);
	int rows, columns, rowsWithBlocks; 


private:
	char** boardMatrix;
};
