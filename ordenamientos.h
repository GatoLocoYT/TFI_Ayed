// ordenamientos.h

#ifndef ORDENAMIENTOS_H
#define ORDENAMIENTOS_H

#include <vector>

// Bubble Sort
double bubbleSort(std::vector<int>& vec, int& comparaciones, int& intercambios);

// QuickSort
double quickSort(std::vector<int>& vec, int& comparaciones, int& intercambios);
void quickSortHelper(std::vector<int>& vec, int inicio, int fin, int& comparaciones, int& intercambios);

// Radix Sort (sin comparaciones ni intercambios)
double radixSort(std::vector<int>& vec, double& tiempo);

#endif
