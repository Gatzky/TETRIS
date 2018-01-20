#include "Garbage.h"
#include <iostream>
#include <windows.h>

Garbage::Garbage(){
	score = 0;
}

Garbage::~Garbage(){}

void Garbage::AddBlock(Block MyBlock) {
	VecGarbage.push_back(MyBlock);
}

Block Garbage::ReturnBlock(int g) {
	return (VecGarbage.at(g));
}

int Garbage::ReturnSize() {
	return(VecGarbage.size());
}

void Garbage::DeleteLine() {
	for (int i = 0; i < 21; i++) {											//test all line in board
		int counter = 0;													//for all line start with counter=0
		for (int g = 0; g < ReturnSize(); g++) {							//test all block in Garbage Vector
			if (VecGarbage.at(g).ReturnY() == i)							//if anyone block lay in the line that is test
				counter++;													//increment counter
		}
		if(counter == 10){													//if in line are 11 blocks...
			for (int g = 0; g < ReturnSize(); g++) {						//for all block in Garbage Vector
				if (VecGarbage.at(g).ReturnY() == i) {						//if block lay in that line
					VecGarbage.erase(VecGarbage.begin() + g);				//erase this block
					g--;													//number of other blocks are decrementer so we must decrement intiger
				}
			}
			for (int g = 0; g < ReturnSize(); g++) {														// test all block in Garbage vector
				if (VecGarbage.at(g).ReturnY() < i) {														// if block in Garbage lay in line upper deleted line...
					VecGarbage.at(g).SetXY(VecGarbage.at(g).ReturnX(), VecGarbage.at(g).ReturnY() + 1);		// move down, that mean: rewrite x, increment y																									// test collision, test that active collision with garbage																							
				}
			}
			score++;
		}
	}
}

int Garbage::ReturnScore() {
	return score;
}

bool Garbage::TestEnd() {
	bool TestEnd = 0;
	for (int g = 0; g < VecGarbage.size(); g++) {
		if ((VecGarbage.at(g).ReturnX() > 4 && VecGarbage.at(g).ReturnX() < 8) && (VecGarbage.at(g).ReturnY() == 1 || VecGarbage.at(g).ReturnY() == 1))	//if anyone block in Garbage Vector lay in "create area"...
			TestEnd = 1;			//The game is end
	}
	return TestEnd;
}

void Garbage::ResetGame() {
	VecGarbage.clear();			//that mean every block in Garbage Vector were erased
	score = 0;					//and score was reseted
	Sleep(500);
}