#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	int minimum_weight, desired_temp;
	std::cin >> minimum_weight >> desired_temp;
	int weight, temp, chair_number = 1;
	std::vector<int> acceptable_places;
	while (std::cin >> weight >> temp) {
		if (weight >= minimum_weight && temp <= desired_temp) {
			acceptable_places.push_back(chair_number);
		}
		chair_number++;
	}
	for (int n : acceptable_places) {
		std::cout << n << ' ';
	}
	std::cout << '\n';
	return 0;
}