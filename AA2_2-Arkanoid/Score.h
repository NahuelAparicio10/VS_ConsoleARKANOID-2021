#pragma once
#include <iostream>
class Score {

public:
	Score();
	~Score();
	int score;

	int GetScore();
	void SetScore(int val);

	void DrawScore();
private:
};