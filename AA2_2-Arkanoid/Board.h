#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

//enum GameState {WIN, LOSE, UNFINISHED, COUNT};

//mapa matriz dinamica, especificadas en el txt, solo habrá información de los limites y las filas de los bloques.

class Board
{
public:
	Board(); //constructor declaration
	~Board(); //destructor declaration
	void Debug(); //For debugging things
	void ReadFile(); 
	void PrintBoard(); 
private:
	int rows, columns, rowsWithBlocks; 
	char** boardMatrix;
};
