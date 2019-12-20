// Name: De Huo
// USC NetID: dehuo
// CSCI 455 PA5
// Fall 2019


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) 
{
    key = theKey;
    value = theValue;
    next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
    key = theKey;
    value = theValue;
    next = n;
}

bool insertEntry(const string &key, int value, ListType &myList)
{
    Node *p = myList;
    if (p == NULL)
    { 
       myList = new Node(key, value);
       return true;
    }
    else
    {
       while(p->next != NULL)
          p = p->next;
         
       p->next = new Node(key, value);
       return true;
         
    }
}
bool changeValue(const string &key, int newValue, ListType &myList)
{
    Node *p = myList;
    while(p != NULL)
    {  
       if(p->key == key)
       {   
          p->value = newValue;
          return true;
       }
          p = p->next;
    }

   return false;
}
int* lookupKey(const string &key, ListType &myList)
{
    Node *p = myList;
    while(p != NULL)
    {  
       if(p->key == key)
       {   
          return &(p->value);
       }
          p = p->next;
    }

    return NULL;
}
bool removeEntry(const string &key, ListType &myList)
{
    Node *p = myList;
    if(p == NULL)
    {
       return false;
    }
    else if(p->key == key)
    {
       delete myList;
       myList = p->next;
       return true;
    }
    else
    {
       while(p->next != NULL)
       {  
          if(p->next->key == key)
          {
             Node *tmp = p->next;
             p->next = p->next->next;
             delete tmp;
             return true;
          }
          p = p->next;
       }
    }

    return false;
}

void printList(ostream &out, ListType myList)
{
    Node *p = myList;
    while(p != NULL)
    {
	  
       out << p->key.c_str() << " " << p->value << endl;
       p = p->next;
    } 

}
int size(ListType myList)
{
    Node *p = myList;
    int count = 0;
    while (p != NULL)
    {
       count++;
       p = p->next;
    }
    return count;
}

//*************************************************************************
// put the function definitions for your list functions below
