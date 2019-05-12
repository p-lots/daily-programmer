#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> tokenize(std::string line)
{
	std::vector<int> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' '))
		ret.push_back(std::stoi(temp));
	return ret;
}

int main()
{
	std::string line;
	while (std::getline(std::cin, line)) {
		auto numbers = tokenize(line);
		std::set<std::vector<int> > results;
		std::sort(numbers.begin(), numbers.end());
		for (unsigned i = 0; i < numbers.size() - 3; i++) {
			int a = numbers[i], start = i + 1, end = numbers.size() - 1;
			while (start < end) {
				int b = numbers[start], c = numbers[end];
				if (a + b + c == 0) {
					std::vector<int> temp = { a, b, c };
					if (results.count(temp) == 0) {
						std::cout << "Found " << a << ' ' << b << ' ' << c << '\n';
						results.insert(temp);
					}
					end--;
				}
				else if (a + b + c > 0) end--;
				else start++;
			}
		}
		std::cout << '\n';
	}
	return 0;
}