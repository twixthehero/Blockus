#pragma once
#include <vector>
#include "block.h"
using std::vector;

class Chunk
{
public:
	Chunk(int, int);
	int getX();
	int getZ();
	void generate();
private:
	int x;
	int z;
	vector<vector<vector<Block>>> data;
	const int SIZE = 16;
};