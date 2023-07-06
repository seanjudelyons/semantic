#include <math.h>
#include "cosine_similarity.h"
#include "vector_processor.h"

// calculate the dot product of two vectors
double dot_product(double vector1[VECTOR_SIZE], double vector2[VECTOR_SIZE]) {
    double sum = 0;
    for (int i = 0; i < VECTOR_SIZE; i++) {
        sum += vector1[i] * vector2[i];
    }
    return sum;
}

// calculate the cosine similarity between two vectors
double cosine_similarity(double vector1[VECTOR_SIZE], double vector2[VECTOR_SIZE]) {
    double dot_product_value = dot_product(vector1, vector2);
    double magnitude_product = get_magnitude(vector1) * get_magnitude(vector2);
    
    if(magnitude_product == 0) {
        printf("Error: Divide by Zero encountered in Cosine Similarity calculation!\n");
        return -1;
    }

    return dot_product_value / magnitude_product;
}
