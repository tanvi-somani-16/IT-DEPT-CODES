#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
int xc, yc,r;
void display(int x, int y){
    glPointSize(1.5);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}

void bcircle(int xc, int yc, int r){
    int d=3-2*r;    //decision parameter
    int x=0,y=r;    // starting points

    while(x<=y){
            display(xc+x,yc+y);
            display(xc+x,yc-y);
            display(xc-x,yc+y);
            display(xc-x,yc-y);
            display(xc+y,yc+x);
            display(xc+y,yc-x);
            display(xc-y,yc+x);
            display(xc-y,yc-x);         

            if(d<0){
                d=d+4*x+6;
            }
            else{
                d=d+4*(x-y)+10;
                y--;
            }
            x++;
    }
}

// int check=1;
// void mouse(int button, int state, int mx, int my){
//     if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
//         if(check){
//             xc=mx;
//             yc=480-my;
//         }
//     }
//     else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
//         glClearColor(1.0,1.0,1.0,0.0);
//         glClear(GL_COLOR_BUFFER_BIT);
//         check=0;
//     }
// }

int x,y;
void render(){
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);

    // mouse(x,y);
    bcircle(x,y,r);
    bcircle(x,y,r/2);                   
    
    bcircle(x+r/2,y,r/2);
    bcircle(x-r/2,y,r/2);
    bcircle(x,y+r/2,r/2);
    bcircle(x,y-r/2,r/2);

    bcircle(x+r/4,y+r/2.25,r/2);
    bcircle(x-r/4,y+r/2.25,r/2);
    bcircle(x+r/4,y-r/2.25,r/2);
    bcircle(x-r/4,y-r/2.25,r/2);

    gluOrtho2D(0.0,1200.0,0.0,800.0);
    glFlush();
}

int main(int argc, char ** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1200,800);
    glutInitWindowPosition(100,100);

    printf("Enter centre coordinates x and y and radius r");
    scanf("%d%d%d",&x,&y,&r);

    glutCreateWindow("Bangle");
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;
}