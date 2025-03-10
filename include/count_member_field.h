#ifndef COUNT_MEMBER_FIELD
#define COUNT_MEMBER_FIELD

#include "common_module.h"
#include <cmath>
#include <cstddef>
#include <type_traits>
#include <utility>
#include"generate_match.h"

namespace ver2 {

template <typename T, size_t... N>
constexpr auto try_aggregate_init(long long, std::index_sequence<N...>)
    -> decltype(T{{AnyType{N}}...}, 0ll) {
  return sizeof...(N);
}

template <typename T, size_t... N>
constexpr auto try_aggregate_init(int, std::index_sequence<N...>) {
  return 0;
}

template <typename T, int begin = 0, int end = MAX_MEMBER_FIELD + 1>
constexpr size_t binary_search_member_field() {
  if constexpr (end - begin <= 1) {
    return begin;
  } else if constexpr (try_aggregate_init<T>(
                           1ll,
                           std::make_index_sequence<midder_v<begin, end>>{})) {
    return binary_search_member_field<T, midder_v<begin, end>, end>();
  } else {
    return binary_search_member_field<T, begin, midder_v<begin, end>>();
  }
}
template <typename T, size_t size_> constexpr size_t for_each_field_size();
template <typename T, std::enable_if_t<
                          std::is_class_v<T>, int> = 0>
constexpr size_t plain_size() {
  using T_ = std::remove_reference_t<T>;
  constexpr size_t member_field =
      binary_search_member_field<T_>();
  return for_each_field_size<T_, member_field>();
}

template <typename T, 
          std::enable_if_t<std::is_class_v<std::remove_all_extents_t<T>> &&
                               std::is_array_v<T>,
                           int> = 0>
constexpr size_t plain_size() {
  using no_array_t = std::remove_all_extents_t<T>;
  constexpr size_t array_size = std::extent_v<T>;
  constexpr size_t member_field =
      binary_search_member_field<no_array_t>();
  return for_each_field_size<no_array_t, member_field>() * array_size;
}

template <typename T,
          std::enable_if_t<std::is_fundamental_v<std::remove_reference_t<T>> ||
                               std::is_pointer_v<std::remove_reference_t<T>>,
                           int> = 0>
constexpr size_t plain_size() {
  return sizeof(T);
}

template <typename T, std::enable_if_t<
                          std::is_fundamental_v<std::remove_all_extents_t<T>> &&
                              std::is_array_v<T>,
                          int> = 0>
constexpr size_t plain_size() {
  constexpr size_t array_size = std::extent_v<T>;
  return sizeof(std::remove_all_extents_t<T>) * array_size;
}

template <typename T, size_t size_> constexpr size_t for_each_field_size() {
    if constexpr (size_ == 1) {
      auto &&[_1] = T{};
      return plain_size<decltype(_1)>();
    } else if constexpr (size_ == 2) {
      auto &&[_1, _2] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>();
    } else if constexpr (size_ == 3) {
      auto &&[_1, _2, _3] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>();
    } else if constexpr (size_ == 4) {
      auto &&[_1, _2, _3, _4] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>();
    } else if constexpr (size_ == 5) {
      auto &&[_1, _2, _3, _4, _5] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>();
    } else if constexpr (size_ == 6) {
      auto &&[_1, _2, _3, _4, _5, _6] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>();
    } else if constexpr (size_ == 7) {
      auto &&[_1, _2, _3, _4, _5, _6, _7] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>();
    } else if constexpr (size_ == 8) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>();
    } else if constexpr (size_ == 9) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>();
    } else if constexpr (size_ == 10) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>();
    } else if constexpr (size_ == 11) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>();
    } else if constexpr (size_ == 12) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>();
    } else if constexpr (size_ == 13) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>();
    } else if constexpr (size_ == 14) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>();
    } else if constexpr (size_ == 15) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15] =
          T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>();
    } else if constexpr (size_ == 16) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>();
    } else if constexpr (size_ == 17) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>();
    } else if constexpr (size_ == 18) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>();
    } else if constexpr (size_ == 19) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>();
    } else if constexpr (size_ == 20) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>();
    } else if constexpr (size_ == 21) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>();
    } else if constexpr (size_ == 22) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>();
    } else if constexpr (size_ == 23) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>();
    } else if constexpr (size_ == 24) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>();
    } else if constexpr (size_ == 25) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>();
    } else if constexpr (size_ == 26) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>();
    } else if constexpr (size_ == 27) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>();
    } else if constexpr (size_ == 28) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28] =
          T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>();
    } else if constexpr (size_ == 29) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>();
    } else if constexpr (size_ == 30) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>();
    } else if constexpr (size_ == 31) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>();
    } else if constexpr (size_ == 32) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>();
    } else if constexpr (size_ == 33) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>();
    } else if constexpr (size_ == 34) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>();
    } else if constexpr (size_ == 35) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>();
    } else if constexpr (size_ == 36) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>();
    } else if constexpr (size_ == 37) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>();
    } else if constexpr (size_ == 38) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>();
    } else if constexpr (size_ == 39) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>();
    } else if constexpr (size_ == 40) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>();
    } else if constexpr (size_ == 41) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41] =
          T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>();
    } else if constexpr (size_ == 42) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>();
    } else if constexpr (size_ == 43) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>();
    } else if constexpr (size_ == 44) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>();
    } else if constexpr (size_ == 45) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>();
    } else if constexpr (size_ == 46) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>();
    } else if constexpr (size_ == 47) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>();
    } else if constexpr (size_ == 48) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>();
    } else if constexpr (size_ == 49) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>();
    } else if constexpr (size_ == 50) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>();
    } else if constexpr (size_ == 51) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>();
    } else if constexpr (size_ == 52) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>();
    } else if constexpr (size_ == 53) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>();
    } else if constexpr (size_ == 54) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54] =
          T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>();
    } else if constexpr (size_ == 55) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>();
    } else if constexpr (size_ == 56) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>();
    } else if constexpr (size_ == 57) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>();
    } else if constexpr (size_ == 58) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>();
    } else if constexpr (size_ == 59) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>();
    } else if constexpr (size_ == 60) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>();
    } else if constexpr (size_ == 61) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>();
    } else if constexpr (size_ == 62) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>();
    } else if constexpr (size_ == 63) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>();
    } else if constexpr (size_ == 64) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>();
    } else if constexpr (size_ == 65) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>();
    } else if constexpr (size_ == 66) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>();
    } else if constexpr (size_ == 67) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67] =
          T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>();
    } else if constexpr (size_ == 68) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>();
    } else if constexpr (size_ == 69) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>();
    } else if constexpr (size_ == 70) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>();
    } else if constexpr (size_ == 71) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>();
    } else if constexpr (size_ == 72) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>();
    } else if constexpr (size_ == 73) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>();
    } else if constexpr (size_ == 74) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>();
    } else if constexpr (size_ == 75) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>();
    } else if constexpr (size_ == 76) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>();
    } else if constexpr (size_ == 77) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>();
    } else if constexpr (size_ == 78) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>();
    } else if constexpr (size_ == 79) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>();
    } else if constexpr (size_ == 80) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80] =
          T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>();
    } else if constexpr (size_ == 81) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>();
    } else if constexpr (size_ == 82) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>();
    } else if constexpr (size_ == 83) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>();
    } else if constexpr (size_ == 84) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83, _84] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>() + plain_size<decltype(_84)>();
    } else if constexpr (size_ == 85) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83, _84, _85] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>() + plain_size<decltype(_84)>() +
             plain_size<decltype(_85)>();
    } else if constexpr (size_ == 86) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83, _84, _85, _86] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>() + plain_size<decltype(_84)>() +
             plain_size<decltype(_85)>() + plain_size<decltype(_86)>();
    } else if constexpr (size_ == 87) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83, _84, _85, _86, _87] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>() + plain_size<decltype(_84)>() +
             plain_size<decltype(_85)>() + plain_size<decltype(_86)>() +
             plain_size<decltype(_87)>();
    } else if constexpr (size_ == 88) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83, _84, _85, _86, _87, _88] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>() + plain_size<decltype(_84)>() +
             plain_size<decltype(_85)>() + plain_size<decltype(_86)>() +
             plain_size<decltype(_87)>() + plain_size<decltype(_88)>();
    } else if constexpr (size_ == 89) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83, _84, _85, _86, _87, _88, _89] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>() + plain_size<decltype(_84)>() +
             plain_size<decltype(_85)>() + plain_size<decltype(_86)>() +
             plain_size<decltype(_87)>() + plain_size<decltype(_88)>() +
             plain_size<decltype(_89)>();
    } else if constexpr (size_ == 90) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83, _84, _85, _86, _87, _88, _89, _90] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>() + plain_size<decltype(_84)>() +
             plain_size<decltype(_85)>() + plain_size<decltype(_86)>() +
             plain_size<decltype(_87)>() + plain_size<decltype(_88)>() +
             plain_size<decltype(_89)>() + plain_size<decltype(_90)>();
    } else if constexpr (size_ == 91) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>() + plain_size<decltype(_84)>() +
             plain_size<decltype(_85)>() + plain_size<decltype(_86)>() +
             plain_size<decltype(_87)>() + plain_size<decltype(_88)>() +
             plain_size<decltype(_89)>() + plain_size<decltype(_90)>() +
             plain_size<decltype(_91)>();
    } else if constexpr (size_ == 92) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>() + plain_size<decltype(_84)>() +
             plain_size<decltype(_85)>() + plain_size<decltype(_86)>() +
             plain_size<decltype(_87)>() + plain_size<decltype(_88)>() +
             plain_size<decltype(_89)>() + plain_size<decltype(_90)>() +
             plain_size<decltype(_91)>() + plain_size<decltype(_92)>();
    } else if constexpr (size_ == 93) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93] =
          T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>() + plain_size<decltype(_84)>() +
             plain_size<decltype(_85)>() + plain_size<decltype(_86)>() +
             plain_size<decltype(_87)>() + plain_size<decltype(_88)>() +
             plain_size<decltype(_89)>() + plain_size<decltype(_90)>() +
             plain_size<decltype(_91)>() + plain_size<decltype(_92)>() +
             plain_size<decltype(_93)>();
    } else if constexpr (size_ == 94) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93,
              _94] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>() + plain_size<decltype(_84)>() +
             plain_size<decltype(_85)>() + plain_size<decltype(_86)>() +
             plain_size<decltype(_87)>() + plain_size<decltype(_88)>() +
             plain_size<decltype(_89)>() + plain_size<decltype(_90)>() +
             plain_size<decltype(_91)>() + plain_size<decltype(_92)>() +
             plain_size<decltype(_93)>() + plain_size<decltype(_94)>();
    } else if constexpr (size_ == 95) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93,
              _94, _95] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>() + plain_size<decltype(_84)>() +
             plain_size<decltype(_85)>() + plain_size<decltype(_86)>() +
             plain_size<decltype(_87)>() + plain_size<decltype(_88)>() +
             plain_size<decltype(_89)>() + plain_size<decltype(_90)>() +
             plain_size<decltype(_91)>() + plain_size<decltype(_92)>() +
             plain_size<decltype(_93)>() + plain_size<decltype(_94)>() +
             plain_size<decltype(_95)>();
    } else if constexpr (size_ == 96) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93,
              _94, _95, _96] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>() + plain_size<decltype(_84)>() +
             plain_size<decltype(_85)>() + plain_size<decltype(_86)>() +
             plain_size<decltype(_87)>() + plain_size<decltype(_88)>() +
             plain_size<decltype(_89)>() + plain_size<decltype(_90)>() +
             plain_size<decltype(_91)>() + plain_size<decltype(_92)>() +
             plain_size<decltype(_93)>() + plain_size<decltype(_94)>() +
             plain_size<decltype(_95)>() + plain_size<decltype(_96)>();
    } else if constexpr (size_ == 97) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93,
              _94, _95, _96, _97] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>() + plain_size<decltype(_84)>() +
             plain_size<decltype(_85)>() + plain_size<decltype(_86)>() +
             plain_size<decltype(_87)>() + plain_size<decltype(_88)>() +
             plain_size<decltype(_89)>() + plain_size<decltype(_90)>() +
             plain_size<decltype(_91)>() + plain_size<decltype(_92)>() +
             plain_size<decltype(_93)>() + plain_size<decltype(_94)>() +
             plain_size<decltype(_95)>() + plain_size<decltype(_96)>() +
             plain_size<decltype(_97)>();
    } else if constexpr (size_ == 98) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93,
              _94, _95, _96, _97, _98] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>() + plain_size<decltype(_84)>() +
             plain_size<decltype(_85)>() + plain_size<decltype(_86)>() +
             plain_size<decltype(_87)>() + plain_size<decltype(_88)>() +
             plain_size<decltype(_89)>() + plain_size<decltype(_90)>() +
             plain_size<decltype(_91)>() + plain_size<decltype(_92)>() +
             plain_size<decltype(_93)>() + plain_size<decltype(_94)>() +
             plain_size<decltype(_95)>() + plain_size<decltype(_96)>() +
             plain_size<decltype(_97)>() + plain_size<decltype(_98)>();
    } else if constexpr (size_ == 99) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93,
              _94, _95, _96, _97, _98, _99] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>() + plain_size<decltype(_84)>() +
             plain_size<decltype(_85)>() + plain_size<decltype(_86)>() +
             plain_size<decltype(_87)>() + plain_size<decltype(_88)>() +
             plain_size<decltype(_89)>() + plain_size<decltype(_90)>() +
             plain_size<decltype(_91)>() + plain_size<decltype(_92)>() +
             plain_size<decltype(_93)>() + plain_size<decltype(_94)>() +
             plain_size<decltype(_95)>() + plain_size<decltype(_96)>() +
             plain_size<decltype(_97)>() + plain_size<decltype(_98)>() +
             plain_size<decltype(_99)>();
    } else if constexpr (size_ == 100) {
      auto &&[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,
              _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28,
              _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41,
              _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
              _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67,
              _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
              _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93,
              _94, _95, _96, _97, _98, _99, _100] = T{};
      return plain_size<decltype(_1)>() + plain_size<decltype(_2)>() +
             plain_size<decltype(_3)>() + plain_size<decltype(_4)>() +
             plain_size<decltype(_5)>() + plain_size<decltype(_6)>() +
             plain_size<decltype(_7)>() + plain_size<decltype(_8)>() +
             plain_size<decltype(_9)>() + plain_size<decltype(_10)>() +
             plain_size<decltype(_11)>() + plain_size<decltype(_12)>() +
             plain_size<decltype(_13)>() + plain_size<decltype(_14)>() +
             plain_size<decltype(_15)>() + plain_size<decltype(_16)>() +
             plain_size<decltype(_17)>() + plain_size<decltype(_18)>() +
             plain_size<decltype(_19)>() + plain_size<decltype(_20)>() +
             plain_size<decltype(_21)>() + plain_size<decltype(_22)>() +
             plain_size<decltype(_23)>() + plain_size<decltype(_24)>() +
             plain_size<decltype(_25)>() + plain_size<decltype(_26)>() +
             plain_size<decltype(_27)>() + plain_size<decltype(_28)>() +
             plain_size<decltype(_29)>() + plain_size<decltype(_30)>() +
             plain_size<decltype(_31)>() + plain_size<decltype(_32)>() +
             plain_size<decltype(_33)>() + plain_size<decltype(_34)>() +
             plain_size<decltype(_35)>() + plain_size<decltype(_36)>() +
             plain_size<decltype(_37)>() + plain_size<decltype(_38)>() +
             plain_size<decltype(_39)>() + plain_size<decltype(_40)>() +
             plain_size<decltype(_41)>() + plain_size<decltype(_42)>() +
             plain_size<decltype(_43)>() + plain_size<decltype(_44)>() +
             plain_size<decltype(_45)>() + plain_size<decltype(_46)>() +
             plain_size<decltype(_47)>() + plain_size<decltype(_48)>() +
             plain_size<decltype(_49)>() + plain_size<decltype(_50)>() +
             plain_size<decltype(_51)>() + plain_size<decltype(_52)>() +
             plain_size<decltype(_53)>() + plain_size<decltype(_54)>() +
             plain_size<decltype(_55)>() + plain_size<decltype(_56)>() +
             plain_size<decltype(_57)>() + plain_size<decltype(_58)>() +
             plain_size<decltype(_59)>() + plain_size<decltype(_60)>() +
             plain_size<decltype(_61)>() + plain_size<decltype(_62)>() +
             plain_size<decltype(_63)>() + plain_size<decltype(_64)>() +
             plain_size<decltype(_65)>() + plain_size<decltype(_66)>() +
             plain_size<decltype(_67)>() + plain_size<decltype(_68)>() +
             plain_size<decltype(_69)>() + plain_size<decltype(_70)>() +
             plain_size<decltype(_71)>() + plain_size<decltype(_72)>() +
             plain_size<decltype(_73)>() + plain_size<decltype(_74)>() +
             plain_size<decltype(_75)>() + plain_size<decltype(_76)>() +
             plain_size<decltype(_77)>() + plain_size<decltype(_78)>() +
             plain_size<decltype(_79)>() + plain_size<decltype(_80)>() +
             plain_size<decltype(_81)>() + plain_size<decltype(_82)>() +
             plain_size<decltype(_83)>() + plain_size<decltype(_84)>() +
             plain_size<decltype(_85)>() + plain_size<decltype(_86)>() +
             plain_size<decltype(_87)>() + plain_size<decltype(_88)>() +
             plain_size<decltype(_89)>() + plain_size<decltype(_90)>() +
             plain_size<decltype(_91)>() + plain_size<decltype(_92)>() +
             plain_size<decltype(_93)>() + plain_size<decltype(_94)>() +
             plain_size<decltype(_95)>() + plain_size<decltype(_96)>() +
             plain_size<decltype(_97)>() + plain_size<decltype(_98)>() +
             plain_size<decltype(_99)>() + plain_size<decltype(_100)>();
    } else {
      return -1;
    }
  }



template <typename T> struct is_padded {
  constexpr static size_t member_field = binary_search_member_field<T>();
  constexpr static bool value =
      for_each_field_size<T, member_field>() != sizeof(T);
};

template <typename T>
inline static constexpr bool is_padded_v = is_padded<T>::value;

} // namespace ver2

#endif