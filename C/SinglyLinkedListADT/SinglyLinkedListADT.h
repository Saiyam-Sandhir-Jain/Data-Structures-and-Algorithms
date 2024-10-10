#ifndef SINGLYLINKEDLISTADT_H
#define SINGLYLINKEDLISTADT_H

// ########## NodeADT ADT ##########

// NodeADT Structure
typedef struct SinglyNodeADTADT {
    int value;
    struct SinglyNodeADTADT *next;
} NodeADT;

// NodeADT Properties
int getNodeADTValue(NodeADT *node);                  // value getter
NodeADT *getNodeADTNext(NodeADT *node);              // next getter
void setNodeADTADTValue(NodeADT *node, int value);   // value setter
void setNodeADTNext(NodeADT *node, NodeADT *next);   // next setter

// NodeADT Operations

// NodeADT Constructors
NodeADT *createDefaultNodeADT();                                     // defalut constructor
NodeADT *createNodeADTWithValue(int value);                          // parameterized constructor: value
NodeADT *createNodeADTWithValueAndNext(int value, NodeADT *next);    // parameterized constructor: value, next
NodeADT *createNodeADTCopy(NodeADT *node);                           // copy constructor

// NodeADT Destructor
void freeNodeADT(NodeADT **node);


// ########## Singly Linked List ADT ##########

// NodeADT Structure
typedef struct SinglyLinkedListADT {
    NodeADT *head;
    unsigned int length;
} SinglyLLADT;

// SinglyLLADT Properties
NodeADT *getListHead(SinglyLLADT *list);             // head getter
unsigned int getListLength(SinglyLLADT *list);       // length getter

// SinglyLLADT Operations
int getListElement(SinglyLLADT *list, unsigned int index);
void setListElement(SinglyLLADT *list, unsigned int index, int value);
void displayList(SinglyLLADT *list);
void appendList(SinglyLLADT *list, int value);
void extendList(SinglyLLADT *list, SinglyLLADT *otherList);
void insertList(SinglyLLADT *list, unsigned int index);
int popList(SinglyLLADT *list);
int removeListElement(SinglyLLADT *list, unsigned int index);
unsigned int removeValueFromList(SinglyLLADT *list, int value);
unsigned int linearSearchList(SinglyLLADT *list, int value);
bool isEmpty(SinglyLLADT *list);

// SinglyLLADT Constructors
SinglyLLADT *createDefaultList();                                   // default Constructor
SinglyLLADT *createListWithArray(int array[], unsigned int size);   // parameterized constructor: array
SinglyLLADT *createListCopy(SinglyLLADT *list);                     // copy constructor

// SinglyLLADT Destructor
void freeList(SinglyLLADT **list);

#endif // SINGLYLINKEDLISTADT_H