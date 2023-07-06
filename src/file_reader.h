#ifndef FILE_READER_H
#define FILE_READER_H
#include <stdio.h>

#define MAX_WORD_LENGTH 100

// size of the vector for each word
#define VECTOR_SIZE 200
// maximum number of words to read from the file
#define MAX_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    double vector[VECTOR_SIZE];
} WordVector;

// read a file and return an array of word vectors
WordVector *read_file(const char *filename);

#endif
