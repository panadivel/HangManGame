#include "ChooseLanguageMenu.h"

ChooseLMView::ChooseLMView()
	: isEnglish(true)
{
	system("cls");
	std::cout << "\n\n\n\n\t\t\tChoose language\n\n"
		<< "\t\t         �������� ����\n\n\n\n\n\n"
		<< "\t\t        << English >>\n\n"
		<< "\t\t           �������";
	while (!menu1.getState())
	{
		controller1.setInput();
		if (controller1.getInput() == 13 || controller1.getInput() == 32)
			menu1.changeState();
		else if (controller1.getInput() == 224)
		{
			if (getIsEnglish() == false)
			{
				system("cls");
				std::cout << "\n\n\n\n\t\t\tChoose language\n\n"
					<< "\t\t         �������� ����\n\n\n\n\n\n"
					<< "\t\t        << English >>\n\n"
					<< "\t\t           �������";
				switchIsEnglish();
			}
			else
			{
				system("cls");
				std::cout << "\n\n\n\n\t\t\tChoose language\n\n"
					<< "\t\t         �������� ����\n\n\n\n\n\n"
					<< "\t\t           English\n\n"
					<< "\t\t        << ������� >>";
				switchIsEnglish();
			}

		}
		continue;
	}
	system("cls");
	}