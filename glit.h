#pragma once
#include <vector>
#include <string>
#include <span>
#include <ranges>
#include <type_traits>
#include <concepts>
#include <numeric>

using std::string;
using std::string_view;
using std::vector;

constexpr vector<uint8_t> operator"" _hex(const char* chars, const size_t len) {
	vector<uint8_t> data;
	string str(chars, len);

	auto isHexChar = [](char ch) -> bool {
		return (ch >= '0' && ch <= '9')
			|| (ch >= 'a' && ch <= 'f')
			|| (ch >= 'A' && ch <= 'F')
			|| ch == 'x';
	};

	auto parseBytes = [](string_view str, vector<uint8_t> &data) {
		auto parseByte = [](string_view str) -> uint8_t {
			return std::stoi(string(str), nullptr, 16);
		};

		if (str.starts_with("0x")) {
			str = str.substr(2);
		}

		if (str.empty()) {
			return;
		}

		if (str.length() % 2 == 1) {
			data.push_back(parseByte(str.substr(0, 1)));
			str = str.substr(1);
		}

		while (!str.empty()) {
			data.push_back(parseByte(str.substr(0, 2)));
			str = str.substr(2);
		}
	};
	
	auto splitTo = [](string_view str, auto filter, auto reciver) {
		auto start = str.begin();
		auto end = str.end();

		for (auto it = str.begin(); it != str.end(); it++) {
			if (start != str.end() && !filter(*it)) {
				reciver({ start, it });

				start = str.end();
			} else if (start == str.end() && filter(*it)) {
				start = it;
			}
		}

		if (start != str.end()) {
			reciver({ start, str.end() });
		}
	};

	splitTo(str, isHexChar, 
		[&](string_view str) {parseBytes(str, data); }
	);

	return data;
}