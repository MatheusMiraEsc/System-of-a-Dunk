#include "../include/movimento.h"
#include "screen.h"
/*
#define MINX 0
#define MINY 0
#define MAXX 80  // Supondo uma tela de 80 colunas
#define MAXY 24  // Supondo uma tela de 24 linhas
*/

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
    printf("/ \\");

    /*
    if(bolaComJogador2){
        screenGotoxy(x+1, y+1);
        printf("O");
    }
    */
    
    
    }

void limparJogador(int jogador1X,int jogador1Y){
    screenGotoxy(jogador1X, jogador1Y);
        printf("    ");
        screenGotoxy(jogador1X, jogador1Y+1);
        printf("    ");
        screenGotoxy(jogador1X, jogador1Y+2);
        printf("    ");
}

void moverJogador1(char direcao, int jogador1X, int jogador1Y){
    limparJogador(jogador1X, jogador1Y);
    if (direcao == 'W'){
        jogador1Y-=3;
        exibirJogador1(jogador1X, jogador1Y);
        limparJogador(jogador1X, jogador1Y);
        jogador1Y+=3;
        exibirJogador1(jogador1X, jogador1Y);
    }else if(direcao == 'A'){
        jogador1X-=2;
        exibirJogador1(jogador1X, jogador1Y);
    }else if(direcao == 'D'){
        jogador1X+=2;
        exibirJogador1(jogador1X, jogador1Y);
    }
    
    
}

void moverJogador2(char direcao, int jogador2X, int jogador2Y){
    if (direcao == 'I'){
        exibirJogador1(jogador2X, jogador2Y-3);
        exibirJogador1(jogador2X, jogador2Y);
    }else if(direcao == 'J'){
        exibirJogador1(jogador2X-2, jogador2Y);
    }else if(direcao == 'L'){
        exibirJogador1(jogador2X+2, jogador2Y);
    }
}

/*void moverJogador1(char direcao) {
    screenClear();  // Limpar a tela antes de mover

    // Limpar a posição anterior do jogador 1
    screenGotoxy(jogador1X, jogador1Y);
    printf("        ");
    
    // Atualizar a posição de acordo com a direção
    switch (direcao) {
        case 'W': if (jogador1Y > MINY) jogador1Y--; break;
        case 'A': if (jogador1X > MINX) jogador1X--; break;
        case 'S': if (jogador1Y < MAXY-3) jogador1Y++; break;
        case 'D': if (jogador1X < MAXX-3) jogador1X++; break;
    }
    
    // Exibir o jogador 1 na nova posição
    exibirJogador1(jogador1X, jogador1Y);
}

void moverJogador2(char direcao) {
    screenClear();  // Limpar a tela antes de mover

    // Limpar a posição anterior do jogador 2
    screenGotoxy(jogador2X, jogador2Y);
    printf("        ");
    
    // Atualizar a posição de acordo com a direção
    switch (direcao) {
        case 'I': if (jogador2Y > MINY) jogador2Y--; break;
        case 'J': if (jogador2X > MINX) jogador2X--; break;
        case 'K': if (jogador2Y < MAXY-3) jogador2Y++; break;
        case 'L': if (jogador2X < MAXX-3) jogador2X++; break;
    }
    
    // Exibir o jogador 2 na nova posição
    exibirJogador2(jogador2X, jogador2Y);
}*/