#include <iostream>   
#include <cstdlib>    
#include <ctime>      
using namespace std;  

int ReadPositiveNumber(string Message) {
	int Number = 0;
    do {
        cout << Message;
        cin >> Number;
        if (Number <= 0) {
            cout << "Invalid number! " << endl;
        }
    } while (Number <= 0);
	return Number;
}

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

int main() {

    srand((unsigned)time(NULL));
	int N = ReadPositiveNumber("Please enter a positive number: ");
    cout << "Number 0-N :     " << RandomNumber(1, N) << endl;
   
  

    return 0;
}
