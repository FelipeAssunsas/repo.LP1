#include <array>
#include <iostream>
#include <iterator>

int *filter(int *first,int *last) {
		

	return last; //
}

int main() {
	std::array vet{-2, -8, 6, 7, -3 , 10, 1 , 0 , -3, 7};

	std::cout << ">>> Original array = [ ";
	for(const auto &e : vet) {
		std::cout << e << " ";
	}
	std::cout << "], Size = " << vet.size() <<'\n';

	auto *new_end 
