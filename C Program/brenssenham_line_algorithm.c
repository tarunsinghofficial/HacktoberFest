// Line Drawing algo. brensenham's Line Algo

#include<stdio.h>
#include<graphics.h>


void wait_for_char()
{

    //Wait for a key press
    int in = 0;

    while (in == 0) {
        in = getchar();
    }
}


void drawLine(int x1,int y1,int x2,int y2){
	int dx= x2 - x1;
	int dy= y2 - y1;
	int x = x1;
	int y  = y1;
	int p = 2 * dy - dx;
	while(x < x2){
		if(p < 0){
			putpixel(x,y,7);
			p = p + 2*dy;

		}
		if(p >= 0){
			putpixel(x,y,7);
			p  = p + 2*dy-2*dx;
			y = y + 1;

		}

		x++;
	}

}

int main(){
	 int gdriver=DETECT, gmode, error, x1, y1, x2, y2;  
	 x1 = 20;
	 y1 = 10;
	 x2 = 123;
	 y2 = 134;
	 initgraph(&gdriver, &gmode, NULL); 
	// printf("Enter Cordinates x0 y0 x1 y1\n");
	 //scanf("%d %d %d %d",&x0,&y0,&x1,&y1); 

	 drawLine(x1,y1,x2,y2);

   wait_for_char();
   c
