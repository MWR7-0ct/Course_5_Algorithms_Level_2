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

	} while (Number > 100 || Number <= 0);

	return Number;
}

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrayRandomly(int arr[100], int arr_size) 
{
	for (int i = 0; i < arr_size; i++) 
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int arr[100],int array_size)
{
	for (int i = 0; i < array_size; i++) 
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void CopyArrayInReverseOrder(int arr1[100],int arr2[100], int arr_size)
{
	/*for (int i = 0; i < arr_size / 2; i++) 
	{
		int temp = arr1[i];
		arr1[i] = arr1[arr_size - 1 - i];
		arr1[arr_size - 1 - i] = temp;
	}*/
	for (int i = 0; i < arr_size ; i++) 
	{
		arr2[i] = arr1[arr_size - 1 - i];
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int array_size = ReadArraySize("Please enter array size (1-100) : ");
	int arr1[100],arr2[100];

	FillArrayRandomly(arr1, array_size);
	PrintArray(arr1, array_size);

	CopyArrayInReverseOrder(arr1,arr2, array_size);
	PrintArray(arr2, array_size);

	return 0;
}