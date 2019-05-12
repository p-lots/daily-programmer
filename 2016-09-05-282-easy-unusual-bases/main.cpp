#include <sstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

int fib(int n)
{
	if (n == 2) {
		return 1;
	}

	else if (n == 1) {
		return 1;
	}

	return fib(n - 2) + fib(n - 1);
}

int fib2dec(std::string fibo)
{
	int sum = 0, place = fibo.length(), fib_of_place, p;

	for (auto i = 0; i < fibo.length(); ++i) {
		fib_of_place = fib(place--);
		p = fibo[i] - '0';
		sum += p * fib_of_place;
	}

	return sum;
}

std::string dec2fib(int n)
{
	int place_value, fib_incr = 1;
	std::vector<int> places;
	std::string ret = "";

	while ((place_value = fib(fib_incr++)) < n) {
		places.insert(places.begin(), place_value);
	}

	for (auto i : places) {
		if (n >= i) {
			ret.push_back('1');
			n -= i;
		}
		else {
			ret.push_back('0');
		}
	}

	return ret;
}

static const std::string input = 
	"10 16\n"
	"10 32\n"
	"10 9024720\n"
	"F 10\n"
	"F 1\n"
	"F 111111\n"
	"F 100000\n"
	"F 10110110100111001\n";

static const std::string expected_output_string =
	"1001000\n"
	"10101000\n"
	"1010100101010100000010001000010010\n"
	"1\n"
	"1\n"
	"20\n"
	"8\n"
	"2868\n"; 

int main(int argc, char *argv[])
{
	std::stringstream input_ss(input), actual_output_ss;
	std::string temp;

	while (getline(input_ss, temp)) {
		auto space = temp.find(' ');
		std::string conversion_specifier = temp.substr(0, space),
			number_to_convert = temp.substr(space + 1);
		if (conversion_specifier == "10") {
			std::string result = dec2fib(std::stoi(number_to_convert));
			actual_output_ss << result << '\n';
		}

		else if (conversion_specifier == "F") {
			int result = fib2dec(number_to_convert);
			actual_output_ss << result << '\n';
		}

		else {
			throw std::domain_error("Invalid conversion specified");
		}
	}

	int i = 1;

	std::stringstream expected_output_ss(expected_output_string);

	while (getline(actual_output_ss, temp)) {
		std::string temp2;
		getline(expected_output_ss, temp2);
		
		std::cout << "Input " << i++ << ": " <<
			(temp == temp2 ? "Correct\n" : "Incorrect\n");
	}

	return 0;
}
/*
std::string dec2fib2(int n) {
	std::string ret = "";
	int curr_fib = 1, fib_incr = 1;
	while (n > 0) {
		//
	}
	return ret;
}
*/