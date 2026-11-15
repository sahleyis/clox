#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

// type aliase for enum for OpCode
typedef enum {
    OP_RETURN,
} OpCode;

// type aliase for Chunk which refers to this struct
typedef struct {

    // tracks how many slots the code array contains and the maximum number of bytes the code array can hold
    int count;
    int capacity;

    // the array pointer itself
    uint8_t* code;
} Chunk;

// declares the initilizer function
void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);

#endif