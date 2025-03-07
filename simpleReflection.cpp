#include <cstddef>
#include <iostream>
#include <optional>
#include <type_traits>
#include <utility>
// #include<format>
#include <fmt/core.h>
// #include"NestedStructure.h"
#include "NestedStructure.h"
#include "plain_array.h"
using namespace std;

struct AnyType {
  size_t ignore;
  template <typename T> operator T() noexcept;
};

template <typename T, size_t... N>
constexpr auto try_init_impl(index_sequence<N...>)
    -> decltype(T{AnyType{N}...});

template <typename T, size_t N>
constexpr auto try_init(long long)
    -> decltype(try_init_impl<T>(make_index_sequence<N>{}), true) {
  return true;
}

template <typename T, size_t N> constexpr auto try_init(int) { return false; }

template <typename T, size_t begin, size_t end, size_t target>
constexpr auto binary_search_stop() -> decltype(end - begin == 1);

template <typename T, size_t begin, size_t end, size_t target>
constexpr auto binary_search(int)
    -> decltype(binary_search_stop<T, begin, end, target>(), 0u) {
  return begin;
}

template <typename T, size_t begin, size_t end, size_t target>
constexpr size_t binary_search(long) {

  if constexpr (end - begin == 1) {
    return begin;
  } else {
    constexpr auto mid = (end - begin) / 2 + begin;
    if (try_init<T, mid>(1ll)) {
      return binary_search<T, mid, end, target>(1l);
    } else {
      return binary_search<T, begin, mid, target>(1l);
    }
  }
}

// constexpr size_t max_count = binary_search<baz, 0, 20, 1>(1l);

template <typename T, size_t... begin, size_t... agg, size_t... end>
constexpr auto aggregate_initable(index_sequence<begin...>,
                                  index_sequence<agg...>,
                                  index_sequence<end...>)
    -> decltype(T{AnyType{begin}..., {AnyType{agg}...}, AnyType{end}...});

template <typename T, size_t begin, size_t agg, size_t end>
constexpr auto pass_struct_aggeregate(long long)
    -> decltype(aggregate_initable<T>(make_index_sequence<begin>{},
                                      make_index_sequence<agg>{},
                                      make_index_sequence<end>{}),
                0ull) {
  return 1;
}

template <typename T, size_t begin, size_t agg, size_t end>
constexpr auto pass_struct_aggeregate(int) -> decltype(std::false_type{}) {
  return std::false_type{};
}
template <typename T, size_t max_count> const size_t try_aggregate_init() {
  return 0;
}

template <typename T, size_t... begin, size_t... agg>
constexpr auto enable_buildin_array(index_sequence<begin...>,
                                    index_sequence<agg...>, long long)
    -> decltype(T{AnyType{begin}...,
                  {
                      AnyType{agg}...,
                  }},
                -1) {
  return 1;
}

template <typename T, size_t... begin, size_t... agg>
constexpr auto enable_buildin_array(index_sequence<begin...>,
                                    index_sequence<agg...>, int)
    -> decltype(-1) {
  return 0;
}

template <typename T, size_t... begin, size_t... agg, size_t... end>
constexpr auto continuous_array(index_sequence<begin...>,
                                index_sequence<agg...>, index_sequence<end...>)
    -> decltype(T{AnyType{begin}..., {AnyType{agg}...}, AnyType{end}...}, 0);

template <typename T, int begin, int agg, int end>
constexpr auto should_dive_in(long long)
    -> decltype(continuous_array<T>(make_index_sequence<begin>{},
                                    make_index_sequence<agg>{},
                                    make_index_sequence<end>{}),
                0ull) {
  return 1;
}

template <typename T, int begin> constexpr auto should_dive_in(int) {
  return 0;
}

template <typename T, size_t max_count, size_t... begin, size_t... end>
constexpr auto aggregate_with_2_element(index_sequence<begin...>,
                                        index_sequence<end...>, long long)
    -> decltype(T{AnyType{begin}..., {AnyType{end}...}}, 0u) {

  if constexpr (sizeof...(end) == 0) {
    return 0;
  } else {
    constexpr auto begin_ = sizeof...(begin);
    constexpr auto end_ = sizeof...(end);
    aggregate_with_2_element<T, max_count>(make_index_sequence<begin_ + 1>{},
                                           1ll);
  }
  static_assert(sizeof...(begin) + sizeof...(end) == max_count, "not match");
  return 1;
}

template <typename T, size_t max_count, size_t... begin, size_t... end>
constexpr auto pass_struct(index_sequence<begin...>, index_sequence<end...>,
                           int) -> decltype(0u) {

  if constexpr (sizeof...(end) == 0) {
    return 0;
  } else if constexpr (

      aggregate_with_2_element<T, max_count>(
          make_index_sequence<sizeof...(begin) + 1>{},

          1ll)) {
  }
  static_assert(sizeof...(begin) + sizeof...(end) == max_count + 1,
                "not match");

  return 0;
}

template <typename T, size_t begin, size_t agg, size_t end>
constexpr size_t test_build_in_array_size() {
  if constexpr (end - begin <= 1) {
    return 0;
  } else if constexpr (!enable_buildin_array<T>(make_index_sequence<begin>{},
                                                make_index_sequence<agg>{},
                                                make_index_sequence<end>{})) {
    return test_build_in_array_size<T, begin + 1, agg + 1, end - 1>();
  } else {
    return agg;
  }
}

template <int left, int right> struct Midder {
  static constexpr int mid_ = (right - left) / 2 + left;
};

template <int left, int right>
inline constexpr int midder_v = Midder<left, right>::mid_;

template <typename T, int front, int left, int right>
constexpr int binary_search_array_size(long long) {
  constexpr int mid = midder_v<left, right>;
  if constexpr (right - left <= 1 || mid == left || mid == right) {
    return right - 1;
  } else if constexpr (enable_buildin_array<T>(make_index_sequence<front>{},
                                               make_index_sequence<mid>{},
                                               0ll)) {
    return binary_search_array_size<T, front, mid, right>(0ll);
  } else {
    return binary_search_array_size<T, front, left, mid>(0ll);
  }
}

template <typename T, int max_count, int begin, int end>
constexpr size_t count_field(size_t field) {
  if constexpr (end <= 0) {
    return field;
  } else if constexpr (should_dive_in<T, begin>(1ll)) {
    constexpr auto remain =
        binary_search_array_size<T, begin, 1, max_count - begin>(1ll);
    return count_field<T, max_count, begin + remain, end - remain>(field + 1);
  } else {
    return count_field<T, max_count, begin + 1, end - 1>(field + 1);
  }

  // return 0;
}

template <typename T, size_t... begin, size_t... agg, size_t... end>
constexpr auto detect_struct(index_sequence<begin...>, index_sequence<agg...>,
                             index_sequence<end...>)
    -> decltype(T{AnyType{begin}..., {AnyType{agg}...}, AnyType{end}...}, 0);

template <typename T, size_t begin, size_t agg, size_t end>
constexpr auto pass_struct(long long)->decltype(detect_struct<T>(
    make_index_sequence<begin>{}, make_index_sequence<agg>{},
    make_index_sequence<end>{}, 0)) {
  return 1;
}

template <typename T, size_t begin, size_t agg, size_t end>
constexpr auto pass_struct(int) {
  return 0;
}
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
  bbb b[10];
  // int arr[3];
  int a;
  char c;
};
struct qweqwe {
  // int arr[3];
  int a;
  aaa temp[3];
  char c;
};

int main() {
  // cout << should_dive_in<fff, 1, 1>(1ll) << endl;
  // cout << should_dive_in<fff, 0, 1>(1ll) << endl;
  // cout << should_dive_in<fff, 4, 1>(1ll) << endl;
  // cout << count_field<fff, 5, 0, 4, 5>(0) << endl;
  // cout << midder_v<fff, 2, 4> << endl;
  // cout << enable_buildin_array<foo>(make_index_sequence<2>{},
  // make_index_sequence<4>{}, 1ll) << endl;
  // cout << binary_search_array_size<fff, 1, 1, 4>(1ll) << endl;
  // cout << binary_search_array_size<aaa, 0, 1, 12>(1ll) << endl;
  // cout << binary_search_array_size<qweqwe, 1, 1, 4>(1ll) << endl;
  //cout << should_dive_in<fff, 0, 2, >(1ll) << endl;
  cout << pass_struct<fff, 5>(1, 4, 1ll) << endl;

  // cout << count_field<fff, 5, 0, 5>(0) << endl;
  // cout << count_field<aaa, 12, 0, 12>(0) << endl;
  // cout << count_field<qweqwe, 5, 0, 5>(0) << endl;
  // cout << count_field<fff, 5, 0, 5, 0>(0) << endl;
  // cout << count_field<fff, 5, 0, 5, 0>(0) << endl;
  //  cout << count_field<fff, 5, 1, 4, 1>(5) << endl;
  //   cout << continuous_array<fff>(make_index_sequence<1>{},
  //   make_index_sequence<2>{}) <<endl;
  //   auto f_ = fff{{}, {1, 1}, {}};
  return 0;
}
