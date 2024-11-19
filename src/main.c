/**
 * main.h
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
*/
#include "menu.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "movimento.h"
#include "mecanica.h"
#include "feedback.h"
#include "screen.h"
#include "keyboard.h"
#include "../include/timer.h"

int J1X= 10, J1Y= 14;
int npcX = 50, npcY = 14;
int *jogador1X = &J1X, *jogador1Y= &J1Y;
int incX = 1, incY = 1;
int cestaX2 = 54, CestaY2 = 8;
int velocidadeY1 = 0;  
int puloAtivo1 = 0; 
int GRAVIDADE = 1;    
int ALTURA_PULO = 5;  
int CHAO = 14; 
int INTERVALO_TEMPO = 100000; // 100ms
int velXBola = 3, velYBola = 4;
#define TEMPO_LIMITE 30000


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
    int pontos = 0;
    screenInit(1);
    keyboardInit();
    timerInit(50);

    Jogador *jogador = NULL;
   
    while(1){
        if (estadoJogo==0){
            ch = exibirMenu();
            jogador = malloc(sizeof(Jogador));
            if (ch == 0){
                estadoJogo = 1;
                confirmarJogador(jogador);
                timerInit(50);   
            }
            else if (ch == 1){
                estadoJogo = 2;
            }
            
        }
        else if(estadoJogo ==1){
            pontos = 0;
            while(1){
                int tempoDecorrido = getTimeDiff() / 1000;
                int tempoRestante = (TEMPO_LIMITE/1000) - tempoDecorrido;
                if (tempoRestante < 0) tempoRestante = 0;                                                                                        
                if (keyhit()){                                                                                                                                                                                                                                                                                                                                                   
                    screenClear();
                    ch = readch();
                    screenGotoxy(1, 1);                                                                                                                             
                    printf("Tecla pressionada: %c", ch);
                    screenGotoxy(1, 2);
                    printf("Pressione ESC para voltar ao menu");
                    exibirCesta2();
                    atualizarPontuacao(0);
                    exibirJogador1(jogador1X, jogador1Y);
                    exibirNpc(npcX, npcY);  
                    movNpc(npcX, npcY, velocidadeY1);
                    screenGotoxy(60,1);
                    printf("Tempo restante: %ds", tempoRestante);
                    if(ch == 'w' || ch == 'a' || ch == 'd')
                    {
                        moverJogador1(ch, jogador1X, jogador1Y);
                    }
                    else if(ch == 'f')
                    {
                        pontos+=arremessarJogador1(J1X+2, J1Y-1, velXBola,velYBola);
                    }
                    else if(ch == 27) //ESC
                    {
                        estadoJogo = 0;
                        screenClear();
                        screenGotoxy(1, 1);
                        printf("Exibindo menu novamente...\n");
                        usleep(INTERVALO_TEMPO  * 20);
                        break;
                    }
                    screenUpdate();
                }

                if (getTimeDiff() >= TEMPO_LIMITE) {
                    jogador->pontuacao = pontos;
                    screenClear();
                    screenGotoxy(10, 5);
                    printf("Tempo esgotado! Salvando pontuação...\n");
                    salvarPontuacao(*jogador);
                    usleep(INTERVALO_TEMPO * 20);
                    exibirRanking();
                    estadoJogo = 0;
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
            int newX = J1X + incX;
            if (newX >= (MAXX -strlen("Hello World") -1) || newX <= MINX+1) incX = -incX;
            int newY = J1Y + incY;
            if (newY >= MAXY-1 || newY <= MINY+1) incY = -incY;

            screenGotoxy(newX, newY);

            screenUpdate();
        }

    keyboardDestroy();
    screenDestroy();
    timerDestroy();

    return 0;
}

