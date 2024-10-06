#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "ArrayADT.h"

#define ERROR_VALUE INT_MAX  // Constant for error values

// Get the size of the array
unsigned int getArraySize(Array *arrayADT) {
    if (arrayADT)
        return arrayADT->_size;
    
    // NULL pointer is passed
    printf("Error: Cannot get size from NULL ArrayADT.\n");
    return ERROR_VALUE;
}

// Get the length of the array
unsigned int getArrayLength(Array *arrayADT) {
    if (arrayADT)
        return arrayADT->_length;

    // NULL pointer is passed
    printf("Error: Cannot get length from NULL ArrayADT.\n");
    return ERROR_VALUE;
}

// Get an element from the array
int getArrayElement(Array *arrayADT, unsigned int index) {
    if (arrayADT && index < arrayADT->_length)
        return arrayADT->_items[index];

    if (!arrayADT) // NULL pointer is passed
        printf("Error: Cannot get element from NULL ArrayADT.\n");
    else if (index >= arrayADT->_length) // Index is out of array bounds
        printf("Error: Index out of ArrayADT bounds.\n");

    return ERROR_VALUE;
}

// Constructor to create a default (empty) array
Array *createDefaultArray() {
    Array *arrayADT = (Array *)malloc(sizeof(Array));

    if (arrayADT) {
        arrayADT->_items = NULL; // Initialize items to NULL
        arrayADT->_size = 0;     // Set size to 0
        arrayADT->_length = 0;   // Set length to 0

        return arrayADT;
    }

    // Error during array creation
    printf("Error: Error occured during ArrayADT creation.\n");
    return NULL;
}

// Constructor to create an array with a specified size
Array *createArrayWithSize(unsigned int size) {
    Array *arrayADT = (Array *)malloc(sizeof(Array));
    if (!arrayADT) { // Error during array creation
        printf("Error: Error occured during ArrayADT creation.\n");
        return NULL;
    }

    if (size == 0) {
        arrayADT->_items = NULL;  // Initialize items to NULL
        arrayADT->_size = 0;     // Set size to 0
        arrayADT->_length = 0;   // Set length to 0

        return arrayADT;
    }
    
    arrayADT->_items = (int *)malloc(size * sizeof(int));
    if (!arrayADT->_items) { // Error during array creation
        printf("Error: Error occured during array creation.\n");
        return NULL;
    }

    arrayADT->_size = size; // Initialize size to 'size' parameter
    arrayADT->_length = 0;  // Initialize length to 0

    return arrayADT; 
}
