#include "mecanica.h"
#include "screen.h"
#include <stdlib.h>
#include <unistd.h>
#include "feedback.h"
#include "movimento.h"

int cestaY2=8;

void exibirTeste(int x, int y, char teste){
    /*screenGotoxy(x, y);
    printf("Teste %d %d", x, y);
    screenUpdate();
*/
    screenGotoxy(x-1, y-1);
        printf("%c", teste);
        screenGotoxy(x + 3, y-1);
        printf("%c", teste);
        screenGotoxy(x-1, y + 1);
        printf("%c", teste);
        screenGotoxy(x + 3, y + 1);
        printf("%c", teste);
        screenUpdate();
}

void exibirBola(int x, int y){
    screenGotoxy(x, y);
    printf("o");
}
void limparPosicao(int x, int y){
    screenGotoxy(x, y);
    printf(" ");
}

int arremessarJogador1(int posXInicial, int posYInicial, int velXInicial, int velYInicial) {
    int x = posXInicial;
    int y = posYInicial;
    int velX = velXInicial;
    int velY = velYInicial;
    int acertouCesta = 0;

    while (y <= CHAO || velY == 0) {
        limparPosicao(x, y);
        x += velX;
        y -= velY;

        velY -= GRAVIDADE;

        exibirBola(x, y);
        screenUpdate();

        usleep(INTERVALO_TEMPO);
        if (x >= cestaX2-1 && x <= cestaX2 + 3) {
        if(y >= cestaY2-1 && y <= cestaY2 + 3) {
            exibirTeste(cestaX2, cestaY2, 'o');
            acertouCesta = 1;
            limparPosicao(cestaX2, cestaY2);
            return atualizarPontuacao(2);
            }
        }

    }
    limparPosicao(x, y);
    if (!acertouCesta) {
        exibirTeste(x, y, 'x');
        limparPosicao(cestaX2, cestaY2);
        return 0;
    }
    return 0;
    
}

