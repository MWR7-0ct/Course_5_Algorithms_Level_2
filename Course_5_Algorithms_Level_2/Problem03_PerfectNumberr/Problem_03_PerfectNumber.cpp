
#include <iostream>
#include <string>
    using namespace std;

    
    int ReadPositiveNumber(string Message)
    {
        int Number = 0;
        cout << Message;
        cin >> Number;

        while (Number <= 0)
        {
           cout << "\nError: Negative numbers and Zero cannot be perfect." << endl;

            cout << "\nPlease enter a positive number greater than 0: ";
            cin >> Number;
        }

        return Number;
    }

    bool IsPerfectNumber(int Number)
    {
        
        int Sum = 0;
        for (int Counter = 1; Counter <= Number / 2; Counter++)
        {
            if (Number % Counter == 0)
            {
                Sum += Counter;
            }
        }
        return Sum == Number;
    }

    void PrintPerfectOrNotPerfect(int Number)
    {

        
        if (IsPerfectNumber(Number))
        {
            cout << "\n" << Number << " : is perfect number." << endl;
        }
        else
        {
            cout << "\n" << Number << " : is not perfect number." << endl;
        }
    }

    int main()
    {
        PrintPerfectOrNotPerfect(ReadPositiveNumber("Please enter a positive number: "));

        return 0;
    }