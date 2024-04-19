#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
void main()
{
int a,gd=DETECT,gm,d,i,c=200, s=190,f=210,t,r,v=180,b=210,m,n,speed=8;
int arr[]={400,300,410,330,410,330,390,330,390,330,400,300};
system("cls");
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
for(a=1;a<=17&&!kbhit();a++)
{
   t=s,r=f;
   m=v,n=b;
   for(i=300;i<=315&&!kbhit();i++)
   {
     gotoxy(29,2);printf("Credit = Joerush");
     line(1,350,630,350);
     ellipse(400,273,-10,200,15,20);  ellipse(401,273,-10,200,15,20);
     ellipse(405,268,0,360,2,3);      ellipse(395,268,0,360,2,3);
     putpixel(395,269,15);        putpixel(405,269,15);
     line(398,274,403,274);         line(399,274,404,274);
     line(414,279,407,279);           line(415,279,408,279);
     line(386,279,394,279);           line(387,279,395,279);
     circle(400,270,10);         circle(401,270,10);
     line(400,300,400,280);       line(401,300,401,280);
     line(400,280,410,290);       line(401,280,411,290);
     line(410,290,400,300);       line(411,290,401,300);
     line(400,280,390,290);       line(401,280,391,290);
     line(390,290,400,300);       line(391,290,401,300);
     fillpoly(6,arr);
     line(395,330,395,350);       line(396,330,396,350);
     line(405,330,405,350);       line(406,330,406,350);
     line(1,351,630,351);
     circle(c,270,10); circle(c+1,270,10);
     ellipse(c+5,269,0,360,2,3); putpixel(c+5,269,15);
     line(c+3,276,c+8,276);
     line(c,280,c,320); line(c+1,280,c+1,320);
     line(c,280,n,298); line(c+1,280,n+1,298);
     line(n,298,(b+10),292); line(n+1,298,(b+11),292);
     circle(n+10,281,2); circle(n+11,281,2);
     circle(n+10,278,2);   circle(n+11,278,2);
     circle(n+15,280,2); circle(n+16,280,2);
     circle(n+5,280,2); circle(n+6,280,2);
     line(n+10,292,n+10,285); line(n+11,292,n+11,285);
     line(c+1,320,r-=1,350);
     line(c,320,t+=1,350);
     delay(100);
     if(a==17)
     goto zx;
     cleardevice();
   }
   c+=speed;
   s+=speed,f+=speed,v+=speed,b+=speed;
}
zx:
{
ellipse(375,231,0,360,60,15);  ellipse(376,231,0,360,60,15);
line(360,245,335,260);   line(361,245,336,260);
gotoxy(45,15);setcolor(13);outtextxy(337,227,"I LOVE YOU");fflush(stdout);
gotoxy(45,17); gotoxy(46,17);printf("%c",3);fflush(stdout);
}
getch();
closegraph();
}
