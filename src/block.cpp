#include "block.h"

Block::Block(int x, int y, int z, int id)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->id = id;
}

int Block::getId() { return id; }
int Block::getX() { return x; }
int Block::getY() { return y; }
int Block::getZ() { return z; }