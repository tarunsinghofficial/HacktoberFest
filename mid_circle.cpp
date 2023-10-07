#include<GL/glut.h>
#include<iostream>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(0,0,255);
    int x=0,y=190,r=y,P=1-r;
    glBegin(GL_POINTS);
        glVertex2d(0,r);
        while(x<=y){
            if(P<0){
                x=x+1;

                P=P+2*x+3;
                glVertex2d(x,y);
                glVertex2d(y,x);
                glVertex2d(-x,y);
                glVertex2d(-y,x);
                glVertex2d(-x,-y);
                glVertex2d(-y,-x);
                glVertex2d(x,-y);
                glVertex2d(y,-x);
            }
            else{
                x=x+1;
                y=y-1;

                P=P+2*(x-y)+5;
                glVertex2d(x,y);
                glVertex2d(y,x);
                glVertex2d(-x,y);
                glVertex2d(-y,x);
                glVertex2d(-x,-y);
                glVertex2d(-y,-x);
                glVertex2d(x,-y);
                glVertex2d(y,-x);
            }
        }
    glEnd();
    glFlush();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400,300);
    glutInitWindowPosition(300,300);
    glutCreateWindow("Mid_Circle");
    gluOrtho2D(-500,500,-500,500);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}