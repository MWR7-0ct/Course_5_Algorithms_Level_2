
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

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

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

int ReadArraySize(string Message)
{
	int ArrSize = 0;
	do
	{
		cout << Message;
		cin >> ArrSize;
		if (ArrSize <= 0 || ArrSize > 100) {
			cout << "Invalid size! " << endl;
		}
	} while (ArrSize <= 0 || ArrSize > 100);

	return ArrSize;
}

void FillArrayElements(int Arr[100], int& ArrSize)
{
	cout << "Please enter the size of the array (1-100): ";
	cin >> ArrSize;

	for (int i = 0; i < ArrSize; i++)
	{
		Arr[i] = RandomNumber(1, 100);
	}
}

void PrintArrayElements(int Arr[100], int ArrSize)
{
	for (int i = 0; i < ArrSize; i++)
	{
		cout << Arr[i];
		if (i < ArrSize - 1)
		{
			cout << "," << " ";
		}
	}
}


int FindMaxOfArray(int Arr[100], int ArrSize)
{
	int Max = Arr[0];
	for (int i = 1; i < ArrSize; i++)
	{
		if (Arr[i] > Max)
		{
			Max = Arr[i];
		}
	}
	return Max;
}
int main()
{
	srand(unsigned(time(NULL)));
	int Arr[100];
	int ArrSize;
	
	FillArrayElements(Arr, ArrSize);

	cout << "\nArray elements are: " << endl;
	cout << "\n[";
	PrintArrayElements(Arr, ArrSize);
	cout << "]" << endl;

	cout << "\nThe maximum element in the array is: " << endl;
	cout << FindMaxOfArray(Arr, ArrSize) << endl;

	return 0;
}