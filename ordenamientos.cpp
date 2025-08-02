// ordenamientos.cpp

#include "ordenamientos.h"
#include "utilidades.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>       // para std::max
#include <thread>          // para std::this_thread::sleep_for
#include <chrono>          // para std::chrono::milliseconds

using namespace std;

// --- BUBBLE SORT ---
double bubbleSort(vector<int>& vec, int& comparaciones, int& intercambios) {
    clock_t inicio = clock();

    int n = vec.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            comparaciones++;
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                intercambios++;

                // Mostrar paso a paso si el vector es pequeño
                if (n <= 20) {
                    system("cls");
                    cout << "Ordenando con Bubble Sort...\n";
                    mostrarVector(vec);
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
            }
        }
    }

    clock_t fin = clock();
    return double(fin - inicio) / CLOCKS_PER_SEC;
}

// --- QUICKSORT ---
double quickSort(vector<int>& vec, int& comparaciones, int& intercambios) {
    clock_t inicio = clock();
    quickSortHelper(vec, 0, vec.size() - 1, comparaciones, intercambios);
    clock_t fin = clock();
    return double(fin - inicio) / CLOCKS_PER_SEC;
}

void quickSortHelper(vector<int>& vec, int inicio, int fin, int& comparaciones, int& intercambios) {
    if (inicio >= fin) return;

    int pivote = vec[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; ++j) {
        comparaciones++;
        if (vec[j] < pivote) {
            i++;
            swap(vec[i], vec[j]);
            intercambios++;
        }
    }
    swap(vec[i + 1], vec[fin]);
    intercambios++;

    if (vec.size() <= 20) {
        system("cls");
        cout << "Ordenando con QuickSort...\n";
        mostrarVector(vec);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    quickSortHelper(vec, inicio, i, comparaciones, intercambios);
    quickSortHelper(vec, i + 2, fin, comparaciones, intercambios);
}

// --- RADIX SORT ---
int obtenerMaximo(const vector<int>& vec) {
    int max = vec[0];
    for (int i = 1; i < vec.size(); ++i)
        if (vec[i] > max)
            max = vec[i];
    return max;
}

void countingSort(vector<int>& vec, int exp) {
    int n = vec.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; ++i)
        count[(vec[i] / exp) % 10]++;

    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; --i) {
        output[count[(vec[i] / exp) % 10] - 1] = vec[i];
        count[(vec[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; ++i)
        vec[i] = output[i];
}

double radixSort(vector<int>& vec, double& tiempo) {
    clock_t inicio = clock();

    int max = obtenerMaximo(vec);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(vec, exp);

        if (vec.size() <= 20) {
            system("cls");
            cout << "Ordenando con Radix Sort...\n";
            mostrarVector(vec);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    clock_t fin = clock();
    tiempo = double(fin - inicio) / CLOCKS_PER_SEC;
    return tiempo;
}
