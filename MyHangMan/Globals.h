#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>

// strings for hangman output

static std::string hangman1 =
"          _\n"
"          |\n\n\n\n";
static std::string hangman2 =
"          _\n"
"          |\n"
"          0\n\n\n";
static std::string hangman3 =
"          _\n"
"          |\n"
"          0\n"
"          O \n\n";
static std::string hangman4 =
"          _\n"
"          |\n"
"          0\n"
"         /O\\\n\n";
static std::string hangman5 =
"          _\n"
"          |\n"
"          0\n"
"         /O\\\n"
"         / \n";
static std::string hangman6 =
"          _\n"
"          |\n"
"          0\n"
"         /O\\\n"
"         //\n";

static std::string hangmans[6] = { hangman1, hangman2, hangman3, hangman4, hangman5, hangman6 };

#endif