#include <iostream>
#include <chrono>
using namespace std;

int main() { 
  int max = 10;
  double A[max][max], x[max], y[max] = {0};

  for (int i = 0; i < max; i++) {
    x[i] = 1.0;
    for (int j = 0; j < max; j++) {
      A[i][j] = 1.0;
    }
  }

  auto start = std::chrono::system_clock::now();
  
  for (int i = 0; i < max; i++) {
    for (int j = 0; j < max; j++) {
      y[i] += A[i][j] * x[j];
    }
  }

  auto end = std::chrono::system_clock::now();
  std::chrono::duration<float, std::milli> duration = end - start;
  std::cout << "Duración acceso por filas: " << duration.count() << " ms" << endl;
  
  fill_n(y, max, 0);

  auto start1 = std::chrono::system_clock::now();
  
  for (int j = 0; j < max; j++) {
    for (int i = 0; i < max; i++) {
      y[i] += A[i][j] * x[j];
    }
  }

  auto end1 = std::chrono::system_clock::now();
  std::chrono::duration<float, std::milli> duration1 = end1 - start1;
  std::cout << "Duración acceso por columnas: " << duration1.count() << " ms" << endl;

  return 0;
}
