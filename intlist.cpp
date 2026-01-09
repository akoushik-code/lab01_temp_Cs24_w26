// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE
// Name: Aarnav Koushik
// Date: 01/08/2026

#include "intlist.h"

#include <iostream>
#include <climits>
using std::cout;
// using namespace std; 
// copy constructor
IntList::IntList(const IntList& source) {
    if(source.head){
   //copy just the head 
   Node* newHead = new Node;
   newHead->info = source.head->info;
   newHead->next = nullptr;
   //start copying the rest of the list 
   Node* curr = source.head->next;
   Node* newTail = newHead;  
   Node* newNode; 
   while(curr){
    newNode = new Node; 
    newNode->info = curr->info; 
    newNode->next = nullptr; 
    newTail->next = newNode; 
    newTail = newTail->next; 
    curr = curr->next; 
   }
   head = newHead; 
   tail = newTail; 
}
    else{
        head = nullptr; 
        tail = nullptr; 
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
    Node* curr;
    while(head){
        curr = head->next; 
        delete head; 
        head = curr; 
    }
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0; 
    Node* curr = head; 
    while(curr){
        sum += curr->info;
        curr = curr->next; 
    }
    return sum; 
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    //bool has = 0; 
    Node* curr = head; 
    while(curr){
        if(curr->info == value){
            return true; 
        }
        curr = curr->next; 
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (!head) return 0;
    int max = head->info; 
    
    Node* curr = head; 
    while(curr){
        if(curr->info > max){
            max = curr->info; 
        }
        curr = curr->next; 
    }
    return max; 
    // if (max != INT_MIN) return max;
    // return 0; 
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
   Node *curr = head; 
   int elem = 0; 
   while(curr){
    elem ++;
    curr = curr->next; 
  }
  if(elem!=0){
    return this->sum()/elem;}
    return 0;  
}
// inserts value as new node at beginning of list
void IntList::push_front(int value) {
   
    Node *newNode = new Node(); 
    newNode->info = value; 
    newNode -> next = head; 
     if(head == tail){
        tail = newNode; 
     }
    head = newNode; 
}

// append value at end of list
void IntList::push_back(int value) {
    // IMPLEMENT
     Node *newNode = new Node(); 
    newNode->info = value; 
    newNode->next = nullptr; 
    if(head){ 
    tail->next = newNode; 
    tail = newNode;}
    else{
        head = tail = newNode;
    }
}

// return count of values
int IntList::count() const {
   Node *curr = head; 
   int count = 0; 
   while(curr){
    count ++; 
    curr = curr -> next; 
   }
   return count; 
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    // I didnt want to re-write code, so I asked claude the following prompt: 
    //"i wrote a lot of code for this copy constructor(which you shouldnt tell me if its correct or not), and i want to reuse as much as possible without rewriting for the equals assignment. how can i do this"(with the relavent funcitons attatched)
    //the solution below utilzes the knowledge from that output


    //use the constructor
    IntList tempList(source);

    //swap the source head with tempList head 
    Node* tempHead = head;
    Node* tempTail = tail;
    head = tempList.head;
    tail = tempList.tail; 
    //since we reassigned the old head and tail to templist, once it goes out of scope the deconstructor deletes the nodes for us 
    tempList.head = tempHead; 
    tempList.tail = tempTail; 
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    //IMPLEMENT THIS 
    head = nullptr; 
    tail = nullptr; 
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

