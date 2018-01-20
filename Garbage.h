#pragma once
#include "Block.h"
#include "Active.h"
#include <vector>
using namespace std;

class Active;
class Block;

class Garbage
{
	vector<Block>VecGarbage;
	int score;
public:
	Garbage();
	~Garbage();
	void AddBlock(Block);
	Block ReturnBlock(int);
	int ReturnSize();
	int ReturnScore();
	void DeleteLine();
	bool TestEnd();
	void ResetGame();
};