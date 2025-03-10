#include "common_module.h"
#include "count_member_field.h"
#include "generate_match.h"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <optional>
#include <type_traits>
#include <utility>
#include"generate_match.h"
using namespace std;
struct bbb {
  char a;
  float f;
};

struct fff {
  bbb b;
  int arr[3];
  int a;
};

struct aaa {
  fff f_;
  bbb b[10];
  int a;
  char c;
};
struct qweqwe {
  int a;
  aaa temp[3];
  char c;
};

int main() {
  using namespace ver2;
  auto q = aaa{};
 //cout << binary_search_member_field<bbb>() << endl;
 //cout << plain_size<bbb>() << endl;
 //cout << std::extent_v<decltype(q.b)> << endl;
 //cout << for_each_field_size<bbb, 2>() << endl;
 static_assert(is_padded_v<bbb> == 1, "no padded");
  // cout << plain_size<bbb>() <<endl;
  //cout <<  << endl;
  
  return 0;
}
