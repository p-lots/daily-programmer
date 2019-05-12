#include <iostream>
#include <stdexcept>
#include <string>

int parse_line(std::string);

bool will_explode(int, int);

int main(int argc, char *argv[])
{
	std::string line;
	std::getline(std::cin, line);
	int prev_line = parse_line(line), current_line;

	while (std::getline(std::cin, line)) {
		current_line = parse_line(line);

		if (will_explode(prev_line, current_line)) {
			std::cout << "Boom\n";
			return 1;
		}

		prev_line = current_line;
	}

	std::cout << "Bomb defused\n";
	return 0;
}

bool will_explode(int prev, int curr)
{
	switch (prev) {
		case 1:
		return curr == 1 || curr == 3;
		break;
		case 2:
		return curr != 5;
		break;
		case 3:
		return (curr == 1 || curr == 4) || curr == 5;
		break;
		case 4:
		return curr != 2 && curr != 3;
		break;
		case 5:
		return curr != 1 && curr != 4;
		break;
		case 6:
		return (curr == 1 || curr == 4) || (curr == 5 || curr == 6);
		break;
		default:
		throw std::domain_error("Invalid wire color encountered");
	}

	return false;
}

int parse_line(std::string line)
{
	if (line == "white") {
		return 1;
	}
	else if (line == "red") {
		return 2;
	}
	else if (line == "black") {
		return 3;
	}
	else if (line == "orange") {
		return 4;
	}
	else if (line == "green") {
		return 5;
	}
	else if (line == "purple") {
		return 6;
	}

	throw std::domain_error("Invalid wire color encountered");
}