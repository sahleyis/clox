#include "headers/value.h"
#include <stdio.h>

#include "headers/memory.h"
#include "memory.h"
#include "values.h"

// initialises the value array
void initValueArray(ValueArray* array) {
    array->values = NULL;
    array->capacity = 0;
    array->count = 0;
}

void writeValueArray(ValueArray* array, Value value) {

    // if the arrays capacity is less than the count+1 then we increase the capacity and grow the array
    if (array->capacity  < array->count + 1) {
        int oldCapacity = array->capacity;
        array->capacity = GROW_CAPACITY(oldCapacity);
        array->values = GROW_ARRAY(Value, array->values, oldCapacity, array->capacity);
    }

    array->values[array->count] = value;
    array->count++;
}

void freeValueArray(ValueArray* array) {

    // frees the array then inits it so everything is empty
    FREE_ARRAY(Value, array->values, array->capacity);
    initValueArray(array);
}

void printValue(Value value) {
    printf("%g", value);
}