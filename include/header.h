#ifndef __HEADER__
#define __HEADER__


struct bar {
    unsigned long long fakel;
    float single[3];
    double (*dual)[3];
  };
  
  struct foo {
  
    int a;
    unsigned char b;
   // bar b_;
  };

  

  struct baz {
    foo f_;
    unsigned long long ll;
  };

#endif