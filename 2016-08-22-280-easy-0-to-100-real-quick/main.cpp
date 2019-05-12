#include <iostream>
#include <map>
#include <vector>
#include <string>

std::map<std::string, int> lookup_table_l = {
	{"00000", 0},
	{"00010", 1},
	{"00110", 2},
	{"01110", 3},
	{"11110", 4},
	{"00001", 5},
	{"00011", 6},
	{"00111", 7},
	{"01111", 8},
	{"11111", 9}
};

std::map<std::string, int> lookup_table_r = {
	{"00000", 0},
	{"01000", 1},
	{"01100", 2},
	{"01110", 3},
	{"01111", 4},
	{"10000", 5},
	{"11000", 6},
	{"11100", 7},
	{"11110", 8},
	{"11111", 9}
};

std::vector<std::string> input = {
	"0111011100",
	"1010010000",
	"0011101110",
	"0000110000",
	"1111110001"
};


int main(int argc, char *argv[])
{
	for (auto it = input.begin(); it != input.end(); ++it) {
		std::string tens = it->substr(0, 5), ones = it->substr(5), result;
		if (lookup_table_l.count(tens) == 0 || lookup_table_r.count(ones) == 0) {
			result = "Invalid";
		}
		else {
			result = std::to_string(lookup_table_l[tens] * 10 + lookup_table_r[ones]);
		}
		std::cout << *it << " -> " << result << '\n';
	}
	return 0;
}