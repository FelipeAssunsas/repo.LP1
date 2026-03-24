#include <iostream>

int main() {
	int a,b,c;
	std::cin >> a >> b >> c;

	int maior_AB, maior_total;

	maior_AB = (a+b+abs(a-b))/2;
	maior_total = (maior_AB+c+abs(maior_AB-c))/2;

	std::cout << maior_total << " eh o maior" << std::endl;

	return 0;
}
