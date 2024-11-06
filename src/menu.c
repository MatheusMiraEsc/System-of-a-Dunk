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
            printf("-> Controles");
        }
        else{
            screenSetColor(WHITE, BLACK);
            printf("   Controles");
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
    screenGotoxy(10, 5);
    printf("Controles:");
    screenGotoxy(10, 7);
    printf("Jogador 1:");
    screenGotoxy(10, 8);
    printf("W (Cima), A (Esquerda), D (Direita)");
    screenGotoxy(10, 9);
    printf("Ataque: C");
    screenGotoxy(10, 10);
    printf("Defesa: S");
    screenGotoxy(10, 11);
    printf("Arremesso: E");

    screenGotoxy(10, 13);
    printf("Jogador 2:");
    screenGotoxy(10, 14);
    printf("I (Cima), J (Esquerda), L (Direita)");
    screenGotoxy(10, 15);
    printf("Ataque: N");
    screenGotoxy(10, 16);
    printf("Defesa: K");
    screenGotoxy(10, 17);
    printf("Arremesso: U");
    screenGotoxy(10, 19);
    printf("Pressione qualquer tecla para voltar ao menu");
    screenUpdate();
    readch();
    }
