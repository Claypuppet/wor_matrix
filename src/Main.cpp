#include "Matrix.hpp"

int main() {
  Matrix<double, 3, 3> m0{{1, -2, 1},
                          {1, -4, -3},
                          {3, 0,  -1}};

  std::cout << m0.inverse() << std::endl;
  return 0;
}
