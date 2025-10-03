// IO_DEMO.cpp

#include <iostream> // Provides standard input/output operations, like cin and cout.
#include <fstream> // Provides classes for file input and output (ifstream and ofstream).
#include <string> // Provides the string class for working with sequences of characters.
#include <iomanip> // Provides functions for input/output manipulators, like setw and setprecision.
#include <filesystem> // Provides a way to perform operations on the underlying filesystem.
#include <cmath> // Provides mathematical functions, like pow.

using namespace std;

int main()
{
	int integer;
	double decimal;
	char ch;
	string st;

	// Demonstrate how different types of data are extracted from the input stream.
	cout << "++++++++++++ EXTRACTION +++++++++++++" << endl;
	cout << "Integer: ";
	cin >> integer; // Reads an integer from the standard input.
	cout << "Decimal: ";
	cin >> decimal; // Reads a double from the standard input.
	cout << "Character: ";
	cin >> ch; // Reads a single character from the standard input.
	cout << "String: ";
	cin >> st; // Reads a string from the standard input, stopping at whitespace.

	// Show what happens when the wrong data type is extracted.
	cout << "Decimal when expecting an int: ";
	cin >> integer; // Attempts to read a decimal into an integer, which might fail or truncate.
	cout << "Read: " << integer << endl;
	cout << "Still in the stream: " << decimal << endl; // decimal has not been read from the stream yet.

	// Show how a single character is read, and the rest remains in the stream.
	cout << "String when expecting a char: ";
	cin >> ch; // Reads the first character of the string.
	cout << "Read: " << ch << endl;
	cin >> st; // Reads the rest of the string that is still in the stream.
	cout << "Still in the stream: " << st << endl;

	// Show what happens when a character is read when a number is expected.
	cout << "Character when expecting a number: ";
	cin >> integer; // Attempts to read a character as a number, which typically fails.
	cout << "Read: " << integer << endl; // The integer will likely be 0.
	cin >> st; // Reads the character and any subsequent data as a string.
	cout << "Still in the stream: " << st << endl;

	// Demonstrate how to handle a broken input stream.
	cout << "+++++++++++ DUMP THE STREAM +++++++++++" << endl;
	cin.ignore(100, '\n'); // Ignores up to 100 characters or until a newline is found, clearing the buffer.
	cout << "Read an integer: ";
	cin >> integer;
	ch = cin.peek(); // Peeks at the next character without extracting it.
	cout << "cin is broken... must fix using clear() and ignore()" << endl;

	cin.clear(); // Clears the error flags on the input stream.
	cin.ignore(100, '\n'); // Clears the input buffer.

	cout << "Now read the next integer: ";
	cin >> integer; // Now that the stream is fixed, the next integer can be read correctly.
	cout << "Read: " << integer << endl;

	// Read a single character using get().
	cout << "Try to read the next character: ";
	cin.get(ch); // Reads a single character, including whitespace.
	cout << "Read: " << int(ch) << endl; // Prints the integer value of the character.

	// Put a character back into the stream.
	cout << "Put a character back using putback(ch)" << endl;
	cin.putback(ch + 1); // Puts a character back into the stream, modified by adding 1.
	cout << "Read the stream again: " << endl;
	cin >> st; // Reads the character that was put back, followed by any remaining characters.
	cout << "Read: " << st << endl;
	cin.ignore(100, '\n'); // Clear the input buffer.

	// Demonstrate peeking at the next character without extracting it.
	cout << "+++++++++++++ PEEKING ++++++++" << endl;
	cout << "Enter a string: ";
	ch = cin.peek(); // Peeks at the first character of the string.
	cout << "Saw: " << ch << endl;
	cout << "Read the string: " << endl;
	cin >> st; // Reads the entire string.
	cout << "Read: " << st << endl;

	//////////////////////////////////////////////////////////////////////////

	const string FILENAME = "demo.txt";
	string output_file;
	string output;
	bool newfile = false;
	bool keep_asking = true;
	int blank_line = 0;

	ifstream fin; // For file reading.
	ofstream fout; // For file writing.

	
	// Example of reading from a file
	if (filesystem::exists(FILENAME)) {
		fin.open(FILENAME); // Opens the file for reading.
		fin >> integer; // Reads an integer from the file.
		cout << integer << endl;
		fin.ignore(100, '\n'); // Ignores the rest of the line.
		getline(fin, st); // Reads a full line from the file.
		cout << st << endl;
		fin.close(); // Closes the file.
	}
	

	// Prompt the user for the output file name.
	cout << "Where do you want the output to go? ";
	cin >> output_file;

	// Check if the output file already exists.
	if (filesystem::exists(output_file)) {
		cin.ignore(100, '\n'); // Clear the input buffer.
		cout << "Do you wish to overwrite? (y or n) ";
		cin.get(ch); // Get a single character from the user.
		if (ch == 'y')
			newfile = true; // Set the flag to overwrite.
	}
	cin.ignore(100, '\n'); // Clear the input buffer.

	// Open the file for writing, either appending or creating new.
	if (!newfile) {
		cout << "Opening " << output_file << " to append." << endl;
		fout.open(output_file, ios::app); // Opens the file in append mode.
	}
	else {
		cout << "Creating " << output_file << "." << endl;
		fout.open(output_file); // Opens the file, creating or overwriting it.
	}

	// Loop to get user input to write to the file.
	while (keep_asking) {
		cout << "What do you want to write to the file?\n";
		getline(cin, st); // Reads a full line from the standard input.
		if (st.empty()) {
			// Allow for exiting the loop by pressing enter twice.
			keep_asking = ++blank_line - 2;
			if (blank_line == 1) {
				cout << "Press 'Enter' again to exit.\n";
			}
		}
		else {
			// If a blank line was entered previously, add a newline.
			if (blank_line == 1) {
				output += '\n';
			}
			blank_line = 0; // Reset blank line counter.
			output += st + '\n'; // Append the line and a newline to the output string.
		}
	}
	output.erase(output.size() - 1); // Remove the trailing newline character.
	fout << output; // Write the entire string to the file.

	fout.close(); // Close the output file.

	/////////////////////////////////////////////////////////////
	// Demonstrate output formatting with iomanip.
	int start = 1;
	int stop = 9;
	cout << setprecision(2); // Sets the precision for floating-point numbers.
	cout << fixed; // Uses fixed-point notation for floating-point numbers.
	cout << showpoint; // Forces the display of a decimal point.
	cout << showpos; // Displays a '+' for positive numbers.
	cout << left; // Aligns output to the left.
	cout << setfill('_'); // Fills extra space with the '_' character.
	// setw must be rewritten after each << output

	// Print a formatted table.
	for (int i = start; i <= stop; i++) {
		cout << setw(10) << i // Sets the width for the integer.
			<< setw(15) << pow(i, .5) // Sets the width for the square root.
			<< setw(20) << pow(i, 8.0 / 3) // Sets the width for the third power.
			<< endl;
	}

	// Reset the output stream manipulators.
	cout << noshowpoint; // Turns off the display of a decimal point.
	cout << noshowpos; // Turns off the display of a '+'.
	cout << right; // Aligns output to the right.
	cout << setfill(' '); // Resets the fill character to a space.
	cout << setprecision(-1); // Resets the precision to its default value.
	cout.unsetf(ios::fixed); // Unsets the fixed-point notation flag.

	return 0; // Standard main function return.
}
