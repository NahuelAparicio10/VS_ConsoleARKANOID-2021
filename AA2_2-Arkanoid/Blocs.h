#pragma once
#include <queue>
class Block {
public:
	std::queue<int> values;
	Block();
	~Block();

	void SetBaseValues(int, int, int);
	int SetValue(int, int);
	int GetValue();
};