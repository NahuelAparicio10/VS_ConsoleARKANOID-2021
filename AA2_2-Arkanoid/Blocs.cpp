#include "Blocs.h"

Block::Block(int v1, int v2, int maxBlocks) {

	for (int i = 0; i < maxBlocks; i++)
		values.push(SetValue(v1, v2));
}
Block::~Block() {}

int Block::SetValue(int v1, int v2) { return  v1 + rand() % v2; }

int Block::GetValue() {
	int temp = values.front();
	values.pop();
	return temp;
}

void Block::DeleteValue() { values.pop(); }