#include <iostream>
#include <string>

int main() {
	int N;
	std::cin >> N;


	for(int i = 0; i < N; i++) {
		int L;
		std::cin >> L;

		int hash_total = 0;

		for(int j = 0; j < L; j++) {
			std::string s;
			std::cin >> s;

			for(int k = 0; k < s.length(); k++) {
			
			hash_total += (s[k] - 'A') + j + k;
			
			}
		}
		std::cout << hash_total << std::endl;
	}
	return 0;
}
