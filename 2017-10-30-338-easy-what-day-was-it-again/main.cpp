#include <iostream>
#include <vector>

static const std::vector<std::string> weekdays = { "Saturday", "Sunday", "Monday",
	"Tuesday", "Wednesday", "Thursday", "Friday" };

int main()
{
	int year, month, day;
	while (std::cin >> year >> month >> day) {
		if (month < 3) {
			month += 12;
			year--;
		}
		int k = year % 100, j = year / 100;
		int result = (day + (13 * (month + 1) / 5) + k + (k / 4) + (j / 4) + (5 * j)) % 7;
		std::cout << weekdays.at(result) << '\n';
	}
	return 0;
}