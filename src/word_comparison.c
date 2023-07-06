#include <stdio.h>
#include "word_comparison.h"
#include <string.h>
#include <stdlib.h>
#include "cosine_similarity.h"
#include "vector_processor.h"
#include "file_reader.h"

// hold a word and its similarity score
typedef struct {
    char word[MAX_WORD_LENGTH];
    double score;
} WordScore;

// qsort
int compare_scores(const void *a, const void *b) {
    double diff = ((WordScore*)b)->score - ((WordScore*)a)->score;
    return (diff > 0) - (diff < 0);
}

// find and print the top n similar words
void find_similar_words(WordVector *input_word_vector, WordVector *word_vectors, int num_words, int top_n) {
    // vector from the input word
    double *input_vector = input_word_vector->vector;

    if (input_vector == NULL) {
        printf("Input word not found in dataset\n");
        return;
    }

    // cosine similarity for each word
    WordScore *scores = malloc(num_words * sizeof(WordScore));
    for (int i = 0; i < num_words; i++) {
        scores[i].score = cosine_similarity(input_vector, word_vectors[i].vector);
        strncpy(scores[i].word, word_vectors[i].word, MAX_WORD_LENGTH);
    }

    // sort the scores
    qsort(scores, num_words, sizeof(WordScore), compare_scores);

    // print the top n words
    for (int i = 0; i < top_n && i < num_words; i++) {
        printf("%s\n", scores[i].word);
    }

    free(scores);
}
