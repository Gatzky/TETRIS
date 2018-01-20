#pragma once
#include "Garbage.h"
#include "Active.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Garbage;

class Block
{
	int x;								//coordinate x
	int y;								//coordinate y
	int red;
	int green;
	int blue;
	
public:
	Block(int, int, int, int, int);		//(X, Y, Red, Green, Blue)
	~Block();
	void SetXY(int ,int);				//(X,Y)
	void SetColor(int, int, int);		//(Red, Green, Blue)
	int ReturnX();
	int ReturnY();
	int ReturnRED();
	int ReturnGREEN();
	int ReturnBLUE();
};