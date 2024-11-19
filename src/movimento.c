#include "../include/movimento.h"
#include "../include/mecanica.h"
#include "screen.h"
#include <math.h>
#include <unistd.h>

#define MINX 1
#define MINY 1
#define MAXX 80  
#define MAXY 24  



void exibirJogador1(int *x, int *y){
    screenGotoxy(*x, *y);
    printf(" O ");
    screenGotoxy(*x, *y+1);
    printf("/|\\o");
    screenGotoxy(*x, *y+2);
    printf("/ \\ ");

    
    }
void exibirNpc(int x, int y){
    screenGotoxy(x, y);
    printf("\\O/ ");
    screenGotoxy(x, y+1);
    printf(" | ");
    screenGotoxy(x, y+2);
    printf("/ \\ ");
}


void limparJogador(int *jogador1X,int *jogador1Y){
    screenGotoxy(*jogador1X, *jogador1Y);
    printf("    ");
    screenGotoxy(*jogador1X, *jogador1Y+1);
    printf("    ");
    screenGotoxy(*jogador1X, *jogador1Y+2);
    printf("    ");
}


void moverJogador1(char direcao, int *jogador1X, int *jogador1Y){
    
    limparJogador(jogador1X, jogador1Y);

    if (direcao == 'a' && *jogador1X > MINX) {
        J1X-=2;
    } else if (direcao == 'd' && *jogador1X < MAXX - 36) { 
        J1X+=2;
    }

   
    if (direcao == 'w' && *jogador1Y == CHAO) { 
        puloAtivo1 = 1;  
        velocidadeY1 = -ALTURA_PULO; 
        J1Y+=2;
    }
    while(puloAtivo1){
        limparJogador(jogador1X, jogador1Y);
        aplicarGravidade(jogador1Y, &velocidadeY1);
        /*if(keyhit()){
            char tecla = readch();
            if(tecla =='c'){
                screenGotoxy(J1X, J1Y);
                printf("ARREMESSO");
            }
        }*/

        if (*jogador1Y >= CHAO){
            *jogador1Y = CHAO;
            puloAtivo1 = 0;
        }
        exibirJogador1(jogador1X, jogador1Y);
        screenUpdate();
    }


    exibirJogador1(jogador1X, jogador1Y);

}
void movNpc(int posXInicial, int posYInicial, int velYInicial, int tempoRestante) {
    int x = posXInicial;
    int y = posYInicial;
    int velY = velYInicial;

    while (y <= CHAO || velY == 0) {
        limparJogador(&x, &y);
        y += velY;

        velY += GRAVIDADE;
        
        exibirNpc(x, y);
        screenUpdate();

        usleep(INTERVALO_TEMPO);
        if (tempoRestante==10){
            while(x>MINX){
                limparJogador(&x, &y);
                x-=2;
                exibirNpc(x, y);
                screenUpdate();
                usleep(INTERVALO_TEMPO/10);
            }
        }
    }
    limparJogador(&x, &y);
    exibirNpc(x, y);

}




void aplicarGravidade(int *y, int *velocidadeY) {
    if (*y < CHAO) {
        *velocidadeY += GRAVIDADE; 
    } else {
        *y = CHAO; 
        *velocidadeY = 0; 
    }

    *y -= *velocidadeY;
}

