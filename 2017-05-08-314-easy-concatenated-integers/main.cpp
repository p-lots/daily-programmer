#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> tokenize(std::string line)
{
	std::vector<int> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' ')) {
		ret.push_back(std::stoi(temp));
	}
	return ret;
}

int main()
{
	std::string line;
	while (std::getline(std::cin, line)) {
		auto numbers = tokenize(line);
		std::sort(numbers.begin(), numbers.end());
		for (const int &n : numbers) {
			std::cout << n;
		}
		std::cout << ' ';
		std::sort(numbers.rbegin(), numbers.rend());
		for(const int &n : numbers) {
			std::cout << n;
		}
		std::cout << '\n';
	}
	return 0;
}