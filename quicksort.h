#ifndef QUICKSORT_H
#define QUICKSORT_H

// Data type (64-bit unsigned integers).

typedef unsigned long long data_t;

// Sort the first n elements of data.
//
// The result should be equivalent to:
//   std::sort(data, data+n);

void qsort(int n, data_t* data);
void quicksort_parallel(data_t* data, int low, int high);
int partition(data_t* data, int low, int high);  
void swaphelper(data_t &a, data_t &b);    

#endif
