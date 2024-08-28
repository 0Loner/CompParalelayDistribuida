#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

void testByRows(int max, vector<vector<double>>& A, vector<double>& x, vector<double>& y) {
    for (int i = 0; i < max; i++)
        for (int j = 0; j < max; j++)
            y[i] += A[i][j] * x[j];
}

void testByColumns(int max, vector<vector<double>>& A, vector<double>& x, vector<double>& y) {
    for (int j = 0; j < max; j++)
        for (int i = 0; i < max; i++)
            y[i] += A[i][j] * x[j];
}

int main() { 
    int max;
    cout << "Ingrese el tamaño de la matriz: ";
    cin >> max;

    vector<vector<double>> A(max, vector<double>(max, 1.0)); // Inicializado con 1.0
    vector<double> x(max, 1.0); // Inicializado con 1.0
    vector<double> y(max, 0.0); // Inicializado con 0.0

    // Prueba por filas
    auto start = chrono::high_resolution_clock::now();
    testByRows(max, A, x, y);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float, milli> duration = end - start;
    cout << "Tiempo acceso por filas: " << duration.count() << " ms" << endl;

    // Reinicializar y para la siguiente prueba
    fill(y.begin(), y.end(), 0.0);

    // Prueba por columnas
    auto start1 = chrono::high_resolution_clock::now();
    testByColumns(max, A, x, y);
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<float, milli> duration1 = end1 - start1;
    cout << "Tiempo acceso por columnas: " << duration1.count() << " ms" << endl;

    return 0;
}