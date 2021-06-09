#include "Score.h"

Score::Score() { score = 0; }

Score::~Score() {}

int Score::GetScore() {	return score; }

void Score::SetScore(int val) { score += val; }

void Score::DrawScore() { std::cout << std::endl << std::endl << "Score ~> " << GetScore() << std::endl; }