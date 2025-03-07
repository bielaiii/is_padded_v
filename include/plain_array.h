#ifndef __PLAIN_STRUCTURE__
#define __PLAIN_STRUCTURE__

struct Single {
    float ff;
    double db;
};


struct baz {
    Single sgl;

  unsigned long long ll;
  char pad;
  int arr[2];
  double ft;
  float dff;
};

#endif