#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
//convert degree into radian
double ang(int q)
{
return (double)q*3.142/180;
}

int x,y;
void render(){
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);

    bcircle(x,y,2*r);
	
	bcircle((float)x+2*r+0.3*r,y,(float)r*0.3);
	bcircle((float)x,y+2*r+0.3*r,(float)r*0.3);
	bcircle((float)x,y-2*r-0.3*r,(float)r*0.3);
	bcircle((float)x-2*r-0.3*r,y,(float)r*0.3);
	
	bcircle(x+(2*r+0.3*r)*cos(ang(15)),y+(2*r+0.3*r)*sin(ang(15)),(float)r*0.3);
	bcircle(x+(2*r+0.3*r)*cos(ang(30)),y+(2*r+0.3*r)*sin(ang(30)),(float)r*0.3);
	bcircle(x+(2*r+0.3*r)*cos(ang(45)),y+(2*r+0.3*r)*sin(ang(45)),(float)r*0.3);
	bcircle(x+(2*r+0.3*r)*cos(ang(60)),y+(2*r+0.3*r)*sin(ang(60)),(float)r*0.3);
	bcircle(x+(2*r+0.3*r)*cos(ang(75)),y+(2*r+0.3*r)*sin(ang(75)),(float)r*0.3);
	
	bcircle(x-(2*r+0.3*r)*cos(ang(15)),y+(2*r+0.3*r)*sin(ang(15)),(float)r*0.3);
	bcircle(x-(2*r+0.3*r)*cos(ang(30)),y+(2*r+0.3*r)*sin(ang(30)),(float)r*0.3);
	bcircle(x-(2*r+0.3*r)*cos(ang(45)),y+(2*r+0.3*r)*sin(ang(45)),(float)r*0.3);
	bcircle(x-(2*r+0.3*r)*cos(ang(60)),y+(2*r+0.3*r)*sin(ang(60)),(float)r*0.3);
	bcircle(x-(2*r+0.3*r)*cos(ang(75)),y+(2*r+0.3*r)*sin(ang(75)),(float)r*0.3);
	
	bcircle(x-(2*r+0.3*r)*cos(ang(15)),y-(2*r+0.3*r)*sin(ang(15)),(float)r*0.3);
	bcircle(x-(2*r+0.3*r)*cos(ang(30)),y-(2*r+0.3*r)*sin(ang(30)),(float)r*0.3);
	bcircle(x-(2*r+0.3*r)*cos(ang(45)),y-(2*r+0.3*r)*sin(ang(45)),(float)r*0.3);
	bcircle(x-(2*r+0.3*r)*cos(ang(60)),y-(2*r+0.3*r)*sin(ang(60)),(float)r*0.3);
	bcircle(x-(2*r+0.3*r)*cos(ang(75)),y-(2*r+0.3*r)*sin(ang(75)),(float)r*0.3);
	
	bcircle(x+(2*r+0.3*r)*cos(ang(15)),y-(2*r+0.3*r)*sin(ang(15)),(float)r*0.3);
	bcircle(x+(2*r+0.3*r)*cos(ang(30)),y-(2*r+0.3*r)*sin(ang(30)),(float)r*0.3);
	bcircle(x+(2*r+0.3*r)*cos(ang(45)),y-(2*r+0.3*r)*sin(ang(45)),(float)r*0.3);
	bcircle(x+(2*r+0.3*r)*cos(ang(60)),y-(2*r+0.3*r)*sin(ang(60)),(float)r*0.3);
	bcircle(x+(2*r+0.3*r)*cos(ang(75)),y-(2*r+0.3*r)*sin(ang(75)),(float)r*0.3);

	bcircle(x,y,(float)2*r-r*(0.20));

    gluOrtho2D(0.0,1200.0,0.0,1000.0);
    glFlush();
}

int main(int argc, char ** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1200,1000);
    glutInitWindowPosition(100,100);

    printf("Enter centre coordinates x and y and radius r");
    scanf("%d%d%d",&x,&y,&r);

    glutCreateWindow("Bangle");
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;
}