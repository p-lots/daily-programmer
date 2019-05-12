#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> tokenize(const std::string &line)
{
	std::vector<std::string> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' '))
		ret.push_back(temp);
	return ret;
}

int main()
{
	std::vector<std::string> input = {
		"I heard the pastor sing live verses easily.",
		"Deep episodes of Deep Space Nine came on the television only after the news.",
		"Digital alarm clocks scare area children."
	};
	for (const auto &str : input) {
		auto tokens = tokenize(str);
		std::string result = "";
		for (unsigned i = 1; i < tokens.size(); i++) {
			int letter_count = 1;
			int highest_valid_letter_count = 0;
			auto prev = tokens[i - 1];
			auto curr = tokens[i];
			while (letter_count < prev.length() && letter_count < curr.length()) {
				if (prev.substr(prev.length() - letter_count) == curr.substr(0, letter_count))
					highest_valid_letter_count = letter_count;
				letter_count++;
			}
			if (highest_valid_letter_count > 0 && i == tokens.size() - 1)
				result += prev.substr(0, prev.length() - highest_valid_letter_count) + " " + curr.substr(highest_valid_letter_count);
			else if (i == tokens.size() - 1)
				result += prev + " " + curr;
			else if (highest_valid_letter_count > 0)
				result += prev.substr(0, prev.length() - highest_valid_letter_count);
			else
				result += prev + " ";
		}
		std::cout << result << '\n';
	}
	return 0;
}
