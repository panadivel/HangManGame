#include "MultiVersion.h"
#include "Globals.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <conio.h>


//multiplayer version

void MultiGame(){
	std::string word;
	char ch;
	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int mistakes = 0;
	std::string playField;

	system("cls");
	
	std::cout << "\n\n               ENTER A WORD FOR OPPONENT: " << std::endl;
	std::cout << "(of course your opponent should not look at the screen)" << std::endl;
	std::getline(std::cin, word);

	//erasing digit, spaces and punctuation from the word
	word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
	word.erase(std::remove_if(word.begin(), word.end(), isdigit), word.end());
	word.erase(std::remove_if(word.begin(), word.end(), isspace), word.end());

	std::transform(word.begin(), word.end(), word.begin(), ::toupper);

	system("cls");

	for (int i = 0; i < word.length(); i++)
		playField.append("_");

	while (mistakes < 6){

		std::cout << hangmans[mistakes];
		std::cout << "\n\n" << playField << "\n\n";
		std::cout << "   remaining characters:\n" << alphabet << "\n\n\n";
		
		//check for win
		if (word == playField){
			std::cout << "\n\nCongratulations! You WIN!" << std::endl;
			break;
		}
		
		//check for loose
		if (mistakes == 5){
			std::cout << "\n\nYou loose, you hanged!" << std::endl;
			break;
		}
		
		std::cout << "Enter a character: ";
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
			std::cout << "Wrong character, try again!";
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