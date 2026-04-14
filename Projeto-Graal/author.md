# Identificação Pessoal

Preencha os dados abaixo para identificar a autoria do trabalho.

- Nome: *<Felipe Assunção>*
- Email: *<assunofel@gmail.com>*
- Turma: *<DIM0176>*

# Questões Finalizadas

- [x] minmax
- [x] reverse
- [x] copy
- [x] find_if
- [x] all_of
- [x] any_of
- [x] none_of
- [x] equal
- [x] unique
- [ ] partition

--------
&copy; DIMAp/UFRN 2024.

#Dificuldades e Comentarios:
Inicialmente tive bastante dificuldade com ponteiros e iteradores, mas com o tempo consegui me aprofundar
bem nesta parte. Fora isso houve dificuldade na interpretacão do que eu deveria fazer em cada uma das
questões. também houveram diversos erros bobos onde passei grande parte do
meu tempo quebrando a cabeca. Abaixo estão especificados os erros de cada questão, retirados
de anotacões e colocados enquanto o código estava sendo feito.

Minmax:
Entender o uso do "cmp" e descobrir que eu deveria usar Iteradores extras como min_ptr e max_ptr. A 
principal dificuldade foi lidar com o retorno do tipo std::pair<Itr, Itr> e garantir que a 
lógica encontrasse a primeira ocorrência do mínimo e a última ocorrência do máximo.

Reverse:
Fiquei pensando em como inverter a ordem por um tempo, e depois se deveria usar o "swap" ou haveria outra
forma. O desafio maior foi a lógica de parada para intervalos com tamanhos ímpares e pares,
utilizando o operador de decremento pré-fixado (--last) corretamente para evitar
acesso fora do limite.

Copy:
Como foi o primeiro que eu fiz, tive dificuldade geral em entender first, last e como funcionavam os
ponteiros e iteradores. Entender que a função precisava gerenciar dois intervalos diferentes simultaneamentee retornar o iterador exato da posição final no destino.

find_if, all_of, any_of, none_of: Nestas funções, a dificuldade foi lógica: traduzir 
conceitos como "ao menos um" ou "todos" em condições de parada dentro de um laço while. 
Foi necessário cuidado redobrado para que funções como all_of retornassem true corretamente
em intervalos vazios. Mas no geral quando eu entendi a lógica da primeira as outras 2 ficaram bem
mais tranquilas.

Equal: Tentei evitar o uso de condicionais if para tornar o código mais limpo,
o que gerou confusão sobre como verificar se dois intervalos de tamanhos diferentes terminaram 
exatamente ao mesmo tempo.

Unique: Esse foi o mais difícil para mim, passei o dia inteiro pensando nele. Minhas maiores dificuldades 
foram que demorei para perceber que tinha que criar duas variaveis, o slow, que é como se fosse um "fiscal",
onde tudo que esta entre first e slow é a "zona segura", e o it, que pergunta se o próximo elemento depois 
do slow pode ser colocado na "zona segura", e o j, que é o cara que percorre toda essa zona verificando se oelemento já não esta lá dentro. Além disso, demorei para pensar em criar um bool, que verificasse se já 
exite o elemento na lista.
