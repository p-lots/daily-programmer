#include <cctype>
#include <iostream>
#include <set>
#include <string>

#define NUM_LIVES 3;

int main()
{
	std::string word = "HELLO";
	std::string guessed_letters = std::string(word.length(), '_');
	for (unsigned i = 0; i < guessed_letters.length(); i++) {
		std::cout << guessed_letters[i] << " ";
	}
	std::cout << '\n';
	bool keep_going = true;
	int lives_left = NUM_LIVES;
	std::set<char> guess_set;
	do {
		std::cout << "Lives left: " << lives_left << '\n';
		if (!guess_set.empty()) {
			std::cout << "Guessed letters:\n";
			for (auto ch : guess_set) {
				std::cout << ch << " ";
			}
			std::cout << '\n';
		}
		char guess;
		std::cout << "Guess a letter: ";
		std::cin >> guess;
		while (!std::isalpha(guess)) {
			std::cout << "Error! Guess must be a letter\n";
			std::cout << "Guess a letter: ";
			std::cin >> guess;
		}
		guess = std::toupper(guess);
		while (guess_set.count(guess) > 0) {
			std::cout << "You've already guessed " << guess << ".\n";
			std::cout << "Guess a letter: ";
			std::cin >> guess;
		}
		guess_set.insert(guess);
		auto letter_pos = word.find(guess);
		if (letter_pos == std::string::npos) {
			std::cout << "Missed the guess\n";
			lives_left--;
		}
		else {
			while (letter_pos != std::string::npos) {
				guessed_letters.replace(letter_pos, 1, word.substr(letter_pos, 1));
				letter_pos = word.find(guess, letter_pos + 1);
			}
		}
		std::cout << '\n';
		for (unsigned i = 0; i < guessed_letters.length(); i++) {
			std::cout << guessed_letters[i] << " ";
		}
		std::cout << '\n';
		if (guessed_letters == word) {
			std::cout << "You guessed the word!\n";
			std::cout << "You win!\n";
			keep_going = false;
		}
		else if (lives_left <= 0) {
			std::cout << "No lives left.\n";
			std::cout << "You lose!\n";
			keep_going = false;
		}
	} while (keep_going);
	return 0;
}