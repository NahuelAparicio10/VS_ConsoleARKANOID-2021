#include "Blocs.h"

Block::Block(int v1, int v2, int maxBlocks) {

	for (int i = 0; i < maxBlocks; i++)
		SetValue(v1, v2);
}
Block::~Block() {}

void Block::SetValue(int v1, int v2) { 
	int temp = v1 + rand() % v2;
	values.push(temp); 
}
int Block::GetValue() { 
	int tempValue = values.front();
	values.pop();
	return tempValue;
}