#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL, "portuguese");

    
    printf("********************************\n");
    printf("Bem vindo ao jogo de adivinhação\n");
    printf("Tente adivinhar o número secreto\n");
    printf("********************************\n\n");
    
    int segundos = time(0);
    srand (segundos);
    int numaleatorio = rand();

    int numsecreto = numaleatorio % 100;
    int chute;
    int tentativa = 1;
    float pontos = 1000;
    int numtentativas;
    int dificuldade;
    
    printf("Escolha o nível de dificuldade\n");
    printf("(1) fácil (2) médio (3) difícil\n");
    printf("Escolha: ");
    scanf("%d", &dificuldade);
    
    switch(dificuldade) {
        case 1: numtentativas = 20;
            break;
        case 2: numtentativas = 12;
            break;
        case 3: numtentativas = 6;
            
    }

    while(tentativa <= numtentativas){

    
    //for (i = 1; i <= CHANCES; i++){
        
        printf("Tentativa %d\n", tentativa);
        printf("Qual o seu chute? ");
        scanf("%d", &chute);
        
        int negativo = chute < 0;
        int acertou = chute == numsecreto;
        int maior = chute > numsecreto;
        int menor = chute < numsecreto;
        float pontuacao;

        if(negativo){
            printf("Você não pode chutar números negativos\n\n");
            continue;
        }
        else if(acertou){
            printf("Você acertou!\n");
            printf("Você acertou em %d tentativas\n", tentativa);
            printf("Sua pontuação é: %.2f\n", pontos);
            break;
            
        }
        else if(maior){
            printf("Seu chute foi maior que o número secreto\n");
            
        }
        else if(menor){
            printf("Seu chute foi menor que o número secreto!\n");
        }
        else if(pontos <= 0){
            pontos = 1;
        }
        pontuacao = abs(chute - numsecreto) / (double)2;
        pontos = pontos - pontuacao;    
        
        printf("\n\n");
        tentativa++;
    
    }
    
    if(tentativa > numtentativas){
        printf("Você perdeu\n");
    }
    printf("Fim de jogo!\n");
   
    return 0;
}
