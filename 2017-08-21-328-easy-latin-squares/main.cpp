#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::vector<int> > tokenize(std::string line)
{
	std::vector<int> row;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' ')) {
		row.push_back(std::stoi(temp));
	}
	int n = std::sqrt(row.size());
	int it = 0;
	std::vector<std::vector<int> > ret;
	for (int i = 0; i < n; i++) {
		std::vector<int> temp_row(n, 0);
		for (int j = 0; j < n; j++) {
			temp_row[j] = row.at(it);
			it++;
		}
		ret.push_back(temp_row);
	}
	return ret;
}

int main()
{
	std::string line;
	while (std::getline(std::cin, line)) {
		int n;
		std::vector<std::vector<int> > grid;
		if (line.length() == 1) {
			n = std::stoi(line);
			continue;
		}
		else {
			grid = tokenize(line);
		}
		std::vector<bool> has_n_arr(n, false);
		bool has_all = true;
		// check rows
		for (unsigned i = 0; i < n; i++) {
			for (unsigned j = 0; j < n; j++) {
				int num_at = grid[i][j];
				has_n_arr[num_at - 1] = true;
			}
			for (unsigned j = 0; j < n; j++) {
				has_all = has_n_arr[j];
				if (!has_all) break;
			}
			if (!has_all) break;
		}
		if (!has_all) {
			std::cout << (has_all ? "true" : "false") << '\n';
			continue;
		}
		// check columns
		has_n_arr = std::vector<bool>(n, false);
		for (unsigned i = 0; i < n; i++) {
			for (unsigned j = 0; j < n; j++) {
				int num_at = grid[j][i];
				has_n_arr[num_at - 1] = true;
			}
			for (unsigned j = 0; j < n; j++) {
				has_all = has_n_arr[j];
				if (!has_all) break;
			}
			if (!has_all) break;
		}
		std::cout << (has_all ? "true" : "false") << '\n';
	}
	return 0;
}