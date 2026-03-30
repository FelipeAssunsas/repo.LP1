#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

struct Caractere {
    int ascii;
    int freq;
};

bool comparar(Caractere a, Caractere b) {
    if (a.freq != b.freq) {
        return a.freq < b.freq;
    }
    return a.ascii > b.ascii;   
}

int main() {
    std::string linha;
    bool primeira_linha = true;

    while (std::getline(std::cin, linha)) {
        if (!primeira_linha) std::cout << std::endl;
        primeira_linha = false;

        int frequencias[256] = {0};
        for (char c : linha) {
            frequencias[(unsigned char)c]++;
        }

        std::vector<Caractere> lista;
        for (int i = 0; i < 256; i++) {
            if (frequencias[i] > 0) {
                lista.push_back({i, frequencias[i]});
            }
        }

        std::sort(lista.begin(), lista.end(), comparar);

        for (const auto& item : lista) {
            std::cout << item.ascii << " " << item.freq << std::endl;
        }
    }

    return 0;
}
