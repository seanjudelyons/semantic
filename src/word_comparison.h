#ifndef WORD_COMPARISON_H
#define WORD_COMPARISON_H
#include "file_reader.h"

// find and print the top n similar words
void find_similar_words(WordVector *input_word_vector, WordVector *word_vectors, int num_words, int top_n);

#endif
