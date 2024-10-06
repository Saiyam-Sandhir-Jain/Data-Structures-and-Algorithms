#ifndef ARRAYADT_H
#define ARRAYADT_H

// ArrayADT Structure
typedef struct ArrayADT {
    int *_items;
    unsigned int _size;
    unsigned int _length;
} Array;

// Properties
unsigned int getArraySize(Array *arrayADT); // Get '_size' attribute of Array
unsigned int getArrayLength(Array *arrayADT); // Get '_length' attribute of Array

// ArrayADT Constructors
Array *createDefaultArray(); // Array Default Constructor
Array *createArrayWithSize(unsigned int size); // Construct Array with 'size' parameter
Array *copyArray(int arrayC[], unsigned int size, unsigned int length); // Construct Array with 'arrayC', 'size' and 'length' parameters
Array *copyArrayADT(Array *arrayADT, unsigned int length); // Array Copy Constructor

// Operations
int getArrayElement(Array *arrayADT, unsigned int index); 
void displayArray(Array *arrayADT);
void appendArray(Array *arrayADT, int value);
void extendArray(Array *arrayADT, Array *otherArray);
void insertArray(Array *arrayADT, unsigned int index, int value);
int popArray(Array *arrayADT);
int removeArray(Array *arrayADT, unsigned int index);
unsigned int removeValueFromArray(Array *arrayADT, int value);
unsigned int linearSearchArray(Array *arrayADT, int value);
void resizeArray(Array **arrayADT, unsigned int newSize);

// ArrayADT Destructor
void freeArray(Array **arrayADT);

#endif // ARRAYADT_H