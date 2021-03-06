#include <iostream>
#include <conio.h>
#include "MainMenu.h"
#include "ChooseModeMenu.h"
#include "MultiVersion.h"
#include "SingleVersion.h"

bool playAgain();

int main()
{
	setlocale(LC_ALL, "Russian");

	View * myview = new View;
	ChooseMView * myview1 = new ChooseMView;
	
	if (myview1->getIsMulti() == true){
		do
			MultiGame();
		while (playAgain());
	}
	else
	{
		do
			SingGame();
		while (playAgain());
	}


	delete myview;
	delete myview1;

	return 0;
}

bool playAgain(){
	std::cout << "Do you want to try again?" << std::endl;
	std::cout << "(\'esc\' to exit, any button for continue)" << std::endl;
	int input;
	input = getch();
	if (input == 27)
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //flush input stream
		return false;
	}
	else
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return true;
	}
}