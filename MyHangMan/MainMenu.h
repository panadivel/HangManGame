#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <conio.h>

class Model{
private:
	bool goFurther;
public:
	Model() : goFurther(false) {}
	bool getState() { return goFurther; }
	void changeState() { goFurther ? (goFurther = false) : (goFurther = true); }
};



class Controller
{
private:
	int _input;
public:
	Controller() : _input(0) {}
	void setInput() { _input = getch(); }
	int getInput() { return _input; }
};

class View
{
private:
	Controller controller1;
	Model menu1;
public:
	View()
	{

		system("cls");
		std::cout << "\n\n\n\n\n\n\n\n\t\t\tHANGMAN THE GAME\n\n\n"
			<< "\n\n\n\n\n\n\n\n\n\n\n"
			<< "\t\tpress 'enter' or 'space' to continue\n";
		while (!menu1.getState())
		{
			controller1.setInput();
			if (controller1.getInput() == 13 || controller1.getInput() == 32)
				menu1.changeState();
			else
				continue;
		}
		system("cls");
	}
};


#endif