#ifndef FEEDBACK_H
#define FEEDBACK_H

typedef struct{
    char nome[20];
    int pontuacao;
} Jogador;

int atualizarPontuacao(int pontos);
void confirmarJogador(Jogador *jogador);
void salvarPontuacao(Jogador jogador);
void exibirRanking();
#endif
