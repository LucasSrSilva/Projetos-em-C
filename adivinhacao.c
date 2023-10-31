#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL, "portuguese");

    
    printf("********************************\n");
    printf("Bem vindo ao jogo de adivinha��o\n");
    printf("Tente adivinhar o n�mero secreto\n");
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
    
    printf("Escolha o n�vel de dificuldade\n");
    printf("(1) f�cil (2) m�dio (3) dif�cil\n");
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
            printf("Voc� n�o pode chutar n�meros negativos\n\n");
            continue;
        }
        else if(acertou){
            printf("Voc� acertou!\n");
            printf("Voc� acertou em %d tentativas\n", tentativa);
            printf("Sua pontua��o �: %.2f\n", pontos);
            break;
            
        }
        else if(maior){
            printf("Seu chute foi maior que o n�mero secreto\n");
            
        }
        else if(menor){
            printf("Seu chute foi menor que o n�mero secreto!\n");
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
        printf("Voc� perdeu\n");
    }
    printf("Fim de jogo!\n");
   
    return 0;
}