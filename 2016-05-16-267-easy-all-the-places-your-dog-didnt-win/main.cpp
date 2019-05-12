#include <iostream>
#include <string>
#include <vector>

void other_places(int);

int main(int argc, char *argv[])
{
	int place;
	if (argc < 2) {
		place = 1;
	}
	else if (argc > 2) {
		std::cerr << "Too many arguments.";
		return 1;
	}
	else {
		place = std::atoi(argv[1]);
	}
	
	other_places(place);

	return 0;
}

void other_places(int place)
{
	static const std::vector<std::string> suffix = { "st", "nd", "rd" };
	for (int i = 1; i <= 100; i++) {
		if (i == place) {
			continue;
		}

		int mod = i % 10;
		std::cout << std::to_string(i);

		// if 1 ≤ mod ≤ 3 and !(11 ≤ i ≤ 13)
		//     output number + suffix
		if ((mod >= 1 && mod <= 3) && !(i >= 11 && i <= 13)) {
			std::cout << suffix.at(mod - 1);
		}
		else {
			std::cout << "th";
		}

		if (i == 100) {
			std::cout << '\n';
		}
		else {
			std::cout << ", ";
		}
	}
}