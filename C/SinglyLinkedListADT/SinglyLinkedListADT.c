#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "SinglyLinkedListADT.h"
#include "NodeADT.h"

#define ERROR_VALUE INT_MAX;

// ########## Properties ##########

// Get list head
NodeADT *getListHead(SinglyLLADT *list) {
    if (list) {
        return list->_head;  // Return the head of the list if it exists
    }

    printf("Error: Cannot return head of a NULL list.\n");
    return NULL;
}

// Get list length
unsigned int getListLength(SinglyLLADT *list) {
    if (list) {
        return list->_length;  // Return the length of the list if it exists
    }

    printf("Error: Cannot return length of a NULL list.\n");
    return ERROR_VALUE;
}

// ########## Constructors ##########

// Create an empty list (default constructor)
SinglyLLADT *createDefaultList() {
    SinglyLLADT *list = (SinglyLLADT *)malloc(sizeof(SinglyLLADT));

    if (!list) {
        printf("Error: Error occurred during list creation.\n");
        return NULL;
    }

    // Initialize the list as empty
    list->_head = NULL;
    list->_length = 0;

    return list;
}

// Create a list from an array of integers
SinglyLLADT *createListWithArray(int array[], unsigned int size) {
    // Handle invalid input
    if (!array && size != 0) {
        printf("Error: Invalid arguments passed. NULL array cannot have non-zero size.");
        return NULL;
    }
    
    SinglyLLADT *list = (SinglyLLADT *)malloc(sizeof(SinglyLLADT));

    if (!list) {
        printf("Error: Error occurred during list creation.\n");
        return NULL;
    }

    // If an empty array is passed, return an empty list
    if (!array && size == 0) {
        list->_head = NULL;
        list->_length = 0;
        return list;
    }

    // Create the head node using the first element of the array
    list->_head = createNodeADTWithValue(array[0]);
    if (!list->_head) {
        printf("Error: Failed to create the head node of the list.\n");
        free(list);
        return NULL;
    }

    NodeADT *curr = list->_head;  // Current node pointer
    // Loop to create and link the rest of the nodes
    for (unsigned int i = 1; i < size; ++i) {
        curr->_next = createNodeADTWithValue(array[i]);

        // Handle any error during node creation and free the allocated memory
        if (!curr->_next) {
            printf("Error: Error occurred during node creation for the list.\n");
            while (list->_head) {
                NodeADT *temp = list->_head;
                list->_head = list->_head->_next;
                freeNodeADT(&temp);
            }
            list->_length = 0;
            free(list);
            return NULL;
        }

        curr = curr->_next;  // Move to the next node
    }

    // Set the length of the list
    list->_length = size;

    return list;
}

// Create a copy of the provided list
SinglyLLADT *createListCopy(SinglyLLADT *list) {
    if (!list) {
        printf("Error: Cannot copy from NULL list.\n");
        return NULL;
    }

    SinglyLLADT *copiedList = (SinglyLLADT *)malloc(sizeof(SinglyLLADT));
    if (!copiedList) {
        printf("Error: Error occurred during list creation.\n");
        return NULL;
    }
    
    // If the source list is empty, return an empty copied list
    if (!list->_head && list->_length == 0) {
        copiedList->_head = NULL;
        copiedList->_length = 0;
        return copiedList;
    }

    // Create the head node of the copied list
    copiedList->_head = createNodeADTWithValue(list->_head->_value);
    if (!copiedList->_head) {
        printf("Error: Failed to create the head node of the list.\n");
        free(copiedList);
        return NULL;
    }
    
    NodeADT *listItr = list->_head;  // Iterator for the original list
    NodeADT *copyListItr = copiedList->_head;  // Iterator for the copied list
    
    // Loop to copy each node from the original list to the new list
    for (unsigned int i = 1; i < list->_length; ++i) {
        listItr = listItr->_next;
        copyListItr->_next = createNodeADTWithValue(listItr->_value);
        
        // Handle any error during node creation in the copy process
        if (!copyListItr->_next) {
            printf("Error: Error occurred during node creation for the list.\n");
            NodeADT *temp;
            while (copiedList->_head) {
                temp = copiedList->_head;
                copiedList->_head = copiedList->_head->_next;
                freeNodeADT(&temp);
            }
            copiedList->_length = 0;
            free(copiedList);
            return NULL;
        }

        copyListItr = copyListItr->_next;  // Move to the next node in the copy
    }

    // Set the length of the copied list
    copiedList->_length = list->_length;
    return copiedList;
}

// ########## Operations ##########
int getListElement(SinglyLLADT *list, unsigned int index) {
    if (!list) {
        printf("Error: Cannot get element from a NULL list.\n");
        return NULL;
    }

    if (index >= list->_length) {
        printf("Error: index out of list bounds.\n");
        return NULL;
    }

    NodeADT *curr = list->_head;
    for (unsigned int i = 1; i <= index; ++i) {
        curr = getNodeADTNext(curr);
    }

    return getNodeADTValue(curr);
}

void setListElement(SinglyLLADT *list, unsigned int index, int value) {
    if (!list) {
        printf("Error: Cannot set element value in a NULL list.\n");
        return;
    }

    if (index >= list->_length) {
        printf("Error: Index out of list bounds.\n");
        return;
    }

    NodeADT *curr = list->_head;
    for (unsigned int i = 1; i < list->_length; ++i) {
        curr = getNodeADTNext(curr);
    }

    setNodeADTValue(curr, value);
}

void displayList(SinglyLLADT *list) {
    if (!list) {
        printf("Error: Cannot display a NULL list.\n");
        return;
    }

    NodeADT *curr = list->_head;
    while (curr) {
        displayNodeADT(curr);
        printf("->");
    }
    printf("NULL");
}

void appendList(SinglyLLADT *list, int value) {
    if (!list) {
        printf("Error: Cannot append to a NULL list.\n");
        return;
    }

    NodeADT *newNode = createNodeADTWithValue(value);
    if (!newNode) {
        printf("Error: Error occurred during node creation.\n");
        return;
    }

    NodeADT *curr = list->_head;
    while (curr->_next) {
        curr = getNodeADTNext(curr);
    }

    curr->_next = newNode;
}

void insertList(SinglyLLADT *list, unsigned int index, int value) {
    if (!list) {
        printf("Error: Cannot insert to a NULL list.\n");
        return;
    }

    if (index > list->_length) {
        printf("Error: Index out of list bounds.\n");
        return;
    }

    NodeADT *newNode = createNodeADTWithValue(value);
    if (index == 0) {
        setNodeADTNext(newNode, list->_head);
    }

    NodeADT *curr = list->_head;
    for (unsigned int i = 1; i < index; ++i) {
        setNodeADTNext(curr, getNodeADTNext(curr));
    }

    NodeADT *temp = getNodeADTNext(curr);
    setNodeADTNext(curr, newNode);
    setNodeADTNext(newNode, temp);
}

int popList(SinglyLLADT *list) {
    if (!list) {
        printf("Error: Cannot pop from a NULL list.\n");
        return ERROR_VALUE;
    }

    if (isEmpty(list)) {
        printf("Error: Cannot pop from an empty list.\n");
        return ERROR_VALUE;
    }

    NodeADT *curr = list->_head;
    while (getNodeADTNext(curr)) {
        setNodeADTNext(curr, getNodeADTNext(curr));
    }

    int poppedValue = getNodeADTValue(curr);
    freeNodeADT(&curr);
    list->_length--;

    return poppedValue;
}

int removeListElement(SinglyLLADT *list, unsigned int index)
{
    if (!list) {
        printf("Error: Cannot remove from a NULL list.\n");
        return ERROR_VALUE;
    }

    if (index >= list->_length) {
        printf("Error: Index out of list bounds.\n");
        return ERROR_VALUE;
    }

    NodeADT *curr = list->_head;
    for (unsigned int i = 1; i < index; ++i) {
        setNodeADTNext(curr, getNodeADTNext(curr));
    }
    NodeADT *temp = getNodeADTNext(curr);
    int removedValue = getNodeADTValue(temp);
    setNodeADTNext(curr, getNodeADTNext(temp));
    freeNodeADT(&temp);
    list->_length--;

    return temp;
}

unsigned int linearSearchList(SinglyLLADT *list, int value) {
    if (!list) {
        printf("Error: Cannot search a NULL list.\n");
        return ERROR_VALUE;
    }

    NodeADT *curr = list->_head;
    for (unsigned int i = 0; i < list->_length; ++i) {
        if (getNodeADTValue(curr) == value) {

        }
    }
}

bool isEmpty(SinglyLLADT *list) {
    if (!list) {
        printf("Error: Cannot check a NULL list.\n");
        return false;
    }

    if (!list->_head && list->_length == 0) {
        return true;
    }

    return false;
}

// ########## Destructor ##########

// Frees the memory associated with the list and all its nodes
void freeList(SinglyLLADT **list) {
    if (!list || !(*list)) {
        printf("Error: Cannot free a NULL list.\n");
        return;
    }

    // Free all nodes in the list
    NodeADT *curr = (*list)->_head;
    while (curr) {
        NodeADT *temp = curr;
        curr = curr->_next;
        free(temp);
    }

    // Set list properties to default values
    (*list)->_head = NULL;
    (*list)->_length = 0;

    // Free the list structure itself
    free(*list);
    *list = NULL;
}