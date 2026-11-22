#include <stdlib.h>
#include "headers/chunk.h"
#include "headers/memory.h"
#include "headers/value.h"

// the initilizer function defintion that takes a pointer to the chunk struct as a parameter
// then it initiliazers all the variables in the struct ( chunk-> count is the same as this.count in Java)
void initChunk(Chunk* chunk) {
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
    chunk->lines = NULL;

    // initilise the constant list of the chunk
    initValueArray(&chunk->constants);
}

void writeChunk(Chunk* chunk, uint8_t byte, int line) {

    // check to see if the current array already has capacity for the new byte
    // if it doesnt then we grow the array to make room
    if (chunk->capacity < chunk->count + 1) {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
        chunk->lines = GROW_ARRAY(int, chunk->lines, oldCapacity, chunk->capacity);
    }

    chunk->code[chunk->count] = byte;
    chunk->lines[chunk->count] = line;
    chunk->count++;
}

int addConstant(Chunk* chunk, Value value) {
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}


// deallocate all the memory then call initChunk to zero out the fields leaving the chunk in a well-defined empty state
void freeChunk(Chunk* chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    FREE_ARRAY(int, chunk->lines, chunk->capacity);
    // frees the chunks constant lists
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}