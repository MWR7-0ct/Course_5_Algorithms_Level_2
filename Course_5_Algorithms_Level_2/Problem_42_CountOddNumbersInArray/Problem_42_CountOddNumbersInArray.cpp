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
        Arr[i] = RandomNumber(1,100);
    }
}


void CountOddElement(int Arr1[100], int ArrLength1,int &CountOddNumbers)
{
    CountOddNumbers = 0;
    for (int i = 0; i < ArrLength1; i++) {

        if (Arr1[i] %2 != 0)
        {
            CountOddNumbers++;
        }
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
srand((unsigned int)time(NULL));

    int arr1[100];



    int arrLength1 = ReadNumber();

    FillArrayElements(arr1, arrLength1);

    cout << "Array1 elements: ";
    PrintArray(arr1, arrLength1);

    int CountOddNumbers = 0;


    CountOddElement(arr1, arrLength1, CountOddNumbers);
    cout << "\nOdd Numbers is : " << CountOddNumbers << "\n";


    return 0;
}