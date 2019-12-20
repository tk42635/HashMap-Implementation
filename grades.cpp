// Name: De Huo
// USC NetID: dehuo
// CSCI 455 PA5
// Fall 2019

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>
#include <string>

using namespace std;

void printErrors();
void printCommands();

int main(int argc, char * argv[]) {

    // gets the hash table size from the command line

   	int hashSize = Table::HASH_SIZE;

   	Table * grades;  // Table is dynamically allocated below, so we can call
   	// different constructors depending on input from the user.

    if (argc > 1) {
      	hashSize = atoi(argv[1]);  // atoi converts c-string to int

      	if (hashSize < 1) {
         	cout << "Command line argument (hashSize) must be a positive number" 
              	<< endl;
         	return 1;
      	}

      	grades = new Table(hashSize);

   	}
   	else {   // no command line args given -- use default table size
      	grades = new Table();
   	}


   	grades->hashStats(cout);

   // add more code here
   // Reminder: use -> when calling Table methods, since grades is type Table*
   	while (1)
   	{
	   	cout << "cmd>";
	   	string input;
	   	cin >> input;
	   	if (input == "insert")
	   	{
		   	string name;
		   	int value;
		   	if (cin >> name >> value)
			{
				if (!grades->insert(name, value))
				   	cout << "This name has already existed!" << endl;
			}  
		   	else
			{
				printErrors();
				printCommands();
			}
	   	}
	   	else if (input == "change")
	   	{
		   	string name;
		   	int newValue, *value;
		   	if (cin >> name >> newValue)
		   	{
			   	value = grades->lookup(name);
			   	if(value == NULL)
				   	cout << "This name not found!" << endl;
			   	else
				   	*grades->lookup(name) = newValue;
		   	}
		   	else
			{
				printErrors();
				printCommands();
			}
	   	}
	   	else if (input == "lookup")
	   	{
		   	string name;
		   	int *value;
		   	if (cin >> name)
		   	{
			   	value = grades->lookup(name);
			   	if (value == NULL)
				   	cout << "This name not found!" << endl;
			   	else
				   	cout << "Score: " << *value << endl;
		   	}	
		   	else
			{
				printErrors();
				printCommands();
			}
	   }
	   	else if (input == "remove")
	   	{
		   	string name;
		   	if (cin >> name)
		   	{
			   	if (!grades->remove(name))
				   cout << "This name not found!" << endl;
		   	}
		   	else
			{
				printErrors();
				printCommands();
			}
	   	}
	   	else if (input == "print")
	   	{
		   	grades->printAll();
	   	}
	   	else if (input == "size")
	   	{
		   	cout << grades->numEntries() << endl;
	   	}
	   	else if (input == "stats")
	   	{
		   	grades->hashStats(cout);
	   	}
	   	else if (input == "help")
	   	{
		   	printCommands();
	   	}
	   	else if (input == "quit")
	   	{
		   	break;
	   	}
	   	else
		{
			printErrors();
			printCommands();
		}
   	}

   	return 0;
}

void printErrors()
{
	cout << "ERROR: invalid command" << endl;
}
void printCommands()
{
	cout << "Valid Commands:" << endl;
	cout << "insert " << "[name] " << "[score]" << endl;
	cout << "change " << "[name] " << "[newscore]" << endl;
	cout << "lookup " << "[name] " << endl;
	cout << "remove " << "[name] " << endl;
	cout << "print" << endl;
	cout << "size" << endl;
	cout << "stats" << endl;
	cout << "help" << endl;
	cout << "quit" << endl;

}