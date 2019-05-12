#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string line;
	const std::string digits = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (std::getline(std::cin, line)) {
		unsigned long long n = std::stoull(line);
		std::string result = "";
		while (n > 0) {
			auto offset = n % static_cast<unsigned long long>(digits.length());
			std::cout << "Offset: " << offset << '\n';
			result = digits.at(offset) + result;
			n /= 62ULL;
		}
		std::cout << result << '\n';
	}
	return 0;
}