
#include <iostream>
#include <string>

using namespace std;


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

int GetSumOfDigits(int Number)
{
    int Reminder = 0, Sum = 0;
    while (Number > 0)
    {
        Reminder = Number % 10;
        Number = Number / 10;
        Sum += Reminder;
    }
    return Sum;
}

int main()
{
    int Number = ReadPositiveNumber("Please enter a positive numbers: ");
    cout << "\nSum Of Digits = " << GetSumOfDigits(Number) << endl;

    return 0;
}