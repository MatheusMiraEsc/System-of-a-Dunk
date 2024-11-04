#include "movimento.h"
#include "screen.h"

extern int jogador1X, jogador1Y;
extern int jogador2X, jogador2Y;


void moverJogador1(char direcao){
    screenGotoxy(jogador1X, jogador1Y);
    printf("        ");
    switch (direcao)
    {
    case 'W': jogador1Y--; break;
    case 'A': jogador1X--; break;
    case 'S': jogador1Y++; break;
    case 'D': jogador1X++; break;
    }
    screenGotoxy(jogador1X, jogador1Y);
    printf("Jogador 1");
}

void moverJogador2(char direcao){
    screenGotoxy(jogador2X, jogador2Y);
    printf("        ");
    switch (direcao)
    {
    case 'I': jogador2Y--; break;
    case 'J': jogador2X--; break;
    case 'K': jogador2Y++; break;
    case 'L': jogador2X++; break;
    }
    screenGotoxy(jogador2X, jogador2Y);
    printf("Jogador 2");
}