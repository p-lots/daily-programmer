#include <iostream>
#include <map>
#include <string>

#define PI 3.141592653589793

void parse_line(const std::string, double &, int &, int &);

static const std::map<char, int> lookup_table = {
	{ 'r', 0 },
	{ 'd', 1 },
	{ 'c', 2 },
	{ 'f', 3 },
	{ 'k', 4 }
};

int main(int argc, char *argv[])
{
	std::string line;
	while (std::cin >> line) {
		double units;
		int from = -1, to = -1;
		parse_line(line, units, from, to);
		if (from == -1 || to == -1) {
			std::cout << "No candidate for conversion.\n";
			continue;
		}
		double result;
		if (from == 0 && to == 1) {
			result = units * (static_cast<double>(180) / PI);
		}
		else if (from == 1 && to == 0) {
			result = units * (PI / static_cast<double>(180));
		}
		else if (from == 2 && to == 3) {
			result = units * (static_cast<double>(9) / static_cast<double>(5)) + 32;
		}
		else if (from == 3 && to == 2) {
			result = (units - static_cast<double>(32))
				* (static_cast<double>(5) / static_cast<double>(9));
		}
		else if (from == 2 && to == 4) {
			result = units + 273.15;
		}
		else if (from == 3 && to == 4) {
			result = (units + 459.67)
				* (static_cast<double>(5) / static_cast<double>(9));
		}
		else if (from == 4 && to == 2) {
			result = units - 273.15;
		}
		else if (from == 4 && to == 3) {
			result = units * (static_cast<double>(9) / static_cast<double>(5))
				- 459.67;
		}
		std::cout << result << line.back() << '\n';
	}
}

void parse_line(const std::string line, double &units, int &from, int &to)
{
	auto conv_str = line.substr(line.find_first_of("drcfk"));
	char from_char = conv_str.at(0), to_char = conv_str.at(1);
	if ((from_char == 'r' && to_char != 'd')
		|| (from_char == 'd' && to_char != 'r')) {
		from = -1;
		to = -1;
		return;
	}
	else if (((from_char == 'c' && (to_char != 'f' && to_char != 'k'))
		|| (from_char == 'f' && (to_char != 'c' && to_char != 'k')))
		|| (from_char == 'k' && (to_char != 'f' && to_char != 'c'))) {
		from = -1;
		to = -1;
		return;
	}

	units = std::stod(line.substr(0, line.find_first_of("drcfk")));

	from = lookup_table.at(from_char);
	to = lookup_table.at(to_char);
}