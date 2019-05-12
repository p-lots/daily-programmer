#include <iostream>

int reverse_factorial(unsigned long long);

int main(int argc, char *argv[])
{
	int result;
	unsigned long long input;
	while (std::cin >> input) {
		result = reverse_factorial(input);
		std::cout << input;
		if (result > 0) {
			std::cout << " = " << result << "!\n";
		}
		else {
			std::cout << "  NONE\n";
		}
	}
	return 0;
}

int reverse_factorial(unsigned long long input)
{
	int i = 2;
	unsigned long long mod;
	bool mod_bool = true;
	while (input > 0) {
		mod = input % i;
		if (mod != 0) {
			mod_bool = false;
		}
		input /= i;
		if (input == 1 && mod_bool) {
			return i;
		}
		i++;
	}
	return input;
}