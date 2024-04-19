#include<graphics.h>
#include<iostream.h>
#include <conio.h>
void main()
{
start: int a[3][3]={5,6,7,8,9,10,11,12,13},i,j,k,x,y,t,cn=0,co=0;
char c;
static int nod=0,nn=0,sc[2]={0,0};
nod++;
clrscr();
int driver=DETECT,mode;
initgraph(&driver,&mode,"c:\tc\bgi");
setbkcolor(RED);
line(100,200,400,200);
line(100,300,400,300);
line(200,100,200,400);
line(300,100,300,400);
gotoxy(20,2);
cout<<"TIC TAC TOE";
gotoxy(20,3);
cout<<"Unregistered Vesion 1.0";
gotoxy(10,5);cout<<" BOX NO ";
gotoxy(15,7);cout<<"0";
gotoxy(30,7);cout<<"1";
gotoxy(45,7);cout<<"2";
gotoxy(15,14);cout<<"3";
gotoxy(30,14);cout<<"4";
gotoxy(45,14);cout<<"5";
gotoxy(15,21);cout<<"6";
gotoxy(30,21);cout<<"7";
gotoxy(45,21);cout<<"8";
gotoxy(55,22);cout<<"RESULT";
gotoxy(55,23);cout<<"*************************";
gotoxy(55,15);cout<<"P1-"<<sc[0];
gotoxy(55,16);cout<<"P2-"<<sc[1];
for(i=0;i<=2;i++)
{
for(j=0;j<=2;j++)
{ re:gotoxy(65,4);
k=((i+j)%2+1);
cout<<"Enter player"<<k;
gotoxy(60,5);
cout<<" Box no from 0 to 8 ";
gotoxy(58,6);cout<<"[ ]";
gotoxy(60,6);
t=getch();
t=t-48;
if(t==0){x=0;y=0;goto play;}
if(t==1){x=1;y=0;goto play;}
if(t==2){x=2;y=0;goto play;}
if(t==3){x=0;y=1;goto play;}
if(t==4){x=1;y=1;goto play;}
if(t==5){x=2;y=1;goto play;}
if(t==6){x=0;y=2;goto play;}
if(t==7){x=1;y=2;goto play;}
if(t==8){x=2;y=2;goto play;}
else
{goto re ;}
play:
if((a[x][y]==1)||(a[x][y]==2))
{goto re;}
if((a[x][y]!=1)&&(a[x][y]!=2))
{ if(k==1)
{circle(100*x+100+50,100*y+100+50,50);
a[x][y]=k;co++;} if(k==2)
{line(x*100+100,y*100+100,x*100+200,y*100+200);
line(x*100+100,y*100+200,x*100+200,y*100+100);
a[x][y]=k;co++;}
}
gotoxy(60,23);
if((a[0][0]==a[1][0])&&(a[1][0]==a[2][0]))
{cout<<"Player "<<k<<" wins";cn=1;sc[k-1]++;}
if((a[0][0]==a[0][1])&&(a[0][1]==a[0][2]))
{cout<<"Player "<<k<<" wins";cn=1;sc[k-1]++;}
if((a[0][0]==a[1][1])&&(a[1][1]==a[2][2]))
{cout<<"Player "<<k<<" wins";cn=1;sc[k-1]++;}
if((a[1][0]==a[1][1])&&(a[1][1]==a[1][2]))
{cout<<"Player "<<k<<" wins";cn=1;sc[k-1]++;}
if((a[2][0]==a[2][1])&&(a[2][1]==a[2][2]))
{cout<<"Player "<<k<<" wins";cn=1;sc[k-1]++;}
if((a[2][0]==a[1][1])&&(a[1][1]==a[0][2]))
{cout<<"Player "<<k<<" wins";cn=1;sc[k-1]++;}
if((a[0][2]==a[1][2])&&(a[1][2]==a[2][2]))
{cout<<"Player "<<k<<" wins";cn=1;sc[k-1]++;}
if((a[0][1]==a[1][1])&&(a[1][1]==a[2][1]))
{cout<<"Player "<<k<<" wins";cn=1;sc[k-1]++;}
if(cn==1)
{goto que;}
if(co==9)
{gotoxy(62,23);
cout<<"DRAW";
nn++;
goto que;}
}
}
que:
gotoxy(60,24);
cout<<"Play again y/n";
c=getch();
if((c=='y')||(c=='Y'))
{ goto start;}
else if((c=='n')||(c=='N'))
{goto end;}
else goto que;
end:
closegraph();
cout<<"Final score is "<<sc[k-1]<<"-"<<nod-nn-sc[k-1];
gotoxy(20,10);
cout<<"Thanks for playing this game";
getch();
}
