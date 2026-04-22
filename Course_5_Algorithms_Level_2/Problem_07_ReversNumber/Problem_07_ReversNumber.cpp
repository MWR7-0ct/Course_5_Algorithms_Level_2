
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

int GetReverseNumber(int Number)
{
    int Reminder = 0, ReverseNumber = 0;
    while (Number > 0)
    {
        Reminder = Number % 10;
        Number = Number / 10;
        ReverseNumber = (ReverseNumber*10)+Reminder;
    }
    return ReverseNumber;
}

int main()
{
    int Number = ReadPositiveNumber("Please enter a positive numbers: ");
    cout << "\nReverse = " << GetReverseNumber(Number) << endl;

    return 0;
}