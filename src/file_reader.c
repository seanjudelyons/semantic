#include <stdio.h>
#include <stdlib.h>
#include "file_reader.h"

WordVector *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return NULL;
    }

    WordVector *word_vectors = malloc(MAX_WORDS * sizeof(WordVector));
    if (word_vectors == NULL) {
        printf("Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    int word_count = 0;
    while (!feof(file) && word_count < MAX_WORDS) {
        if (fscanf(file, "%s", word_vectors[word_count].word) != 1) break;

        for (int i = 0; i < VECTOR_SIZE; i++) {
            if (fscanf(file, "%lf", &word_vectors[word_count].vector[i]) != 1) break;
        }
        word_count++;
    }

    fclose(file);
    return word_vectors;
}
