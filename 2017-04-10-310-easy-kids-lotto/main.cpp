// https://www.reddit.com/r/dailyprogrammer/comments/64jesw/20170410_challenge_310_easy_kids_lotto/
/*
 *  needs to be re-factored for "The number of kids names the teacher want on each output list"
 */

#include <fstream>
#include <random>
#include <set>
#include <string>
#include <vector>

std::vector<std::string> tokenize(std::string line)
{
	std::stringstream ss(line);
	std::string temp;
	std::vector<std::string> ret;
	while (std::getline(ss, temp, ';')) {
		ret.push_back(temp);
	}
	return ret;
}

int main()
{
	std::ifstream file("input.txt");
	std::string line;
	while (std::getline(file, line)) {
		auto tokens = tokenize(line);
		std::random_device r;
		std::mt19937 m(r());
		std::uniform_int_distribution<int> uid(0, tokens.size() - 1);
		std::set<int> already_chosen_names;
		std::vector<std::vector<std::string>> ret;
		while (already_chosen_names.size() != tokens.size()) {
			int chosen_idx = uid(m);
			while (already_chosen_names.count(chosen_idx) != 0) {
				chosen_idx = uid(m);
			}
			already_chosen_names.insert(chosen_idx);
			std::vector<std::string> ret_insert;
			ret_insert.push_back(tokens.at(chosen_idx));
			std::set<int> already_chosen_idxs;
			while (already_chosen_idxs.size() != tokens.size()) {
				int chosen_idx_2 = uid(m);
				while (already_chosen_idxs.count(chosen_idx_2) != 0) {
					chosen_idx_2 = uid(m);
				}
				already_chosen_idxs.insert(chosen_idx_2);
				ret_insert.push_back(tokens.at(chosen_idx_2));
			}
			ret.push_back(ret_insert);
		}
		for (auto vec : ret) {
			for (auto it = vec.begin(); it != vec.end(); it++) {
				if (it == vec.begin()) {
					std::cout << *it << " > ";
				}
				else {
					std::cout << *it << "; ";
				}
			}
		}
		std::cout << '\n';
	}
	return 0;
}