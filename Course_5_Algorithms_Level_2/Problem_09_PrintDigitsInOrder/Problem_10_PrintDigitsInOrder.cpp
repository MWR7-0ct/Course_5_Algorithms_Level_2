//#include <iostream>
//#include <string>
//
//using namespace std;
//
//
//int ReadPositiveNumber(string Message)
//{
//    int Number = 0;
//
//    do
//    {
//        cout << Message;
//        cin >> Number;
//    } while (Number <= 0);
//
//    return Number;
//}
//
//int GetReverseNumber(int Number)
//{
//    int Reminder = 0, ReverseNumber = 0;
//    while (Number > 0)
//    {
//        Reminder = Number % 10;
//        Number = Number / 10;
//        ReverseNumber = (ReverseNumber * 10) + Reminder;
//    }
//    return ReverseNumber;
//}
//
//void  PrintDigitsInOrder(int Number)
//{
//    cout << "\nDigits in order: \n" << endl;
//    int Reminder = 0;
//    while (Number > 0)
//    {
//        Reminder = Number % 10;
//        Number = Number / 10;
//        cout << Reminder << endl;
//    }
//}
//
//int main()
//{   
//    PrintDigitsInOrder(GetReverseNumber(ReadPositiveNumber("Please enter a positive numbers: ")));
//
//    return 0;
//}

#include <iostream>
#include <string>

using namespace std;

// دالة قراءة الرقم وتسمح بالصفر
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

// دالة قلب الرقم (تستخدم لترتيب الطباعة)
long long GetReverseNumber(long long Number)
{
    long long Reminder = 0, ReverseNumber = 0;
    while (Number > 0)
    {
        Reminder = Number % 10;
        Number = Number / 10;
        ReverseNumber = (ReverseNumber * 10) + Reminder;
    }
    return ReverseNumber;
}

// دالة عد الخانات (لمعرفة الأصفار الضائعة)
short CountDigits(long long Number)
{
    if (Number == 0) return 1;
    short Counter = 0;
    while (Number > 0)
    {
        Number = Number / 10;
        Counter++;
    }
    return Counter;
}

// الدالة النهائية للطباعة بالترتيب مع معالجة الأصفار
void PrintDigitsInOrder(long long Number)
{
    long long Reversed = GetReverseNumber(Number);

    // 1. نحسب كم خانة كانت في الرقم الأصلي وكم أصبحت بعد القلب
    short OriginalCount = CountDigits(Number);
    short ReversedCount = CountDigits(Reversed);

    cout << "\nDigits in order:\n";

    // 2. نطبع خانات الرقم المقلوب (التي هي بداية الرقم الأصلي)
    long long TempReversed = Reversed;
    while (TempReversed > 0)
    {
        cout << TempReversed % 10 << "\n";
        TempReversed = TempReversed / 10;
    }

    // 3. الخدعة: إذا كان هناك فرق في عدد الخانات، اطبع الأصفار الناقصة
    // مثلاً 1200 -> المقلوب 21 (الفرق هو صفرين)
    for (short i = 1; i <= (OriginalCount - ReversedCount); i++)
    {
        cout << "0\n";
    }
}

int main()
{
    long long Number = ReadPositiveNumber("Please enter a positive number: ");

    PrintDigitsInOrder(Number);

    return 0;
}