#ifndef __COMMON__
#define __COMMON__

#include <cstddef>
#define MAX_SEARCH_COUNT 200
#define MAX_MEMBER_FIELD 100

template<int left, int right>
struct Midder {
  static constexpr int mid_ = (right - left) / 2 + left;
};

template <int left, int right>
inline constexpr int midder_v = Midder<left, right>::mid_;

struct AnyType {
  size_t ignore;
  template <typename T> operator T() noexcept;
};
#endif