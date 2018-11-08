#include "mergesort.h"
#include <algorithm>
#include <iostream>
#include <omp.h>
#include <ctime>


void mergesort(int n, data_t* data) {
    // FIXME: make this more efficient with parallelism

   
    //std::sort(data, data + n);
   

    unsigned int low = 0; 
    unsigned int high = n;

    #pragma omp parallel
    #pragma omp single
    mergesort_parallel(data, low, high, omp_get_num_threads());

}

void mergesort_parallel(data_t* data, unsigned int low, unsigned int high, unsigned int threads) {


    if(high - low > 1) {

        if(threads == 1) {
            mergesort_linear(data, low, high);
	        return;
        }

        unsigned int mid = low + (high-low) / 2;

        #pragma omp task
        mergesort_parallel(data, low, mid, threads/2);

        #pragma omp task
        mergesort_parallel(data, mid, high, threads-threads/2);
        
        #pragma omp taskwait
        inplacemerge(data, low, mid, high);   
    }

}


void mergesort_linear(data_t* data, unsigned int low, unsigned int high) {
    
        if(high - low < 50) {
            std::sort(data + low, data + high);
            return;
        }
        
            unsigned int mid = low + (high-low) / 2;
    
            mergesort_linear(data, low, mid);
            mergesort_linear(data, mid, high);
            inplacemerge(data, low, mid, high);   
        
    
    }




void inplacemerge(data_t* data, unsigned int low, unsigned int mid, unsigned int high) {
    std::inplace_merge(data + low, data + mid, data + high);   
}





