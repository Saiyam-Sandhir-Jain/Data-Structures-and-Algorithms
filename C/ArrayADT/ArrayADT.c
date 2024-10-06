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

// Construct an ArrayADT using an array
Array *copyArray(int arrayC[], unsigned int size, unsigned int length) {
    // Size of the ArrayADT remains same are size of the array
    // Length decides how many elements need to be copied

    if (length > size) {
        printf("Error: ArrayADT length cannot be greater than size.\n");
        return NULL;
    }

    if (!arrayC && size > 0) {
        printf("Error: NULL array cannot have a non-zero size.\n");
        return NULL;
    }

    Array *arrayADT = (Array *)malloc(sizeof(Array));
    if (!arrayADT) {
        printf("Error: Error occured during ArrayADT creation.\n");
        return NULL;
    }

    if (!arrayC) {
        arrayADT->_items = NULL; // Initialize items with NULL
        arrayADT->_size = 0;     // Initialize size with 0
        arrayADT->_length = 0;   // Initalize length with 0

        return arrayADT;
    }

    arrayADT->_items = (int *)malloc(size * sizeof(int));
    if (!arrayADT->_items) {
        printf("Error: Error occured during array creation.\n");
        return NULL;
    }

    // Initialize items with elemets from array
    for (unsigned int i = 0; i < length; ++i) {
        arrayADT->_items[i] = arrayC[i];
    }
    arrayADT->_size = size;      // Initialize size with 'size'
    arrayADT->_length = length;  // Initialize length with 'length'

    return arrayADT;
}

// ArrayADT copy constructor
Array *copyArrayADT(Array *arrayADT, unsigned int length) {
    // Length decides how many elements need to be copied

    if (!arrayADT)
        return NULL;

    // Error is returned when number of elemets in arrayADT items is less than number of elements to be copied
    if (arrayADT->_length < length) {
        printf("Error: Length is out of ArrayADT bounds.\n");
        return NULL;
    }

    Array *copiedArrayADT = (Array *)malloc(sizeof(Array));
    if (!copiedArrayADT) {
        printf("Error: Error occured during ArrayADT creation.\n");
        return NULL;
    }

    copiedArrayADT->_items = (int *)malloc(arrayADT->_size * sizeof(int));
    // Initialize copiedArrayADT items with elements from arrayADT items
    for (unsigned int i = 0; i < length; ++i) {
        copiedArrayADT->_items[i] = arrayADT->_items[i];
    }
    copiedArrayADT->_size = arrayADT->_size;  // Initialize copiedArrayADT size with arrayADT size
    copiedArrayADT->_length = length;         // Initialize copiedArrayADT length with length

    return copiedArrayADT;
}