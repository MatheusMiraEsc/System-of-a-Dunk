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

int jogador1X = 10, jogador1Y= 12;
int jogador2X = 70, jogador2Y = 12;
int incX = 1, incY = 1;

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
                    ch = readch();
                    printf("Tecla pressionada: %c\n", ch);
                    if(ch == 'W' || ch == 'A' || ch == 'S' || ch == 'D')
                    {
                        moverJogador1(ch);
                    }
                    else if(ch == 'I' || ch == 'J' || ch == 'K' || ch == 'L')
                    {
                        moverJogador2(ch);
                    }
                    else if(ch == 'C')
                    {
                        if(atacarJogador1(jogador1X, jogador1Y, jogador2X, jogador2Y))
                        {
                            atualizarPontuacao(1, 10);
                        }
                    }
                    else if(ch == 'V')
                    {
                        if(defenderJogador1(jogador1X, jogador1Y, jogador2X, jogador2Y))
                        {
                            atualizarPontuacao(1, 5);
                        }
                    }
                    else if(ch == 'M')
                    {
                        if(atacarJogador2(jogador1X, jogador1Y, jogador2X, jogador2Y))
                        {
                            atualizarPontuacao(2, 10);
                        }
                    }
                    else if(ch == 'N')
                    {
                        if(defenderJogador2(jogador1X, jogador1Y, jogador2X, jogador2Y))
                        {
                            atualizarPontuacao(2, 5);
                        }
                    }
                    else if (ch == 'Q'){
                        if (arremessarJogador1(jogador1X, jogador1Y)){
                            atualizarPontuacao(1, 20);
                        }
                    }
                    else if (ch == 'U'){
                        if (arremessarJogador2(jogador2X, jogador2Y)){
                            atualizarPontuacao(2, 20);
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

