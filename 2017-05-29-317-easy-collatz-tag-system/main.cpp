#include <iostream>
#include <map>
#include <string>
#include <vector>

std::map<char, std::string> production_rules = {
	{ 'a', "bc" },
	{ 'b', "a" },
	{ 'c', "aaa" }
};

std::string produce_next(std::string input)
{
	if (input.length() < 2) return input;
	char first = input.front();
	input = input.substr(2);
	input += production_rules.at(first);
	std::cout << input << '\n';
	return produce_next(input);
}

int main()
{
	std::vector<std::string> input = { "aaa", "aaaaaaa" };
	for (std::string str : input) {
		std::cout << str << '\n';
		produce_next(str);
	}
	return 0;
}