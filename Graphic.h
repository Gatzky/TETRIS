#pragma once
#include "Block.h"
#include "Active.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <windows.h>

using namespace sf;

class Graphic
{
public:
	Graphic();
	~Graphic();
	void MainLoop();
	void DrawBlock(Block &MyBlock, RenderWindow& MyWindow);
	void DrawEverything(Active MyActive, RenderWindow& MyWindow, Garbage MyGarbage, Font font);
	void Grid(RenderWindow& MyWindow);
	void Score(RenderWindow& window, Font font, Garbage MyGarbage);
};