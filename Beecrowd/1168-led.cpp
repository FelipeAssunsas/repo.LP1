#include <iostream>
#include <string>

int main() {
	int numero_de_leds;
	std::cin >> numero_de_leds;

	for (int i = 0; i < numero_de_leds; i++) {
		long long soma = 0;
		std::string linhas_numeros;
		std:: cin >> linhas_numeros;

		for (int j = 0; j < linhas_numeros.size(); j++) {
			char digito = linhas_numeros[j];
			
			if (digito == '1') {
                		soma += 2;
            		} else if (digito == '2' || digito == '3' || digito == '5') {
                		soma += 5;
            		} else if (digito == '4') {
                		soma += 4;
            		} else if (digito == '7') {
                		soma += 3;
            		} else if (digito == '8') {
                		soma += 7;
            		} else if (digito == '0' || digito == '6' || digito == '9') {
                		soma += 6;
			}
        	}
		
			std::cout << soma << " leds" << std::endl;
	}
	return 0;
}
