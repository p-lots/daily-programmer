#include <iostream>
#include <string>
#include <vector>

static const std::vector<std::string> ones = {
	"oh",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

static const std::vector<std::string> tweens_teens = {
	"ten",
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen"
};

static const std::vector<std::string> tens = {
	"twenty",
	"thirty",
	"forty",
	"fifty"
};

std::string make_words(int n, bool is_hours)
{
	if (n == 0) return is_hours ? "twelve" : "";
	else if (n < 10) return (is_hours ? "" : "oh ") + ones.at(n);
	else if (n < 20) return tweens_teens.at(n % 10);
	else return tens.at(n / 10 - 2) + (n % 10 == 0 ? "" : " " + ones.at(n % 10));
}

int main()
{
	std::string line;
	while (std::getline(std::cin, line)) {
		auto colon_pos = line.find(':');
		int hours = std::stoi(line.substr(0, colon_pos));
		int minutes = std::stoi(line.substr(colon_pos + 1));
		bool past_noon = (hours >= 12 ? true : false);
		hours = (hours >= 12 ? hours == 12 ? 12 : hours % 12 : hours);
		auto hours_str = make_words(hours, true);
		auto mins_str = make_words(minutes, false);
		std::cout << "It's " << hours_str << " " << mins_str;
		if (!mins_str.empty()) std::cout << " ";
		std::cout << (past_noon ? "pm" : "am") << '\n';
	}
	return 0;
}