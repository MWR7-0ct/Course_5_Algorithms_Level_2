#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



int ReadNumber()
{
    int Number;
    cout << "\nPlease enter array size? ";
    cin >> Number;
    return Number;
}


void FillArrayElements(int Arr[100], int ArrLength)
{
    cout << "Enter array elements: \n"; // إضافة رسالة عامة
    for (int i = 0; i < ArrLength; i++)
    {
        cout << "Element [" << i + 1 << "] : "; // توضيح رقم العنصر
        cin >> Arr[i];
    }
}


bool IsPalindromeArray(int Arr1[100], int ArrLength1)
{

    for (int i = 0; i < ArrLength1/2; i++) {

        if (Arr1[i] != Arr1[ArrLength1-1-i])
        {
            return false;
        }
    }
        return true;

}


void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{

    int arr1[100];


    int arrLength1 = ReadNumber();

    FillArrayElements(arr1, arrLength1);

    cout << "Array1 elements: ";
    PrintArray(arr1, arrLength1);


    if (IsPalindromeArray(arr1,arrLength1))

    {
        cout << "The array is a palindrome.";
    }

    else
    {
        cout << "The array is not a palindrome.";
    }
    return 0;
}