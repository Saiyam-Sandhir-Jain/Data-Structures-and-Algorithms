#include <stdio.h>
#include <stdlib.h>
#include "NodeADT.h"
#include <limits.h>

#define ERROR_VALUE INT_MAX

// ########## Properties ##########

// get value from NodeADt
int getNodeADTValue(NodeADT *node) {
    if (node) {
        return node->value;
    }
    
    printf("Error: Cannot get value from NULL node.\n");
    return ERROR_VALUE;
}

// get next node from NodeADT
NodeADT *getNodeADTNext(NodeADT *node) {
    if (node) {
        return node->next;
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

    node->value = value;
}

// set next node for NodeADT
void setNodeADTNext(NodeADT *node, NodeADT *next) {
    if (!node) {
        printf("Error: Cannot set next of a NULL node.\n");
        return;
    }

    node->next = next;
}


// ########## Operations ##########

// Display the value of NodeADT
void displayNodeADT(NodeADT * node) {
    if (!node) {
        printf("Error: Cannot display a NULL node.\n");
        return;
    }

    printf("|%d|", node->value);
}

// ########## Constructors ##########

NodeADT *createDefaultNodeADT() {
    NodeADT *node = (NodeADT *)malloc(sizeof(NodeADT));

    if (!node) {
        printf("Error: error occurred during node creation.\n");
        return NULL;
    }

    node->value = 0;
    node->next = NULL;

    return node;
}

NodeADT *createNodeADTWithValue(int value) {
    NodeADT *node = (NodeADT *)malloc(sizeof(NodeADT));

    if (!node) {
        printf("Error: error occurred during node creation.\n");
        return NULL;
    }

    node->value = value;
    node->next = NULL;

    return node;
}

NodeADT *createNodeADTWithValueAndNext(int value, NodeADT *next) {
    NodeADT *node = (NodeADT *)malloc(sizeof(NodeADT));

    if (!node) {
        printf("Error: error occurred during node creation.\n");
        return NULL;
    }

    node->value = value;
    node->next = next;

    return node;
}

NodeADT *createNodeADTCopy(NodeADT *node) {
    if (!node) {
        return NULL;
    }
    
    NodeADT *nodeADT = (NodeADT *)malloc(sizeof(NodeADT));

    if (!nodeADT) {
        printf("Error: error occurred during node creation.\n");
        return NULL;
    }

    nodeADT->value = node->value;
    nodeADT->next = node->next;

    return nodeADT;
}