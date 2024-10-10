#include <stdio.h>
#include <stdlib.h>
#include "NodeADT.h"
#include <limits.h>

#define ERROR_VALUE INT_MAX

// ########## Properties ##########

// get value from NodeADt
int getNodeADTValue(NodeADT *node) {
    if (node) {
        return node->_value;
    }
    
    printf("Error: Cannot get value from NULL node.\n");
    return ERROR_VALUE;
}

// get next node from NodeADT
NodeADT *getNodeADTNext(NodeADT *node) {
    if (node) {
        return node->_next;
    }

    printf("Error: Cannot get next from NULL node.\n");
    return NULL;
}

// set value of NodeADT
void setNodeADTValue(NodeADT *node, int value) {
    if (!node) {
        printf("Error: Cannot set value of a NULL node.\n");
        return;
    }

    node->_value = value;
}

// set next node for NodeADT
void setNodeADTNext(NodeADT *node, NodeADT *next) {
    if (!node) {
        printf("Error: Cannot set next of a NULL node.\n");
        return;
    }

    node->_next = next;
}


// ########## Operations ##########

// Display the value of NodeADT
void displayNodeADT(NodeADT * node) {
    if (!node) {
        printf("Error: Cannot display a NULL node.\n");
        return;
    }

    printf("|%d|", node->_value);
}

// ########## Constructors ##########

// Default constructor
NodeADT *createDefaultNodeADT() {
    NodeADT *node = (NodeADT *)malloc(sizeof(NodeADT));

    if (!node) {
        printf("Error: error occurred during node creation.\n");
        return NULL;
    }

    node->_value = 0;
    node->_next = NULL;

    return node;
}

// Parameterized Constructor: value
NodeADT *createNodeADTWithValue(int value) {
    NodeADT *node = (NodeADT *)malloc(sizeof(NodeADT));

    if (!node) {
        printf("Error: error occurred during node creation.\n");
        return NULL;
    }

    node->_value = value;
    node->_next = NULL;

    return node;
}

// Parameterized Constructor: value, next
NodeADT *createNodeADTWithValueAndNext(int value, NodeADT *next) {
    NodeADT *node = (NodeADT *)malloc(sizeof(NodeADT));

    if (!node) {
        printf("Error: error occurred during node creation.\n");
        return NULL;
    }

    node->_value = value;
    node->_next = next;

    return node;
}

// Copy constructor
NodeADT *createNodeADTCopy(NodeADT *node) {
    if (!node) {
        return NULL;
    }
    
    NodeADT *nodeADT = (NodeADT *)malloc(sizeof(NodeADT));

    if (!nodeADT) {
        printf("Error: error occurred during node creation.\n");
        return NULL;
    }

    nodeADT->_value = node->_value;
    nodeADT->_next = node->_next;

    return nodeADT;
}

// ########## Destructor ##########

// Free the space allocated for a node in the heap
void freeNodeADT(NodeADT **node) {
    if (!node || !(*node)) {
        printf("Error: Cannot free a NULL node.\n");
        return;
    }

    (*node)->_value = 0;
    (*node)->_next = NULL;
    free((*node));

    *node = NULL;
}