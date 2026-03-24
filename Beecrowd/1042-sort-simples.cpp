#include<iostream>
#include<algorithm>

//Bubble Sort

 int main() {
	 int a, b, c;
	 std::cin >> a >> b >> c;

	 int orig_a = a, orig_b = b, orig_c = c;

	 if(a > b) std::swap(a, b);
	 if(b > c) std::swap(b, c);
	 if(a > b) std::swap(a, b);

	 std::cout << a << std::endl << b << std::endl << c << std::endl << std::endl;

	 std::cout << orig_a << std::endl << orig_b << std::endl << orig_c << std::endl;

 }
