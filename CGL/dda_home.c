#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

void dda(float x1, float y1, float x2, float y2){
    float x,y,xin,yin,dx,dy,step;

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)>abs(dy)){
        step=abs(dx);
    }
    else{
        step=abs(dy);
    }

    xin=dx/step;
    yin=dy/step;

    x=x1;
    y=y1;

    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();

    for(int i=0;i<step;i++){
        x=x+xin;
        y=y+yin;

        glBegin(GL_POINTS);
        glVertex2f(x,y);
        glEnd();
    }
}

float m,n;
void display(){
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    //outer blundary
    dda(m,n,m,n+200);
    dda(m,n+200,m+100,n+400);
    dda(m+100,n+400,m+470,n+475);
    dda(m+470,n+475,m+550,n+300);
    dda(m+550,n+300,m+550,n+100);
    dda(m+550,n+100,m+200,n);
    dda(m+200,n,m,n);
    //inner line
    dda(m,n+200,m+200,n+200);
    dda(m+200,n+200,m+550,n+300);
    dda(m+100,n+400,m+200,n+200);
    dda(m+200,n+200,m+200,n);
    //inner square
    dda(m+50,n+50,m+50,n+150);
    dda(m+50,n+150,m+150,n+150);
    dda(m+150,n+150,m+150,n+50);
    dda(m+150,n+50,m+50,n+50);
    //door
    dda(m+325,n+38,m+325,n+150);
    dda(m+325,n+150,m+400,n+170);
    dda(m+400,n+170,m+400,n+60);
    //proper nhi hai abhi tak pixels ki values 
    gluOrtho2D(0.0,1200.0,0.0,800.0);
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
    glutInitWindowSize(1200,800);
    glutInitWindowPosition(100,100);
    printf("Enter m and n coordinates");
    scanf("%f%f",&m,&n);
    glutCreateWindow("DDA Home");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}