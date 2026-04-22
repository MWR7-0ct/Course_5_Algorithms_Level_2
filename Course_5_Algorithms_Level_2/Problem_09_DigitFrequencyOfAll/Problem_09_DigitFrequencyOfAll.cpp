
#include <iostream>
#include <string>

using namespace std;


long long ReadPositiveNumber(string Message)
{
    long long Number = 0;

    do
    {
        cout << Message;
        cin >> Number;
    } while (Number < 0);

    return Number;
}

int CountDigitFrequency(long long MainNumber, short checkNumber)
{
    int Reminder = 0, FreqCounter = 0;

    while (MainNumber > 0)
    {
        Reminder = MainNumber % 10;
        MainNumber = MainNumber / 10;
        if (Reminder == checkNumber)
        {
            FreqCounter++;
        }
    }
    return  FreqCounter;
}

void PrintAllDigitsFrequency(long long MainNumber) // غيرنا النوع هنا ليتوافق مع long long
{
    for (int i = 0; i < 10; i++)
    {
        short Freq = CountDigitFrequency(MainNumber, i);
        if (Freq > 0) // هذا السطر سيجعل المخرج أنيقاً مثل الصورة تماماً
        {
            cout << "Digit (" << i << ") frequency is (" << Freq << ") time(s)" << endl;
        }
    }
}

int main()
{
    long long MainNumber = ReadPositiveNumber("Please enter the main number: ");
    PrintAllDigitsFrequency(MainNumber);

    return 0;
}
