#include <psl1ght/lv2.h>
#include <rsx/rsx.h>
#include <io/pad.h>
#include <stdio.h>

int fome = 50, felicidade = 50, energia = 50, vida = 100;
int selecao = 0;

int main() {
    padInfo padinfo;
    padData paddata;
    ioPadInit(7);
    // Inicializa video RSX simples
    gcmContextData *context = NULL;
    void *host_addr = memalign(1024*1024, 1024*1024);
    rsxInit(&context, 0x10000, 1024*1024, host_addr);
    
    while(1) {
        ioPadGetInfo(&padinfo);
        if(padinfo.status[0]) {
            ioPadGetData(0, &paddata);
            if(paddata.BTN_CROSS) {
                if(selecao==0) { fome+=20; if(fome>100) fome=100; }
                if(selecao==1) { felicidade+=20; if(felicidade>100) felicidade=100; }
                if(selecao==2) { energia+=20; if(energia>100) energia=100; }
                if(selecao==3) { vida=100; fome=100; felicidade=100; energia=100; }
            }
            if(paddata.BTN_LEFT) selecao--;
            if(paddata.BTN_RIGHT) selecao++;
            if(selecao<0) selecao=3;
            if(selecao>3) selecao=0;
            if(paddata.BTN_START) break;
        }
        // Pou vai perdendo status com o tempo
        fome--; felicidade--; energia--;
        if(fome<0) fome=0;
        if(felicidade<0) felicidade=0;
        if(energia<0) energia=0;
        if(fome==0 || energia==0) vida--;
        if(vida<=0) vida=0;
        
        rsxSetClearColor(context, 0xFF87CEEB);
        rsxClearSurface(context, GCM_CLEAR_R | GCM_CLEAR_G | GCM_CLEAR_B | GCM_CLEAR_A | GCM_CLEAR_S | GCM_CLEAR_Z);
        rsxFlushBuffer(context);
        sys_timer_usleep(500000);
    }
    return 0;
}