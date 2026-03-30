#include <iostream>
#include <iomanip>

int main() {
	char operacao;
	double M[12][12];
	double soma = 0.0;
	int contador = 0;

	std::cin >> operacao;

	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 12; j++){
			std::cin >> M[i][j];

			if(j > i && (i + j) < 11) {
				soma += M[i][j];
				contador++;
			}
		}
	}
	std::cout << std::fixed << std::setprecision(1);

	if(operacao == 'S') {
		std::cout << soma << std::endl;
	} else {
		std::cout << soma / contador << std::endl;
	}
	return 0;
}
