
#include <iostream>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;

	do
	{
		cout << Message;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

void InvertedNumberPattern(int Number)
{
	for (int i = 65; i <= Number - 1 + 65; i++)
	{
		for (int j = 1; j <= i - 65 + 1; j++)
		{
			cout << (char)i << " ";
		}
		cout << endl;
	}
}


int main()
{

	InvertedNumberPattern(ReadPositiveNumber("Please enter a positive numbers : "));

	return 0;
}

