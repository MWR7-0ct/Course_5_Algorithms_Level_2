
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


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

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void FillArrayElements(int Arr[100], int ArrSize)
{
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

void GetSumArrays(int Arr1[100], int Arr2[100],int ArrSum[100], int ArrSize)
{
	for (int i = 0; i < ArrSize; i++)
	{
		ArrSum[i]=Arr2[i] + Arr1[i];
	}
}

int main()
{
	srand(unsigned(time(NULL)));
	int Arr1[100];
	int Arr2[100];
	int ArrSum[100];
	int ArrSize= ReadArraySize("Please enter the size of the array (1-100): ");

	FillArrayElements(Arr1, ArrSize);
	FillArrayElements(Arr2, ArrSize);

	cout << "\nArray 1: " << endl;
	cout << "[";
	PrintArrayElements(Arr1, ArrSize);
	cout << "]" << endl;

	cout << "\nArray 2: " << endl;
	cout << "[";
	PrintArrayElements(Arr2, ArrSize);
	cout << "]" << endl;

	GetSumArrays(Arr1, Arr2, ArrSum, ArrSize);

	cout << "\nSum of 2 arrays: " << endl;
	cout << "[";
	PrintArrayElements(ArrSum, ArrSize);
	cout << "]" << endl;	
	
	return 0;
}