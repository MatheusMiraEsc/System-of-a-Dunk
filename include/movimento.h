#ifndef MOVIMENTO_H
#define MOVIMENTO_H

extern int J1X, J1Y;
extern int *jogador1X, *jogador1Y;
extern int incX, incY;
extern int cestaX2, cestaY2;
extern int velocidadeY1;
extern int puloAtivo1;
extern int GRAVIDADE, ALTURA_PULO, CHAO;


void limparJogador(int *jogador1X,int *jogador1Y);
void exibirJogador1(int *x, int *y);
void exibirNpc(int *x, int *y);
void moverJogador1(char direcao, int *jogador1X,int *jogador1Y);
void aplicarGravidade(int *jogador1Y, int *velocidadeY);
#endif
