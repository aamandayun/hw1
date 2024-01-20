/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

void printList(Node*& head){
  while(head!=nullptr){
    cout<< head->value << " ";
    head = head->next;
  }
}

int main(int argc, char* argv[])
{
  Node* head = new Node(1, nullptr);
  Node* second = new Node(2, nullptr);
  Node* third = new Node(3, nullptr);
  Node* fourth = new Node(4, nullptr);

  head->next = second;
  second->next = third;
  third->next = fourth;

  Node* headOdds = NULL;
  Node* headEvens = NULL;

  split(head, headOdds, headEvens);

  cout<<"odds: ";
  printList(headOdds);
  cout <<endl;

  cout<<"evens: ";
  printList(headEvens);
  cout <<endl;
}

