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
        return list->_head;
    }

    printf("Error: Cannot return head of a NULL list.\n");
    return NULL;
}

// Get list length
unsigned int getListLength(SinglyLLADT *list) {
    if (list) {
        return list->_length;
    }

    printf("Error: Cannot return length of a NULL list.\n");
    return ERROR_VALUE;
}


// ########## Constructors ##########

SinglyLLADT *createDefaultList() {
    SinglyLLADT *list = (SinglyLLADT *)malloc(sizeof(SinglyLLADT));

    if (!list) {
        printf("Error: Error occurred during list creation.\n");
        return NULL;
    }

    list->_head = NULL;
    list->_length = 0;

    return list;
}

SinglyLLADT *createListWithArray(int array[], unsigned int size) {
    if (!array && size != 0) {
        printf("Error: Invalid arguments passed. NULL array cannot have non-zero size.");
        return NULL;
    }
    
    SinglyLLADT *list = (SinglyLLADT *)malloc(sizeof(SinglyLLADT));

    if (!list) {
        printf("Error: Error occurred during list creation.\n");
        return NULL;
    }

    if (!array && size == 0) {
        list->_head = NULL;
        list->_length = 0;
        return list;
    }

    list->_head = createNodeADTWithValue(array[0]);
    if (!list->_head) {
        printf("Error: Failed to create the head node of the list.\n");
        free(list);
        return NULL;
    }

    NodeADT *curr = list->_head;
    for (unsigned int i = 1; i < size; ++i) {
        curr->_next = createNodeADTWithValue(array[i]);

        if (!curr->_next) {
            printf("Error: Error occurred during node creation for the list.\n");
            while (list->_head) {
                NodeADT *temp = list->_head;
                list->_head = list->_head->_next;
                freeNodeADT(&temp);
            }
            list->_length = 0;

            free(list);
            list = NULL;

            return NULL;
        }

        curr = curr->_next;
    }

    list->_length = size;

    return list;
}

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
    
    if (!list->_head && list->_length == 0) {
        copiedList->_head = NULL;
        copiedList->_length = 0;
        return copiedList;
    }

    copiedList->_head = createNodeADTWithValue(list->_head->_value);
    if (!copiedList->_head) {
        printf("Error: Failed to create the head node of the list.\n");
        free(copiedList);
        return NULL;
    }
    
    NodeADT *listItr = list->_head;
    NodeADT *copyListItr = copiedList->_head;
    for (unsigned int i = 1; i < list->_length; ++i) {
        listItr = listItr->_next;
        copyListItr->_next = createNodeADTWithValue(listItr->_value);
        
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

        copyListItr = copyListItr->_next;
    }

    copiedList->_length = list->_length;
    return copiedList;
}
