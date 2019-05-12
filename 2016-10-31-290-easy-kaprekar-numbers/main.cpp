#include <cmath>
#include <iostream>

bool is_kaprekar(int);

int main(int argc, char *argv[])
{
	int start, end;
	std::cin >> start >> end;
	while (start <= end) {
		if (is_kaprekar(start)) {
			std::cout << start << ' ';
		}
		start++;
	}
	std::cout << '\n';
	return 0;
}

bool is_kaprekar(int n)
{
	int square = std::pow(n, 2);
	bool ret = false;
	int power_of_10 = std::pow(10, static_cast<int>(std::log10(square)));
	while (power_of_10 > 0) {
		int first_part = square / power_of_10;
		int second_part = square % power_of_10;
		if (second_part > 0) {
			ret = ((first_part + second_part) == n);
		}
		if (ret) {
			break;
		}
		power_of_10 /= 10;
	}
	return ret;
}