
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
	for (int i = Number - 1 + 65; i >= 65; i--)
	{
		for (int j = i; j >= 65; j--)
		{
			cout << (char)i << " ";
		}
		/*for (int j = 1; j >= Number - ((65 + Number - 1) - i); j++)
		{
			//cout << (char)i << " ";
		}*/
		cout << endl;
	}
}


int main()
{

	InvertedNumberPattern(ReadPositiveNumber("Please enter a positive numbers : "));

	return 0;
}

