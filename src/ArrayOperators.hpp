//
// Created by klei on 10/3/18.
//

#ifndef MATRIXWOR_ARRAYOPERATORS_HPP
#define MATRIXWOR_ARRAYOPERATORS_HPP

#include <array>

/**
 *
 */
template<class T, const size_t N>
void operator*=(std::array<T, N> &arr, const T &scalar) {
  for (auto &val : arr) {
    val *= scalar;
  }
}

/**
 *
 */
template<class T, const size_t N>
std::array<T, N> operator*(const std::array<T, N> &arr, const T &scalar) {
  std::array<T, N> newArr = arr;
  newArr *= scalar;
  return newArr;
}

/**
 *
 */
template<class T, const size_t N>
void operator/=(std::array<T, N> &arr, const T &scalar) {
  for (auto &val : arr) {
    val /= scalar;
  }
}

/**
 *
 */
template<class T, const size_t N>
std::array<T, N> operator/(const std::array<T, N> &arr, const T &scalar) {
  std::array<T, N> newArr = arr;
  newArr /= scalar;
  return newArr;
}

/**
 *
 */
template<class T, const size_t N>
void operator+=(std::array<T, N> &arr, const std::array<T, N> &arr2) {
  for (size_t i = 0; i < N; ++i) {
    arr[i] += arr2[i];
  }
}

/**
 *
 */
template<class T, const size_t N>
std::array<T, N> operator+(const std::array<T, N> &arr, const std::array<T, N> &arr2) {
  std::array<T, N> newArr = arr;
  newArr += arr2;
  return newArr;
}

/**
 *
 */
template<class T, const size_t N>
void operator-=(std::array<T, N> &arr, const std::array<T, N> &arr2) {
  for (size_t i = 0; i < N; ++i) {
    arr[i] -= arr2[i];
  }
}

/**
 *
 */
template<class T, const size_t N>
std::array<T, N> operator-(const std::array<T, N> &arr, const std::array<T, N> &arr2) {
  std::array<T, N> newArr = arr;
  newArr -= arr2;
  return newArr;
}

#endif //MATRIXWOR_ARRAYOPERATORS_HPP
