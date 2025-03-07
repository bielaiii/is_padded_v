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