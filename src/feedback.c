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

void exibirRanking(){
    FILE *arquivo = fopen("ranking.txt", "r");
    if (arquivo == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    
    Jogador jogador[10];
    int count = 0;
    while (fscanf(arquivo, "%s %d", jogador[count].nome, &jogador[count].pontuacao) != EOF){
        count++;
    }

    fclose(arquivo);

    for(int i = 0; i < count-1; i++){
        for(int j = i+1; j < count; j++){
            if (jogador[i].pontuacao < jogador[j].pontuacao){
                Jogador temp = jogador[i];
                jogador[i] = jogador[j];
                jogador[j] = temp;
            }
        }
    }

    screenClear();

    screenGotoxy(15, 5);
    printf("*** RANKING ***");
    for(int i = 0; i < count; i++){
        screenGotoxy(10, 6+i);
        printf("%d. %s %d\n", i+1, jogador[i].nome, jogador[i].pontuacao);
    }
    screenGotoxy(10, 6+count);
    printf("Pressione qualquer tecla para voltar ao menu");
    getchar();
}
