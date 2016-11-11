#ifndef CHOOSELM_H
#define CHOOSELM_H

#include <iostream>
#include <conio.h>

class ChooseLMModel{
private:
	bool goFurther;
public:
	ChooseLMModel() : goFurther(false) {}
	bool getState() { return goFurther; }
	void changeState() { goFurther ? (goFurther = false) : (goFurther = true); }
};



class ChooseLMController
{
private:
	int _input;
public:
	ChooseLMController() : _input(0) {}
	void setInput() { _input = getch(); }
	int getInput() { return _input; }
};

class ChooseLMView
{
private:
	ChooseLMController controller1;
	ChooseLMModel menu1;
	bool isEnglish;
public:
	ChooseLMView();
	bool getIsEnglish() { return isEnglish; }
	void switchIsEnglish() { isEnglish == true ? (isEnglish = false) : (isEnglish = true); }
};

#endif