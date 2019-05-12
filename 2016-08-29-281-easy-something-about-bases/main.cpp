#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static const std::vector<std::string> input = { "1",
	"21",
	"ab3",
	"ff" };

int get_base(std::string input)
{
	int ret = 0;
	for (char c : input) {
		if (isdigit(c)) {
			ret = std::max(ret, c - '0');
		}
		else if (isalpha(c)) {
			ret = std::max(ret, c - 'a' + 10);
		}
	}
	return ret + 1;
}

int base2dec(std::string n, int base)
{
	int ret = 0, power = n.length() - 1;
	for (char c : n) {
		if (isalpha(c)) {
			ret += pow(base, power--) * (c - 'a' + 10);
		}
		else if (isdigit(c)) {
			ret += pow(base, power--) * (c - '0');
		}
	}
	return ret;
}

int main(int argc, char *argv[])
{
	for (auto it = input.begin(); it != input.end(); ++it) {
		std::cout << "base " << get_base(*it) << " => " << base2dec(*it, get_base(*it)) << '\n';
	}
	return 0;
}