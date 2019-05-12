#include <iostream>
#include <iterator>
#include <string>

char largest_digit(std::string);

std::string desc_digits(std::string);

int kaprekar(int);

bool kaprekar_check(int);

int main(int argc, char *argv[])
{
	int first = kaprekar(6589);
	int second = kaprekar(5455);
	int third = kaprekar(6174);
	std::cout << "kaprekar(6589) -> " << first << '\n';
	std::cout << "kaprekar(5455) -> " << second << '\n';
	std::cout << "kaprekar(6174) -> " << third << '\n';
	return 0;
}

char largest_digit(std::string input)
{
	int max = 0, curr_n;
	for (char c : input) {
		curr_n = c - '0';
		if (curr_n > max) {
			max = curr_n;
		}
	}
	return max + '0';
}

std::string desc_digits(std::string input)
{
	std::string ret, n = input;
	while (n.length() < 4) {
		n = '0' + n;
	}
	while (!n.empty()) {
		char largest = largest_digit(n);
		ret.push_back(largest);
		n = n.erase(n.find(largest), 1);
	}
	return ret;
}

int kaprekar(int n)
{
	int ret = 0;
	if (!kaprekar_check(n)) {
		return 0;
	}
	while (n != 6174) {
		std::string forward = desc_digits(std::to_string(n)), reverse;
		std::copy(forward.rbegin(), forward.rend(), std::back_inserter(reverse));
		int for_int = std::stoi(forward), rev_int = std::stoi(reverse);
		n = for_int - rev_int;
		ret++;
	}
	return ret;
}

bool kaprekar_check(int n)
{
	if (n == 6174) {
		return false;
	}
	std::string n_str = std::to_string(n);
	char first = n_str[0];
	int unique_count = 1;
	for (unsigned i = 1; i < n_str.length(); i++) {
		char second = n_str[i];
		if (first != second) {
			unique_count++;
		}
	}
	return unique_count > 1;
}