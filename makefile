CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -g -Isrc/headers # to remove treat warnings as errors remove -Werror
TARGET = build/clox

# Automatically find all .c files in the src directory
SRCS = $(wildcard src/*.c)
HEADERS = $(wildcard src/headers/*.h)
OBJS = $(SRCS:src/%.c=build/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

clean:
	rm -rf build

.PHONY: all clean
