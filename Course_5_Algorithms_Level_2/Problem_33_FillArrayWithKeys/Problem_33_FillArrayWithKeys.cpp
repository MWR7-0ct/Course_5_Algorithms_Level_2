#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// استخدام الثوابت يجعل التعديل مستقبلاً سهلاً جداً
const int MaxArraySize = 100;
const short KeyPartLength = 4;

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter:      return char(RandomNumber(97, 122));
    case enCharType::CapitalLetter:    return char(RandomNumber(65, 90));
    case enCharType::SpecialCharacter: return char(RandomNumber(33, 47));
    case enCharType::Digit:            return char(RandomNumber(48, 57));
    default:                           return char(RandomNumber(65, 90));
    }
}

string GenerateWord(enCharType CharType, short Length)
{
    string Word = "";
    for (int i = 1; i <= Length; i++)
    {
        Word += GetRandomCharacter(CharType);
    }
    return Word;
}

string GenerateKey()
{
    string Key = "";
    // بناء المفتاح بسطر واحد أكثر كفاءة وأناقة
    Key = GenerateWord(enCharType::CapitalLetter, KeyPartLength) + "-";
    Key += GenerateWord(enCharType::CapitalLetter, KeyPartLength) + "-";
    Key += GenerateWord(enCharType::CapitalLetter, KeyPartLength) + "-";
    Key += GenerateWord(enCharType::CapitalLetter, KeyPartLength);
    return Key;
}

void FillArrayWithKeys(string arr[MaxArraySize], short NumberOfKeys)
{
    for (int i = 0; i < NumberOfKeys; i++)
        arr[i] = GenerateKey();
}

void PrintKeys(string arr[MaxArraySize], short NumberOfKeys)
{
    cout << "\nGenerated Keys:\n";
    for (int i = 0; i < NumberOfKeys; i++)
    {
        cout << "Array[" << i << "] : " << arr[i] << endl;
    }
}

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0 || Number > MaxArraySize); // حماية إضافية من تجاوز حجم المصفوفة
    return Number;
}

int main()
{
    srand((unsigned)time(NULL));

    string arr[MaxArraySize];
    short NumberOfKeys = ReadPositiveNumber("How many keys do you want to generate (1-100)?");

    FillArrayWithKeys(arr, NumberOfKeys);
    PrintKeys(arr, NumberOfKeys);

    return 0;
}