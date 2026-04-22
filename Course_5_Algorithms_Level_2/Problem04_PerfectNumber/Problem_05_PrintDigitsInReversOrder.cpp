
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

void GetSumOfDigits(int Number)
{
    cout << "\nDigits in reverse order: \n" << endl;
    int Reminder = 0;
    while (Number > 0)
    {
        Reminder = Number % 10;
        Number = Number / 10;
        cout << Reminder << endl;
    }

}

int main()
{

    GetSumOfDigits(ReadPositiveNumber("Please enter a positive numbers: "));
    

    return 0;
}