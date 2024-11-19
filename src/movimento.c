#include "../include/movimento.h"
#include "../include/mecanica.h"
#include "screen.h"
#include <math.h>
#include <unistd.h>

#define MINX 1
#define MINY 1
#define MAXX 80  // Supondo uma tela de 30 colunas
#define MAXY 24  // Supondo uma tela de 24 linhas



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
    // Limpa o jogador da posição anterior
    limparJogador(jogador1X, jogador1Y);

    // Movimentação horizontal
    if (direcao == 'a' && *jogador1X > MINX) { // Mover para a esquerda
        J1X-=2;
    } else if (direcao == 'd' && *jogador1X < MAXX - 36) { // Mover para a direita
        J1X+=2;
    }

    // Pulo (apenas se não estiver no chão)
    if (direcao == 'w' && *jogador1Y == CHAO) { // Começa o pulo quando o jogador estiver no chão
        puloAtivo1 = 1;  // Ativa o pulo
        velocidadeY1 = -ALTURA_PULO;  // Inicializa a velocidade de subida
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


    // Exibe o jogador na nova posição
    exibirJogador1(jogador1X, jogador1Y);

}
void movNpc(int posXInicial, int posYInicial, int velYInicial) {
    int x = posXInicial;
    int y = posYInicial;
    int velY = velYInicial;

    while (y <= CHAO || velY == 0) {
        limparJogador(&x, &y);
        y -= velY;

        velY -= GRAVIDADE;

        exibirNpc(x, y);
        screenUpdate();

        usleep(INTERVALO_TEMPO);

    }
    limparJogador(&x, &y);

}




void aplicarGravidade(int *y, int *velocidadeY) {
    if (*y < CHAO) {  // Se o jogador estiver no ar
        *velocidadeY += GRAVIDADE;  // Aplica a gravidade
    } else {
        *y = CHAO;  // Impede que o jogador ultrapasse o chão
        *velocidadeY = 0;  // Reseta a velocidade de queda
    }

    *y -= *velocidadeY;  // Atualiza a posição vertical
}

