#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**) {
  std::cout << "=== Original Tests ===" << std::endl;
  Array<int> numbers(MAX_VAL);
  int* mirror = new int[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }

  try {
    numbers[-2] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }
  delete[] mirror;

  std::cout << std::endl;

  std::cout << "=== Additional Tests for Array Template ===" << std::endl;

  // Test 1: Default constructor
  std::cout << "\n1. Testing default constructor..." << std::endl;
  Array<int> empty;
  std::cout << "Empty array size: " << empty.size() << std::endl;

  // Test 2: Assignment operator
  std::cout << "\n2. Testing assignment operator..." << std::endl;
  Array<int> a(5);
  Array<int> b(3);
  for (unsigned int i = 0; i < a.size(); i++) {
    a[i] = i * 10;
  }
  for (unsigned int i = 0; i < b.size(); i++) {
    b[i] = i * 100;
  }
  std::cout << "Before assignment - a.size(): " << a.size()
            << ", b.size(): " << b.size() << std::endl;
  a = b;  // Assignment operator test
  std::cout << "After assignment - a.size(): " << a.size()
            << ", b.size(): " << b.size() << std::endl;

  // Test 3: Different types
  std::cout << "\n3. Testing different types..." << std::endl;
  Array<std::string> strings(3);
  strings[0] = "Hello";
  strings[1] = "World";
  strings[2] = "42";
  std::cout << "String array: ";
  for (unsigned int i = 0; i < strings.size(); i++) {
    std::cout << strings[i] << " ";
  }
  std::cout << std::endl;

  Array<double> doubles(2);
  doubles[0] = 3.14;
  doubles[1] = 2.71;
  std::cout << "Double array: ";
  for (unsigned int i = 0; i < doubles.size(); i++) {
    std::cout << doubles[i] << " ";
  }
  std::cout << std::endl;

  // Test 4: const array
  std::cout << "\n4. Testing const array..." << std::endl;
  const Array<int> constArray = a;  // Copy from previous test
  std::cout << "Const array size: " << constArray.size() << std::endl;
  std::cout << "Const array elements: ";
  for (unsigned int i = 0; i < constArray.size(); i++) {
    std::cout << constArray[i] << " ";  // const operator[]
  }
  std::cout << std::endl;

  return 0;
}
