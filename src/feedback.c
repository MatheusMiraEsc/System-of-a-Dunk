#include "feedback.h"
#include "screen.h"

int pontuacao = 0;

void atualizarPontuacao(int jogador,int pontos){
    if(jogador == 1){
    pontuacao += pontos;
    screenGotoxy(1, 1);
    printf("Pontuacao jogador 1: %d", pontuacao);
    }
    else if(jogador == 2){
    pontuacao += pontos;
    screenGotoxy(1, 2);
    printf("Pontuacao jogador 2: %d", pontuacao);
    }
}