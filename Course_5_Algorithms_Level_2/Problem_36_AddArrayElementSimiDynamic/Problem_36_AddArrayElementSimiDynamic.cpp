#include <iostream>
#include <string>

using namespace std;

void AddArrayElement(int Number, int Arr[100], int& ArrLength)
{
    Arr[ArrLength] = Number;
    ArrLength++;
}

int ReadNumber()
{
    int Number;
    cout << "Please enter a number: ";
    cin >> Number;
    return Number;
}

void FillArraySemiDynamic(int Arr[100], int& ArrLength)
{
    bool AddMore = true;

    do
    {
        AddArrayElement(ReadNumber(), Arr, ArrLength);

        do {
            cout << "\nDo you want to add more numbers? [0]:No, [1]:Yes? ";
            cin >> AddMore;
        } while (AddMore != 0 && AddMore != 1);

    } while (AddMore);
}

void PrintArray(int Arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        cout << Arr[i] << (i < ArrLength - 1 ? ", " : "");
    }
}

int main()
{
    int Arr[100];
    int ArrLength = 0; 

    FillArraySemiDynamic(Arr, ArrLength);

    cout << "\nArray Length: " << ArrLength << endl;
    cout << "Array elements: [ ";
    PrintArray(Arr, ArrLength);
    cout << " ]" << endl;

    return 0;
}