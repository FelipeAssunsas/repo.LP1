#include <iostream>

int main() {
	int valor;
	std::cin >> valor;

	std::cout << valor << std::endl;
	
	int contador_cem = 0;
	while( valor >= 100) {
		contador_cem += 1;
		valor = valor - 100;
	}
	std::cout << contador_cem << " nota(s) de R$ 100,00" << std::endl;

	int contador_cinquenta = 0;

	while(valor >= 50) {
		contador_cinquenta += 1;
		valor = valor - 50;
	}
	std::cout << contador_cinquenta << " nota(s) de R$ 50,00" << std::endl;

	int contador_vinte = 0;
	while(valor >= 20) {
		contador_vinte += 1;
		valor = valor - 20;
	}
	std::cout << contador_vinte << " nota(s) de R$ 20,00" << std::endl;

	int contador_dez = 0;
	while(valor >= 10) {
		contador_dez += 1;
		valor = valor - 10;
	}
	std::cout << contador_dez << " nota(s) de R$ 10,00" << std::endl;

	int contador_cinco = 0;
	while(valor >= 5){
		contador_cinco += 1;
		valor = valor - 5;
	}
	std::cout << contador_cinco << " nota(s) de R$ 5,00" << std::endl;

	int contador_dois = 0;
	while(valor >= 2){
		contador_dois += 1;
		valor = valor - 2;
	}
	std::cout << contador_dois << " nota(s) de R$ 2,00" << std::endl;

	int contador_um = 0;
	while(valor >= 1) {
		contador_um += 1;
		valor = valor - 1;
	}
	std::cout << contador_um << " nota(s) de R$ 1,00" << std::endl;
}

