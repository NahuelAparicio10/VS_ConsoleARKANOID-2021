#pragma once
#include "Blocs.h"
#include "Ball.h"
#include "Score.h"
#include <map>
#include <set>

class GameManager
{
public:
	GameManager();
	~GameManager();
	void Play();
	void Menu();
	void Exit();

	void PlayScore();
	void SortRanking(std::map<int, std::string> &M);
	void ReadRankingFile();
	void SaveRanking();
	void ShowRanking();
	void ChangeSpeed();

	std::map<int, std::string> ranking;
	int maxBlocs, sleepRate;
	Player player;
	Board board;
	Score score;
	Ball ball;
	Block blocks;


private:

};

struct comparator {
	template <typename T>

	bool operator()(const T& l, const T& r) const {
		if (l.first != r.first) return l.first > r.first;
		return l.second > r.second;
	}
};
