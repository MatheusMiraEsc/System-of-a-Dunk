#include "movimento.h"
#include "screen.h"


extern int jogador1X, jogador1Y;
extern int jogador2X, jogador2Y;

void exibirJogador1(int x, int y){
    screenGotoxy(x, y);
    printf(" O ");
    screenGotoxy(x, y+1);
    printf("/|\\");
    screenGotoxy(x, y+2);
    printf("/ \\ ");

    /*
    if(bolaComJogador1){
        screenGotoxy(x+1, y+1);
        printf("O");
    }
    */
    
    }

void exibirJogador2(int x, int y){
    screenGotoxy(x, y);
    printf(" O ");
    screenGotoxy(x, y+1);
    printf("/|\\");
    screenGotoxy(x, y+2);
    printf("/ \\ ");

    /*
    if(bolaComJogador2){
        screenGotoxy(x+1, y+1);
        printf("O");
    }
    */
    
    
    }

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
    exibirJogador1(jogador1X, jogador1Y);
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
    exibirJogador2(jogador2X, jogador2Y);
}