#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "SinglyLinkedListADT.h"
#include "NodeADT.h"

#define ERROR_VALUE INT_MAX;  // Define a constant for returning error values

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
