#ifndef SINGLYLINKEDLISTADT_H
#define SINGLYLINKEDLISTADT_H

#include <stdbool.h>
#include "NodeADT.h"

// NodeADT Structure
typedef struct SinglyLinkedListADT {
    NodeADT *_head;
    unsigned int _length;
} SinglyLLADT;

// SinglyLLADT Properties
NodeADT *getListHead(SinglyLLADT *list);             // head getter
unsigned int getListLength(SinglyLLADT *list);       // length getter

// SinglyLLADT Constructors
SinglyLLADT *createDefaultList();                                   // default Constructor
SinglyLLADT *createListWithArray(int array[], unsigned int size);   // parameterized constructor: array
SinglyLLADT *createListCopy(SinglyLLADT *list);                     // copy constructor

// SinglyLLADT Operations
int getListElement(SinglyLLADT *list, unsigned int index);
void setListElement(SinglyLLADT *list, unsigned int index, int value);
void displayList(SinglyLLADT *list);
void appendList(SinglyLLADT *list, int value);
void extendList(SinglyLLADT *list, SinglyLLADT *otherList);
void insertList(SinglyLLADT *list, unsigned int index, int value);
int popList(SinglyLLADT *list);
int removeListElement(SinglyLLADT *list, unsigned int index);
unsigned int removeValueFromList(SinglyLLADT *list, int value);
unsigned int linearSearchList(SinglyLLADT *list, int value);
bool isEmpty(SinglyLLADT *list);

// SinglyLLADT Destructor
void freeList(SinglyLLADT **list);

#endif // SINGLYLINKEDLISTADT_H