//#include "stdafx.h"
#include "Graphic.h"
#include <cstdlib>
#include <ctime>
#include <windows.h>


int main()
{	
	srand(time(NULL));
	Graphic MyGraphic = Graphic::Graphic();
	MyGraphic.MainLoop();
	return 0;
}

//Rotacja zamula
//Przycisk reset, pause
//Podglad nastepnego klocka
//Muzyczka
//Intro
//Poziomy i przyspieszanie