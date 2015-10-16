#pragma once
class Block
{
public:
	Block(int, int, int, int);
	int getId();
	int getX();
	int getY();
	int getZ();
private:
	int id;
	int x;
	int y;
	int z;
};