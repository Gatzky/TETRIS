#include "Graphic.h"
#include <sstream>
#include <iostream>
#include <windows.h>

Graphic::Graphic(){}

Graphic::~Graphic(){}

void Graphic::MainLoop() {
	RenderWindow MyWindow(VideoMode(200, 383), "TETRIS by B.Gac");
	MyWindow.setFramerateLimit(9);
	MyWindow.setVerticalSyncEnabled(true);
	Font font;
	font.loadFromFile("arial.ttf");
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	Event event;
	Active MyActive = Active::Active();
	Garbage MyGarbage = Garbage::Garbage();
	while (true) {
		MyActive.MoveDown(MyGarbage);
		MyWindow.clear(Color::Black);
		MyWindow.pollEvent(event);
		if (event.type == Event::Closed) {
			MyWindow.close();
			break;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right)) {
			MyActive.MoveRight(MyGarbage);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			MyActive.MoveLeft(MyGarbage);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			MyActive.MoveDown(MyGarbage);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up)) {
			MyActive.TestRotate(MyGarbage);
		}
		else if (Keyboard::isKeyPressed(Keyboard::R)) {
			MyGarbage.ResetGame();
		}
		DrawEverything(MyActive, MyWindow, MyGarbage, font);				//Draw Blocks from Active and Garbage
		MyWindow.display();
	}
};

void Graphic::DrawBlock(Block &MyBlock, RenderWindow& window){
	RectangleShape drawblock(Vector2f(16, 16));
	drawblock.setFillColor(Color(MyBlock.ReturnRED(), MyBlock.ReturnGREEN(), MyBlock.ReturnBLUE()));
	drawblock.setOutlineThickness(1);
	drawblock.setOutlineColor(sf::Color::White);
	drawblock.setPosition(5 + (17 * MyBlock.ReturnX()), 5 + (17 * MyBlock.ReturnY()));
	window.draw(drawblock);
};

void Graphic::DrawEverything(Active MyActive, RenderWindow& MyWindow, Garbage MyGarbage, Font font) {
	Grid(MyWindow);
	Score(MyWindow, font, MyGarbage);
	for (int a = 0; a < 4; a++) {
		DrawBlock(MyActive.ReturnBlock(a), MyWindow);
	}
	for (int g = 0; g < MyGarbage.ReturnSize(); g++) {
		DrawBlock(MyGarbage.ReturnBlock(g), MyWindow);
	}
};

void Graphic::Grid(RenderWindow& window) {
	for (int i = 0; i < 11; i++) {
		sf::RectangleShape line(sf::Vector2f(357, 1));
		line.rotate(90);
		line.setPosition(5 + 17 * i, 5);
		line.setFillColor(Color(117, 117, 117, 200));
		window.draw(line);
	}
	for (int i = 0; i < 22; i++) {
		sf::RectangleShape line(sf::Vector2f(170, 1));
		line.rotate(0);
		line.setPosition(5, 4 + 17 * i);
		line.setFillColor(Color(117, 117, 117, 200));
		window.draw(line);
	}
};

void Graphic::Score(RenderWindow& window, Font font, Garbage MyGarbage) {
	Text text;
	text.setFont(font);
	String ScoreText = "Score: ";
	ostringstream oss;
	oss << MyGarbage.ReturnScore()*10;
	ScoreText += oss.str();
	oss.str();
	text.setString(ScoreText);
	text.setCharacterSize(16);
	text.setFillColor(Color(117, 117, 117, 200));
	text.setPosition(10, 365);
	window.draw(text);
}