#ifndef CHOOSEM_H
#define CHOOSEM_H

#include <iostream>
#include <conio.h>

class ChooseMModel{
private:
	bool goFurther;
public:
	ChooseMModel() : goFurther(false) {}
	bool getState() { return goFurther; }
	void changeState() { goFurther ? (goFurther = false) : (goFurther = true); }
};



class ChooseMController
{
private:
	int _input;
public:
	ChooseMController() : _input(0) {}
	void setInput() { _input = getch(); }
	int getInput() { return _input; }
};

class ChooseMView
{
private:
	ChooseMController controller1;
	ChooseMModel menu1;
	bool isMulti;
public:
	ChooseMView();
	bool getIsMulti() { return isMulti; }
	void switchIsMulti() { isMulti == true ? (isMulti = false) : (isMulti = true); }
};

#endif