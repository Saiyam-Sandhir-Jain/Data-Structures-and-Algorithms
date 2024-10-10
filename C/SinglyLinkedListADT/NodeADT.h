#ifndef NODEADT_H
#define NODEADT_H

// NodeADT Structure
typedef struct NodeADT {
    int value;
    struct NodeADT *next;
} NodeADT;

// NodeADT Properties
int getNodeADTValue(NodeADT *node);                  // value getter
NodeADT *getNodeADTNext(NodeADT *node);              // next getter
void setNodeADTADTValue(NodeADT *node, int value);   // value setter
void setNodeADTNext(NodeADT *node, NodeADT *next);   // next setter

// NodeADT Operations
void displayNodeADT(NodeADT *node);

// NodeADT Constructors
NodeADT *createDefaultNodeADT();                                     // defalut constructor
NodeADT *createNodeADTWithValue(int value);                          // parameterized constructor: value
NodeADT *createNodeADTWithValueAndNext(int value, NodeADT *next);    // parameterized constructor: value, next
NodeADT *createNodeADTCopy(NodeADT *node);                           // copy constructor

// NodeADT Destructor
void freeNodeADT(NodeADT **node);

#endif // NODEADT_H