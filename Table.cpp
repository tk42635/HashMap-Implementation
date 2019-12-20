// Name: De Huo
// USC NetID: dehuo
// CSCI 455 PA5
// Fall 2019

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
	hashSize = HASH_SIZE;
	hashArr = new ListType[hashSize]();

}


Table::Table(unsigned int hSize) {
	hashSize = hSize;
	hashArr = new ListType[hashSize]();

}


int* Table::lookup(const string &key) {

    return lookupKey(key, hashArr[hashCode(key)]);

}

bool Table::remove(const string &key) {
	
	return removeEntry(key, hashArr[hashCode(key)]);

}

bool Table::insert(const string &key, int value) {
    if (lookup(key) != NULL)
		return false;
	
	insertEntry(key, value, hashArr[hashCode(key)]);
	return true;  // dummy return value for stub
}

int Table::numEntries() const {
	int count = 0;
	for (int i = 0; i < hashSize; i++)
		count += size(hashArr[i]);
    return count;      // dummy return value for stub
}


void Table::printAll() const {
	for (int i = 0; i < hashSize; i++)
		printList(cout, hashArr[i]);
}

void Table::hashStats(ostream &out) const {
	out << "number of buckets: " << hashSize << endl;
	out << "number of entries: " << numEntries() << endl;
	int count = 0;
	for (int i = 0; i < hashSize; i++)
		if (hashArr[i] != NULL)
			count++;
	out << "number of non-empty buckets: " << count << endl;
	int longest = 0;
	for (int i = 0; i < hashSize; i++)
		longest = max(longest, size(hashArr[i]));
	out << "longest chain: " << longest << endl;
}


// add definitions for your private methods here
