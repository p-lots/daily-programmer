#include <iostream>
#include <numeric>
#include <string>
#include <vector>

std::string dec_to_fac(int n)
{
	int divisor = 1, rem;
	std::vector<int> vec;
	while (n != 0) {
		rem = n % divisor;
		n /= divisor++;
		vec.push_back(rem);
	}
	std::string ret;
	for (auto it = vec.rbegin(); it != vec.rend(); it++) {
		ret += std::to_string(*it);
	}
	return ret;
}

std::vector<int> make_permutation(std::vector<int> input, std::string fac)
{
	std::vector<int> ret;
	for (char c : fac) {
		int n = c - '0';
		ret.push_back(input.at(n));
		input.erase(input.begin() + n);
	}
	return ret;
}

int main(int argc, char *argv[])
{
	std::vector<int> vec1(6);
	std::iota(vec1.begin(), vec1.end(), 0);
	auto result1 = make_permutation(vec1, dec_to_fac(239)); // 240 - 1
	for (int n : result1) {
		std::cout << n << ' ';
	}
	std::cout << '\n';
	auto vec2 = std::vector<int>(7);
	std::iota(vec2.begin(), vec2.end(), 0);
	auto result2 = make_permutation(vec2, dec_to_fac(3239)); // 3240 - 1
	for (int n : result2) {
		std::cout << n << ' ';
	}
	std::cout << '\n';
	return 0;
}