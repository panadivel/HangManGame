#include "ChooseModeMenu.h"

ChooseMView::ChooseMView()
	: isMulti(true)
{
	system("cls");
	std::cout << "\n\n\n\n\t\t\t   Choose mode\n\n\n"
		<< "\t\t        << MultiPlayer >>\n\n"
		<< "\t\t           SinglePlayer";
	while (!menu1.getState())
	{
		controller1.setInput();
		if (controller1.getInput() == 13 || controller1.getInput() == 32)
			menu1.changeState();
		else if (controller1.getInput() == 224)
		{
			if (getIsMulti() == false)
			{
				system("cls");
				std::cout << "\n\n\n\n\t\t\t   Choose mode\n\n\n"
					<< "\t\t        << MultiPlayer >>\n\n"
					<< "\t\t           SinglePlayer";
				switchIsMulti();
			}
			else
			{
				system("cls");
				std::cout << "\n\n\n\n\t\t\t   Choose mode\n\n\n"
					<< "\t\t           MultiPlayer\n\n"
					<< "\t\t        << SinglePlayer >>";
				switchIsMulti();
			}

		}
		continue;
	}
	system("cls");
	}