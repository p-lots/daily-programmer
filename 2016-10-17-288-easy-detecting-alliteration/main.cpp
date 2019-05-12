#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> stop_words = {
	"I",
	"a",
	"about",
	"an",
	"and",
	"are",
	"as",
	"at",
	"be",
	"by",
	"for",
	"from",
	"how",
	"in",
	"is",
	"it",
	"of",
	"on",
	"or",
	"that",
	"the",
	"this",
	"to",
	"was",
	"what",
	"when",
	"where",
	"who",
	"will",
	"with"
};

std::vector<std::string> tokenize(std::string);

void remove_stop_words(std::vector<std::string> &);

std::vector<std::string> get_alliteration(std::vector<std::string>);

int main(int argc, char *argv[])
{
	int total_num_lines, line_counter = 0;
	std::string line;
	std::getline(std::cin, line);
	total_num_lines = std::stoi(line);
	while (line_counter < total_num_lines) {
		std::getline(std::cin, line);
		std::vector<std::string> tokens = tokenize(line);
		//for (std::string word : tokens) {
		//	std::cout << word << ' ';
		//}
		//std::cout << '\n';
		std::vector<std::string> alliteration = get_alliteration(tokens);
		for (std::string word : alliteration) {
			std::cout << word << ' ';
		}
		std::cout << '\n';
		line_counter++;
	}
}

std::vector<std::string> tokenize(std::string line)
{
	std::vector<std::string> ret;
	std::stringstream ss(line);
	std::string temp;
	while (ss >> temp) {
		temp.erase(std::remove_if(temp.begin(), temp.end(),
			[](char c){ return std::ispunct(c); }), temp.end());
		std::transform(temp.begin(), temp.end(), temp.begin(),
			[](char c){ return std::tolower(c); });
		if (std::find(stop_words.begin(), stop_words.end(), temp)
			== stop_words.end()) {
			ret.push_back(temp);
		}
	}
	return ret;
}

std::vector<std::string> get_alliteration(std::vector<std::string> words)
{
	std::vector<std::string> ret;
	bool first_time = true;
	char previous_first_letter = words.front().front(), current_first_letter;
	for (auto it = words.begin() + 1; it != words.end(); it++) {
		current_first_letter = it->front();
		if (current_first_letter == previous_first_letter) {
			if (first_time) {
				ret.push_back(*(it - 1));
				ret.push_back(*it);
				first_time = false;
			}
			else if (std::find(ret.begin(), ret.end(), *(it - 1)) == ret.end()) {
				ret.push_back(*(it - 1));
				if (std::find(ret.begin(), ret.end(), *it) == ret.end()) {
					ret.push_back(*it);
				}
			}
			else if (std::find(ret.begin(), ret.end(), *it) == ret.end()) {
				ret.push_back(*it);
			}
		}
		previous_first_letter = current_first_letter;
	}
	return ret;
}