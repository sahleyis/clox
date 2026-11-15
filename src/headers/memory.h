#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

// a macro that pastes the code after the end of the parameter wherever it sees GROW_CAPACITY
// it replaces the capacity with the value that capacity was passed into
#define GROW_CAPACITY(capacity) \
 ((capacity) < 8 ? 8 : (capacity) * 2)

// grows an array and reallocates the memory using the reallocate function
#define GROW_ARRAY(type, pointer, oldCount, newCount) \ 
(type*)reallocate(pointer, sizeof(type) * (oldCount), \
sizeof(type) * (newCount))

// declaration for the reallocate function
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif