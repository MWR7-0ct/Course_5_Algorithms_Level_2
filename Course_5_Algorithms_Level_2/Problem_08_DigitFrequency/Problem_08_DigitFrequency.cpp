
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
    } while (Number < 0);

    return Number;
}

int GetDigitFrequency(int MainNumber, short DigitToCheck)
{
    if (MainNumber == 0 && DigitToCheck == 0) return 1;

    int Reminder = 0, FreqCounter = 0;
    while (MainNumber > 0)
    {
        Reminder = MainNumber % 10;
        MainNumber = MainNumber / 10;
        if (Reminder == DigitToCheck)
        {
            FreqCounter++;
        }
    }
    return FreqCounter;
}



int main()
{
    int MainNumber = ReadPositiveNumber("Please enter the main number: ");
    short DigitToCheck = ReadPositiveNumber("Please enter the digit you want to count: ");
    cout << "\nDigit (" << DigitToCheck << ") frequency is (" << GetDigitFrequency(MainNumber, DigitToCheck) << ") time(s)" << endl;

    return 0;
}
