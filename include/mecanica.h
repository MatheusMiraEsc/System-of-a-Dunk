#ifndef MECANICA_H
#define MECANICA_H

extern int J1X, J1Y;
extern int *jogador1X, *jogador1Y;
extern int cestaX2, cestaY2;
extern int CHAO, GRAVIDADE, INTERVALO_TEMPO;

void exibirTeste(int x, int y, char teste);
void limparPosicao(int x, int y);
void exibirBola(int x, int y);
int arremessarJogador1(int posXInicial, int posYInicial, int velXInicial, int velYInicial);
#endif
