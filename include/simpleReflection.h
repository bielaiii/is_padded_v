#include <cstddef>
#include <cstdlib>
#include <type_traits>
#include <utility>
//using namespace std;

struct AnyType {
  size_t ignore;
  template <typename T> operator T() noexcept;
};

template <typename T, size_t... N>
constexpr auto try_init_impl(std::index_sequence<N...>)
    -> decltype(T{AnyType{N}...});

template <typename T, size_t N>
constexpr auto try_init(long long)
    -> decltype(try_init_impl<T>(std::make_index_sequence<N>{}), true) {
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

template <typename T, size_t... begin, size_t... agg, size_t... end>
constexpr auto aggregate_initable(std::index_sequence<begin...>,
                                  std::index_sequence<agg...>,
                                  std::index_sequence<end...>)
    -> decltype(T{AnyType{begin}..., {AnyType{agg}...}, AnyType{end}...});

template <typename T, size_t begin, size_t agg, size_t end>
constexpr auto pass_struct_aggeregate(long long)
    -> decltype(aggregate_initable<T>(std::make_index_sequence<begin>{},
                                      std::make_index_sequence<agg>{},
                                      std::make_index_sequence<end>{}),
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
constexpr auto enable_buildin_array(std::index_sequence<begin...>,
                                    std::index_sequence<agg...>, long long)
    -> decltype(T{AnyType{begin}...,
                  {
                      AnyType{agg}...,
                  }},
                -1) {
  return 1;
}

template <typename T, size_t... begin, size_t... agg>
constexpr auto enable_buildin_array(std::index_sequence<begin...>,
                                    std::index_sequence<agg...>, int)
    -> decltype(-1) {
  return 0;
}

template <typename T, size_t... begin, size_t... agg, size_t... end>
constexpr auto continuous_array(std::index_sequence<begin...>)
    -> decltype(T{AnyType{begin}..., {AnyType{}, AnyType{}}}, 0);

template <typename T, int begin>
constexpr auto should_dive_in(long long)
    -> decltype(continuous_array<T>(std::make_index_sequence<begin>{}

                                    ),
                0ull) {
  return 1;
}

template <typename T, int begin> constexpr auto should_dive_in(int) {
  return 0;
}

template <typename T, size_t max_count, size_t... begin, size_t... end>
constexpr auto aggregate_with_2_element(std::index_sequence<begin...>,
                                        std::index_sequence<end...>, long long)
    -> decltype(T{AnyType{begin}..., {AnyType{end}...}}, 0u) {

  if constexpr (sizeof...(end) == 0) {
    return 0;
  } else {
    constexpr auto begin_ = sizeof...(begin);
    constexpr auto end_ = sizeof...(end);
    aggregate_with_2_element<T, max_count>(std::make_index_sequence<begin_ + 1>{},
                                           1ll);
  }
  static_assert(sizeof...(begin) + sizeof...(end) == max_count, "not match");
  return 1;
}

/* template <typename T, size_t max_count, size_t... begin, size_t... end>
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
} */

template <typename T, size_t... begin, size_t... agg, size_t... end>
constexpr auto detect_struct(std::index_sequence<begin...>, std::index_sequence<agg...>,
                             std::index_sequence<end...>)
    -> decltype(T{AnyType{begin}..., {AnyType{agg}...}, AnyType{end}...}, 0) {
  return 314;
}

template <typename T, size_t begin, size_t agg, size_t end>
constexpr auto pass_struct(long long)
    -> decltype(detect_struct<T>(std::make_index_sequence<begin>{},
                                 std::make_index_sequence<agg>{},
                                 std::make_index_sequence<end>{}),
                0) {
  return 1;
}

template <typename T, size_t begin, size_t agg, size_t end>
constexpr auto pass_struct(int) {
  return 0;
}

template <typename T, size_t begin, size_t agg, size_t end>
constexpr size_t test_build_in_array_size() {
  if constexpr (end - begin <= 1) {
    return 0;
  } else if constexpr (!enable_buildin_array<T>(std::make_index_sequence<begin>{},
                                                std::make_index_sequence<agg>{},
                                                std::make_index_sequence<end>{})) {
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
  } else if constexpr (enable_buildin_array<T>(std::make_index_sequence<front>{},
                                               std::make_index_sequence<mid>{},
                                               0ll)) {
    return binary_search_array_size<T, front, mid, right>(0ll);
  } else {
    return binary_search_array_size<T, front, left, mid>(0ll);
  }
}

template <typename T, int max_count, int begin, int end, size_t field>
constexpr size_t count_unique_field() {
  if constexpr (end <= 0) {
    return field;
  }
#if 1
  else if constexpr (pass_struct<T, begin, 2, max_count - begin - 1>(1ll) ==
                     1) {
    return count_unique_field<T, max_count, begin + 1, end - 1, field + 1>();
  }
#endif

  else if constexpr (should_dive_in<T, begin>(1ll)) {
    constexpr auto remain =
        binary_search_array_size<T, begin, 1, max_count - begin>(1ll);
    return count_unique_field<T, max_count, begin + remain, end - remain,
                              field + 1>();
  } else {
    return count_unique_field<T, max_count, begin + 1, end - 1, field + 1>();
  }
}

template <typename T> constexpr size_t get_member_field() {
  constexpr auto sz = binary_search<T, 0, 50, 50>(1l);
  return count_unique_field<T, sz, 0, sz - 0, 0>();
}
template <typename T, size_t size_> constexpr size_t for_each_field_size();

template <typename T,
          std::enable_if_t<std::is_class_v<std::remove_reference_t<T>>, int> = 0>
constexpr size_t plain_size(T) {
  using T_ = std::remove_reference_t<T>;
  constexpr size_t sz = binary_search<T_, 0, 50, 50>(1l);
  return for_each_field_size<T, sz>();
}

template <
    typename T, size_t N,
    std::enable_if_t<std::is_class_v<std::remove_all_extents_t<T>> && std::is_array_v<T>, int> = 0>
constexpr size_t plain_size(T[N]) {
  using no_array_t = std::remove_all_extents_t<T>;
  constexpr size_t sz = binary_search<no_array_t, 0, 50, 50>(1l);
  return for_each_field_size<no_array_t, sz>() * N;
}

template <typename T,
          std::enable_if_t<!std::is_class_v<std::remove_reference_t<T>>, int> = 0>
constexpr size_t plain_size(T) {
  return sizeof(T);
}
// template <typename T,
// enable_if_t<std::is_fundamental_v<std::remove_reference_t<T>>, int> = 0>
// constexpr size_t plain_size(T ) {
//   return sizeof(T);
// }
/* template <typename T, size_t size_> constexpr size_t for_each_field_size() {
  if constexpr (size_ == 1) {
    auto &&[_1] = T{};
    return plain_size<_1>();
  } else if constexpr (size_ == 2) {
    auto &&[_1, _2] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2);
  } else if constexpr (size_ == 3) {
    auto &&[_1, _2, _3] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3);
  } else if constexpr (size_ == 4) {
    auto &&[_1, _2, _3, _4] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4);
  } else if constexpr (size_ == 5) {
    auto &&[_1, _2, _3, _4, _5] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5);
  } else {
    // static_assert(0, "should not print");
    return -1;
  }
} */

template <typename T, size_t size_> constexpr size_t for_each_field_size() {
  if constexpr (size_ == 1) {
    auto &&[_1] = T{};
    return plain_size<decltype(_1)>(_1);
  }
  if constexpr (size_ == 2) {
    auto &&[_1, _2] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2);
  } else if constexpr (size_ == 3) {
    auto &&[_1, _2, _3] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3);
  } else if constexpr (size_ == 4) {
    auto &&[_1, _2, _3, _4] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4);
  } else if constexpr (size_ == 5) {
    auto &&[_1, _2, _3, _4, _5] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5);
  } else if constexpr (size_ == 6) {
    auto &&[_1, _2, _3, _4, _5, _6] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6);
  } else if constexpr (size_ == 7) {
    auto &&[_1, _2, _3, _4, _5, _6, _7] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7);
  } else if constexpr (size_ == 8) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8);
  } else if constexpr (size_ == 9) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9);
  } else if constexpr (size_ == 10) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10);
  } else if constexpr (size_ == 11) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11);
  } else if constexpr (size_ == 12) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12);
  } else if constexpr (size_ == 13) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13);
  } else if constexpr (size_ == 14) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14);
  } else if constexpr (size_ == 15) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15] =
        T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15);
  } else if constexpr (size_ == 16) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16);
  } else if constexpr (size_ == 17) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17);
  } else if constexpr (size_ == 18) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18);
  } else if constexpr (size_ == 19) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19);
  } else if constexpr (size_ == 20) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20);
  } else if constexpr (size_ == 21) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21);
  } else if constexpr (size_ == 22) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22);
  } else if constexpr (size_ == 23) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23);
  } else if constexpr (size_ == 24) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24);
  } else if constexpr (size_ == 25) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25);
  } else if constexpr (size_ == 26) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26);
  } else if constexpr (size_ == 27) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27);
  } else if constexpr (size_ == 28) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28] =
        T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28);
  } else if constexpr (size_ == 29) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29);
  } else if constexpr (size_ == 30) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30);
  } else if constexpr (size_ == 31) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31);
  } else if constexpr (size_ == 32) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32);
  } else if constexpr (size_ == 33) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33);
  } else if constexpr (size_ == 34) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33, _34] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33) + plain_size<decltype(_34)>(_34);
  } else if constexpr (size_ == 35) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33, _34, _35] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33) + plain_size<decltype(_34)>(_34) +
           plain_size<decltype(_35)>(_35);
  } else if constexpr (size_ == 36) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33, _34, _35, _36] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33) + plain_size<decltype(_34)>(_34) +
           plain_size<decltype(_35)>(_35) + plain_size<decltype(_36)>(_36);
  } else if constexpr (size_ == 37) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33, _34, _35, _36, _37] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33) + plain_size<decltype(_34)>(_34) +
           plain_size<decltype(_35)>(_35) + plain_size<decltype(_36)>(_36) +
           plain_size<decltype(_37)>(_37);
  } else if constexpr (size_ == 38) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33, _34, _35, _36, _37, _38] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33) + plain_size<decltype(_34)>(_34) +
           plain_size<decltype(_35)>(_35) + plain_size<decltype(_36)>(_36) +
           plain_size<decltype(_37)>(_37) + plain_size<decltype(_38)>(_38);
  } else if constexpr (size_ == 39) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33) + plain_size<decltype(_34)>(_34) +
           plain_size<decltype(_35)>(_35) + plain_size<decltype(_36)>(_36) +
           plain_size<decltype(_37)>(_37) + plain_size<decltype(_38)>(_38) +
           plain_size<decltype(_39)>(_39);
  } else if constexpr (size_ == 40) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33) + plain_size<decltype(_34)>(_34) +
           plain_size<decltype(_35)>(_35) + plain_size<decltype(_36)>(_36) +
           plain_size<decltype(_37)>(_37) + plain_size<decltype(_38)>(_38) +
           plain_size<decltype(_39)>(_39) + plain_size<decltype(_40)>(_40);
  } else if constexpr (size_ == 41) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41] =
        T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33) + plain_size<decltype(_34)>(_34) +
           plain_size<decltype(_35)>(_35) + plain_size<decltype(_36)>(_36) +
           plain_size<decltype(_37)>(_37) + plain_size<decltype(_38)>(_38) +
           plain_size<decltype(_39)>(_39) + plain_size<decltype(_40)>(_40) +
           plain_size<decltype(_41)>(_41);
  } else if constexpr (size_ == 42) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
            _42] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33) + plain_size<decltype(_34)>(_34) +
           plain_size<decltype(_35)>(_35) + plain_size<decltype(_36)>(_36) +
           plain_size<decltype(_37)>(_37) + plain_size<decltype(_38)>(_38) +
           plain_size<decltype(_39)>(_39) + plain_size<decltype(_40)>(_40) +
           plain_size<decltype(_41)>(_41) + plain_size<decltype(_42)>(_42);
  } else if constexpr (size_ == 43) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
            _42, _43] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33) + plain_size<decltype(_34)>(_34) +
           plain_size<decltype(_35)>(_35) + plain_size<decltype(_36)>(_36) +
           plain_size<decltype(_37)>(_37) + plain_size<decltype(_38)>(_38) +
           plain_size<decltype(_39)>(_39) + plain_size<decltype(_40)>(_40) +
           plain_size<decltype(_41)>(_41) + plain_size<decltype(_42)>(_42) +
           plain_size<decltype(_43)>(_43);
  } else if constexpr (size_ == 44) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
            _42, _43, _44] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33) + plain_size<decltype(_34)>(_34) +
           plain_size<decltype(_35)>(_35) + plain_size<decltype(_36)>(_36) +
           plain_size<decltype(_37)>(_37) + plain_size<decltype(_38)>(_38) +
           plain_size<decltype(_39)>(_39) + plain_size<decltype(_40)>(_40) +
           plain_size<decltype(_41)>(_41) + plain_size<decltype(_42)>(_42) +
           plain_size<decltype(_43)>(_43) + plain_size<decltype(_44)>(_44);
  } else if constexpr (size_ == 45) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
            _42, _43, _44, _45] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33) + plain_size<decltype(_34)>(_34) +
           plain_size<decltype(_35)>(_35) + plain_size<decltype(_36)>(_36) +
           plain_size<decltype(_37)>(_37) + plain_size<decltype(_38)>(_38) +
           plain_size<decltype(_39)>(_39) + plain_size<decltype(_40)>(_40) +
           plain_size<decltype(_41)>(_41) + plain_size<decltype(_42)>(_42) +
           plain_size<decltype(_43)>(_43) + plain_size<decltype(_44)>(_44) +
           plain_size<decltype(_45)>(_45);
  } else if constexpr (size_ == 46) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
            _42, _43, _44, _45, _46] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33) + plain_size<decltype(_34)>(_34) +
           plain_size<decltype(_35)>(_35) + plain_size<decltype(_36)>(_36) +
           plain_size<decltype(_37)>(_37) + plain_size<decltype(_38)>(_38) +
           plain_size<decltype(_39)>(_39) + plain_size<decltype(_40)>(_40) +
           plain_size<decltype(_41)>(_41) + plain_size<decltype(_42)>(_42) +
           plain_size<decltype(_43)>(_43) + plain_size<decltype(_44)>(_44) +
           plain_size<decltype(_45)>(_45) + plain_size<decltype(_46)>(_46);
  } else if constexpr (size_ == 47) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
            _42, _43, _44, _45, _46, _47] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33) + plain_size<decltype(_34)>(_34) +
           plain_size<decltype(_35)>(_35) + plain_size<decltype(_36)>(_36) +
           plain_size<decltype(_37)>(_37) + plain_size<decltype(_38)>(_38) +
           plain_size<decltype(_39)>(_39) + plain_size<decltype(_40)>(_40) +
           plain_size<decltype(_41)>(_41) + plain_size<decltype(_42)>(_42) +
           plain_size<decltype(_43)>(_43) + plain_size<decltype(_44)>(_44) +
           plain_size<decltype(_45)>(_45) + plain_size<decltype(_46)>(_46) +
           plain_size<decltype(_47)>(_47);
  } else if constexpr (size_ == 48) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
            _42, _43, _44, _45, _46, _47, _48] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33) + plain_size<decltype(_34)>(_34) +
           plain_size<decltype(_35)>(_35) + plain_size<decltype(_36)>(_36) +
           plain_size<decltype(_37)>(_37) + plain_size<decltype(_38)>(_38) +
           plain_size<decltype(_39)>(_39) + plain_size<decltype(_40)>(_40) +
           plain_size<decltype(_41)>(_41) + plain_size<decltype(_42)>(_42) +
           plain_size<decltype(_43)>(_43) + plain_size<decltype(_44)>(_44) +
           plain_size<decltype(_45)>(_45) + plain_size<decltype(_46)>(_46) +
           plain_size<decltype(_47)>(_47) + plain_size<decltype(_48)>(_48);
  } else if constexpr (size_ == 49) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
            _42, _43, _44, _45, _46, _47, _48, _49] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33) + plain_size<decltype(_34)>(_34) +
           plain_size<decltype(_35)>(_35) + plain_size<decltype(_36)>(_36) +
           plain_size<decltype(_37)>(_37) + plain_size<decltype(_38)>(_38) +
           plain_size<decltype(_39)>(_39) + plain_size<decltype(_40)>(_40) +
           plain_size<decltype(_41)>(_41) + plain_size<decltype(_42)>(_42) +
           plain_size<decltype(_43)>(_43) + plain_size<decltype(_44)>(_44) +
           plain_size<decltype(_45)>(_45) + plain_size<decltype(_46)>(_46) +
           plain_size<decltype(_47)>(_47) + plain_size<decltype(_48)>(_48) +
           plain_size<decltype(_49)>(_49);
  } else if constexpr (size_ == 50) {
    auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
            _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
            _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
            _42, _43, _44, _45, _46, _47, _48, _49, _50] = T{};
    return plain_size<decltype(_1)>(_1) + plain_size<decltype(_2)>(_2) +
           plain_size<decltype(_3)>(_3) + plain_size<decltype(_4)>(_4) +
           plain_size<decltype(_5)>(_5) + plain_size<decltype(_6)>(_6) +
           plain_size<decltype(_7)>(_7) + plain_size<decltype(_8)>(_8) +
           plain_size<decltype(_9)>(_9) + plain_size<decltype(_10)>(_10) +
           plain_size<decltype(_11)>(_11) + plain_size<decltype(_12)>(_12) +
           plain_size<decltype(_13)>(_13) + plain_size<decltype(_14)>(_14) +
           plain_size<decltype(_15)>(_15) + plain_size<decltype(_16)>(_16) +
           plain_size<decltype(_17)>(_17) + plain_size<decltype(_18)>(_18) +
           plain_size<decltype(_19)>(_19) + plain_size<decltype(_20)>(_20) +
           plain_size<decltype(_21)>(_21) + plain_size<decltype(_22)>(_22) +
           plain_size<decltype(_23)>(_23) + plain_size<decltype(_24)>(_24) +
           plain_size<decltype(_25)>(_25) + plain_size<decltype(_26)>(_26) +
           plain_size<decltype(_27)>(_27) + plain_size<decltype(_28)>(_28) +
           plain_size<decltype(_29)>(_29) + plain_size<decltype(_30)>(_30) +
           plain_size<decltype(_31)>(_31) + plain_size<decltype(_32)>(_32) +
           plain_size<decltype(_33)>(_33) + plain_size<decltype(_34)>(_34) +
           plain_size<decltype(_35)>(_35) + plain_size<decltype(_36)>(_36) +
           plain_size<decltype(_37)>(_37) + plain_size<decltype(_38)>(_38) +
           plain_size<decltype(_39)>(_39) + plain_size<decltype(_40)>(_40) +
           plain_size<decltype(_41)>(_41) + plain_size<decltype(_42)>(_42) +
           plain_size<decltype(_43)>(_43) + plain_size<decltype(_44)>(_44) +
           plain_size<decltype(_45)>(_45) + plain_size<decltype(_46)>(_46) +
           plain_size<decltype(_47)>(_47) + plain_size<decltype(_48)>(_48) +
           plain_size<decltype(_49)>(_49) + plain_size<decltype(_50)>(_50);
  } else {
    return -1;
  }
}

template <typename T> constexpr size_t plain_size_of_struct() {
  constexpr size_t unique_field = get_member_field<T>();
  return for_each_field_size<T, unique_field>();
}

template <
    typename T,
    std::enable_if_t<std::is_standard_layout_v<T> && std::is_trivial_v<T>, int> = 0>
struct is_padded {
  static constexpr bool value = plain_size_of_struct<T>() != sizeof(T);
};

template <typename T> inline constexpr bool is_padded_v = is_padded<T>::value;
