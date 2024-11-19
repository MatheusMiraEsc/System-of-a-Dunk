#include "feedback.h"
#include "screen.h"
#include <stdlib.h>
#include <string.h>

int pontuacao = 0;

int atualizarPontuacao(int pontos){
    pontuacao += pontos;
    screenGotoxy(30, 1);
    printf("Pontuacao jogador: %d", pontuacao);
    screenUpdate();
    return pontuacao;
}

void confirmarJogador(Jogador *jogador){
    screenClear();
    screenGotoxy(10, 5);
    printf("Digite seu nome: ");
    fgets(jogador->nome,sizeof(jogador->nome),stdin);

    size_t len = strlen(jogador->nome);
    if (len > 0 && jogador->nome[len-1] == '\n'){
        jogador->nome[len-1] = '\0';
    }
    jogador->pontuacao = 0;
    screenClear();
}

void salvarPontuacao(Jogador jogador){
    FILE *arquivo = fopen("ranking.txt", "a");
    if (arquivo == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    fprintf(arquivo, "%s %d\n", jogador.nome, jogador.pontuacao);
    fclose(arquivo);

}
