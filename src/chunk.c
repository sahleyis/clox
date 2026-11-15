#include <stdlib.h>
#include "headers/chunk.h"
#include "headers/memory.h"

// the initilizer function defintion that takes a pointer to the chunk struct as a parameter
// then it initiliazers all the variables in the struct ( chunk-> count is the same as this.count in Java)
void initChunk(Chunk* chunk) {
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
}

void writeChunk(Chunk* chunk, uint8_t byte) {

    // check to see if the current array already has capacity for the new byte
    // if it doesnt then we grow the array to make room
    if (chunk->capacity < chunk->count + 1) {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
    }

    chunk->code[chunk->count] = byte;
    chunk->count++;
}