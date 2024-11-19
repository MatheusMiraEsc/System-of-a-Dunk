#include <stdio.h>
#include "menu.h"
#include "screen.h"
#include "keyboard.h"

int exibirMenu(){
    int posicaoMenu = 0;
    int ch;

        screenClear();
        screenGotoxy(10, 5);
        screenSetColor(WHITE, BLACK);
        printf("Bem vindo à System of a Dunk");
    while(1){
        
        screenGotoxy(10, 7);
        if (posicaoMenu == 0){
            screenSetColor(YELLOW, BLACK);
            printf("-> Jogar");
        }
        else{
            screenSetColor(WHITE, BLACK);
            printf("   Jogar");
        }

        screenGotoxy(10, 8);
        if (posicaoMenu == 1){
            screenSetColor(YELLOW, BLACK);
            printf("-> Regras/Controles");
        }
        else{
            screenSetColor(WHITE, BLACK);
            printf("   Regras/Controles");
        }
        
        screenUpdate();
        ch = readch();

        switch(ch){
            case 65:
                posicaoMenu = (posicaoMenu == 0) ? 1 : 0;
                break;

            case 66:
                posicaoMenu = (posicaoMenu == 1) ? 0 : 1;
                break;
            case 10:
                return posicaoMenu;
            default:
                break;
        }
    }
}

void exibirControles(){
    screenClear();
    screenGotoxy(45, 5);
    printf("Regras:");
    screenGotoxy(30, 7);
    printf("1. O jogador deve arremessar a bola na cesta");
    screenGotoxy(30, 8);
    printf("2. Cada arremesso bem sucedido vale 2 pontos");
    screenGotoxy(30, 9);
    printf("3. O jogador tem 30 segundos para fazer o maior");
    screenGotoxy(30, 10);
    printf("   número de cestas possíveis");
    screenGotoxy(10, 5);
    printf("Controles:");
    screenGotoxy(10, 7);
    printf("Esquerda: A");
    screenGotoxy(10, 8);
    printf("Direita: D");
    screenGotoxy(10, 9);
    printf("Pulo: W");
    screenGotoxy(10, 10);
    printf("Arremesso: F");

    screenGotoxy(10, 15);
    printf("Pressione qualquer tecla para voltar ao menu");
    screenUpdate();
    readch();
    }
