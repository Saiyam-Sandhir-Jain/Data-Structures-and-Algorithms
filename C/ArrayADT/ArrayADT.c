#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "ArrayADT.h"

#define ERROR_VALUE INT_MAX  // Constant for error values

enum MessageType {
    NULL_ARRAY_ARGUMENT_ERROR,  // Error for null array argument
    ARRAY_CREATION_ERROR,       // Error during array creation
    NO_MESSAGE                  // No message
};

// Function to check if a pointer is null and print an error message if needed
bool isNull(void *ptr, enum MessageType message) {
    if (ptr) 
        return false;

    switch (message) {
        case NULL_ARRAY_ARGUMENT_ERROR:
            printf("Error: Invalid operation. Cannot operate on NULL Array.\n");
            break;

        case ARRAY_CREATION_ERROR:
            printf("Error: Error occurred during array creation.\n");
            break;

        case NO_MESSAGE:
        default:
            break;
    }

    return true; 
}

// Get the size of the array
unsigned int getArraySize(Array *arrayADT) {
    if (isNull(arrayADT, NULL_ARRAY_ARGUMENT_ERROR)) 
        return ERROR_VALUE;

    return arrayADT->_size;
}

// Get the length of the array
unsigned int getArrayLength(Array *arrayADT) {
    if (isNull(arrayADT, NULL_ARRAY_ARGUMENT_ERROR)) 
        return ERROR_VALUE;

    return arrayADT->_length;
}

// Constructor to create a default (empty) array
Array *createDefaultArray() {
    Array *arrayADT = (Array *)malloc(sizeof(Array));

    if (isNull(arrayADT, ARRAY_CREATION_ERROR))
        return NULL;

    arrayADT->_items = NULL; // Initialize items to NULL
    arrayADT->_size = 0;     // Set size to 0
    arrayADT->_length = 0;   // Set length to 0

    return arrayADT; 
}

// Constructor to create an array with a specified size
Array *createArrayWithSize(unsigned int size) {
    Array *arrayADT = (Array *)malloc(sizeof(Array));

    if (isNull(arrayADT, ARRAY_CREATION_ERROR))
        return NULL;

    // If size is zero, initialize the array as empty
    if (size == 0) {
        arrayADT->_items = NULL;
        arrayADT->_size = 0;
        arrayADT->_length = 0;
        return arrayADT;
    }

    // Allocate memory for the items in the array
    arrayADT->_items = (int *)malloc(size * sizeof(int));
    if (isNull(arrayADT->_items, ARRAY_CREATION_ERROR))
        return NULL;

    arrayADT->_size = size;   // Set size
    arrayADT->_length = 0;    // Initial length is 0

    return arrayADT; 
}
