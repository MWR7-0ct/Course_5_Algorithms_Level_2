#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
//#include "GetRandomCharacter.h"

using namespace std;

enum enCharType {
	SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4
};

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

char GetRandomChar(enCharType CharType) {

	switch (CharType)
	{
	case enCharType::CapitalLetter:
		return char(RandomNumber(65, 90));
		break;

	case enCharType::SmallLetter:
		return char(RandomNumber(97, 122));
		break;

	case enCharType::Digit:
		return char(RandomNumber(48, 57));
		break;

	case enCharType::SpecialCharacter:
		return char(RandomNumber(33, 47));
		break;

	default:
		return '\0';
	}
}

int main()
{

	srand((unsigned)time(NULL));

	cout << "Random Small Letter:    " << GetRandomChar(enCharType::SmallLetter) << endl;
	cout << "Random Capital Letter:   " << GetRandomChar(enCharType::CapitalLetter) << endl;
	cout << "Random Special Character: " << GetRandomChar(enCharType::SpecialCharacter) << endl;
	cout << "Random Digit:              " << GetRandomChar(enCharType::Digit) << endl;

	return 0;
}