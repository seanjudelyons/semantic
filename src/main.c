#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_reader.h"
#include "word_comparison.h"
#define MAX_WORDS_IN_FILE 1000
#define TOP_N 25

int main(int argc, char *argv[]) {
    // cmd arguments
    if (argc != 3) {
        printf("Usage: %s <input_word> <filename>\n", argv[0]);
        return 1;
    }

    const char *input_word = argv[1];
    const char *filename = argv[2];
    const char *glove_filename = getenv("GLOVEDATASET");

    if (glove_filename == NULL) {
        printf("Error: GLOVEDATASET environment variable not set\n");
        return 1;
    }

    // read GloVe file
    WordVector *glove_word_vectors = read_file(glove_filename);
    if (glove_word_vectors == NULL) {
        printf("Error reading GloVe file\n");
        return 1;
    }

    // input word in the GloVe vectors
    WordVector *input_word_vector = NULL;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(glove_word_vectors[i].word, input_word) == 0) {
            input_word_vector = &glove_word_vectors[i];
            break;
        }
    }
    if (input_word_vector == NULL) {
        printf("Input word not found in dataset\n");
        return 1;
    }

    // input file and store the corresponding GloVe vectors
    WordVector *input_word_vectors = malloc(MAX_WORDS_IN_FILE * sizeof(WordVector));
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    // ...

char word[MAX_WORD_LENGTH];
int word_count = 0;
while (fscanf(file, "%s", word) != EOF && word_count < MAX_WORDS_IN_FILE) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(glove_word_vectors[i].word, word) == 0) {
            input_word_vectors[word_count] = glove_word_vectors[i];
            word_count++;
            break;
        }
    }
}

// ...


    fclose(file);

    // print the top n similar words
    find_similar_words(input_word_vector, input_word_vectors, word_count, TOP_N);

    free(glove_word_vectors);
    free(input_word_vectors);
    return 0;
}

