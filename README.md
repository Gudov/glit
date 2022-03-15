# Glit
Simple c++ literal to convert hex string to binary blob
```c++
auto data = "43 9F 2E 00 00 19 AC"_hex;
```
By default returning type is `std::vector<uint8_t>`

Tested only at MSVC 2022 at c++20


Example of valid input string
```c++
auto test = "0x3 0x44 44 0x123 1 12-123'1234  12345 (33) 123456"_hex;
```
Translates to `03 44 44 01 23 01 12 01 23 12 34 01 23 45 33 12 34 56`
