#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
void gaadi(){
rectangle(280,370,320,430);
}
void rasta(int x,int y1){
line(250+x,0,100+x,450);
line(350+x,0,500+x,450);
//rectangle(200+x,0,400+x,450);
rectangle(295+x,10+y1,305+x,60+y1);
rectangle(295+x,100+y1,305+x,150+y1);
rectangle(295+x,190+y1,305+x,240+y1);
rectangle(295+x,280+y1,305+x,330+y1);
}
void main(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:/TURBOC3/BGI");
rasta(0,0);
int x=0,y=0,y1=0,flag=0;
gaadi();
int score=0,level=0;
char s[100];
while(1){
if(y1==300){flag=0;y1=0;score++;}
int n1=rand()%100,n2=rand()%3,n3;
if(n1%11==0){
if(flag==0){
if(n2==0){
circle(300+x,30+y1,20);flag=1,n3=n2;
}
if(n2==1){
circle(350+x,30+y1,20);flag=1;n3=n2;
}
if(n2==2){
circle(250+x,30+y1,20);flag=1;n3=n2;
}
}
}
cleardevice();
y+=2;
y1+=6;
if(kbhit()){
int key=getch();
cleardevice();
if(key==75){//left
x+=70;
}
if(key==77){
x-=70;
}
if(key=='q')exit(0);
rasta(x,y);
if(flag==1){
if(n3==0)circle(300+x,30+y1,20);
else if(n3==1)circle(350+x,30+y1,20);
else if(n3==2)circle(250+x,30+y1,20);
}
sprintf(s,"Score : %d",score);
outtextxy(0,20,s);
gaadi();
}
//marne ki condition
if((x==70&&y1>=300&&n3==2)||(x==0&&y1>=300&&n3==0)||(x==-70&&y1>=300&&n3==1)){
rasta(x,y);
gaadi();
if(n3==0){circle(300+x,30+y1,20);outtextxy(x+280,y1+50,"BOOM");}
else if(n3==1){circle(350+x,30+y1,20);outtextxy(x+330,y1+50,"BOOM");}
else if(n3==2){circle(250+x,30+y1,20);outtextxy(x+230,y1+50,"BOOM"); }
getch();exit(0);}
if(y==40)y=0;
rasta(x,y);
if(flag==1){
if(n3==0)circle(300+x,30+y1,20);
else if(n3==1)circle(350+x,30+y1,20);
else if(n3==2)circle(250+x,30+y1,20);
}
sprintf(s,"Score : %d",score);
settextstyle(0,0,2);
outtextxy(0,20,s);
gaadi();
delay(30);
}
getch();
}