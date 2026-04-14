#include <iostream>
#include <vector>



int main() {


    std::string linha;
    
    int freq[256];
    while(std::getline(std::cin, linha)) {
        int freq[256] = {0};
        
        for(char c : linha) {
            freq[(usigned char)c]++;
        }

        
        std::cout << std::endl;
    }
}
