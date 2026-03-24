//1175 beecrowd

#include <iostream>
#include <array>


int main() {
	
	int N[20];
	for(int i = 0; i < 20; i++) {
		std::cin >> N[i];
	}
	for(int i = 0; i < 10; i++) {
		int temp = N[i];
		N[i] = N[19 - i];
		N[19 - i] = temp;
	}
	for(int i = 0; i < 20; i++) {
		std::cout << "N[" << i << "] = " << N[i] << std::endl;
	}
	return 0;
}
