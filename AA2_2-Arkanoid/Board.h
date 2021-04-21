#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Player.h"

//enum GameState {WIN, LOSE, UNFINISHED, COUNT};

enum class CELLS {WALL = '|', };
class Board
{
public:
	Board(); //constructor declarati on
	~Board(); //destructor declaration
	void setBaseMatrix();
	void Debug(); //For debugging things
	void ReadFile(); 
	void PrintBoard(); 
	void ClearPlayer(int playerPosX, int playerPosY);
	void ClearBall(int BallPosX, int BallPosY);
	void UpdateBoard(int playerPosX, int playerPosY, int ballPosX, int ballPosY);
	int rows, columns, rowsWithBlocks; 


private:
	char** boardMatrix;
};
