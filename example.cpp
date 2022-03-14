#include <stdio.h>
#include "glit.h"

int main() {
	auto test = "0x3 0x44 44 0x123 1 12-123'1234  12345 (33) 123456"_hex;
	for (const auto &byte : test) {
		printf("%02X ", byte);
	}
	printf("\n");
	return 0;
}