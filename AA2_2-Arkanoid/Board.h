#pragma once
struct Board {
    enum class CellsChar { VOID_CHAR = ' ', PLAYER_CHAR = '---', BRICK_CHAR = '@', BALL_CHAR = '*', VERICAL_CHAR = '|', HORITZONTALCHAR = '' };
    CellsChar** board;
    int NUM_ROWS; //EN FICHERO
    int NUM_COLUMNS;//EN FICHERO
    int numberBricks;
};