#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

// type aliase for enum for OpCode
typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

// type aliase for Chunk which refers to this struct
typedef struct {

    // tracks how many slots the code array contains and the maximum number of bytes the code array can hold
    int count;
    int capacity;

    // the array pointer itself
    uint8_t* code;

    // an array of lines that is parallel to the array of the bytes but just holds the line that every byte is located in ( very memory inefficient);
    int* lines;

    // stores the chunks constants
    ValueArray constants;
} Chunk;

// declares the initilizer function
void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);

// a function to add a new constant to the chunk
int addConstant(Chunk* chunk, Value value);

#endif