#include "mergesort.h"
#include "quicksort.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <omp.h>
#include <random>
#include <ratio>
#include <chrono>

int main(int argc, char *argv[]) {


    if(argc < 3) {
        std::cout << "Usage: ./main.o input_size mode" << std::endl;
    } else {
 
        int size = atoi(argv[1]);

        data_t *Array = new data_t[size];

        std::random_device rd;
        std::default_random_engine generator(rd());
        std::uniform_int_distribution<long long unsigned> distribution(0,0xFFFFFFFFFFFFFFFF); 

        for(int i=0; i<size; ++i){
            Array[i] = distribution(generator);
        }

        auto begin = std::chrono::high_resolution_clock::now();
        
    
        if(atoi(argv[2]) == 0) {
            std::sort(Array, Array + size);
        } else if(atoi(argv[2]) == 1) {
            omp_set_num_threads(16);
            qsort(size, Array);  
        } else if(atoi(argv[2]) == 2) {
            omp_set_num_threads(32);
            mergesort(size, Array);
        } else {
            std::cout << "Invalid mode: Choose 0 for builtin, 1 for quicksort or 2 for mergesort" << std::endl;
        }
    
        auto end = std::chrono::high_resolution_clock::now();
        auto seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() * 10e-10;

        std::cout << seconds << "s" << std::endl;
    
    }
}