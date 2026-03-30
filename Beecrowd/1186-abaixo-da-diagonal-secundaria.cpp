#include <iostream>
#include <iomanip>
#include <string>

int main() {
	double soma = 0.0;
	int contador = 0;
	double M[12][12];

	char t;
	std::cin >> t;

	for(int i = 0; i < 12; i++) {
		for(int j = 0; j < 12; j++) {
			std::cin >> M[i][j];

			if(i + j > 11) {
				soma += M[i][j];
				contador++;
			}
		}
	}
	if(t == 'S') {
		std::cout << std::fixed << std::setprecision(1) << soma << std::endl;
	} else if(t == 'M') {
		std::cout << std::fixed << std::setprecision(1) << (soma/contador) << std::endl;
	}


	return 0;
}
