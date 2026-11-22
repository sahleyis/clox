#ifndef clox_value_h
#define clox_value_h

#include "common.h"

// abstracts how lox values are conretely represented in C so we can change that representation
typedef double Value;

// defines a dynamic array structure that holds a list/array of values/constants
// the instruction to load a constant looks up the value by index in this array, it needs to be dynamic since the compiler wont know how big the array is
typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;


void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);
#endif