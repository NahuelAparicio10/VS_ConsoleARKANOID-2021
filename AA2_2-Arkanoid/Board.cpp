#pragma once
#include "Board.h"

//Default Constructor
Board::Board()
{
	ReadFile();
	SetBaseMatrix();
	PrintBoard();
}

Board::~Board() {} //Destructor

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
			if (getline(ss, line, ';'))	data.push_back(line); //save the data to vector
		}
	}

	file.close();

	//give the data to the variables
	rows = std::stoi(data[0]);
	columns = std::stoi(data[0]);
	rowsWithBlocks = std::stoi(data[1]);
	blockVal1 = std::stoi(data[2]);
	blockVal2 = std::stoi(data[3]);
}

void Board::SetBaseMatrix() {
	//create empty matrix
	boardMatrix = new CellType* [rows];
	//initialize the base matrix
	for (int i = 0; i < rows; i++)
	{
		boardMatrix[i] = new CellType[columns];
		for (int j = 0; j < columns; j++)
		{
			if (i == 0 || i == rows - 1) boardMatrix[i][j] = CellType::FLOOR;
			else if (j == 0 || j == columns - 1) boardMatrix[i][j] = CellType::WALL;
			else if ((i >= 0 && i <= rowsWithBlocks) && (j != 0 || j != columns)) boardMatrix[i][j] = CellType::BLOCK;
			else boardMatrix[i][j] = CellType::EMPTY;
		}
	}
}

void Board::UpdateBoard(int playerPosY, int playerPosX, int ballPosY, int ballPosX) {
	//Update Player Pos
	boardMatrix[playerPosY][playerPosX] = CellType::PLAYER;
	boardMatrix[playerPosY][playerPosX + 1] = CellType::PLAYER;
	boardMatrix[playerPosY][playerPosX - 1] = CellType::PLAYER;


	//Update Ball Pos
	boardMatrix[ballPosY][ballPosX] = CellType::BALL;
}

void Board::ClearBall(int posY, int posX) {	boardMatrix[posY][posX] = CellType::EMPTY; }

//Print the board *DRAW*
void Board::PrintBoard() {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++) std::cout << CellToChar(boardMatrix[i][j]);
		std::cout << std::endl;
	}
}

char Board::CellToChar(CellType currentCell) {
	switch (currentCell)
	{
	case CellType::EMPTY:
		return ' ';
	case CellType::FLOOR:
		return '_';
	case CellType::WALL:
		return '|';
	case CellType::BLOCK:
		return '@';
	case CellType::PLAYER:
		return '-';
	case CellType::BALL:
		return '*';
	default:
		return ' ';
	}

}

