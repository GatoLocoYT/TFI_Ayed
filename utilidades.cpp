// utilidades.cpp

#include "utilidades.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void mostrarVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << "\n";
}

vector<int> generarVectorAleatorio(int cantidad) {
    vector<int> vec(cantidad);
    for (int i = 0; i < cantidad; ++i) {
        vec[i] = rand() % 1000 + 1; // números aleatorios positivos del 1 al 1000
    }
    return vec;
}
