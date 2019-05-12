#include <iostream>

bool is_prime(long long n)
{
	for (long long i = 2; i < std::sqrt(n); i++) {
		if (n % i == 0) return true;
	}
	return false;
}

int main()
{
	
	return 0;
}
