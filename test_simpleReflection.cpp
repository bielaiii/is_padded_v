#include <iostream>
#include <cassert>
#include "simpleReflection.h"

struct simple {
  int a;
  char b;
};

struct nested {
  simple s;
  double d;
};

struct array_struct {
  int arr[5];
  char c;
};

struct complex {
  nested n;
  array_struct a[3];
  float f;
};

void test_simple() {
  constexpr size_t count = get_member_field<simple>();
  static_assert(count == 2, "count is not 2");
  std::cout << "test_simple passed!" << std::endl;
}

void test_nested() {
  constexpr size_t count = get_member_field<nested>();
  assert(count == 2);
  std::cout << "test_nested passed!" << std::endl;
}

void test_array_struct() {
  constexpr size_t count = get_member_field<array_struct>();
  assert(count == 2);
  std::cout << "test_array_struct passed!" << std::endl;
}

void test_complex() {
  constexpr size_t count = get_member_field<complex>();
  assert(count == 3);
  std::cout << "test_complex passed!" << std::endl;
}

int main() {
  test_simple();
  test_nested();
  test_array_struct();
  test_complex();
  return 0;
}