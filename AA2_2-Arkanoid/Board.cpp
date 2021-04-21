#include "Board.h"
//Reads config.txt file and sets
void Board::ReadFile() {
	
	std::vector<std::string> data;
	std::string line;
	std::ifstream file;

	file.open("config.txt"); 

	//If the file can not be opened, stop the game execution
	if (file.fail()) {
		std::cout << "config is not available";
		exit(1);
	}
	
	while (!file.eof()) { //while the file is not ended

		while (getline(file, line)) {
			std::stringstream ss(line);
			if (getline(ss, line, ';')) {
				data.push_back(line); //save the data to vector
			}
		}
	}
	
	file.close(); 

	//give the data to the variables
	rows = std::stoi(data[0]);
	columns = std::stoi(data[0]);
	rowsWithBlocks = std::stoi(data[1]);
}

//Debug
void Board::Debug() {
	std::cout << rows << std::endl << columns << std::endl << rowsWithBlocks;
}

//Default Constructor
Board::Board()
{
	ReadFile();
	//create empty matrix
	boardMatrix = new char*[rows];
	for (int i = 0; i <= rows; i++)
	{
		boardMatrix[i] = new char[columns];
	}

	setBaseMatrix();
}

void Board::setBaseMatrix() {
	//initialize the base matrix
	for (int i = 0; i <= rows; i++)
	{
		for (int j = 0; j <= columns; j++)
		{
			if (i == 0 || i == rows) boardMatrix[i][j] = '_';

			else if (j == 0 || j == columns) boardMatrix[i][j] = '|';

			else if ((i >= 1 && i <= rowsWithBlocks) && (j != 0 || j != columns)) boardMatrix[i][j] = '@';

			else boardMatrix[i][j] = ' ';
		}
	}
}

void Board::UpdateBoard(int playerPosX, int playerPosY, int ballPosX, int ballPosY) {
	//Update Player Pos
	boardMatrix[playerPosY][playerPosX] = '-';
	boardMatrix[playerPosY][playerPosX + 1] = '-';
	boardMatrix[playerPosY][playerPosX - 1] = '-';

	//Update Ball Pos
	boardMatrix[ballPosY][ballPosX] = '*';
}

void Board::ClearPlayer(int playerPosX, int playerPosY) {
	//Delete Player Pos
	boardMatrix[playerPosY][playerPosX] = ' ';
	boardMatrix[playerPosY][playerPosX + 1] = ' ';
	boardMatrix[playerPosY][playerPosX - 1] = ' ';
}

void Board::ClearBall(int ballPosX, int ballPosY) {
	//Delete Ball Pos
	boardMatrix[ballPosY][ballPosX] = ' ';
}

//Print the board *DRAW*
void Board::PrintBoard() {

	for (int i = 0; i <= rows; i++)
	{
		for (int j = 0; j <= columns; j++)
		{
			std::cout << boardMatrix[i][j];
		}
		std::cout << std::endl;
	}
}

Board::~Board() {} //Destructor
