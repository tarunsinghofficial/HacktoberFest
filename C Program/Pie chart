#include<graphics.h>
#include<conio.h>
int main()
{
   int gd = DETECT, gm, midx, midy;

   initgraph(&gd, &gm, "C:\\TC\\BGI");

   setcolor(MAGENTA);
   rectangle(0,40,639,450);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   setcolor(WHITE);
   outtextxy(275,10,"Pie Chart");

   midx = getmaxx()/2;
   midy = getmaxy()/2;

   setfillstyle(LINE_FILL,BLUE);
   pieslice(midx, midy, 0, 75, 100);
   outtextxy(midx+100, midy - 75, "20.83%");

   setfillstyle(XHATCH_FILL,RED);
   pieslice(midx, midy, 75, 225, 100);
   outtextxy(midx-175, midy - 75, "41.67%");

   setfillstyle(WIDE_DOT_FILL,GREEN);
   pieslice(midx, midy, 225, 360, 100);
   outtextxy(midx+75, midy + 75, "37.50%");

   getch();
   return 0;
}
