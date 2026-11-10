#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/process.h>

// Estrutura simples para guardar os dados do nosso Pou 3D
typedef struct {
    int fome;
    int saude;
    int energia;
} Pou;

int main(int argc, char *argv[]) {
    // Inicializa o Pou com os status cheios (100%)
    Pou meu_pou = {100, 100, 100};

    printf("=== POU PS3 INICIADO! ===\n");
    printf("Status iniciais -> Fome: %d | Saúde: %d | Energia: %d\n", 
           meu_pou.fome, meu_pou.saude, meu_pou.energia);

    // Loop principal do jogo
    while(1) {
        // O Pou vai perdendo fome aos pouquinhos com o tempo
        if (meu_pou.fome > 0) {
            meu_pou.fome -= 5;
        }

        printf("O Pou está respirando... Fome atual: %d\n", meu_pou.fome);
        
        // Espera 3 segundos antes do próximo ciclo
        sleep(3);
    }

    return 0;
}
