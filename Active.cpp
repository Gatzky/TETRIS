#include "Active.h"
#include "windows.h"
#include <iostream>

Active::Active(){
	VecActive.push_back(Block(1, 1, 255, 255, 255));			//Add for random blocks
	VecActive.push_back(Block(1, 1, 255, 255, 255));
	VecActive.push_back(Block(1, 1, 255, 255, 255));
	VecActive.push_back(Block(1, 1, 255, 255, 255));
	Reset();													//Reset random blocks that mean make them a figure
	rotstate = 1;												//Set rotstate to default = 1
}

Active::~Active(){	
}

Block Active::ReturnBlock(int i) {
	return (VecActive.at(i));
}

void::Active::MoveLeft(Garbage MyGarbage) {
	bool TestBarrier = (VecActive.at(0).ReturnX() == 0 || VecActive.at(1).ReturnX() == 0 || VecActive.at(2).ReturnX() == 0 || VecActive.at(3).ReturnX() == 0);  //Test is active vector reach left barrier, 1-collision
	bool TestGarbage = 0;
	for (int g = 0; g < MyGarbage.ReturnSize(); g++) {
		for (int a = 0; a < 4; a++) {
			if ((VecActive.at(a).ReturnY() == MyGarbage.ReturnBlock(g).ReturnY()) && (VecActive.at(a).ReturnX() == MyGarbage.ReturnBlock(g).ReturnX()+1))		//Test is anyone block from active vector collision with aynone block from garbage vector
				TestGarbage=1;																							//TestGarbage=1 mean collision
		}
	}
	if (!TestBarrier && !TestGarbage) {																					//if not collision with barrier and not collision with garbage
		for (int a = 0; a < 4; a++) {																					//for all block from active vector	
			VecActive.at(a).SetXY(VecActive.at(a).ReturnX() - 1, VecActive.at(a).ReturnY());							//move left that mean: y rewrite, x decrement
		}
	}
}
void::Active::MoveRight(Garbage MyGarbage) {
	bool TestBarrier = (VecActive.at(0).ReturnX() == 9 || VecActive.at(1).ReturnX() == 9 || VecActive.at(2).ReturnX() == 9 || VecActive.at(3).ReturnX() == 9);  //Test is active vector reach right barrier, 1-collision
	bool TestGarbage = 0;
	for (int g = 0; g < MyGarbage.ReturnSize(); g++) {
		for (int a = 0; a < 4; a++) {
			if ((VecActive.at(a).ReturnY() == MyGarbage.ReturnBlock(g).ReturnY()) && (VecActive.at(a).ReturnX() == MyGarbage.ReturnBlock(g).ReturnX() - 1))		//Test is anyone block from active vector collision with aynone block from garbage vector
				TestGarbage = 1;																				//TestGarbage=1 mean collision
		}
	}
	if (!TestBarrier && !TestGarbage) {																			//if not collision with barrier and not collision with garbage
		for (int a = 0; a < 4; a++) {																			//for all block from active vector	
			VecActive.at(a).SetXY(VecActive.at(a).ReturnX() + 1, VecActive.at(a).ReturnY());					//move right that mean: y rewrite, x increment
		}
	}
}
void Active::MoveDown(Garbage& MyGarbage) {
	for (int a = 0; a < 4; a++) {																				// for all blocks in active vector
		VecActive.at(a).SetXY(VecActive.at(a).ReturnX(), VecActive.at(a).ReturnY() + 1);						// move down, that mean: rewrite x, increment y																									// test collision, test that active collision with garbage																							
	}
	bool TestDown = VecActive.at(1).ReturnY() == 21 || VecActive.at(0).ReturnY() == 21 || VecActive.at(2).ReturnY() == 21 || VecActive.at(3).ReturnY() == 21;		// test collision with down barrier
	if (TestCollision(MyGarbage) || TestDown) {																	// if collision with garbage or down
		for (int a = 0; a < 4; a++) {																			// for all block from active vector
			VecActive.at(a).SetXY(VecActive.at(a).ReturnX(), VecActive.at(a).ReturnY() - 1);					// Move Up the Active Vector
			MyGarbage.AddBlock(VecActive.at(a));																//copy all blocks from active vector to garbage vector 
		}
		MyGarbage.DeleteLine();
		if (MyGarbage.TestEnd()) {
			MyGarbage.ResetGame();
			Reset();
		}
		Reset();
	}
}
bool Active::TestCollision(Garbage MyGarbage) {
	bool TestResult = 0;
	for (int g = 0; g < MyGarbage.ReturnSize(); g++) {
		for (int a = 0; a < 4; a++) {
			if ((VecActive.at(a).ReturnY() == MyGarbage.ReturnBlock(g).ReturnY()) && (VecActive.at(a).ReturnX() == MyGarbage.ReturnBlock(g).ReturnX()))	//test that anyone block from active vector collision with anyone vector from garbage vector
				TestResult = 1;											//TestResult mean collision
		}
	}
	return TestResult;
}

void Active::Rotate(Garbage MyGarbage) {
	switch (type) {
	case 1: {
		switch (rotstate) {
		case 1: {
			VecActive.at(0).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY());
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() + 1);
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() - 1);
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() + 2);
			break;
		}
		case 2: {
			VecActive.at(0).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() + 1);
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY());
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY());
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() - 2, VecActive.at(0).ReturnY());
			break;
		}
		case 3: {
			VecActive.at(0).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY());
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() - 1);
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() + 1);
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() - 2);
			break;
		}
		case 4: {
			VecActive.at(0).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() - 1);
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY());
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY());
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() + 2, VecActive.at(0).ReturnY());
			break;
		}
		}
		break;
	}
	case 2: {
		switch (rotstate) {
		case 1: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() + 1);
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() - 1);
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY() + 1);
			break;
		}
		case 2: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY());
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY());
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY() - 1);
			break;
		}
		case 3: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() + 1);
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() - 1);
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY() - 1);
			break;
		}
		case 4: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY());
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY());
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY() + 1);
			break;
		}
		}
		break;
	}
	case 3: {
		switch (rotstate) {
		case 1: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() + 1);
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() - 1);
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY() - 1);
			break;
		}
		case 2: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY());
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY());
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY() - 1);
			break;
		}
		case 3: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() + 1);
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() - 1);
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY() + 1);
			break;
		}
		case 4: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY());
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY());
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY() + 1);
			break;
		}
		}
		break;
	}
	case 4: {
		switch (rotstate) {
		case 1: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() + 1);
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() - 1);
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY());
			break;
		}
		case 2: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY());
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY());
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() - 1);
			break;
		}
		case 3: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() + 1);
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() - 1);
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY());
			break;
		}
		case 4: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY());
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY());
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() + 1);
			break;
		}
		}
		break;
	}
	case 5: {
		switch (rotstate) {
		case 1: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() + 1);
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY());
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY() - 1);
			break;
		}
		case 2: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY());
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() + 1);
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY() + 1);
			break;
		}
		case 3: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY());
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() - 1);
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY() + 1);
			break;
		}
		case 4: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() - 1);
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY() - 1);
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY());
			break;
		}
		}
		break;
	}
	case 6: {
		switch (rotstate) {
		case 1: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() - 1);
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY());
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY() + 1);
			break;
		}
		case 2: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY() + 1);
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() + 1);
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY());
			break;
		}
		case 3: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY());
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() + 1);
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY() - 1);
			break;
		}
		case 4: {
			VecActive.at(1).SetXY(VecActive.at(0).ReturnX(), VecActive.at(0).ReturnY() - 1);
			VecActive.at(2).SetXY(VecActive.at(0).ReturnX() + 1, VecActive.at(0).ReturnY() - 1);
			VecActive.at(3).SetXY(VecActive.at(0).ReturnX() - 1, VecActive.at(0).ReturnY());
			break;
		}
				break;
		}
	}
	}
	rotstate++;
	if (rotstate == 5)
		rotstate = 1;
}

bool Active::TestRotate(Garbage MyGarbage) {
	Rotate(MyGarbage);
	bool TestBarrierRight = (VecActive.at(0).ReturnX() > 9 || VecActive.at(1).ReturnX() > 9 || VecActive.at(2).ReturnX() > 9 || VecActive.at(3).ReturnX() > 9);
	bool TestBarrierLeft = (VecActive.at(0).ReturnX() < 0 || VecActive.at(1).ReturnX() < 0 || VecActive.at(2).ReturnX() < 0 ||VecActive.at(3).ReturnX() < 0 );
	bool TestBarrierUp = (VecActive.at(0).ReturnY() < 0 || VecActive.at(1).ReturnY() < 0 || VecActive.at(2).ReturnY() < 0 || VecActive.at(3).ReturnY() < 0);
	bool TestBarrierDown = (VecActive.at(0).ReturnY() > 20 || VecActive.at(1).ReturnY() > 20 || VecActive.at(2).ReturnY() > 20 || VecActive.at(3).ReturnY() > 20);
	bool AllTest = TestBarrierRight || TestBarrierLeft || TestBarrierUp || TestBarrierDown || TestCollision(MyGarbage);
	if (AllTest) {											//if in result of rotation block will glitch with barrier or garbage
		Rotate(MyGarbage);									//rotate in counterclockwise that mean 3 time rotate in clockwise
		Rotate(MyGarbage);
		Rotate(MyGarbage);
	}
	return 0;
}

void Active::Reset() {
	rotstate = 1;
	type = rand() % 7;
	switch (type) {
	case 0: {												//2x2 square VecActive
		VecActive.at(0).SetColor(255, 0, 0);				//color Red
		VecActive.at(1).SetColor(255, 0, 0);
		VecActive.at(2).SetColor(255, 0, 0);
		VecActive.at(3).SetColor(255, 0, 0);
		VecActive.at(0).SetXY(5, 0);
		VecActive.at(1).SetXY(6, 0);
		VecActive.at(2).SetXY(5, 1);
		VecActive.at(3).SetXY(6, 1);
		break;
	}
	case 1: {												//4x1 long VecActive
		VecActive.at(0).SetColor(0, 255, 0);				//color green
		VecActive.at(1).SetColor(0, 255, 0);
		VecActive.at(2).SetColor(0, 255, 0);
		VecActive.at(3).SetColor(0, 255, 0);
		VecActive.at(0).SetXY(5, 0);
		VecActive.at(1).SetXY(4, 0);
		VecActive.at(2).SetXY(6, 0);
		VecActive.at(3).SetXY(7, 0);
		break;
	}
	case 2: {												//inverted "L"
		VecActive.at(0).SetColor(0,0, 255);					//color blue
		VecActive.at(1).SetColor(0,0, 255);
		VecActive.at(2).SetColor(0,0, 255);
		VecActive.at(3).SetColor(0,0, 255);
		VecActive.at(0).SetXY(5, 0);
		VecActive.at(1).SetXY(4, 0);
		VecActive.at(2).SetXY(6, 0);
		VecActive.at(3).SetXY(6, 1);
		break;
	}
	case 3: {												//"L"
		VecActive.at(0).SetColor(255, 255, 0);				//color yellow
		VecActive.at(1).SetColor(255, 255, 0);
		VecActive.at(2).SetColor(255, 255, 0);
		VecActive.at(3).SetColor(255, 255, 0);
		VecActive.at(0).SetXY(5, 0);
		VecActive.at(1).SetXY(4, 0);
		VecActive.at(2).SetXY(6, 0);
		VecActive.at(3).SetXY(4, 1);
		break;
	}
	case 4: {												//"T"
		VecActive.at(0).SetColor(127, 0, 255);				//color purple
		VecActive.at(1).SetColor(127, 0, 255);
		VecActive.at(2).SetColor(127, 0, 255);
		VecActive.at(3).SetColor(127, 0, 255);
		VecActive.at(0).SetXY(5, 0);
		VecActive.at(1).SetXY(5, 1);
		VecActive.at(2).SetXY(6, 0);
		VecActive.at(3).SetXY(4, 0);
		break;
	}
	case 5: {												//Inverted "Z"
		VecActive.at(0).SetColor(255,0,127);				//color pink
		VecActive.at(1).SetColor(255, 0, 127);
		VecActive.at(2).SetColor(255, 0, 127);
		VecActive.at(3).SetColor(255, 0, 127);
		VecActive.at(0).SetXY(5, 0);
		VecActive.at(1).SetXY(5, 1);
		VecActive.at(2).SetXY(6, 1);
		VecActive.at(3).SetXY(4, 0);
		break;
	}
	case 6: {												//"Z"
		VecActive.at(0).SetColor(0, 153, 153);				//color turquise
		VecActive.at(1).SetColor(0, 153, 153);
		VecActive.at(2).SetColor(0, 153, 153);
		VecActive.at(3).SetColor(0, 153, 153);
		VecActive.at(0).SetXY(5, 1);
		VecActive.at(1).SetXY(5, 0);
		VecActive.at(2).SetXY(6, 0);
		VecActive.at(3).SetXY(4, 1);
		break;
	}
	}
}