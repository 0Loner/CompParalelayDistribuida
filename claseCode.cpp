#include <iostream>
#include <chrono>
using namespace std;

int main() { 

  auto start = std::chrono::system_clock::now();
  
  int max =10;
  double A[max][max],x[max],y[max];
  for (int i=0;i<max;i++)
    for(int j=0;j<max;j++)
      y[i]+=A[i][j]*x[j];

  auto end = std::chrono::system_clock::now();
  std::chrono::duration<float,std::milli> duration = end - start;
  std::cout << duration.count() << "s" << endl;
  
  auto start1 = std::chrono::system_clock::now();
  
  for(int j=0;j<max;j++)
    for(int i=0;i<max;i++)
      y[i]+=A[i][j]*x[j];

  auto end1 = std::chrono::system_clock::now();
  std::chrono::duration<float,std::milli> duration1 = end1 - start1;
  std::cout << duration1.count() << "s" << endl;
}