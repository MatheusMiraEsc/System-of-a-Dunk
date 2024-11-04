#include <stdio.h>
#include "menu.h"
#include "screen.h"
#include "keyboard.h"

int exibirMenu(){
    int posicaoMenu = 0;
    int ch;

        screenClear();
        screenGotoxy(10, 5);
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
    printf("Movimento: W, A, S, D");
    screenGotoxy(10, 8);
    printf("Ataque: J");
    screenGotoxy(10, 9);
    printf("Defesa: K");
    screenGotoxy(10, 10);
    printf("Pressione qualquer tecla para voltar ao menu");
}