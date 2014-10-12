// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct word
{
	string indefSing;
	string defSing;
	string indefPlural;
	string defPlural;
};
word sAeble = { "aeble", "aeblet", "aebler", "aeblerne" };
word sBog = { "bog", "bogen", "boger", "bogerne" };
word sHund = { "hund", "hunden", "hunde", "hundene" };
word sBarn = { "barn", "barnet", "born", "bornene" };
word sAnd = { "and", "anden", "aender", "aenderne" };
word sKartoffel = { "kartoffel", "kartoflen", "kartofler", "kartoflerne" };
word sOl = { "ol", "ollen", "oller", "ollene" };

string promptform;
string wordform;
word rightword;

void pickword();
string userword;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "welcome to mr jiggys danish noun declension practice" << endl;
	cout << endl;
	cout << endl;
	int numberright = 0;
	for (int i = 0; i < 10; i++)
	{
		pickword();
		cout << "Decline the word '" << rightword.indefSing << "' in the " << promptform << endl;
		cin >> userword;
		if (userword == wordform)
		{
			cout << "Good job." << endl;
			numberright++;
		}
		else
			cout << "Sorry. The correct answer is " << wordform << "." << endl;
		cout << endl;
	}
	cout << "You got " << numberright << " out of 10 questions right. ";
	if (numberright == 10)
		cout << "Outstanding!" << endl;
	else if (numberright == 8 || numberright == 9)
		cout << "Well Done!" << endl;
	else if (numberright == 6 || numberright == 7)
		cout << "Not bad." << endl;
	else cout << "You could use some more practice." << endl;

	return 0;
}

void pickword()
{


	srand(time(NULL));
	int wordnumber = rand() % 7;
	switch (wordnumber) //picks the word to change
	{
	case 0:
		rightword = sAeble;
		break;
	case 1:
		rightword = sBog;
		break;
	case 2:
		rightword = sHund;
		break;
	case 3:
		rightword = sBarn;
		break;
	case 4:
		rightword = sAnd;
		break;
	case 5:
		rightword = sKartoffel;
		break;
	case 6:
		rightword = sOl;
		break;
	};
	int wordformnumber = rand() % 3;
	switch (wordformnumber) //decides which form of the word to use
	{
	case 0:
		wordform = rightword.defSing;
		promptform = "definite singular";
		break;
	case 1:
		wordform = rightword.indefPlural;
		promptform = "indefinite plural";
		break;
	case 2:
		wordform = rightword.defPlural;
		promptform = "definite Plural";
		break;
	};
}
