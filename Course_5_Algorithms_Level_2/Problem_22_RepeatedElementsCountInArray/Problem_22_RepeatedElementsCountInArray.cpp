#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
void ReadArray(int Arr[100], int& ArrSize)
{
	do
	{
		cout << "Please enter the size of the array (1-100): ";
		cin >> ArrSize;

		if (ArrSize <= 0 || ArrSize > 100) {
			cout << "Invalid size! " << endl;
		}
	} while (ArrSize <= 0 || ArrSize > 100);


	cout << "Please enter elements : " << endl;
	for (int i = 0; i < ArrSize; i++)
	{
		cout << "element [" << i + 1 << "] : ";
		cin >> Arr[i];
	}
}

void PrintArray(int Arr[100],int ArrSize)
{
	for (int i = 0; i < ArrSize; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << endl;
}

int CountElementFrequency(int Arr[100], int ArrSize, int NumberToCheck)
{
	int FreqCounter = 0;
	for (int i = 0; i < ArrSize; i++)
	{
		if (Arr[i] == NumberToCheck)
		{
			FreqCounter++;
		}
	}
	return FreqCounter;
}

int main() 
{
	int Arr[100];
	int ArrSize = 0;
	

	ReadArray(Arr,ArrSize );
	cout << "Original Array: " << endl;
	PrintArray(Arr,ArrSize);

	int NumberToCheck = ReadPositiveNumber("Please enter the number to check: ");
	cout << "\nNumber (" << NumberToCheck << ") frequency is (" << CountElementFrequency(Arr, ArrSize, NumberToCheck) << ") time(s)" << endl;
}