#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// multiplicacion de bloques
void multiplyMatricesBlocked(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int n, int blockSize) {
    for (int i = 0; i < n; i += blockSize) {
        for (int j = 0; j < n; j += blockSize) {
            for (int k = 0; k < n; k += blockSize) {
                // Multiplicación dentro del bloque
                for (int ii = i; ii < min(i + blockSize, n); ++ii) {
                    for (int jj = j; jj < min(j + blockSize, n); ++jj) {
                        for (int kk = k; kk < min(k + blockSize, n); ++kk) {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    // tamaño de matriz
    int n;
    cout << "Ingrese el tamaño de la matriz: ";
    cin >> n;
    
    int blockSize;
    cout << "Ingrese el tamaño del bloque: ";
    cin >> blockSize;

    // inicializacion de A , B , C
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    vector<vector<int>> C(n, vector<int>(n, 0)); // inicializamos en 0

    // A y B inicializacion con valores aleatorios
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }

    // medir el tiempo de ejecucion
    auto start = high_resolution_clock::now();
    multiplyMatricesBlocked(A, B, C, n, blockSize);
    auto end = high_resolution_clock::now();

    // tiempo transcurrido en milisegundos
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << "Tiempo de ejecución para la multiplicación por bloques de tamaño " << blockSize << " y matrices de tamaño " << n << ": " << duration << " ms" << endl;

    return 0;
}