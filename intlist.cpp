// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE
//Jack Brockett, Aidan Babb 2/11/2018
 
#include "intlist.h"

#include <iostream>
using std::cout;


// copy constructor
IntList::IntList(const IntList& source) {

}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node* temp = new Node;
    temp = first;
    while(temp != nullptr)
    {
        sum += temp->info;
        temp = temp->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* temp = new Node;
    temp = first;

    while(temp != nullptr)
    {
        if (temp->info == value)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (count() == 0)
        return 0;
    int max = first->info;

    Node* temp = new Node;
    temp = first;
    while(temp != nullptr)
    {
        if(temp->info > max)
        {
            max = temp->info;
        }
        temp = temp->next;
    }

    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (count() == 0)
        return 0;
    double total = sum();
    return total / count();
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node* newFirst = new Node;
    newFirst->info = value;
    if (count() == 0)
        first = newFirst;
    else
    {
        newFirst->next = first;
        first = newFirst;
    }
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
