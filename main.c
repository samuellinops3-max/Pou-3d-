#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Estrutura para guardar os status do nosso Pou
typedef struct {
    int fome;     // 0 a 100
    int saude;    // 0 a 100
    int energia;  // 0 a 100
    int moedas;   // Dinheiro do jogo para comprar comida
} Pou;

// Função para mostrar a carinha e os status do Pou na tela
void mostrar_status(Pou *p) {
    printf("\n==============================\n");
    printf("        MEU POU NO PS3        \n");
    printf("==============================\n");
    printf("  (o.o)  < Olá dono!\n");
    printf("------------------------------\n");
    printf(" 🍗 Fome:    [%d/100]\n", p->fome);
    printf(" ❤️  Saúde:   [%d/100]\n", p->saude);
    printf(" 💤 Energia: [%d/100]\n", p->energia);
    printf(" 🪙 Moedas:  [%d]\n", p->moedas);
    printf("==============================\n");
}

int main(int argc, char *argv[]) {
    // Inicializa o Pou com os status cheios e algumas moedas
    Pou meu_pou = {
        .fome = 100,
        .saude = 100,
        .energia = 100,
        .moedas = 50
    };

    printf("=== JOGO DO POU INICIALIZADO NO PS3! ===\n");

    int contador_tempo = 0;

    // Loop principal do jogo
    while(1) {
        mostrar_status(&meu_pou);

        // Simula o tempo passando: o Pou vai ficando com fome e cansado aos poucos
        contador_tempo++;
        if (contador_tempo >= 3) {
            if (meu_pou.fome > 0) meu_pou.fome -= 10;
            if (meu_pou.energia > 0) meu_pou.energia -= 5;
            // Ganha 5 moedas por passar o tempo cuidando dele
            meu_pou.moedas += 5;
            contador_tempo = 0;
            printf("\n[Aviso] O tempo passou... O Pou gastou energia e fome.\n");
        }

        // Simulação de ações automáticas para o teste rodar direto no terminal
        printf("\nAções disponíveis:\n");
        printf("1. Alimentar (Custa Fome)\n");
        printf("2. Dormir (Recupera Energia)\n");
        printf("Pressione Ctrl+C para sair.\n");

        // Simula uma pausa de 3 segundos antes da próxima atualização
        sleep(3);
    }

    return 0;
}
