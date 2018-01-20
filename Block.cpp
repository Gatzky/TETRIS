#include "Block.h"
using namespace sf;

Block::Block(int defx, int defy, int defred, int defgreen, int defblue) { x = defx; y = defy; red = defred; green = defgreen; blue = defblue; }

Block::~Block(){}

void Block::SetXY(int newx, int newy) {
	x = newx;
	y = newy;
}
void Block::SetColor(int newred, int newgreen, int newblue) {
	red = newred;
	green = newgreen;
	blue = newblue;
}

int Block::ReturnX() {
	return x;
}
int Block::ReturnY() {
	return y;
}
int Block::ReturnRED() {
	return red;
}
int Block::ReturnGREEN() {
	return green;
}
int Block::ReturnBLUE() {
	return blue;
}