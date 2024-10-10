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

