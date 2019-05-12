#include <cstring>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string text_to_print;
	int width, height;

	if (argc != 4) {
		width = 2;
		height = 2;
		text_to_print = "rektangle";	
	}

	else {
		width = argv[1][0] - '0';
		height = argv[2][0] - '0';
		text_to_print = argv[3];
	}

	for (unsigned i = 0; i < width; ++i) {
		if (i == 0) {
			for (char s : text_to_print) {
				std::cout << (char)toupper(s) << ' ';
			}
		}

		else {
			if (i % 2 == 1) {
				for (auto it = text_to_print.crbegin() + 1;
						it != text_to_print.crend(); ++it) {
					std::cout << (char)toupper(*it) << ' ';
				}
			}

			else {
				for (auto it = text_to_print.begin() + 1; it != text_to_print.end(); ++it) {
					std::cout << (char)toupper(*it) << ' ';
				}
			}
		}
	}

	std::cout << '\n';

	// spaces between the letters:
	// Ex: R E K T A N G L E
	//     E<--this (15)-->L
	// # of spaces = # of letters - 2 (exclude first+last letter) + (# of letters - 1)
	// or, # of spaces = # of letters * 2 - 3
	std::string spaces =
		std::string(text_to_print.length() * 2 - 3, ' ');
	
	for (unsigned i = 0; i < height; ++i) {	
		for (unsigned j = 1; j < text_to_print.length() - 1; ++j) {
			unsigned reverse_index = text_to_print.length() - j - 1;
			if (i % 2 == 1) {
				std::cout << (char)(toupper(text_to_print[reverse_index])) << spaces;
			}

			else {
				std::cout << (char)(toupper(text_to_print[j])) << spaces;
			}

			for (unsigned k = 0; k < width; ++k) {
				if (i % 2 == 1) {
					if (k % 2 == 1) {
						std::cout << (char)(toupper(text_to_print[reverse_index])) << spaces;
					}

					else {
						std::cout << (char)(toupper(text_to_print[j])) << spaces;
					}
				}

				else {
					if (k % 2 == 1) {
						std::cout << (char)(toupper(text_to_print[j])) << spaces;
					}

					else {
						std::cout << (char)(toupper(text_to_print[reverse_index])) << spaces;
					}
				}
			}
			
			std::cout << '\n';
		}

		for (unsigned j = 0; j < width; ++j) {
			if (i % 2 == 1) {
				if (j == 0) {
					for (auto it = text_to_print.cbegin();
							it != text_to_print.cend(); ++it) {
						std::cout << (char)(toupper(*it)) << ' ';
					}
				}

				else {
					if (j % 2 == 1) {
						for (auto it = text_to_print.crbegin() + 1;
								it != text_to_print.crend(); ++it) {
							std::cout << (char)(toupper(*it)) << ' ';
						}
					}

					else {
						for (auto it = text_to_print.cbegin() + 1;
								it != text_to_print.cend(); ++it) {
							std::cout << (char)(toupper(*it)) << ' ';
						}
					}
				}
			}

			else {
				if (j == 0) {
					for (auto it = text_to_print.crbegin();
							it != text_to_print.crend(); ++it) {
						std::cout << (char)(toupper(*it)) << ' ';
					}
				}

				else {
					if (j % 2 == 1) {
						for (auto it = text_to_print.cbegin() + 1;
								it != text_to_print.cend(); ++it) {
							std::cout << (char)(toupper(*it)) << ' ';
						}
					}

					else {
						for (auto it = text_to_print.crbegin() + 1;
								it != text_to_print.crend(); ++it) {
							std::cout << (char)(toupper(*it)) << ' ';
						}
					}
				}
			}
		}
		
		std::cout << '\n';
	}
	
	return 0;
}