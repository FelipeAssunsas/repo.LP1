#include <iostream>
#include <cmath>

int main() {
    using ushort = short int;
    ushort x1{0}, y1{0}, x2{0}, y2{0};

    while (std::cin >> x1 >> y1 >> x2 >> y2 && x1 != 0) {

        auto delta_x{std::abs(x1 - x2)};
        auto delta_y{std::abs(y1 - y2)};

        if (x1 == x2 && y1 == y2) {
            // Caso 0: Mesma posição
            std::cout << 0 << '\n';
        } 
        else if (x1 == x2 || y1 == y2 || delta_x == delta_y) {
            // Caso 1: Mesma linha OU mesma coluna OU mesma diagonal
            std::cout << 1 << '\n';
        } 
        else {
            // Caso 2: Qualquer outra posição no tabuleiro
            std::cout << 2 << '\n';
        }
    }

    return 0;
}
