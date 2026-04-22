
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

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

enPrimeNotPrime CheckPrime(int Number)
{
	int M = round(Number / 2);
	

		for (int Counter = 2; Counter <= M; Counter++)
		{
			if (Number % Counter == 0)
				return enPrimeNotPrime::NotPrime;
		}
	

	return enPrimeNotPrime::Prime;
}

void GetPrimeNumberArray(int Arr1[100], int Arr2[100], int ArrSize, int& ArrSize2)
{

	ArrSize2 = 0;

	for (int i = 0; i < ArrSize; i++)
	{

		if (CheckPrime(Arr1[i])==enPrimeNotPrime::Prime)
		{
			Arr2[ArrSize2] = Arr1[i];
			ArrSize2++;
		}
	
	}
}



int main()
{
	srand(unsigned(time(NULL)));
	int Arr1[100];
	
	int ArrSize;
	FillArrayElements(Arr1, ArrSize);

	cout << "\nOriginal array : " << endl;
	cout << "\n[";
	PrintArrayElements(Arr1, ArrSize);
	cout << "]" << endl;

	int Arr2[100], Arr2Size;
	GetPrimeNumberArray(Arr1, Arr2, ArrSize, Arr2Size);

	cout << "\nPrime array : " << endl;
	cout << "\n[";
	PrintArrayElements(Arr2, Arr2Size);
	cout << "]" << endl;

	return 0;
}