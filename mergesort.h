#ifndef MERGESORT_H
#define MERGESORT_H

// Data type (64-bit unsigned integers).

typedef unsigned long long data_t;

// Sort the first n elements of data.
//
// The result should be equivalent to:
//   std::sort(data, data+n);

void mergesort(int n, data_t* data);
void mergesort_parallel(data_t* data, unsigned int low, unsigned int high, unsigned int threads);
void mergesort_linear(data_t* data, unsigned int low, unsigned int high);
void inplacemerge(data_t* data, unsigned int low, unsigned int mid, unsigned int high);    
#endif