#include <iostream>
#include <numeric>
#include <string>
#include <vector>

std::vector<std::string> dec_to_fac(unsigned long long n)
{
	//std::cout << "dec_to_fac\n";
	unsigned long long divisor = 1, rem;
	std::vector<unsigned long long> vec;
	while (n != 0) {
		rem = n % divisor;
		n /= divisor;
		divisor += 1;
		vec.push_back(rem);
	//	std::cout << "Pushed back " << rem << '\n';
	}
	std::vector<std::string> ret;
	for (auto it = vec.rbegin(); it != vec.rend(); it++) {
		ret.push_back(std::to_string(*it));
	}
	return ret;
}

std::vector<int> make_permutation(std::vector<int> input, std::vector<std::string> fac)
{
	std::vector<int> ret;
	for (std::string s : fac) {
		int n = std::stoi(s);
		ret.push_back(input.at(n));
		input.erase(input.begin() + n);
	}
	return ret;
}

int main(int argc, char *argv[])
{
	auto vec = dec_to_fac(12345678901234);
	for (auto n : vec) {
		std::cout << n << '\n';
	}
	//std::vector<int> vec1(42);
	//std::iota(vec1.begin(), vec1.end(), 0);
	// 12345678901234 - 1
	//auto result1 = make_permutation(vec1, dec_to_fac(12345678901233));
	//for (int n : result1) {
	//	std::cout << n << ' ';
	//}
	//std::cout << '\n';
	return 0;
}