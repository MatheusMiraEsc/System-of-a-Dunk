#include "mecanica.h"
#include "screen.h"
#include <stdlib.h>

int cestaX = 40, cestaY = 1;
extern int jogador1X, jogador1Y;
extern int jogador2X, jogador2Y;

int arremessarJogador1(int jogador1X, int jogador1Y){
    int distancia = abs(jogador1X - cestaX);
    int chance = (distancia <=10) ? 70: 30;
    if (rand() % 100 < chance){
        screenGotoxy(1, 1);
        printf("Jogador 1 acertou a cesta");
        return 1;
    }
    screenGotoxy(1, 1);
    printf("Jogador 1 errou a cesta");
    return 0;
}

int arremessarJogador2(int jogador2X, int jogador2Y){
    int distancia = abs(jogador2X - cestaX) + abs(jogador2Y - cestaY);
    int chance = (distancia <=10) ? 70: 30;
    if (rand() % 100 < chance){
        screenGotoxy(1, 2);
        printf("Jogador 2 acertou a cesta");
        return 1;
    }
    screenGotoxy(1, 2);
    printf("Jogador 2 errou a cesta");
    return 0;
}

int atacarJogador1(int jogador1X, int jogador1Y, int jogador2X, int jogador2Y){ 
    if (jogador1X + 1 == jogador2X && jogador1Y == jogador2Y){
        screenGotoxy(1, 1);
        printf("Jogador 1 atacou jogador 2");
        return 1;
    }
    return 0;
}

int atacarJogador2(int jogador1X, int jogador1Y, int jogador2X, int jogador2Y){
    if (jogador2X - 1 == jogador1X && jogador2Y == jogador1Y){
        screenGotoxy(1, 2);
        printf("Jogador 2 atacou jogador 1");
        return 1;
    }
    return 0;
}

int defenderJogador1(int jogador1X, int jogador1Y, int jogador2X, int jogador2Y){
    if(abs(jogador1X - jogador2X) <= 1 && jogador1Y == jogador2Y){
        screenGotoxy(1, 3);
        printf("Jogador 1 defendeu");
        return 1;
    }
    screenGotoxy(1, 3);
    printf("Jogador 1 não defendeu");
    return 0;
}

int defenderJogador2(int jogador1X, int jogador1Y, int jogador2X, int jogador2Y){
    if (abs(jogador2X - 1) <= 1 && jogador1Y == jogador2Y){
        screenGotoxy(1, 4);
        printf("Jogador 2 defendeu");
        return 1;
    }
    printf("Jogador 2 não defendeu");
    return 0;
}

