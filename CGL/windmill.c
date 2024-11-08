#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int framenumber=0;

void drawmill(){
    //POLL OF POLYGON
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05,0);
    glVertex2f(-0.05,3);
    glVertex2f(0.05,3);
    glVertex2f(0.05,0);
    glEnd();

    //DRAWING FINS
    glTranslatef(0.,3,0);//translates the coordinate system to uppper part of poll

    glColor3f(1.0,0.0,0.0);
    glRotated(framenumber*(180.0/45),0,0,1);//rotating speed of the fins

    for(int i=0;i<4;i++){
        glRotated(90,0,0,1);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(1.0f,-0.2f);
        glVertex2f(1.0f,0.2f);
        glEnd();
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslated(2.2,1.6,0);
    glScaled(0.4,0.4,1);
    drawmill();
    glPopMatrix();

    glPushMatrix();
    glTranslated(3.7,0.8,0);
    glScaled(0.7,0.7,1);
    drawmill();
    glPopMatrix();

    glutSwapBuffers();
}

void doframe(int v){
    framenumber++;
    glutPostRedisplay();
    glutTimerFunc(10,doframe,0);
}

void init(){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,7,-1,4,-1,1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Windmill");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(200,doframe,0);
    glutMainLoop();
    return 0;
}