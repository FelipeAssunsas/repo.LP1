#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string senha;

    while (std::getline(std::cin, senha)) {
        
        if (senha.length() < 6 || senha.length() > 32) {
            std::cout << "Senha invalida." << std::endl;
            continue; 
        }

        bool tem_maiuscula = false;
        bool tem_minuscula = false;
        bool tem_numero = false;
        bool tem_caractere_invalido = false;

        for (char c : senha) {
            if (std::isupper(c)) {
                tem_maiuscula = true;
            } else if (std::islower(c)) {
                tem_minuscula = true;
            } else if (std::isdigit(c)) {
                tem_numero = true;
            } else {
                tem_caractere_invalido = true;
                break;
            }
        }

        if (tem_maiuscula && tem_minuscula && tem_numero && !tem_caractere_invalido) {
            std::cout << "Senha valida." << std::endl;
        } else {
            std::cout << "Senha invalida." << std::endl;
        }
    }

    return 0;
}
