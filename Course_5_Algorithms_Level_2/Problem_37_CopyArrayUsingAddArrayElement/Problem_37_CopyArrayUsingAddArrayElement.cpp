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

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillArrayElements(int Arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        Arr[i] = RandomNumber(1, 100);
    }
}

void CopyArrayElement(int Number, int Arr2[100], int& ArrLength2)
{
    Arr2[ArrLength2] = Number;
    ArrLength2++;
}

void SendArrayElement(int Arr1[100], int Arr2[100], int ArrLength1, int& ArrLength2)
{
    ArrLength2 = 0;

    for (int i = 0; i < ArrLength1; i++)
    {
        CopyArrayElement(Arr1[i], Arr2, ArrLength2);
    }
}


void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";  
}

int main()
{
    srand(unsigned(time(NULL)));

    int arr1[100];
    int arr2[100];

    int arrLength1 = ReadNumber();
    int arrLength2= 0;

    FillArrayElements(arr1, arrLength1);

    cout << "Array1 elements: ";
    PrintArray(arr1, arrLength1);

    SendArrayElement(arr1, arr2, arrLength1, arrLength2);

    cout << "Array2 elements: ";
    PrintArray(arr2, arrLength2);
    return 0;
}