# Check No Padding

This project contains a set of utilities to work with binary representations of various data types, ensuring no padding is added to the structures.

## Files

- `bst.cpp`: Contains the main logic for binary conversion and size calculation without padding.

## Usage

### Functions

- `TryInit<T>()`: Initializes an object of type `T` with default values.
- `NoPaddingSize<T>()`: Calculates the size of an object of type `T` without padding.
- `printBinary(const T &obj)`: Prints the binary representation of an object of type `T`.
- `CalBinary(T &obj)`: Calculates the binary size of an object of type `T`.

### Example

```cpp
#include "bst.cpp"

int main() {
    // Example usage of NoPaddingSize
    size_t size = NoPaddingSize<YourType>();
    std::cout << "Size without padding: " << size << std::endl;

    // Example usage of printBinary
    YourType obj;
    printBinary(obj);

    return 0;
}
```

opimization

[build] Time variable                                   usr           sys          wall           GGC

[build]  phase setup                        :   0.00 (  0%)   0.00 (  0%)   0.00 (  0%)  1912k (  2%)

[build]  phase parsing                      :   0.30 ( 88%)   0.15 ( 94%)   0.45 ( 90%)    67M ( 85%)

[build]  phase lang. deferred               :   0.04 ( 12%)   0.00 (  0%)   0.04 (  8%)  8339k ( 10%)

[build]  phase opt and generate             :   0.00 (  0%)   0.00 (  0%)   0.01 (  2%)  2284k (  3%)

[build]  phase last asm                     :   0.00 (  0%)   0.01 (  6%)   0.00 (  0%)   105k (  0%)

[build]  |name lookup                       :   0.04 ( 12%)   0.02 ( 12%)   0.07 ( 14%)  2050k (  2%)

[build]  |overload resolution               :   0.04 ( 12%)   0.00 (  0%)   0.03 (  6%)  4256k (  5%)

[build]  callgraph construction             :   0.00 (  0%)   0.00 (  0%)   0.01 (  2%)  2052k (  2%)

[build]  preprocessing                      :   0.03 (  9%)   0.04 ( 25%)   0.09 ( 18%)  6306k (  8%)

[build]  parser (global)                    :   0.05 ( 15%)   0.04 ( 25%)   0.06 ( 12%)    26M ( 33%)

[build]  parser struct body                 :   0.04 ( 12%)   0.01 (  6%)   0.02 (  4%) 10165k ( 12%)

[build]  parser enumerator list             :   0.01 (  3%)   0.00 (  0%)   0.00 (  0%)   177k (  0%)

[build]  parser function body               :   0.02 (  6%)   0.02 ( 12%)   0.02 (  4%)  3454k (  4%)

[build]  parser inl. func. body             :   0.10 ( 29%)   0.03 ( 19%)   0.15 ( 30%)  7089k (  9%)

[build]  parser inl. meth. body             :   0.03 (  9%)   0.00 (  0%)   0.04 (  8%)  3816k (  5%)

[build]  template instantiation             :   0.04 ( 12%)   0.00 (  0%)   0.10 ( 20%)    15M ( 19%)

[build]  constant expression evaluation     :   0.01 (  3%)   0.00 (  0%)   0.00 (  0%)   177k (  0%)

[build]  symout                             :   0.01 (  3%)   0.02 ( 12%)   0.01 (  2%)  4281k (  5%)

[build]  TOTAL                              :   0.34          0.16          0.50           80M

---
[build] Time variable                                   usr           sys          wall           GGC
[build]  phase setup                        :   0.00 (  0%)   0.00 (  0%)   0.02 (  4%)  1912k (  2%)
[build]  phase parsing                      :   0.15 ( 52%)   0.11 ( 58%)   0.27 ( 52%)    44M ( 37%)
[build]  phase lang. deferred               :   0.13 ( 45%)   0.06 ( 32%)   0.19 ( 37%)    64M ( 54%)
[build]  phase opt and generate             :   0.01 (  3%)   0.02 ( 11%)   0.04 (  8%)  8681k (  7%)
[build]  |name lookup                       :   0.04 ( 14%)   0.01 (  5%)   0.10 ( 19%)  2214k (  2%)
[build]  |overload resolution               :   0.10 ( 34%)   0.05 ( 26%)   0.15 ( 29%)    56M ( 47%)
[build]  callgraph construction             :   0.01 (  3%)   0.01 (  5%)   0.01 (  2%)  8448k (  7%)
[build]  callgraph optimization             :   0.00 (  0%)   0.00 (  0%)   0.01 (  2%)     0  (  0%)
[build]  callgraph ipa passes               :   0.00 (  0%)   0.00 (  0%)   0.01 (  2%)    14k (  0%)
[build]  ipa inheritance graph              :   0.00 (  0%)   0.00 (  0%)   0.01 (  2%)  1968  (  0%)
[build]  preprocessing                      :   0.03 ( 10%)   0.02 ( 11%)   0.05 ( 10%)  2067k (  2%)
[build]  parser (global)                    :   0.01 (  3%)   0.03 ( 16%)   0.07 ( 13%)    14M ( 12%)
[build]  parser struct body                 :   0.05 ( 17%)   0.02 ( 11%)   0.04 (  8%)  9646k (  8%)
[build]  parser function body               :   0.00 (  0%)   0.00 (  0%)   0.02 (  4%)  1311k (  1%)
[build]  parser inl. func. body             :   0.01 (  3%)   0.01 (  5%)   0.04 (  8%)  2918k (  2%)
[build]  parser inl. meth. body             :   0.00 (  0%)   0.02 ( 11%)   0.02 (  4%)  3222k (  3%)
[build]  template instantiation             :   0.16 ( 55%)   0.05 ( 26%)   0.20 ( 38%)    71M ( 60%)
[build]  constant expression evaluation     :   0.01 (  3%)   0.01 (  5%)   0.02 (  4%)   304k (  0%)
[build]  symout                             :   0.01 (  3%)   0.01 (  5%)   0.00 (  0%)  4477k (  4%)
[build]  initialize rtl                     :   0.00 (  0%)   0.01 (  5%)   0.00 (  0%)    12k (  0%)
[build]  rest of compilation                :   0.00 (  0%)   0.00 (  0%)   0.01 (  2%)    11k (  0%)
[build]  TOTAL                              :   0.29          0.19          0.52          120M