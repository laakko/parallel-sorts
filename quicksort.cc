#include "quicksort.h"
#include <algorithm>
#include <random>
#include <iostream>
#include <omp.h>

void qsort(int n, data_t* data) {

    int low = 0; 
    int high = n-1;

	#pragma omp parallel
	#pragma omp single nowait
    quicksort_parallel(data, low, high);
       
}


int partition(data_t* data, int low, int high) {

    
    unsigned long long int pivot = data[(low+high)/2];
    while(low <= high) {
    
    	while(data[low] < pivot)
    		low++;
    	while(data[high] > pivot)
    		high--;
    	if(low <= high) {
    		std::swap(data[low], data[high]);
    		low++;
    		high--;
    	}
    };
    
    
 	return low;

}



void quicksort_parallel(data_t* data, int low, int high) {


	
	if(low < high) {
		int cutoff = 10000;
		int index = partition(data, low, high);
	
	
		if( (high-low) < cutoff) {
			if(low < index -1)
		    	quicksort_parallel(data, low, index-1);
			 if(index < high)
		    	quicksort_parallel(data, index, high);
	
		} else {
	
			#pragma omp task
			quicksort_parallel(data, low, index-1);
			#pragma omp task
			quicksort_parallel(data, index, high);
	
		}
	}
	


}
