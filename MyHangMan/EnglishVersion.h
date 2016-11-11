#ifndef ENGVERSION_H
#define ENGVERSION_H

#include <iostream>
#include <string>
#include <algorithm>

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

//english version

void EngGame(){
	std::string word;
	char ch;
	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int mistakes = 0;
	std::string playField;

	std::cout << "\n\n               ENTER A WORD FOR OPPONENT: " << std::endl;
	std::cout << "(of course your opponent should not look at the screen)" << std::endl;
	std::getline(std::cin, word);

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
		if (word == playField){
			std::cout << "\n\nCongratulations! You WIN!" << std::endl;
			std::cout << "Do you want to try again?" << std::endl;
			std::cout << "(/'esc/' to exit, any button for continue)" << std::endl;
			int input;
			input = getch();
			if (input == 27)
			{
				break;
			else
			{
				system("cls");
				EngGame();
			}
				
		}
		if (mistakes == 5){
			std::cout << "You loose, you hanged!" << std::endl;
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

#endif