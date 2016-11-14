#include "SingleVersion.h"
#include "Globals.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <conio.h>
#include <fstream>
#include <vector>
#include <random>
#include <time.h>


//single version

std::string returnRandWord();

void SingGame(){
	
	std::string word;
	char ch;
	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int mistakes = 0;
	std::string playField;

	system("cls");

	//pick a random word from a file

	word = returnRandWord();

	std::transform(word.begin(), word.end(), word.begin(), ::toupper);

	system("cls");

	for (int i = 0; i < word.length(); i++)
		playField.append("_");

	while (mistakes < 6){

		std::cout << hangmans[mistakes];
		std::cout << "\n\n\t" << playField << "\n\n";
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

std::string returnRandWord()
{
	std::vector<std::string> words;
	std::ifstream wordsfile("wordsForSingleGame.txt");
	std::string w;

	if (!wordsfile)
	{
		std::cerr << "Cannot open file \"wordsForSingleGame.txt\" with words\n";
		exit(EXIT_FAILURE);
	}

	while (getline(wordsfile, w))
	{
		words.push_back(w);
	}

	srand(time(0));
	int randInd = rand() % words.size();

	return words[randInd];
}