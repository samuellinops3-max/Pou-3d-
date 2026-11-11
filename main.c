#include <stdio.h>
#include <io/pad.h>
#include <sysutil/sysutil.h>

// Função que gerencia os eventos do sistema do PS3
void sys_callback(uint64_t status, uint64_t param, void* userdata) {
    if (status == SYSUTIL_EXIT_GAME) {
        printf("Saindo do Jogo do Pou...\n");
    }
}

int main(int argc, char* argv[]) {
    // Registra o callback para o botão de sair do PS3 funcionar
    sysUtilRegisterCallback(SYSUTIL_EVENT_SLOT0, sys_callback, NULL);

    printf("==================================\n");
    printf("   POU NATIVO PS3 INICIALIZADO   \n");
    printf("==================================\n");

    PadInfo padinfo;
    PadData paddata;
    
    ioPadInit(7); // Inicializa os controles do PS3

    // Loop principal do jogo
    while(1) {
        sysUtilCheckCallback();

        ioPadGetInfo(&padinfo);
        if(padinfo.status[0]) {
            ioPadGetData(0, &paddata);
            
            // Se o jogador apertar START no controle, o jogo fecha
            if(paddata.BTN_START) {
                break;
            }
        }
    }

    ioPadEnd();
    return 0;
}