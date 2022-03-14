# Glit
Simple c++ literal to convert hex string to binary blob
```c++
auto data = "43 9F 2E 00 00 19 AC"_hex;
```
By default returning type is `std::vector<uint8_t>`

Tested only at MSVC 2022 at c++20
