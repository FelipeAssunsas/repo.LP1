#include <iostream>
#include <string>
#include <sstream>

int main() {
	std::string linha;

	while(std::getline(std::cin, linha) && linha != "*") {

		for(char &c : linha) {
			c = std::tolower(c);
		}
		std::stringstream ss(linha);
		std::string palavra;

		if(ss >> palavra) {
			char primeira_letra = palavra[0];
			bool eh_tautograma = true;

			while(ss >> palavra) {
				if(palavra[0] != primeira_letra) {
					eh_tautograma = false;
					break;
				}
			}
			if(eh_tautograma) {
				std::cout << "Y" << std::endl;
			} else {
				std::cout << "N" << std::endl;
			}
		}

		
	}
	return 0;
}
