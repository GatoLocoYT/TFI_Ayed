#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "ordenamientos.h"
#include "utilidades.h"

using namespace std;

int main() {
    int cantidad;
    vector<int> vec;
    int opcion;

    srand(time(nullptr)); // Semilla para números aleatorios

    cout << "=== ORDENAMIENTO DE VECTORES ===\n";
    do {
        cout << "\nIngrese cantidad de elementos (min 3, max 5000): ";
        cin >> cantidad;
    } while (cantidad < 3 || cantidad > 5000);

    vec = generarVectorAleatorio(cantidad);

    cout << "\nVector generado:\n";
    mostrarVector(vec);

    do {
        cout << "\nSeleccione el algoritmo de ordenamiento:\n";
        cout << "1. Bubble Sort\n";
        cout << "2. QuickSort\n";
        cout << "3. Radix Sort\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        vector<int> copia = vec; // Usamos una copia para no modificar el original

        int comparaciones = 0;
        int intercambios = 0;
        double tiempo = 0;

        switch (opcion) {
            case 1:
                tiempo = bubbleSort(copia, comparaciones, intercambios);
                break;
            case 2:
                tiempo = quickSort(copia, comparaciones, intercambios);
                break;
            case 3:
                tiempo = radixSort(copia, tiempo); // Radix no usa comp/interc
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }

        if (opcion >= 1 && opcion <= 3) {
            cout << "\nVector ordenado:\n";
            mostrarVector(copia);

            if (opcion != 3) {
                cout << "Comparaciones: " << comparaciones << endl;
                cout << "Intercambios: " << intercambios << endl;
            }
            cout << "Tiempo de ejecucion: " << tiempo << " segundos\n";
        }

    } while (opcion != 4);

    return 0;
}
