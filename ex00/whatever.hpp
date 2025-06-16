#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// Function template for swap
template <typename T>
void swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

// Function template for min
template <typename T>
const T& min(const T& a, const T& b) {
  return (a < b) ? a : b;  // If equal, return second one
}

// Function template for max
template <typename T>
const T& max(const T& a, const T& b) {
  return (a > b) ? a : b;  // If equal, return second one
}

#endif
