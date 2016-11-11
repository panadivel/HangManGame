#include <iostream>
#include <conio.h>
#include "MainMenu.h"
#include "ChooseLanguageMenu.h"
#include "EnglishVersion.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	View * myview = new View;
	ChooseLMView * myview1 = new ChooseLMView;
	
	if (myview1->getIsEnglish() == true)
		EngGame();
	

	return 0;
}