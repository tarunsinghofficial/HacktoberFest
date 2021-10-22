Caught in the Middle - Game

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>

enum dir direction;  
/*indicates the direction of the shooter*/
int fire(int xco,int yco,int &lr,int &tb,int &rl,int &bt);
/*shoots place check for hit*/
/*The most complex function flashes the green boxes and*/
/*records their coordinates*/
int environment(int xposition,int yposition,int position_array_location);
int match(void);                  
/*checks the fired location and the locations of the boxes*/
int put_banner(void);              
/*banner at the end of game*/
/*structure to record the position of boxes*/
//void refresh();
struct position
{
	int x_pos;
	int y_pos;
};
struct position p[10];
/*array to record the locations of boxes*/
struct position sh;
/*variable to record the location of the shooter*/
enum dir{EAST,WEST,SOUTH,NORTH};
/*enum to indicate direction*/
unsigned int hitcount=0;
void main()
{
int gdriver = DETECT;
int gmode;
int ch,is_hit;
int x=350,y=200;/*x,y coordinates*/
/*variables used to move around boxes*/
int i=0,j=320,k=400,l=0,m=800,n=200,p=600,o=300;
int iflag,lflag,mflag,pflag;
/*flag to indicate which box has been hit*/
initgraph(&gdriver,&gmode,"c:\tc\bgi");
/*initiating graphics*/
setcolor(YELLOW);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
/*Drawing the initial banners*/
outtextxy((getmaxx()/2)-260,(getmaxy()/2)-20,""CAUGHT IN THE MIDDLE"");
setcolor(WHITE);
outtextxy(100,50,"Use "arrow" key to move");
outtextxy(100,100,"Use "enter" to fire");
/*drawing banner completed*/
getch();
settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
setbkcolor(BLUE);
delay(1000);
cleardevice();
x=getmaxx()/2;y=getmaxy()/2;
moveto(x,y);
do
{
/*draws the shooter*/
setfillstyle(SOLID_FILL,WHITE);
circle(x,y,10);
floodfill(x,y,WHITE);
circle(x,y,20);
line(x,y-20,x,y+20);
line(x-20,y,x+20,y);
/*draws the shooter*/
//refresh();
iflag=0,lflag=0,mflag=0,pflag=0;
while(!kbhit())
/*until the keyboard is hit boxes are flashed*/
{
	i=i%800;
	l=l%600;
	if(m<=0)m+=800;
	if(p<=0)p+=600;
	environment(i,j,0);
	/*moves from left to right*/
	environment(k,l,1);
	/*moves from top to bottom*/
	environment(m,n,2);
	/*moves from right to left*/
	environment(o,p,3);
	/*moves from bottom to top*/
	i+=20;
	l+=20;
	m-=20;
	p-=20;
	if(i>=800) j=rand()%600;
	if(l>=600) k=rand()%800;
	if(m<=0) n=rand()%600;
	if(p<=0) o=rand()%800;
}
ch =getch();                
/*gets key from user*/
/*key board is hit*/
setfillstyle(SOLID_FILL,BLUE);
/*draws a block to erase shooter at previous position*/
bar(x+20,y+20,x-20,y-20);
x=getx();
y=gety();
sh.x_pos=x;                    
/*gets the shooter position*/
sh.y_pos=y;
setfillstyle(SOLID_FILL,WHITE);
/*draws the shooter*/
circle(x,y,10);
floodfill(x,y,WHITE);
circle(x,y,20);
line(x,y-20,x,y+20);
line(x-20,y,x+20,y);
setfillstyle(SOLID_FILL,BLUE);
bar(x+20,y+20,x-20,y-20);
outtextxy(240,10,"HIT CTRL+Z TO QUIT");
switch(ch)
{
	case 72:/*up arrow*/
	direction=NORTH;
	x=getx();
	y=gety();
	moveto(x,y-20);
	x=getx();
	y=gety();
	sh.x_pos=x;
	sh.y_pos=y;
	setfillstyle(SOLID_FILL,WHITE);
	circle(x,y,10);
	floodfill(x,y,WHITE);
	circle(x,y,20);
	line(x,y-20,x,y+20);
	line(x-20,y,x+20,y);
	break;
	case 80:/*down arrow*/
	direction=SOUTH;
	x=getx();
	y=gety();
	moveto(x,y+20);
	x=getx();
	y=gety();
	sh.x_pos=x;
	sh.y_pos=y;
	setfillstyle(SOLID_FILL,WHITE);
	circle(x,y,10);
	floodfill(x,y,WHITE);
	circle(x,y,20);
	line(x,y-20,x,y+20);
	line(x-20,y,x+20,y);
	break;
	case 75:/*left arrow*/
	direction=WEST;
	x=getx();
	y=gety();
	moveto(x-20,y);
	x=getx();
	y=gety();
	sh.x_pos=x;
	sh.y_pos=y;
	setfillstyle(SOLID_FILL,WHITE);
	circle(x,y,10);
	floodfill(x,y,WHITE);
	circle(x,y,20);
	line(x,y-20,x,y+20);
	line(x-20,y,x+20,y);
	break;
	case 77:/*right arrow*/
	direction=EAST;
	x=getx();
	y=gety();
	moveto(x+20,y);
	x=getx();
	y=gety();
	sh.x_pos=x;
	sh.y_pos=y;
	setfillstyle(SOLID_FILL,WHITE);
	circle(x,y,10);
	floodfill(x,y,WHITE);
	circle(x,y,20);
	line(x,y-20,x,y+20);
	line(x-20,y,x+20,y);
	break;
	case 13:/*enter key*/
	x=getx();
	y=gety();
	sh.x_pos=x;
	sh.y_pos=y;
	is_hit=fire(x,y,iflag,lflag,mflag,pflag);
	/*flags r passed by reference*/
	if(is_hit==1)
	{
		hitcount++;
		if(iflag)i+=800;
		else if(lflag)k+=600;
		else if(mflag)m=0;
		else if(pflag)p=0;
		iflag=0;lflag=0;mflag=0;pflag=0; /*flag reset*/
	}
	x=getx();
	y=gety();
	setfillstyle(SOLID_FILL,WHITE);
	circle(x,y,10);
	floodfill(x,y,WHITE);
	circle(x,y,20);
	line(x,y-20,x,y+20);
	line(x-20,y,x+20,y);
	break;
}
}while(ch!=26);
closegraph();
restorecrtmode();
gotoxy(30,12);
textcolor(YELLOW);
cprintf("YOU HAVE SCORED :%d",hitcount);/*score is indicated*/
getch();
}

/*function fire draws ans erases a line along the current direction*/
int fire(int x,int y,int <r,int &ttb,int &rtl,int &btt)
{
int i=0,hit=0;
switch(direction)
{
case EAST:/*right*/

	
if(sh.y_pos>=p[i].y_pos-20&&sh.y_pos<=p[i].y_pos+20&&sh.x_pos<p[i].x_pos)
	{
	hit=1;
	switch(i)
	{
		case 0: ltr=1; break;
		case 1: ttb=1; break;
		case 2: rtl=1; break;
		case 3: btt=1; break;
	}
	}
	else
if(sh.y_pos>=p[i+1].y_pos-20&&sh.y_pos<=p[i+1].y_pos+20&&sh.x_pos<p[i+1].x_pos)
	{
	hit=1;
	switch(i+1)
	{
		case 0: ltr=1; break;
		case 1: ttb=1; break;
		case 2: rtl=1; break;
		case 3: btt=1; break;
	}
	}
	else
if(sh.y_pos>=p[i+2].y_pos-20&&sh.y_pos<=p[i+2].y_pos+20&&sh.x_pos<p[i+2].x_pos)
	{
	hit=1;
	switch(i+2)
	{
		case 0: ltr=1; break;
		case 1: ttb=1; break;
		case 2: rtl=1; break;
		case 3: btt=1; break;
	}
	}
	else
if(sh.y_pos>=p[i+3].y_pos-20&&sh.y_pos<=p[i+3].y_pos+20&&sh.x_pos<p[i+3].x_pos)
	{
	hit=1;
	switch(i+3)
	{
		case 0: ltr=1; break;
		case 1: ttb=1; break;
		case 2: rtl=1; break;
		case 3: btt=1; break;
	}
	}
setcolor(YELLOW);
line(x+20,y,x+800,y);
setcolor(BLUE);
delay(100);
line(x+20,y,x+800,y);
setcolor(WHITE);
break;
case WEST:/*left*/
	
if(sh.y_pos>=p[i].y_pos-20&&sh.y_pos<=p[i].y_pos+20&&sh.x_pos>p[i].x_pos)
	{
	hit=1;
	switch(i)
	{
		case 0: ltr=1; break;
		case 1: ttb=1; break;
		case 2: rtl=1; break;
		case 3: btt=1; break;
	}
	}
	else
if(sh.y_pos>=p[i+1].y_pos-20&&sh.y_pos<=p[i+1].y_pos+20&&sh.x_pos>p[i+1].x_pos)
	{
	hit=1;
	switch(i+1)
	{
		case 0: ltr=1; break;
		case 1: ttb=1; break;
		case 2: rtl=1; break;
		case 3: btt=1; break;
	}
	}
	else
if(sh.y_pos>=p[i+2].y_pos-20&&sh.y_pos<=p[i+2].y_pos+20&&sh.x_pos>p[i+2].x_pos)
	{
	hit=1;
	switch(i+2)
	{
		case 0: ltr=1; break;
		case 1: ttb=1; break;
		case 2: rtl=1; break;
		case 3: btt=1; break;
	}
	}
	else
if(sh.y_pos>=p[i+3].y_pos-20&&sh.y_pos<=p[i+3].y_pos+20&&sh.x_pos>p[i+3].x_pos)
	{
	hit=1;
	switch(i+3)
	{
		case 0: ltr=1; break;
		case 1: ttb=1; break;
		case 2: rtl=1; break;
		case 3: btt=1; break;
	}
	}
setcolor(YELLOW);
line(x-20,y,x-800,y);
setcolor(BLUE);
delay(100);
line(x-20,y,x-800,y);
setcolor(WHITE);
break;
case SOUTH:/*down*/

	
if(sh.x_pos>=p[i].x_pos-20&&sh.x_pos<=p[i].x_pos+20&&sh.y_pos<p[i].y_pos)
	{
	hit=1;
	switch(i)
	{
		case 0: ltr=1; break;
		case 1: ttb=1; break;
		case 2: rtl=1; break;
		case 3: btt=1; break;
	}
	}
	else
if(sh.x_pos>=p[i+1].x_pos-20&&sh.x_pos<=p[i+1].x_pos+20&&sh.y_pos<p[i+1].y_pos)
	{
	hit=1;
	switch(i+1)
	{
		case 0: ltr=1; break;
		case 1: ttb=1; break;
		case 2: rtl=1; break;
		case 3: btt=1; break;
	}
	}
	else
if(sh.x_pos>=p[i+2].x_pos-20&&sh.x_pos<=p[i+2].x_pos+20&&sh.y_pos<p[i+2].y_pos)
	{
	hit=1;
	switch(i+2)
	{
		case 0: ltr=1; break;
		case 1: ttb=1; break;
		case 2: rtl=1; break;
		case 3: btt=1; break;
	}
	}
	else
if(sh.x_pos>=p[i+3].x_pos-20&&sh.x_pos<=p[i+3].x_pos+20&&sh.y_pos<p[i+3].y_pos)
	{
	hit=1;
	switch(i+3)
	{
		case 0: ltr=1; break;
		case 1: ttb=1; break;
		case 2: rtl=1; break;
		case 3: btt=1; break;
	}
	}
setcolor(YELLOW);
line(x,y+20,x,y+800);
setcolor(BLUE);
delay(100);
line(x,y+20,x,y+800);
setcolor(WHITE);
break;
case NORTH:/*up*/
	
if(sh.x_pos>=p[i].x_pos-20&&sh.x_pos<=p[i].x_pos+20&&sh.y_pos>p[i].y_pos)
	{
	hit=1;
	switch(i)
	{
		case 0: ltr=1; break;
		case 1: ttb=1; break;
		case 2: rtl=1; break;
		case 3: btt=1; break;
	}
	}
	else
if(sh.x_pos>=p[i+1].x_pos-20&&sh.x_pos<=p[i+1].x_pos+20&&sh.y_pos>p[i+1].y_pos)
	{
	hit=1;
	switch(i+1)
	{
		case 0: ltr=1; break;
		case 1: ttb=1; break;
		case 2: rtl=1; break;
		case 3: btt=1; break;
	}
	}
	else
if(sh.x_pos>=p[i+2].x_pos-20&&sh.x_pos<=p[i+2].x_pos+20&&sh.y_pos>p[i+2].y_pos)
	{
	hit=1;
	switch(i+2)
	{
		case 0: ltr=1; break;
		case 1: ttb=1; break;
		case 2: rtl=1; break;
		case 3: btt=1; break;
	}
	}
	else
if(sh.x_pos>=p[i+3].x_pos-20&&sh.x_pos<=p[i+3].x_pos+20&&sh.y_pos>p[i+3].y_pos)
	{
	hit=1;
	switch(i+3)
	{
		case 0: ltr=1; break;
		case 1: ttb=1; break;
		case 2: rtl=1; break;
		case 3: btt=1; break;
	}
	}
setcolor(YELLOW);
line(x,y-20,x,y-800);
setcolor(BLUE);
delay(100);
line(x,y-20,x,y-800);
setcolor(WHITE);
break;
}
for(i=0;i<=3;i++)
{
  p[i].x_pos=0;
  p[i].y_pos=0;
}
/*refreshing the record*/
return(hit);
/*	of a positions*/
}

/*draws the green boxes */
int environment(int x,int y,int pos)
{
int i;
p[pos].x_pos=x;
p[pos].y_pos=y;
/*conditions to check for collision
checks whether the center of box x,y is within the area
(sh_xpos-20,sh_ypos-20)
(sh_xpos+20,sh_ypos+20)*/
if(x>=sh.x_pos-20&&x<=sh.x_pos+20&&y>=sh.y_pos-20&&y<=sh.y_pos+20)
{
	put_banner();
	getch();
	closegraph();
	restorecrtmode();
	gotoxy(30,12);
	textcolor(YELLOW);
	cprintf("YOU HAVE SCORED :%d",hitcount);
	getch();
	exit(0);
}
setfillstyle(SOLID_FILL,LIGHTGREEN);
bar(x-10,y-10,x+10,y+10);
delay(20);
setfillstyle(SOLID_FILL,BLUE);
bar(x-10,y-10,x+10,y+10);
setcolor(WHITE);
return(0);
}

/*puts a banner at the End of Game*/
int put_banner()
{
setcolor(YELLOW);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
outtextxy((getmaxx()/2)-260,(getmaxy()/2)-20,"SORRY YOU`VE BEEN HIT");
return 0;
}

void refresh(void)
{
int i;
for(i=0;i<4;i++)
{
	p[i].x_pos=0;
	p[i].y_pos=0;
}
}
