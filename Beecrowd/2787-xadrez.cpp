#include <iostream>

int main() {
	int L,C;
	std::cin >> L >> C;

	if((1 <= L and L <= 1000) and (1 <= C and C <= 1000)) {

		if((L%2 == 0 and C%2 == 0) or (L%2 == 1 and C%2 == 1)) {
			std::cout << '1' << std::endl;
		} else if((L%2 == 1 and C%2 == 0) or (L%2 == 0 and C%2 == 1)) {
			std::cout << '0' << std::endl;
		}
	}
	else {
	std::cout << "Valores invalidos!" << std::endl;
	return 0;

	}
}
