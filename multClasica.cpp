#include <iostream>
#include <vector>
#include <chrono> // Para medir el tiempo de ejecución

using namespace std;
using namespace std::chrono;

// Multiplicacion de matrices
void multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // Matriz cuadrada n
    int n;
    cout << "Ingrese el tamaño de la matriz: ";
    cin >> n;

    // Inicializacion de matrizes
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    vector<vector<int>> C(n, vector<int>(n));

    // Llenado de matrices
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }

    // Tiempo de ejecucion
    auto start = high_resolution_clock::now();
    multiplyMatrices(A, B, C, n);
    auto end = high_resolution_clock::now();

    // Calcular el tiempo transcurrido en milisegundos
    auto duration = duration_cast<milliseconds>(end - start).count();

    // Show time execution
    cout << "Tiempo de ejecución para matrices de tamaño " << n << ": " << duration << " ms" << endl;

    return 0;
}
