
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

int ReadElementToSearch(string Message)
{
	int Number = 0;

	while (true) // حلقة تكرار لا نهائية حتى يدخل المستخدم رقماً صحيحاً
	{
		cout << Message;
		cin >> Number;

		// التحقق مما إذا كان الإدخال ناجحاً (رقم)
		if (cin.fail())
		{
			// 1. تصفير حالة الخطأ في cin
			cin.clear();

			// 2. مسح الحروف أو الرموز العالقة في الذاكرة المؤقتة (Buffer)
			cin.ignore(100, '\n');

			cout << "\nInvalid Input! Please enter a valid number (Letters and Symbols are not allowed).\n" << endl;
		}
		else
		{
			// إذا كان الإدخال رقماً صحيحاً، نخرج من الحلقة ونعيد القيمة
			return Number;
		}
	}
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

int SearchForAnElement(int Arr[100], int ArrSize, int Element)
{
	
	for (int i = 0; i < ArrSize; i++)
	{
		if (Element==Arr[i])
		{
			return i;
		}
		
	}
	return -1;
}

void PrintSearchResult(int Arr[100], int ArrSize, int Element)
{
	int i = SearchForAnElement(Arr, ArrSize, Element);
	if (i != -1)
	{
		
		cout << "Found at index: " << i << endl;
		cout << "Found at position: " << i + 1 << endl;
	}
	else
	{
		cout << "Not found in the array." << endl;
	}
}


int main()
{
	srand(unsigned(time(NULL)));
	int Arr[100];
	int ArrSize = ReadArraySize("Please enter the size of the array : ");
	
	FillArrayElements(Arr, ArrSize);

	cout << "\nArray elements are: " << endl;
	cout << "\n[";
	PrintArrayElements(Arr, ArrSize);
	cout << "]" << endl;

	int Element = ReadElementToSearch("Please enter the element to search for : ");
	
	cout << "\nNumber " << Element << "  you are looking for is: " << endl;
	PrintSearchResult(Arr, ArrSize, Element);

	return 0;
}