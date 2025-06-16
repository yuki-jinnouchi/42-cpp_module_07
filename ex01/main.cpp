#include <iostream>
#include <string>

#include "iter.hpp"

// Function templates for testing
template <typename T>
void print(const T& element) {
  std::cout << element << " ";
}

template <typename T>
void increment(T& element) {
  element++;
}

void toUpper(char& c) {
  if (c >= 'a' && c <= 'z') {
    c = c - 'a' + 'A';
  }
}

int main(void) {
  // Test with int array
  std::cout << "=== Testing with int array ===" << std::endl;
  int intArray[] = {1, 2, 3, 4, 5};
  size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

  std::cout << "Original: ";
  iter(intArray, intSize, print<int>);
  std::cout << std::endl;

  iter(intArray, intSize, increment<int>);
  std::cout << "After increment: ";
  iter(intArray, intSize, print<int>);
  std::cout << std::endl;

  // Test with string array
  std::cout << "\n=== Testing with string array ===" << std::endl;
  std::string stringArray[] = {"hello", "world", "42", "school"};
  size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);

  std::cout << "Strings: ";
  iter(stringArray, stringSize, print<std::string>);
  std::cout << std::endl;

  // Test with char array
  std::cout << "\n=== Testing with char array ===" << std::endl;
  char charArray[] = {'h', 'e', 'l', 'l', 'o'};
  size_t charSize = sizeof(charArray) / sizeof(charArray[0]);

  std::cout << "Original: ";
  iter(charArray, charSize, print<char>);
  std::cout << std::endl;

  iter(charArray, charSize, toUpper);
  std::cout << "After toUpper: ";
  iter(charArray, charSize, print<char>);
  std::cout << std::endl;

  return 0;
}
