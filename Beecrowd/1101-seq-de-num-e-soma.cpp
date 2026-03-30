#include <iostream>

int main() {
	int M, N;

	while(std::cin >> N >> M && N > 0 and M > 0) {
		if (M >= N) {
		std::swap(M, N);
		}

		int contador = 0;
		for(int i = M; i <= N; i++) {
			std::cout << i << " ";
			contador += i;
		}
		std::cout << "Sum=" << contador << std::endl;
	}
	return 0;
}
