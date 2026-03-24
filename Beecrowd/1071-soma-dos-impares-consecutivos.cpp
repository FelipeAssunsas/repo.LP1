#include<iostream>
#include<algorithm>

int main() {
	int X, Y;
	std::cin >> X >> Y;
	
	int soma = 0;

	int menor = std::min(X, Y);
	int maior = std::max(X, Y);

	for(int i = menor + 1; i < maior; i++){
		if(i % 2 != 0) {
			soma += i;
		}
	}
	std::cout << soma << std::endl;
}
