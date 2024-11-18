#include "feedback.h"
#include "screen.h"

int pontuacao = 0;

void atualizarPontuacao(int pontos){
    pontuacao += pontos;
    screenGotoxy(30, 1);
    printf("Pontuacao jogador: %d", pontuacao);
    screenUpdate();
}