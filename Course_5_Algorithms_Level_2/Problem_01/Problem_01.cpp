#include <iostream>
#include <string>
using namespace std;

void PrintTableHeader() 
{

	cout << "\n\n\t\t\t\t" << "Multiplication table from 1 to 10 \n" << endl;
	cout << "\t";
	for (int i = 1; i <= 10; i++)
	{

		cout << i << "\t" ;

	}
	cout << endl;
	cout  << "\n------------------------------------------------------------------------------------" << endl;
}

string ColumSeparator(int i)
{

	if (i < 10) 
		return "   |";
	else  
		return "  |";

}
void PrintMultiplicationTable() 
{
	PrintTableHeader();

	for (int i = 1; i <= 10; i++)
	{
		cout <<" " << i << ColumSeparator(i) << "\t";

		for (int j=1;j<=10;j++) 
		{
			cout << i * j << "\t";
		}
		cout << "\n------------------------------------------------------------------------------------" << endl;
	}



}

int main() {
	
	PrintMultiplicationTable();

	return 0;
}