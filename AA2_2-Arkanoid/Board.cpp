#pragma once
#include "Board.h"

//Default Constructor
Board::Board()
{
	ReadFile();
	SetBaseMatrix();
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
}

void Board::SetBaseMatrix() {
	//create empty matrix
	boardMatrix = new char* [rows];
	//initialize the base matrix
	for (int i = 0; i <= rows; i++)
	{
		boardMatrix[i] = new char[columns];
		for (int j = 0; j <= columns; j++)
		{
			if (i == 0 || i == rows) boardMatrix[i][j] = '_';
			else if (j == 0 || j == columns) boardMatrix[i][j] = '|';
			else if ((i >= 1 && i <= rowsWithBlocks) && (j != 0 || j != columns)) boardMatrix[i][j] = '@';
			else boardMatrix[i][j] = ' ';
		}
	}
}

void Board::UpdateBoard(Player actualPlayer, int ballPosY, int ballPosX, InputData actualInputs) {
	//Update Player Pos
	boardMatrix[actualPlayer.pos.posY][actualPlayer.pos.posX] = '-';
	boardMatrix[actualPlayer.pos.posY][actualPlayer.pos.posX + 1] = '-';
	boardMatrix[actualPlayer.pos.posY][actualPlayer.pos.posX - 1] = '-';

	//Update Ball Pos
	boardMatrix[ballPosY][ballPosX] = '*';

	//Update player movement by inputs from the user

	if (actualInputs.Keyboard[(int)InputKey::LEFT]) {
		ClearPlayer(actualPlayer.pos.posY, actualPlayer.pos.posX);
		actualPlayer.moveLeft();
		if (actualPlayer.pos.posX > rows - 2) actualPlayer.pos.posX = 2;
		else if (actualPlayer.pos.posX < 2) actualPlayer.pos.posX = rows - 2;
	}

	else if (actualInputs.Keyboard[(int)InputKey::RIGHT]) {
		ClearPlayer(actualPlayer.pos.posY, actualPlayer.pos.posX);
		actualPlayer.moveRight();
		if (actualPlayer.pos.posX > rows - 2) actualPlayer.pos.posX = 2;
		else if (actualPlayer.pos.posX < 2) actualPlayer.pos.posX = rows - 2;
	}
}

void Board::ClearPlayer(int posY, int posX) {
	//Clear Player Pos
	boardMatrix[posY][posX] = ' ';
	boardMatrix[posY][posX + 1] = ' ';
	boardMatrix[posY][posX - 1] = ' ';
}

void Board::ClearBall(int posY, int posX) {
	//Clear Ball Pos
	boardMatrix[posY][posX] = ' ';
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

