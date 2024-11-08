#include<GL/gl.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

void display(int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
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

void bla(int x1, int y1, int x2, int y2){
    int dx,dy,x,y,xin,yin,p;

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    if(x1>x2){
        xin=-1;
    }
    else{
        xin=1;
    }
    if(y1>y2){
        yin=-1;
    }
    else{
        yin=1;
    }

    x=x1;
    y=y1;

    //line is more horizontal than vertical
    if(dx>dy){
        display(x,y);
        p=2*dy-dx;

        for(int i=0;i<dx;i++){
            if(p>=0){ 
                p=p+2*(dy-dx);
                y=y+yin;
            }
            else{
                p=p+2*dy;
            }
            x=x+xin;
            display(x,y);
        }
    }
    //line is more vertical then horizontal
    else{
        display(x,y);
        p=2*dx-dy;

        for(int i=0;i<dy;i++){
            if(p>=0){
                p=p+2*(dx-dy);
                x=x+xin;
            }
            else{
                p=p+2*dx;
            }
            y=y+yin;
            display(x,y);
        }
    }
}

int m,n;
void render(){
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);

    //draw front part of truck
    bla(m,n,m,n+250);
    bla(m,n+250,m+200,n+350);
    bla(m+200,n+350,m+300,n+350);
    bla(m+300,n+350,m+300,n+500);
    bla(m+300,n+500,m+400,n+500);
    bla(m+400,n+500,m+400,n);
    bla(m+400,n,m,n);

    //draw inner square
    bla(m+200,n+200,m+200,n+300);
    bla(m+200,n+300,m+300,n+300);
    bla(m+300,n+300,m+300,n+200);
    bla(m+300,n+200,m+200,n+200);

    //draw inner ka inner square
    bla(m+225,n+225,m+225,n+275);
    bla(m+225,n+275,m+275,n+275);
    bla(m+275,n+275,m+275,n+225);
    bla(m+275,n+225,m+225,n+225);

    //draw end part of truck
    bla(m+410,n,m+410,n+500);
    bla(m+410,n+500,m+900,n+500);
    bla(m+900,n+500,m+900,n);
    bla(m+900,n,m+410,n);

    gluOrtho2D(0.0,1200.0,0.0,1200.0);
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1200,1200);
    glutInitWindowPosition(50,50);
    printf("Enter the coordinates m and n");
    scanf("%d%d",&m,&n);
    glutCreateWindow("Truck");
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;
}
