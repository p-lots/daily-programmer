#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

static const std::string is_ana = " is an anagram of ";
static const std::string is_not_ana = " is NOT an anagram of ";

std::map<char, int> word_to_hmap(std::string input)
{
	std::map<char, int> ret;

	for (auto c : input) {
		if (isalpha(c)) {
			auto temp_c = tolower(c);
			if (!ret[temp_c]) {
				ret[temp_c] = 1;
			}
		
			else {
				ret[temp_c]++;
			}
		}
	}

	return ret;
}

void parse_input(std::string input, std::string &word1, std::string &word2)
{
	auto mid_separator_pos = input.find('?');
	std::string first_half = input.substr(0, mid_separator_pos);
	std::string second_half = input.substr(mid_separator_pos + 1);

	auto first_word_end = first_half.find_last_of('"');
	word1 = first_half.substr(1, first_word_end - 1);

	auto second_word_start = second_half.find('"');
	auto second_word_end = second_half.find_last_not_of('"');
	word2 = second_half.substr(second_word_start + 1, second_word_end - 1);
}

int main(int argc, char *argv[])
{
	std::ifstream input("input.txt");
	std::string temp, word1, word2;
	std::map<char, int> word1hmap, word2hmap;

	while (std::getline(input, temp)) {
		parse_input(temp, word1, word2);
		
		word1hmap = word_to_hmap(word1);
		word2hmap = word_to_hmap(word2);
		
		if (word1hmap == word2hmap) {
			std::string result = "\"" + word1 + "\"" + is_ana + "\"" + word2 + "\"\n";
			std::cout << result;
		}

		else {
			std::string result = "\"" + word1 + "\"" + is_not_ana + "\"" + word2 + "\"\n";
			std::cout << result;
		}
	}

	return 0;
}