#include <psl1ght/lv2.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <io/pad.h>
#include <rsx/rsx.h>
#include <tiny3d.h>
int main(){
tiny3d_Init(1024*1024);
tiny3d_Project2D();
padInfo padinfo;padData paddata;
int fome=80,feli=80,limp=80,ener=80;
int selecao=0;int frame=0;int piscar=0;
ioPadInit(7);
while(1){
ioPadGetInfo(&padinfo);
if(padinfo.status[0]){
ioPadGetData(0,&paddata);
if(paddata.BTN_LEFT){if(selecao>0)selecao--;usleep(150000);}
if(paddata.BTN_RIGHT){if(selecao<3)selecao++;usleep(150000);}
if(paddata.BTN_CROSS){
if(selecao==0){fome+=25;if(fome>100)fome=100;}
if(selecao==1){feli+=25;if(feli>100)feli=100;fome-=10;ener-=10;}
if(selecao==2){limp=100;}
if(selecao==3){ener=100;}
usleep(250000);}
if(paddata.BTN_START)break;}
frame++;
if(frame%180==0){fome--;feli--;limp--;ener--;if(fome<0)fome=0;if(feli<0)feli=0;if(limp<0)limp=0;if(ener<0)ener=0;}
piscar++;
tiny3d_Clear(0xFF87CEEB,TINY3D_CLEAR_ALL);
tiny3d_SetPolygon(TINY3D_QUADS);
tiny3d_VertexPos(150,80,0);tiny3d_VertexColor(0xFFFFFFFF);
tiny3d_VertexPos(1170,80,0);tiny3d_VertexColor(0xFFFFFFFF);
tiny3d_VertexPos(1170,500,0);tiny3d_VertexColor(0xFFFFFFFF);
tiny3d_VertexPos(150,500,0);tiny3d_VertexColor(0xFFFFFFFF);
tiny3d_End();
tiny3d_SetPolygon(TINY3D_QUADS);
tiny3d_VertexPos(560,220,0);tiny3d_VertexColor(0xFFC68E5F);
tiny3d_VertexPos(760,220,0);tiny3d_VertexColor(0xFFC68E5F);
tiny3d_VertexPos(760,420,0);tiny3d_VertexColor(0xFFC68E5F);
tiny3d_VertexPos(560,420,0);tiny3d_VertexColor(0xFFC68E5F);
tiny3d_End();
tiny3d_SetPolygon(TINY3D_QUADS);
tiny3d_VertexPos(600,280,0);tiny3d_VertexColor(0xFFFFFFFF);
tiny3d_VertexPos(640,280,0);tiny3d_VertexColor(0xFFFFFFFF);
tiny3d_VertexPos(640,330,0);tiny3d_VertexColor(0xFFFFFFFF);
tiny3d_VertexPos(600,330,0);tiny3d_VertexColor(0xFFFFFFFF);
tiny3d_VertexPos(680,280,0);tiny3d_VertexColor(0xFFFFFFFF);
tiny3d_VertexPos(720,280,0);tiny3d_VertexColor(0xFFFFFFFF);
tiny3d_VertexPos(720,330,0);tiny3d_VertexColor(0xFFFFFFFF);
tiny3d_VertexPos(680,330,0);tiny3d_VertexColor(0xFFFFFFFF);
tiny3d_End();
if(piscar%120<110){
tiny3d_SetPolygon(TINY3D_QUADS);
tiny3d_VertexPos(615,300,0);tiny3d_VertexColor(0xFF000000);
tiny3d_VertexPos(630,300,0);tiny3d_VertexColor(0xFF000000);
tiny3d_VertexPos(630,320,0);tiny3d_VertexColor(0xFF000000);
tiny3d_VertexPos(615,320,0);tiny3d_VertexColor(0xFF000000);
tiny3d_VertexPos(695,300,0);tiny3d_VertexColor(0xFF000000);
tiny3d_VertexPos(710,300,0);tiny3d_VertexColor(0xFF000000);
tiny3d_VertexPos(710,320,0);tiny3d_VertexColor(0xFF000000);
tiny3d_VertexPos(695,320,0);tiny3d_VertexColor(0xFF000000);
tiny3d_End();}
tiny3d_SetPolygon(TINY3D_QUADS);
tiny3d_VertexPos(630,360,0);tiny3d_VertexColor(0xFF000000);
tiny3d_VertexPos(690,360,0);tiny3d_VertexColor(0xFF000000);
tiny3d_VertexPos(690,375,0);tiny3d_VertexColor(0xFF000000);
tiny3d_VertexPos(630,375,0);tiny3d_VertexColor(0xFF000000);
tiny3d_End();
int bars[4]={fome,feli,limp,ener};
for(int i=0;i<4;i++){
int x=200+i*250;
tiny3d_SetPolygon(TINY3D_QUADS);
tiny3d_VertexPos(x,90,0);tiny3d_VertexColor(0xFF000000);
tiny3d_VertexPos(x+200,90,0);tiny3d_VertexColor(0xFF000000);
tiny3d_VertexPos(x+200,110,0);tiny3d_VertexColor(0xFF000000);
tiny3d_VertexPos(x,110,0);tiny3d_VertexColor(0xFF000000);
tiny3d_End();
int w=bars[i]*2;u32 cor=0xFF00FF00;
if(bars[i]<30)cor=0xFFFF0000;else if(bars[i]<60)cor=0xFFFFFF00;
tiny3d_SetPolygon(TINY3D_QUADS);
tiny3d_VertexPos(x,90,0);tiny3d_VertexColor(cor);
tiny3d_VertexPos(x+w,90,0);tiny3d_VertexColor(cor);
tiny3d_VertexPos(x+w,110,0);tiny3d_VertexColor(cor);
tiny3d_VertexPos(x,110,0);tiny3d_VertexColor(cor);
tiny3d_End();}
for(int i=0;i<4;i++){
int x=180+i*250;u32 cor=0xFFFFEB3B;
if(i==selecao)cor=0xFF00FF00;
tiny3d_SetPolygon(TINY3D_QUADS);
tiny3d_VertexPos(x,540,0);tiny3d_VertexColor(cor);
tiny3d_VertexPos(x+200,540,0);tiny3d_VertexColor(cor);
tiny3d_VertexPos(x+200,620,0);tiny3d_VertexColor(cor);
tiny3d_VertexPos(x,620,0);tiny3d_VertexColor(cor);
tiny3d_End();}
tiny3d_Flip();usleep(16000);}
return 0;}