#include <iostream>

int main() {
	long long fib[61];
	fib[0] = 0;
	fib[1] = 1;

	for(int i = 2; i <= 60; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}

	int t;
	std::cin >> t;

	for(int j = 0; j < t; j++){
		int n;
		std::cin >> n;

		std::cout << "Fib(" << n << ") = " << fib[n] << std::endl;
	}
	return 0;		
}
