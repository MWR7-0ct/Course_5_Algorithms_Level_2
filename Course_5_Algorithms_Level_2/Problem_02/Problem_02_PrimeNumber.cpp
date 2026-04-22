#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// تعريف الحالة (أولي أو غير أولي) باستخدام Enum لزيادة وضوح الكود
enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

// دالة القراءة: مخصصة لرفض الرقم 1 والأرقام غير الموجبة مع رسائل منفصلة
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    cout << Message;
    cin >> Number;

    // حلقة التحقق لضمان إدخال رقم أولي منطقي (أكبر من 1)
    while (Number <= 1)
    {
        if (Number == 1)
        {
            cout << "\nNotice: Number (1) is NOT a prime number by definition." << endl;
        }
        else
        {
            cout << "\nError: Negative numbers and Zero cannot be prime." << endl;
        }

        cout << "Please enter a positive number greater than 1: ";
        cin >> Number;
    }

    return Number;
}

// دالة الفحص: تختبر إذا كان الرقم أولياً أم لا (تأخذ رقماً واحداً فقط)
enPrimeNotPrime CheckPrime(int Number)
{
    // الرقم 1 تمت تصفيته في دالة القراءة، لذا نبدأ الفحص من الرقم 2
    int M = round(Number / 2);

    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimeNotPrime::NotPrime;
    }

    return enPrimeNotPrime::Prime;
}

// دالة الطباعة الشاملة: تمر على الأرقام من 1 إلى N وتطبع الأولي منها
void PrintPrimeNumbersFrom1ToN(int Number)
{
    cout << "\nPrime Numbers from 1 To " << Number << " are : " << endl;
    cout << "-----------------------------------------------" << endl;

    for (int i = 1; i <= Number; i++)
    {
        if (CheckPrime(i) == enPrimeNotPrime::Prime)
        {
            cout << i << endl;
        }
    }
    cout << "-----------------------------------------------" << endl;
}

int main()
{
    // تنفيذ البرنامج: قراءة الرقم ثم طباعة الأعداد الأولية حتى ذلك الرقم
    PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number: "));

    return 0;
}