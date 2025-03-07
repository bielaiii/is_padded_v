#ifndef __NESTED_STRUCTURE__
#define __NESTED_STRUCTURE__

struct bar {
  unsigned long long ull;
  float f;
  double (*dual)[3];
};

struct foo {
  int a;
  unsigned char b;
};

struct bazzz {
  foo f_;
  unsigned long long ll;
  char pad;
  bar b_;
};

#endif