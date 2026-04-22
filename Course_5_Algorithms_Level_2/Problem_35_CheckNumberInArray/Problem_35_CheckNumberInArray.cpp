
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

int FindNumberPositionInArray(int Arr[100], int ArrSize, int Element)
{
	for (int i = 0; i < ArrSize; i++)
	{
		if (Arr[i] == Element)
			return i;      // وجدناه ← أعد موقعه
	}
	return -1;             // لم نجده
}

// ── دالة 2: تبني فوق دالة 1 وترجع bool ─────────────────
bool IsNumberInArray(int Arr[100], int ArrSize, int Element)
{
	return FindNumberPositionInArray(Arr, ArrSize, Element) != -1;
	//     ↑ تستدعي دالة 1 مباشرة ← لا تكرار للكود
}

// ── دالة 3: الطباعة تستخدم دالة 2 ──────────────────────
void PrintSearchResult(int Arr[100], int ArrSize, int Element)
{
	if (IsNumberInArray(Arr, ArrSize, Element))
		cout << "Yes, The number is found :-)" << endl;
	else
		cout << "No, The number is not found :-(" << endl;
}

// في المستقبل لو احتجت الموقع أيضاً:

//void PrintIndexResult(int Arr[100], int ArrSize, int Element)
//{
//	int Position = FindNumberPositionInArray(Arr, ArrSize, Element);
//
//	if (Position != -1)
//	{
//		cout << "Yes, The number is found :-)" << endl;
//		cout << "Found at index:    " << Position << endl;
//		cout << "Found at position: " << Position + 1 << endl;
//	}
//	else
//		cout << "No, The number is not found :-(" << endl;
//}


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

	int Element = ReadElementToSearch("\nPlease enter the element to search for : ");

	cout << "\nNumber you are looking for is: " << Element << endl;
	PrintSearchResult(Arr, ArrSize, Element);

	return 0;
}