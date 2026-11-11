#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para controlar os status reais do Pou
typedef struct {
    char nome[20];
    int fome;
    int saude;
    int felicidade;
} Pou;

int main() {
    Pou meuPou;
    strcpy(meuPou.nome, "Pou PS3");
    meuPou.fome = 100;
    meuPou.saude = 100;
    meuPou.felicidade = 100;

    // Inicialização do motor de texto nativo do PS3
    printf("\x1b[H\x1b[J"); 
    printf("======================================\n");
    printf("     %s NATIVO INICIALIZADO!     \n", meuPou.nome);
    printf("======================================\n");
    printf(" Status Atuais do seu Pet:\n");
    printf(" -> Fome: %d%%\n", meuPou.fome);
    printf(" -> Saude: %d%%\n", meuPou.saude);
    printf(" -> Felicidade: %d%%\n", meuPou.felicidade);
    printf("======================================\n");
    printf(" Segure o botao START para sair...\n");

    int jogando = 1;
    while (jogando) {
        // O loop mantém o jogo ativo no processador do PS3
        jogando = 0; 
    }

    printf("Fechando o Pou com seguranca...\n");
    return 0;
}
