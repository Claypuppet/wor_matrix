#include "Matrix.hpp"

int main() {
  clock_t s_start_t = clock();
  Matrix<double, 3, 3> m0{{1, -2, 1},
                          {1, -4, -3},
                          {3, 0,  -1}};


  clock_t start_t = clock();

  std::cout << m0.inverse() << std::endl;
  clock_t end_t = clock();

  std::cout << "cycles: " << (double) (end_t - start_t) << std::endl;

  std::cout << m0.transpose() << std::endl;
  clock_t end2 = clock();

  std::cout << "cycles: " << (double) (end2 - end_t) << std::endl;

  return 0;
}
