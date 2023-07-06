#include <math.h>
#include "vector_processor.h"

// calculate the magnitude (norm) of a vector
double get_magnitude(double vector[VECTOR_SIZE]) {
    double sum = 0;
    for (int i = 0; i < VECTOR_SIZE; i++) {
        sum += vector[i] * vector[i];
    }
    return sqrt(sum);
}

// calculate normalised vector
void normalize_vector(double vector[VECTOR_SIZE]) {
    double magnitude = get_magnitude(vector);
    for (int i = 0; i < VECTOR_SIZE; i++) {
        vector[i] /= magnitude;
    }
}
