#ifndef COSINE_SIMILARITY_H
#define COSINE_SIMILARITY_H
#include "file_reader.h"  // for the VECTOR_SIZE definition

// calculate the dot product of two vectors
double dot_product(double vector1[VECTOR_SIZE], double vector2[VECTOR_SIZE]);

// calculate the cosine similarity between two vectors
double cosine_similarity(double vector1[VECTOR_SIZE], double vector2[VECTOR_SIZE]);

#endif
