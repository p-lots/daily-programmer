#include <iostream>
#include <string>

bool scrabble(std::string rack, std::string word)
{
	if (rack.length() < word.length()) return false;
	auto word_copy = word;
	auto rack_copy = rack;
	for (const char &c : word) {
		auto rack_pos = rack_copy.find(c);
		if (rack_pos == std::string::npos) {
			auto q_pos = rack_copy.find('?');
			if (q_pos == std::string::npos) return false;
			rack_copy.erase(q_pos, 1);
			auto word_pos = word_copy.find(c);
			word_copy.erase(word_pos, 1);
		}
		else {
			rack_copy.erase(rack_pos, 1);
			auto word_pos = word_copy.find(c);
			word_copy.erase(word_pos, 1);
		}
	}
	return word_copy.empty();
}

int main()
{
	std::cout << (scrabble("ladilmy", "daily") ? "True\n" : "False\n");
	std::cout << (scrabble("eerriin", "eerie") ? "True\n" : "False\n");
	std::cout << (scrabble("orrpgma", "program") ? "True\n" : "False\n");
	std::cout << (scrabble("orppgma", "program") ? "True\n" : "False\n");

	std::cout << (scrabble("pizza??", "pizzazz") ? "True\n" : "False\n");
	std::cout << (scrabble("piizza?", "pizzazz") ? "True\n" : "False\n");
	std::cout << (scrabble("a??????", "program") ? "True\n" : "False\n");
	std::cout << (scrabble("b??????", "program") ? "True\n" : "False\n");
	return 0;
}