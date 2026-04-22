//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// دالة لقراءة النص بالكامل (حتى مع المسافات)
//string ReadText()
//{
//    string Text;
//    cout << "Please enter Text?\n";
//    getline(cin, Text);
//    return Text;
//}
//
//// دالة التشفير: تضيف رقم معين لكل حرف
//string EncryptText(string Text, short EncryptionKey)
//{
//    for (int i = 0; i < Text.length(); i++)
//    {
//        Text[i] = char((int)Text[i] + EncryptionKey);
//    }
//    return Text;
//}
//
//// دالة فك التشفير: تطرح نفس الرقم من كل حرف
//string DecryptText(string Text, short EncryptionKey)
//{
//    for (int i = 0; i < Text.length(); i++)
//    {
//        Text[i] = char((int)Text[i] - EncryptionKey);
//    }
//    return Text;
//}
//
//int main()
//{
//    const short EncryptionKey = 2; // مفتاح التشفير
//
//    string TextAfterRead = ReadText();
//    string TextAfterEncryption = EncryptText(TextAfterRead, EncryptionKey);
//    string TextAfterDecryption = DecryptText(TextAfterEncryption, EncryptionKey);
//
//    cout << "\nText Before Encryption : " << TextAfterRead << endl;
//    cout << "Text After Encryption  : " << TextAfterEncryption << endl;
//    cout << "Text After Decryption  : " << TextAfterDecryption << endl;
//
//    return 0;
//}
//


#include <iostream>
#include <string>

using namespace std;

string ReadText()
{
    string Text = "";
    cout << "\nPlease enter text: ";
    getline(cin, Text);
    return Text;
}

// استخدام += يجعل الكود أنظف وأسرع
string Encrypt(string Text, short Key)
{
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] += Key;
    }
    return Text;
}

string Decrypt(string Text, short Key)
{
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] -= Key;
    }
    return Text;
}

int main()
{
    const short Key = 9;
    string OriginalText = ReadText();

    string CipherText = Encrypt(OriginalText, Key);
    string RecoveredText = Decrypt(CipherText, Key);

    cout << "\n------------------------------\n";
    cout << "Original  : " << OriginalText << endl;
    cout << "Encrypted : " << CipherText << endl;
    cout << "Decrypted : " << RecoveredText << endl;
    cout << "------------------------------\n";

    return 0;
}