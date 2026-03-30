#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int pa, pb;
        double g1, g2;
        std::cin >> pa >> pb >> g1 >> g2;

        int anos = 0;
        while (pa <= pb && anos <= 100) {
            pa += (int)(pa * (g1 / 100.0));
            pb += (int)(pb * (g2 / 100.0));
            anos++;
        }

        if (anos > 100) {
            std::cout << "Mais de 1 seculo." << std::endl;
        } else {
            std::cout << anos << " anos." << std::endl;
        }
    }

    return 0;
}
