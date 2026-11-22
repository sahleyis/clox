#include <stdlib.h>
#include "headers/memory.h"


// This is the main function for dynamic memory management, allocating, freeing and changing the size of allocations
// reallocates memory, if the oldSize is 0 and the new Size is Non-zero it allocates a new block
// if the oldSize is Non zero and the new Size it frees an allocation ( frees memory )
// if the oldSize is Non-Zero and the newSize is smaller than oldSize then we shrink the esisting allocation
// if the oldSize is Non-Zero and newSize is larger than oldSize then we grow existing allocation
void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    (void)oldSize;
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }

    void* result = realloc(pointer, newSize);

    // if there isnt enough memory and it returns null we exit the program with a status of 1
    if (result == NULL) {
        exit(1);
    }
    return result;
}