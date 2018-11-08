# Parallel Sorts

Parallel implementations of quicksort and mergesort, which are both faster than  
the C++ built-in *std::sort*.  

**To build:**  ``` g++ -std=c++11 -fopenmp -o main.o main.cc quicksort.cc mergesort.cc  ```  
**To run:**  ``` ./main.o input_size mode ```  

**modes:**  
0 for std::sort,  
1 for quicksort,  
2 for mergesort  

### Algorithm running times (in seconds) using Intel Core i7-7700U with input size 10000000:  

**parallel quicksort:**  ~1.0s  
**parallel mergesort:** ~1.4s  
**std::sort:** ~3.2s   