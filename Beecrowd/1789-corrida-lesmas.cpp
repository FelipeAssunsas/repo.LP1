#include <iostream> //Usar uma funcao, recomendacao do professor

int main() {

int L;
while(std::cin >> L) { //pergunta do 10

  int maior_velocidade = 0;

for(int i = 0; i < L; i++) {

 int n;
 std::cin >> n;

 if(maior_velocidade < n) {

   maior_velocidade = n;

   } else {
     continue;
     }
 }

 if(maior_velocidade <= 10) {
   std::cout << "1" << std::endl;
 } else if(maior_velocidade < 20) {
 std::cout << "2" << std::endl;
 } else {
 std::cout << "3"<< std::endl;
    }
  }
}

