#include "RussianVersion.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <conio.h>


//russian version

void RusGame(){
	setlocale(LC_ALL, "1251");

	// strings for hangman output

	std::string hangman1 =
		"          _\n"
		"          |\n\n\n\n";
	std::string hangman2 =
		"          _\n"
		"          |\n"
		"          0\n\n\n";
	std::string hangman3 =
		"          _\n"
		"          |\n"
		"          0\n"
		"          O \n\n";
	std::string hangman4 =
		"          _\n"
		"          |\n"
		"          0\n"
		"         /O\\\n\n";
	std::string hangman5 =
		"          _\n"
		"          |\n"
		"          0\n"
		"         /O\\\n"
		"         / \n";
	std::string hangman6 =
		"          _\n"
		"          |\n"
		"          0\n"
		"         /O\\\n"
		"         //\n";

	std::string hangmans[6] = { hangman1, hangman2, hangman3, hangman4, hangman5, hangman6 };

	std::string word;
	char ch;
	std::string alphabet = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÜİŞß";
	int mistakes = 0;
	std::string playField;

	system("cls");

	std::cout << "\n\n               ÇÀÃÀÄÀÉÒÅ ÑËÎÂÎ ÄËß ÑÎÏÅĞÍÈÊÀ: " << std::endl;
	std::cout << "         (âàø ñîïåğíèê íå äîëæåí ñìîòğåòü íà ıêğàí)" << std::endl;
	std::getline(std::cin, word);

	/*
	//erasing digit, spaces and punctuation from the word
	word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
	word.erase(std::remove_if(word.begin(), word.end(), isdigit), word.end());
	word.erase(std::remove_if(word.begin(), word.end(), isspace), word.end());
	*/

	std::transform(word.begin(), word.end(), word.begin(), ::toupper);

	system("cls");

	for (int i = 0; i < word.length(); i++)
		playField.append("_");

	while (mistakes < 6){

		std::cout << hangmans[mistakes];
		std::cout << "\n\n" << playField << "\n\n";
		std::cout << "   Îñòàâøèåñÿ áóêâû:\n" << alphabet << "\n\n\n";

		//check for win
		if (word == playField){
			std::cout << "\n\nÏîçäğàâëÿåì! Âû ÏÎÁÅÄÈËÈ!" << std::endl;
			break;
		}

		//check for loose
		if (mistakes == 5){
			std::cout << "\n\nÂû ïğîèãğàëè, âû ïîâåøåíû!" << std::endl;
			break;
		}

		std::cout << "Ââåäèòå áóêâó: ";
		std::cin >> ch;
		ch = toupper(ch);

		bool ismatch = false;
		for (int i = 0; i < alphabet.length(); i++)
		{
			if (alphabet[i] == ch){
				alphabet[i] = '-';
				ismatch = true;
			}
		}
		if (ismatch == false){
			std::cout << "Íåâåğíàÿ áóêâà, ïîïğîáóéòå åùå ğàç!";
			for (int i = 0; i < 800000000; i++){}
			system("cls");
			continue;
		}

		int matches = 0;

		for (int i = 0; i < word.length(); i++){
			if (ch == word[i])
			{
				playField[i] = word[i];
				matches++;
			}
		}

		if (matches == 0)
		{
			mistakes++;
		}

		system("cls");
	}

}