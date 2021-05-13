#pragma once
#include <queue>
class Block {
public:
	std::queue<int> values;
	Block(int, int, int);
	~Block();
	void DeleteValue();
	int SetValue(int, int);
	int GetValue();
};