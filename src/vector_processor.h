#ifndef VECTOR_PROCESSOR_H
#define VECTOR_PROCESSOR_H

#include "file_reader.h"  // for the VECTOR_SIZE definition

// calculate the magnitude (norm) of a vector
double get_magnitude(double vector[VECTOR_SIZE]);

// normalise a vector
void normalize_vector(double vector[VECTOR_SIZE]);

#endif
