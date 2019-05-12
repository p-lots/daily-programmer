#include <iostream>
#include <map>
#include <string>
#include <utility>

#define NUM_TYPES 18

std::map<std::string, int> type_to_num = {
	{"normal", 0},
	{"fire", 1},
	{"water", 2},
	{"electric", 3},
	{"grass", 4},
	{"ice", 5},
	{"fighting", 6},
	{"poison", 7},
	{"ground", 8},
	{"flying", 9},
	{"psychic", 10},
	{"bug", 11},
	{"rock", 12},
	{"ghost", 13},
	{"dragon", 14},
	{"dark", 15},
	{"steel", 16},
	{"fairy", 17}
};

double type_matrix[NUM_TYPES][NUM_TYPES] = {
// defending ->  normal   fire     water    electric grass    ice      fighting poison   ground   flying   psychic  bug      rock     ghost    dragon   dark     steel    fairy    
// attacking v
/* normal   */ { 1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     0.5,     0.0,     1.0,     1.0,     0.5,     1.0 },
/* fire     */ { 1.0,     0.5,     0.5,     1.0,     2.0,     2.0,     1.0,     1.0,     1.0,     1.0,     1.0,     2.0,     0.5,     1.0,     0.5,     1.0,     2.0,     1.0 },
/* water    */ { 1.0,     2.0,     0.5,     1.0,     0.5,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     2.0,     1.0,     0.5,     1.0,     1.0,     1.0 },
/* electric */ { 1.0,     1.0,     2.0,     0.5,     0.5,     1.0,     1.0,     1.0,     0.0,     2.0,     1.0,     1.0,     1.0,     1.0,     0.5,     1.0,     1.0,     1.0 },
/* grass    */ { 1.0,     0.5,     2.0,     1.0,     0.5,     1.0,     1.0,     0.5,     2.0,     0.5,     1.0,     0.5,     2.0,     1.0,     0.5,     1.0,     0.5,     1.0 },
/* ice      */ { 1.0,     0.5,     0.5,     1.0,     2.0,     0.5,     1.0,     1.0,     2.0,     2.0,     1.0,     1.0,     1.0,     1.0,     2.0,     1.0,     0.5,     1.0 },
/* fighting */ { 2.0,     1.0,     1.0,     1.0,     1.0,     2.0,     1.0,     0.5,     1.0,     0.5,     0.5,     0.5,     2.0,     0.0,     1.0,     2.0,     2.0,     0.5 },
/* poison   */ { 1.0,     1.0,     1.0,     1.0,     2.0,     1.0,     1.0,     0.5,     1.0,     1.0,     1.0,     1.0,     0.5,     0.5,     1.0,     1.0,     0.0,     2.0 },
/* ground   */ { 1.0,     2.0,     1.0,     2.0,     0.5,     1.0,     1.0,     2.0,     1.0,     0.0,     1.0,     0.5,     2.0,     1.0,     1.0,     1.0,     2.0,     1.0 },
/* flying   */ { 1.0,     1.0,     1.0,     0.5,     2.0,     1.0,     2.0,     1.0,     1.0,     1.0,     1.0,     2.0,     0.5,     1.0,     1.0,     1.0,     0.5,     1.0 },
/* psychic  */ { 1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     2.0,     2.0,     1.0,     1.0,     0.5,     1.0,     1.0,     1.0,     1.0,     0.0,     0.5,     1.0 },
/* bug      */ { 1.0,     0.5,     1.0,     1.0,     2.0,     1.0,     0.5,     0.5,     1.0,     0.5,     2.0,     1.0,     1.0,     0.5,     1.0,     1.0,     0.5,     1.0 },
/* rock     */ { 1.0,     2.0,     1.0,     1.0,     1.0,     2.0,     0.5,     1.0,     0.5,     2.0,     1.0,     2.0,     2.0,     1.0,     1.0,     1.0,     0.5,     1.0 },
/* ghost    */ { 0.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     2.0,     1.0,     1.0,     2.0,     1.0,     1.0,     1.0,     1.0 },
/* dragon   */ { 1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     2.0,     1.0,     0.5,     1.0 },
/* dark     */ { 1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     0.5,     1.0,     1.0,     1.0,     2.0,     1.0,     1.0,     1.0,     1.0,     0.5,     1.0,     0.5 },
/* steel    */ { 1.0,     0.5,     0.5,     0.5,     1.0,     2.0,     1.0,     1.0,     1.0,     1.0,     1.0,     1.0,     2.0,     1.0,     1.0,     1.0,     0.5,     2.0 },
/* fairy    */ { 1.0,     0.5,     1.0,     1.0,     1.0,     1.0,     1.0,     2.0,     0.5,     1.0,     1.0,     1.0,     1.0,     1.0,     2.0,     2.0,     0.5,     1.0 }
};

int main(int argc, char *argv[])
{
	std::string line;
	while (std::getline(std::cin, line)) {
		std::string delim = " -> ";
		auto delim_start = line.find(delim);
		auto delim_end = delim_start + delim.length();
		std::string attacking_type = line.substr(0, delim_start);
		std::string defending_types = line.substr(delim_end);
		auto defending_space_pos = defending_types.find(" ");
		if (defending_space_pos != std::string::npos) {
			std::pair<std::string, std::string> the_multiple_types;
			the_multiple_types.first = defending_types.substr(0, defending_space_pos);
			the_multiple_types.second = defending_types.substr(defending_space_pos + 1);
			int attacking_code = type_to_num.at(attacking_type);
			int defending_code_first = type_to_num.at(the_multiple_types.first);
			int defending_code_second = type_to_num.at(the_multiple_types.second);
			double result = type_matrix[attacking_code][defending_code_first] * type_matrix[attacking_code][defending_code_second];
			std::cout << result << "x\n";
			continue;
		}
		int attacking_code = type_to_num.at(attacking_type);
		int defending_code = type_to_num.at(defending_types);
		double result = type_matrix[attacking_code][defending_code];
		std::cout << result << "x\n";
	}
	return 0;
}

