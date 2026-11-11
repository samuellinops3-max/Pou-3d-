#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LARGURA 40
#define ALTURA 20

typedef struct {
    float x, y;
    float velocidade;
} Passaro;

typedef struct {
    int x;
    int abertura_y;
} Cano;

void tocar_som_pulo() {
    printf("\a"); 
}

int main() {
    Passaro player = {5, ALTURA / 2, 0};
    Cano obstaculo = {LARGURA - 5, ALTURA / 2};
    int pontos = 0;
    int estado_jogo = 0; // 0 = Menu, 1 = Jogando, 2 = Game Over

    printf("======================================\n");
    printf("     FLAPPY BIRD PS3 INICIALIZADO     \n");
    printf("======================================\n");

    while (1) {
        if (estado_jogo == 0) {
            printf("\x1b[H\x1b[J");
            printf("\n\n   === FLAPPY BIRD PS3 ===\n\n");
            printf("      Pressione [X] para Iniciar   \n");
            printf("\n   =======================\n");
            usleep(200000);
            estado_jogo = 1;
        } 
        else if (estado_jogo == 1) {
            player.velocidade += 0.2;
            player.y += player.velocidade;

            if (player.y > ALTURA - 4) {
                player.velocidade = -1.5;
                tocar_som_pulo();
            }

            obstaculo.x--;
            if (obstaculo.x < 0) {
                obstaculo.x = LARGURA - 1;
                obstaculo.abertura_y = (rand() % (ALTURA - 8)) + 4;
                pontos++;
            }

            if (player.y < 0 || player.y >= ALTURA || 
               (obstaculo.x == (int)player.x && 
               ((int)player.y < obstaculo.abertura_y || (int)player.y > obstaculo.abertura_y + 4))) {
                estado_jogo = 2;
            }

            printf("\x1b[H"); 
            for (int y = 0; y < ALTURA; y++) {
                for (int x = 0; x < LARGURA; x++) {
                    if (x == (int)player.x && y == (int)player.y) {
                        printf("O>");
                    } else if (x == obstaculo.x && (y < obstaculo.abertura_y || y > obstaculo.abertura_y + 4)) {
                        printf("H");
                    } else if (y == ALTURA - 1) {
                        printf("_");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            printf("Pontos: %d\n", pontos);
            usleep(50000);
        } 
        else if (estado_jogo == 2) {
            printf("\n   === GAME OVER ===\n");
            printf("   Sua Pontuacao: %d\n", pontos);
            printf("   Reiniciando motor...\n");
            usleep(2000000);
            player.y = ALTURA / 2;
            player.velocidade = 0;
            obstaculo.x = LARGURA - 5;
            pontos = 0;
            estado_jogo = 1;
        }
    }
    return 0;
}
