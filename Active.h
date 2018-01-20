#pragma once
#include "Block.h"
#include <vector>
using namespace std;

class Block;
class Garbage;

class Active
{
	vector<Block>VecActive;
	int type; //0-2x2, 1-4x1, 2-invL, 3-L, 4-T, 5-invZ, 6-Z 
	int rotstate;
public:
	Active();
	~Active();
	Block ReturnBlock(int); //Zwraca a-towy Block vectora VecActive
	void MoveLeft(Garbage);
	void MoveRight(Garbage);
	void MoveDown(Garbage& MyGarbage);
	bool TestCollision(Garbage);
	void Reset();
	void Rotate(Garbage);
	bool TestRotate(Garbage);
};