// Name: De Huo
// USC NetID: dehuo
// CSCI 455 PA5
// Fall 2019


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to not put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
#include <iostream>

struct Node
{
    std::string key;
    int value;

    Node *next;

    Node(const std::string &theKey, int theValue);

    Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;


//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.


bool insertEntry(const std::string &, int, ListType &);

bool changeValue(const std::string &, int, ListType &);

int* lookupKey(const std::string &, ListType &);

bool removeEntry(const std::string &, ListType &);

void printList(std::ostream &, ListType);

int size(ListType);


// keep the following line at the end of the file
#endif
