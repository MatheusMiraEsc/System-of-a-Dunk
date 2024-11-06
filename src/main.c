/**
 * main.h
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
*/

#include <string.h>
#include <stdio.h>
#include "menu.h"
#include "movimento.h"
#include "mecanica.h"
#include "feedback.h"
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

int jogador1X = 10, jogador1Y= 14;
int jogador2X = 54, jogador2Y = 14;
int incX = 1, incY = 1;
int cestaX1 = 8, CestaY1 = 8;
int cestaX2 = 54, CestaY2 = 8;


void exibirBola(int x, int y){
    screenGotoxy(x, y);
    printf("O");
}


void exibirCesta1(){
    screenGotoxy(cestaX1, CestaY1);
    printf("----[ ]");
    for (int i=0; i<CestaY1;i++){
        screenGotoxy(cestaX1, CestaY1+1+i);
        printf("|");
    }
}

void exibirCesta2(){
    screenGotoxy(cestaX2, CestaY2);
    printf("[ ]----");
    for (int i=0; i<CestaY2;i++){
        screenGotoxy(cestaX2+6, CestaY2+1+i);
        printf("|");
    }
}


int main() 
{
    static int ch = 0;
    int estadoJogo=0;


    screenInit(1);
    keyboardInit();
    timerInit(50);

   
    while(1){
        if (estadoJogo==0){
            ch = exibirMenu();

            if (ch == 0){
                estadoJogo = 1;
            }
            else if (ch == 1){
                estadoJogo = 2;
            }
        }
        else if(estadoJogo ==1){
            while(1){
                if (keyhit()){
                    screenClear();
                    ch = readch();
                    exibirCesta1();
                    exibirCesta2();
                    exibirJogador1(jogador1X, jogador1Y);
                    exibirJogador2(jogador2X, jogador2Y);
                    if(ch == 'W' || ch == 'A' || ch == 'D')
                    {
                        screenGotoxy(15, 25);
                        printf("Jogador 1");
                        moverJogador1(ch, jogador1X, jogador1Y);
                    }   
                    else if(ch == 'I' || ch == 'J' ||  ch == 'L')
                    {
                        screenGotoxy(15, 25);
                        printf("Jogador 2");
                        moverJogador2(ch, jogador2X, jogador2Y);
                    }
                    else if(ch == 'C')
                    {
                        if(atacarJogador1(jogador1X, jogador1Y, jogador2X, jogador2Y))
                        {
                            atualizarPontuacao(1, 10);
                            printf("Jogador 1 atacou jogador 2\n");
                        }
                    }
                    else if(ch == 'V')
                    {
                        if(defenderJogador1(jogador1X, jogador1Y, jogador2X, jogador2Y))
                        {
                            atualizarPontuacao(1, 5);
                            printf("Jogador 1 defendeu\n");
                        }
                    }
                    else if(ch == 'M')
                    {
                        if(atacarJogador2(jogador1X, jogador1Y, jogador2X, jogador2Y))
                        {
                            atualizarPontuacao(2, 10);
                            printf("Jogador 2 atacou jogador 1\n");
                        }
                    }
                    else if(ch == 'N')
                    {
                        if(defenderJogador2(jogador1X, jogador1Y, jogador2X, jogador2Y))
                        {
                            atualizarPontuacao(2, 5);
                            printf("Jogador 2 defendeu\n");
                        }
                    }
                    else if (ch == 'Q'){
                        if (arremessarJogador1(jogador1X, jogador1Y)){
                            atualizarPontuacao(1, 20);
                            printf("Jogador 1 acertou a cesta\n");
                        }
                    }
                    else if (ch == 'U'){
                        if (arremessarJogador2(jogador2X, jogador2Y)){
                            atualizarPontuacao(2, 20);
                            printf("Jogador 2 acertou a cesta\n");
                        }
                    }
                    else if(ch == 27) //ESC
                    {
                        estadoJogo = 0;
                        printf("Exibindo menu novamente...\n");
                        break;
                    }
                    screenUpdate();
                }
            }
        } else if(estadoJogo == 2){
            exibirControles();
            getchar();
            estadoJogo = 0;
        }
    }


        // Update game state (move elements, verify collision, etc)
        if (timerTimeOver() == 1)
        {
            int newX = jogador1X + incX;
            if (newX >= (MAXX -strlen("Hello World") -1) || newX <= MINX+1) incX = -incX;
            int newY = jogador1Y + incY;
            if (newY >= MAXY-1 || newY <= MINY+1) incY = -incY;

            screenGotoxy(newX, newY);

            screenUpdate();
        }

    keyboardDestroy();
    screenDestroy();
    timerDestroy();

    return 0;
}

