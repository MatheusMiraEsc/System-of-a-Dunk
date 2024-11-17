#include "mecanica.h"
#include "screen.h"
#include <stdlib.h>

int cestaY2=8;

int arremessarJogador1(int J1X, int J1Y){
    int distancia = abs(J1X - cestaX2) + abs(J1Y - cestaY2);
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

