#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int ReadArraySize(string Message)
{
	int Number;
	do
	{
		cout << Message;
		cin >> Number;

	} while (Number >= 100 || Number <= 0);

	return Number;
}

int RandomNumber(int From,int To) 
{
	return rand() % (To - From + 1) + From;
}

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


void FillArrayWith1toN(int arr[100],int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		arr[i] = i + 1;
	}
	cout << endl;
}

void PrintArray(int arr[100], int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void ShuffleArray(int arr[100],int arr_size)
{
	for (int i = 0; i < arr_size; i++) 
	{
		Swap(arr[i],arr[RandomNumber(0,arr_size - 1)]);
	}
	
}


int main() 
{
	srand((unsigned)time(NULL));

	int arr[100];
	int array_size = ReadArraySize("Please enter array size (1-100) : ");

	FillArrayWith1toN(arr, array_size);
	PrintArray(arr, array_size);

	ShuffleArray(arr, array_size);
	PrintArray(arr, array_size);

	return 0;
}