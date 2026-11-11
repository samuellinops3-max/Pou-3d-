#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura simples para representar o status do Pou no PS3
typedef struct {
    char nome[20];
    int fome;
    int saude;
    int felicidade;
} Pou;

int main() {
    // Inicializa o Pou com status cheios
    Pou meuPou;
    strcpy(meuPou.nome, "Pou PS3");
    meuPou.fome = 100;
    meuPou.saude = 100;
    meuPou.felicidade = 100;

    printf("======================================\n");
    printf("     %s NATIVO INICIALIZADO!     \n", meuPou.nome);
    printf("======================================\n");
    printf(" Status Iniciais:\n");
    printf(" -> Fome: %d%%\n", meuPou.fome);
    printf(" -> Saude: %d%%\n", meuPou.saude);
    printf(" -> Felicidade: %d%%\n", meuPou.felicidade);
    printf("======================================\n");
    printf(" Pressione START para fechar o jogo...\n");

    // Loop basico do jogo rodando no console
    int executando = 1;
    while (executando) {
        // A logica do jogo e os comandos do controle do PS3 entram aqui
        // Por enquanto, ele apenas mantem o motor do jogo ativo
        executando = 0; // Termina o ciclo de teste com sucesso
    }

    printf("Fechando o Pou de forma segura...\n");
    return 0;
}
