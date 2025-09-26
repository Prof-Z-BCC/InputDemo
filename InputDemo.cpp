#include <iostream> // CIN & Cout
#include <fstream> // FILES - ifstream & ofstream
#include <string> // GETLINE
using namespace std;

int main()
{
	int integer;
	double decimal;
	char ch;
	string st;
/*
	cout << "++++++++++++ EXTRACTION +++++++++++++" << endl;
	cout << "Integer: ";
	cin >> integer;
	cout << "Decimal: ";
	cin >> decimal;
	cout << "Character: ";
	cin >> ch;
	cout << "String: ";
	cin >> st;

	cout << "Decimal when expecting an int: ";
	cin >> integer;
	cout << "Read: " << integer << endl;
	cout << "Still in the stream: " << decimal << endl;

	cout << "String when expecting a char: ";
	cin >> ch;
	cout << "Read: " << ch << endl;
	cin >> st;
	cout << "Still in the stream: " << st << endl;

	cout << "Character when expecting a number: ";
	cin >> integer;
	cout << "Read: " << integer << endl;
	cin >> st;
	cout << "Still in the stream: " << st << endl;

	cout << "+++++++++++ DUMP THE STREAM +++++++++++" << endl;
	cin.ignore(100, '\n');
	cout << "Read an integer: ";
	cin >> integer;
	ch = cin.peek();
	cout << "cin is broken... must fix using clear() and ignore()" << endl;
	
	cin.clear();
	cin.ignore(100, '\n');

	cout << "Now read the next integer: ";
	cin >> integer;
	cout << "Read: " << integer << endl;
	

	cout << "Try to read the next character: ";
	cin.get(ch);
	cout << "Read: " << int(ch) << endl;

	cout << "Put a character back using putback(ch)" << endl;
	cin.putback(ch + 1);
	cout << "Read the stream again: " << endl;
	cin >> st;
	cout << "Read: " << st << endl;
	cin.ignore(100, '\n');

	cout << "+++++++++++++ PEEKING ++++++++" << endl;
	cout << "Enter a string: ";
	ch = cin.peek();
	cout << "Saw: " << ch << endl;
	cout << "Read the string: " << endl;
	cin >> st;
	cout << "Read: " << st << endl;
	*/
	//////////////////////////////////////////////////////////////////////////
	ifstream fin;

	fin.open("demo.txt"); // File must exist and path must be correct
	fin >> integer;
	cout << integer << endl;
	fin.ignore(100,'\n');
	getline(fin, st);
	cout << st << endl;
	fin.close();
	integer = -10;
	fin >> integer;
	cout << integer;

	ofstream fout;
	fout.open("output_file.txt"); // Creates a new file everytime
	fout << st << endl;
	fout.close();
	fout << "Write some more.\n";
	

}
