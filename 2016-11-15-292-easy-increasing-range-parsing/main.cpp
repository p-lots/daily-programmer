#include <cmath>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<int> make_range(std::string);

void make_dash_range(std::vector<int> &, std::string, std::string);

void make_colon_range(std::vector<int> &, std::vector<int> &);

int main(int argc, char *argv[])
{
	std::string line;
	while (std::cin >> line) {
		// Remove the first quotation mark, so we know when we encounter one,
		// it's the end of the line
		line = line.substr(1, line.length() - 1);

		auto range = make_range(line);

		if (!range.empty()) {
			for (auto it = range.begin(); it != range.end(); it++) {
				if (it == range.begin()) {
					std::cout << "\"" << *it;
				}
				else if (it == range.end() - 1) {
					std::cout << ' ' << *it << "\"\n";
				}
				else {
					std::cout << ' ' << *it;
				}
			}
		}
	}
	return 0;
}

std::vector<int> make_range(std::string line)
{
	std::vector<int> ret, dash_range, colon_numbers;
	std::string number, start_dash_range, end_dash_range;
	int current_number, previous_number, modifier = 0;
	bool next_make_end_number = false, first_time = true, found_period = false;

	for (char c : line) {
		switch (c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': {
				number.push_back(c);
			}
			break;
			case '-': {
				start_dash_range = number;
				next_make_end_number = true;
				number.clear();
			}
			break;
			case ':': {
				colon_numbers.push_back(std::stoi(number));
				number.clear();
			}
			break;
			case '.': {
				found_period = true;
			}
			break;
			case ',': {
				current_number = std::stoi(number);
				if (first_time) {
					first_time = false;
				}
				else if (current_number < previous_number
					&& !next_make_end_number) { /*
					if (previous_number > 9) {
						modifier = std::pow(10,
							static_cast<int>(std::log10(previous_number)));
					} */
					modifier += 10;
				}
				if (next_make_end_number) {
					end_dash_range = number;
					make_dash_range(dash_range, start_dash_range,
						end_dash_range);
					ret.insert(ret.end(), dash_range.begin(),
						dash_range.end());
					next_make_end_number = false;
					number.clear();
					break;
				}
				ret.push_back(current_number + modifier);
				number.clear();
			}
			break;
			case '"': {
				if (colon_numbers.size() > 1) {
					colon_numbers.push_back(std::stoi(number));
					make_colon_range(ret, colon_numbers);
				}
				else if (next_make_end_number) {
					end_dash_range = number;
					if (!ret.empty()) {
						if (std::stoi(start_dash_range) < ret.back()) {
							start_dash_range = '1' + start_dash_range;
						}
						make_dash_range(dash_range, start_dash_range,
							end_dash_range);
						ret.insert(ret.end(), dash_range.begin(),
							dash_range.end());
					}
					else {
						if (std::stoi(end_dash_range)
							< std::stoi(start_dash_range)
							&& end_dash_range.length() == 1) {
							end_dash_range = "11" + end_dash_range;
						}
						for (int i = std::stoi(start_dash_range);
							i <= std::stoi(end_dash_range); i++) {
							dash_range.push_back(i);
						}
						ret.insert(ret.end(), dash_range.begin(),
							dash_range.end());
					}
				}
				else {
					current_number = std::stoi(number);
					if (current_number < previous_number) {
						modifier += 10;
					}
					ret.push_back(current_number + modifier);
				}
			}
			break;
			default:
			throw std::domain_error("Invalid token encountered");
			break;
		}
		previous_number = current_number;
	}

	return ret;
}

void make_dash_range(std::vector<int> &range, std::string start,
	std::string end)
{
	int start_number = std::stoi(start), end_number = std::stoi(end);
	range = std::vector<int>(end_number);
	std::iota(range.begin(), range.end(), start_number);
}

void make_colon_range(std::vector<int> &ret, std::vector<int> &colon_numbers)
{
	if (colon_numbers.size() > 2) {
		for (int i = colon_numbers.front(); i <= colon_numbers.at(1);
			i += colon_numbers.back()) {
			ret.push_back(i);
		}
	}
	else {
		int start = colon_numbers.front(), end = colon_numbers.back();
		colon_numbers.clear();
		if (start < end) {
			colon_numbers = std::vector<int>(end);
			std::iota(colon_numbers.begin(), colon_numbers.end(), start);
			ret.insert(ret.end(), colon_numbers.begin(), colon_numbers.end());
		}
	}
}