
#include <iostream>

using namespace std;

string ReadPositiveNumber(string Message)
{
	string Letters;

		cout << Message;
		cin >> Letters;

	return Letters;
}
bool PrintAllFromAAAtoZZZ(string Letters)
{
    cout << "\n";  
    
    int Counter=0;
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
				Counter++;
                
                string word = "";  
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);
				cout << "Trail [" << Counter << "] : " << word << endl;

               
                    if (Letters == word)
                    {
                        cout << "\n Password is " << Letters << endl;
                        cout << "Found after [" << Counter << "]" << endl;
                        return true;
                    }

                    
                   
            }
        }
	}return false;
}
int main()
{

    PrintAllFromAAAtoZZZ(ReadPositiveNumber("Please enter 3 letter : "));

	return 0;
}