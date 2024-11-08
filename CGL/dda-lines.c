#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

void dda_simple(float x1, float y1, float x2, float y2){
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

void dda_dotted(float x1, float y1, float x2, float y2){
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

        if(i%3==0){
            glBegin(GL_POINTS);
            glVertex2f(x,y);
            glEnd();
        }
    }
}

void dda_dashed(float x1, float y1, float x2, float y2){
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

        if(i%7==0){
            glBegin(GL_POINTS);
            glVertex2f(x,y);
            glEnd();
        } 
    }
}

float m,n;
void display(){
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);

    dda_simple(m,n+200,m+600,n+600);
    dda_dashed(m,n,m+600,n);
    dda_dotted(m+200,n+200,m+400,n+400);
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
    glutCreateWindow("DDA LINES");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}