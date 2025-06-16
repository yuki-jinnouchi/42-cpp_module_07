#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
 private:
  T* _elements;
  unsigned int _size;

 public:
  // Orthodox canonical form
  Array();
  ~Array();
  Array(const Array& other);
  Array& operator=(const Array& other);
  Array(unsigned int n);

  // Subscript operator
  T& operator[](unsigned int index);
  const T& operator[](unsigned int index) const;

  // Size function
  unsigned int size() const;
};

#include "Array.tpp"

#endif
