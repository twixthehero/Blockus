#include "chunk.h"

Chunk::Chunk(int x, int z)
{
	this->x = x;
	this->z = z;
}

int Chunk::getX() { return x; }
int Chunk::getZ() { return z; }

void Chunk::generate()
{
	data.resize(SIZE);

	for (int x = 0; x < SIZE; x++)
	{
		data[x].resize(SIZE);

		for (int y = 0; y < SIZE; y++)
		{
			for (int z = 0; z < SIZE; z++)
			{

			}
		}
	}
}