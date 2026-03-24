#include <iostream>

void print() {
  std::cout << "[ ";
  auto sz = end - begin;

  for (size_t i{0}; i < sz; i++) {
	std::cout << begin[i] << ' ';
	std::cout << *(begin..	
  }
  std::cout << "]";
}

int main() {
  int vec[]{4, 3, 9, 2, 1, 8, 7};
  const size_t size_vec{7};

  std::cout << ">>> Original vec: \n";
  print(vec+2, vec+4);

  std::cout << "\n>>> Sorted vec:\n";
}
