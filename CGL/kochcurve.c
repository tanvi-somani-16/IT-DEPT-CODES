#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#define radian (3.14/180)

void koch(float x1,float y1, float x2, float y2, int n){

    float x3=(2*x1+x2)/3;
    float y3=(2*y1+y2)/3;

    float x4=(2*x2+x1)/3;
    float y4=(2*y2+y1)/3;

    float x=x3+((x4-x3)*cos(60*radian))+((y4-y3)*sin(60*radian));
    float y=y3-((x4-x3)*sin(60*radian))+((y4-y3)*cos(60*radian));

    if(n>0){
        koch(x1,y1,x3,y3,n-1);
        koch(x3,y3,x,y,n-1);
        koch(x,y,x4,y4,n-1);
        koch(x4,y4,x2,y2,n-1);
    }
    else{
        glVertex2f(x1,y1);
        glVertex2f(x3,y3);

        glVertex2f(x3,y3);
        glVertex2f(x,y);

        glVertex2f(x,y);
        glVertex2f(x4,y4);

        glVertex2f(x4,y4);
        glVertex2f(x2,y2);
    }
}

void display(){
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    koch(400,200,800,200,3);
    koch(800,200,600,500,3);
    koch(600,500,400,200,3);
    glEnd();
    gluOrtho2D(0.0,1200.0,0.0,1200.0);
    glFlush();
}

int main (int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1200,1200);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Koch Curve");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}