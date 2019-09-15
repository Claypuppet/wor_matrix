#include <cassert>
#include <stdexcept>
#include <cmath>
#include <utility>
#include <iomanip>

#include "ArrayOperators.hpp"

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
Matrix<T, M, N>::Matrix(T value) {
  for (std::size_t row = 0; row < M; ++row) {
    for (std::size_t column = 0; column < N; ++column) {
      matrix.at(row).at(column) = value;
    }
  }
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
Matrix<T, M, N>::Matrix(const std::initializer_list<T> &aList) {
  // Check the arguments
  assert(aList.size() == M * N);

  auto row_iter = aList.begin();
  for (std::size_t row = 0; row < M; ++row) {
    for (std::size_t column = 0; column < N; ++column, ++row_iter) {
      matrix.at(row).at(column) = *row_iter;
    }
  }
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
Matrix<T, M, N>::Matrix(const std::initializer_list<std::initializer_list<T> > &aList) {
  // Check the arguments, the static assert assures that there is at least 1 M and 1 N!
  assert(aList.size() == M && (*aList.begin()).size() == N);

  auto row_iter = aList.begin();
  for (std::size_t row = 0; row < aList.size(); ++row, ++row_iter) {
    auto column_iter = (*row_iter).begin();
    for (std::size_t column = 0; column < (*row_iter).size(); ++column, ++column_iter) {
      matrix.at(row).at(column) = *column_iter;
    }
  }
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
Matrix<T, M, N>::Matrix(const Matrix<T, M, N> &aMatrix) :
  matrix(aMatrix.matrix) {
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
std::array<T, N> &Matrix<T, M, N>::at(std::size_t aRowIndex) {
  return matrix.at(aRowIndex);
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
const std::array<T, N> &Matrix<T, M, N>::at(std::size_t aRowIndex) const {
  return matrix.at(aRowIndex);
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
T &Matrix<T, M, N>::at(std::size_t aRowIndex,
                       std::size_t aColumnIndex) {
  return matrix.at(aRowIndex).at(aColumnIndex);
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
const T &Matrix<T, M, N>::at(std::size_t aRowIndex,
                             std::size_t aColumnIndex) const {
  return matrix.at(aRowIndex).at(aColumnIndex);
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
std::array<T, N> &Matrix<T, M, N>::operator[](std::size_t aRowIndex) {
  return matrix[aRowIndex];
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
const std::array<T, N> &Matrix<T, M, N>::operator[](std::size_t aRowIndex) const {
  return matrix[aRowIndex];
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
Matrix<T, M, N> &Matrix<T, M, N>::operator=(const Matrix<T, M, N> &rhs) {
  if (this != &rhs) {
    matrix = rhs.matrix;
  }
  return *this;
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
bool Matrix<T, M, N>::operator==(const Matrix<T, M, N> &rhs) const {
  return matrix == rhs.matrix;
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
template<class T2>
Matrix<T, M, N> &Matrix<T, M, N>::operator*=(const T2 &scalar) {
  static_assert(std::is_arithmetic<T2>::value,
                "Value T2 must be arithmetic, see http://en.cppreference.com/w/cpp/types/is_arithmetic");

  for (std::size_t row = 0; row < M; ++row) {
    for (std::size_t column = 0; column < N; ++column) {
      matrix.at(row).at(column) *= scalar;
    }
  }
  return *this;
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
template<class T2>
Matrix<T, M, N> Matrix<T, M, N>::operator*(const T2 &scalar) const {
  static_assert(std::is_arithmetic<T2>::value,
                "Value T2 must be arithmetic, see http://en.cppreference.com/w/cpp/types/is_arithmetic");

  Matrix<T, M, N> result(*this);
  return result *= scalar;
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
template<class T2>
Matrix<T, M, N> &Matrix<T, M, N>::operator/=(const T2 &scalar) {
  static_assert(std::is_arithmetic<T2>::value,
                "Value T2 must be arithmetic, see http://en.cppreference.com/w/cpp/types/is_arithmetic");

  for (std::size_t row = 0; row < M; ++row) {
    for (std::size_t column = 0; column < N; ++column) {
      matrix.at(row).at(column) /= scalar;
    }
  }
  return *this;
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
template<class T2>
Matrix<T, M, N> Matrix<T, M, N>::operator/(const T2 &scalar) const {
  static_assert(std::is_arithmetic<T2>::value,
                "Value T2 must be arithmetic, see http://en.cppreference.com/w/cpp/types/is_arithmetic");

  Matrix<T, M, N> result(*this);
  return result /= scalar;
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
Matrix<T, M, N> &Matrix<T, M, N>::operator+=(const Matrix<T, M, N> &rhs) {
  for (std::size_t row = 0; row < M; ++row) {
    for (std::size_t column = 0; column < N; ++column) {
      matrix[row][column] += rhs.at(row, column);
    }
  }
  return *this;
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
Matrix<T, M, N> Matrix<T, M, N>::operator+(const Matrix<T, M, N> &rhs) const {
  Matrix<T, M, N> result(*this);
  return result += rhs;
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
Matrix<T, M, N> &Matrix<T, M, N>::operator-=(const Matrix<T, M, N> &rhs) {
  for (std::size_t row = 0; row < M; ++row) {
    for (std::size_t column = 0; column < N; ++column) {
      matrix[row][column] -= rhs.at(row, column);
    }
  }
  return *this;
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
Matrix<T, M, N> Matrix<T, M, N>::operator-(const Matrix<T, M, N> &rhs) const {
  Matrix<T, M, N> result(*this);
  return result -= rhs;
}

/**
 * (M, N) * (N, P) -> (M, P)
 */
template<typename T, std::size_t M, std::size_t N>
template<std::size_t columns>
Matrix<T, M, columns> Matrix<T, M, N>::operator*(const Matrix<T, N, columns> &rhs) const {
  Matrix<T, M, columns> result;
  for (size_t lhsRow = 0; lhsRow < M; ++lhsRow) {
    for (size_t rhsCol = 0; rhsCol < columns; ++rhsCol) {
      for (size_t pos = 0; pos < N; ++pos) {
        result.at(lhsRow, rhsCol) += at(lhsRow, pos) * rhs.at(pos, rhsCol);
      }
    }
  }
  return result;
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
Matrix<T, N, M> Matrix<T, M, N>::transpose() const {
  Matrix<T, N, M> result;
  for (size_t row = 0; row < M; ++row) {
    for (size_t col = 0; col < N; ++col) {
      result.at(col, row) = at(row, col);
    }
  }
  return result;
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
Matrix<T, M, N> Matrix<T, M, N>::identity() const {
  static_assert(N == M, "N (columns) should be equal to M (rows)");
  Matrix<T, N, M> result;
  for (size_t pivot = 0; pivot < M; ++pivot) {
    result.at(pivot, pivot) = 1;
  }
  return result;
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
Matrix<T, M, N> Matrix<T, M, N>::gauss() const {
  static_assert(N >= M, "N (columns) should be equal or more than M (rows)");
  Matrix<T, M, N> result(*this);

  for (size_t pivot = 0; pivot < M; ++pivot) {
    auto rowToSwap = result.getMaxPivotRow(pivot);
    std::swap(result.at(pivot), result.at(rowToSwap));

    // Set pivot to 1 and rest to 0
    for (size_t row = pivot; row < M; ++row) {
      result.at(row) -= result.at(pivot) * result.getLinearFactor(row, pivot);
    }
  }
  return result;
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
Matrix<T, M, N> Matrix<T, M, N>::gaussJordan() const {
  static_assert(N >= M, "N (columns) should be equal or more than M (rows)");

  auto result = Matrix(*this);

  for (size_t pivot = 0; pivot < M; ++pivot) {
    auto rowToSwap = result.getMaxPivotRow(pivot);
    std::swap(result.at(pivot), result.at(rowToSwap));

    for (size_t row = 0; row < M; ++row) {
      result.at(row) -= result.at(pivot) * result.getLinearFactor(row, pivot);
    }
  }
  return result;
}

/**
 *

 */
template<class T, std::size_t M, std::size_t N>
Matrix<T, M, 1> Matrix<T, M, N>::solve() const {
  Matrix<T, M, 1> result;
  auto gaussJd = gaussJordan();

  for (size_t row = 0; row < M; ++row) {
    result.at(row, 0) = gaussJd.at(row, N - 1);
  }
  return result;
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
Matrix<T, M, N> Matrix<T, M, N>::inverse() const {
  static_assert(N == M, "N (columns) should be equal to M (rows)");
  Matrix<T, M, N> copy(*this);
  Matrix<T, M, N> result = identity();

  for (size_t pivot = 0; pivot < M; ++pivot) {
    auto rowToSwap = copy.getMaxPivotRow(pivot);
    std::swap(copy.at(pivot), copy.at(rowToSwap));
    std::swap(result.at(pivot), result.at(rowToSwap));

    for (size_t row = 0; row < M; ++row) {
      auto lf = copy.getLinearFactor(row, pivot);
      copy.at(row) -= copy.at(pivot) * lf;
      result.at(row) -= result.at(pivot) * lf;
    }
  }
  return result;
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
Matrix<T, N, M> Matrix<T, M, N>::leftInverse() const {
  static_assert(N != M, "N (columns) should not be equal to M (rows)");
  auto mTrans = transpose();
  return ((mTrans * *this).inverse() * mTrans);
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
Matrix<T, N, M> Matrix<T, M, N>::rightInverse() const {
  static_assert(N != M, "N (columns) should not be equal to M (rows)");
  auto mTrans = transpose();
  return (mTrans * (*this * mTrans).inverse());
}

/**
 *
 */
template<class T, std::size_t M, std::size_t N>
std::string Matrix<T, M, N>::to_string() const {
  std::string result = "Matrix<" + std::to_string(M) + "," + std::to_string(N) + ">\n{\n";
  for (std::size_t i = 0; i < M; ++i) {
    for (std::size_t j = 0; j < N; ++j) {
      result += std::to_string(matrix[i][j]) + ",";
    }
    result += "\n";
  }
  result += "}";
  return result;
}

template<typename T, const size_t M, const size_t N>
size_t Matrix<T, M, N>::getMaxPivotRow(size_t pivot) {
  T maxPivotValue = std::abs(at(pivot, pivot));
  std::size_t maxPivotRow = pivot;

  for (std::size_t row = pivot; row < M; ++row) {
    if (auto val = std::abs(at(row, pivot) > maxPivotValue)) {
      maxPivotValue = val;
      maxPivotRow = row;
    }
  }
  return maxPivotRow;
}

template<typename T, const size_t M, const size_t N>
const T Matrix<T, M, N>::getLinearFactor(size_t currentRow, size_t pivot) {
  static_assert(std::is_arithmetic<T>::value,
                "Value T2 must be arithmetic, see http://en.cppreference.com/w/cpp/types/is_arithmetic");
  T lFactor = 0;
  if (at(currentRow, pivot) != 0) {
    auto divide = at(pivot, pivot);
    if (std::numeric_limits<T>::epsilon() * 5 > std::abs(divide)) {
      throw std::overflow_error("Divide by zero exception");
    }
    if (currentRow == pivot) {
      // use (a-1)/pivot value
      lFactor = (at(currentRow, pivot) - 1.0) / divide;
    } else {
      // us a/pivot value
      lFactor = at(currentRow, pivot) / divide;
    }

  }
  return lFactor;
}

/**
 *
 */
template<typename T, const std::size_t N>
bool equals(const Matrix<T, 1, N> &lhs,
            const Matrix<T, 1, N> &rhs,
            const T aPrecision /*= std::numeric_limits<T>::epsilon()*/,
            const unsigned long aFactor /*= 1*/) {
  auto precision = aPrecision * static_cast<double>(aFactor);
  for (size_t col = 0; col < N; ++col) {
    if (precision <= std::abs(lhs.at(0, col) - rhs.at(0, col))) {
      return false;
    }
  }
  return true;
}

/**
 *
 */
template<typename T, const std::size_t M>
bool equals(const Matrix<T, M, 1> &lhs,
            const Matrix<T, M, 1> &rhs,
            const T aPrecision /*= std::numeric_limits<T>::epsilon()*/,
            const unsigned long aFactor /*= 1*/) {
  auto precision = aPrecision * static_cast<double>(aFactor);
  for (size_t row = 0; row < M; ++row) {
    if (precision <= std::abs(lhs.at(row, 0) - rhs.at(row, 0))) {
      return false;
    }
  }
  return true;
}

/**
 *
 */
template<typename T, const std::size_t M, const std::size_t N>
bool equals(const Matrix<T, M, N> &lhs,
            const Matrix<T, M, N> &rhs,
            const T aPrecision /*= std::numeric_limits<T>::epsilon()*/,
            const unsigned long aFactor /*= 1*/) {
  auto precision = aPrecision * static_cast<double>(aFactor);
  for (size_t row = 0; row < M; ++row) {
    for (size_t col = 0; col < N; ++col) {
      if (precision <= std::abs(lhs.at(row, col) - rhs.at(row, col))) {
        return false;
      }
    }
  }
  return true;
}