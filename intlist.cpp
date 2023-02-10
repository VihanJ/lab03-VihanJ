// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    Node* sourceHead = source.first;
    Node* node;
    if (sourceHead) { 
        this->first = new Node();
        this->first->info = sourceHead->info;
        node = this->first;

        while(sourceHead->next) {
            node->next = new Node();
            node = node->next; 
            sourceHead = sourceHead->next;

            node->info = sourceHead->info;
        }
        //node->next = nullptr;
    } 
}
//if head of node exists, create first, 

// destructor deletes all nodes
IntList::~IntList() {
    Node *temp;
    Node *node = first;
    while(node) {
        temp = node->next;
        delete node;
        node = temp;
    }
    //implicitly called at function end?
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node *iterator = this->first;
    while (iterator) {
        sum += iterator->info;
        iterator=iterator->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* iterator = this->first;
    while (iterator) {
        if (iterator->info==value) {
            return true;
        } else {
            iterator = iterator->next;
        }
    }
    return false;
}

// returns maximum info in list, or 0 if empty list
int IntList::max() const {
    Node* iterator = this->first;
    if (iterator) {
        int max;
        max = iterator->info;

        iterator = iterator->next;
        while (iterator) {
            if (iterator->info > max) {
                max = iterator->info;
            }
            iterator = iterator->next; 
        }
        return max;
    } else {
        return 0;
    }
    
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    Node* iterator = this->first;

    if (iterator) {
        double sum = 0;
        int count = 0; 
        while (iterator) {
            count++;
            sum+=iterator->info;
            iterator=iterator->next;
        }
        return sum/count;
    } else {
        return 0;
    }
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node* newHead = new Node();
    newHead->info = value;

    if (this->first) {
        newHead->next = this->first;
    }
    this->first = newHead; 
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    
    if (this == &source) {
        return *this;
    }

    //destructor
    Node *temp;
    Node *node = first;
    while (node) {
        temp = node->next;
        delete node;
        node = temp;
    }

    Node* sourceHead = source.first;

    this->first = nullptr;
    if (sourceHead) { 
        this->first = new Node();
        this->first->info = sourceHead->info;
        node = this->first;

        while(sourceHead->next) {
            node->next = new Node();
            node = node->next; 
            sourceHead = sourceHead->next;

            node->info = sourceHead->info;
        }
        //node->next = nullptr;
    } 
    
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
