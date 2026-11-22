#include <stdio.h>
#include "headers/debug.h"
#include "headers/chunk.h"
#include "headers/debug.h"
#include "headers/value.h"

// disassemble all instructions inside of a specific chunk
void disassembleChunk(Chunk *chunk, const char* name) {
    // print a header ( to know which chunk we are looking at)
    printf("== %s ==\n", name);

    // look through the bytecode disassembling each instruction, we dont increment offset in the loop ourself we let the function do it for us
    // after disassembling the instruction for a given offset, it returns the offset of the next instruction because instructions can have different sizes
    for (int offset = 0; offset < chunk->count;) {
        offset = disassembleInstruction(chunk, offset);
    }
}

static int simpleInstruction(const char* name, int offset) {
    printf("%s\n", name);
    return offset + 1;
}

// disassembles and prints a bytecode instruction that takes a constant operand
static int constantInstruction(const char* name, Chunk* chunk, int offset) {
    uint8_t constant = chunk->code[offset + 1];
    printf("%-16s %4d '", name, constant);
    printValue(chunk->constants.values[constant]);
    printf("'\n");
    return offset + 2;
}

int disassembleInstruction(Chunk* chunk, int offset) {
    printf("%04d", offset);

    if (offset > 0 && chunk->lines[offset] == chunk->lines[offset - 1]) {
        printf("   | ");
    } else {
        printf("%4d ", chunk->lines[offset]);
    }

    uint8_t instruction = chunk->code[offset];
    switch (instruction) {
        case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", chunk, offset);
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}

