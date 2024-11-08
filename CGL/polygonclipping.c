#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//structure to hold the values of points
typedef struct 
{
    float x;
    float y;
}PT;

//no of vertices
int n;
int i,j;

//p1 and p2 are min max values of clipping window and p[]is original values array and pp[]is after clipping values array
PT p1,p2,p[20],pp[20];

//left clipper
void left(){
    i=0;
    j=0;
    for(i=0;i<n;i++){
        //case 1:outside to inside
        if(p[i].x<p1.x && p[i+1].x>=p1.x){
            if(p[i+1].x-p[i].x!=0){
                pp[j].y=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x)*(p1.x-p[i].x)+p[i].y;
            }
            else{
                pp[j].y=p[j].y;
            }
            pp[j].x=p1.x;
            j++;
            pp[j+1].x=p[i+1].x;
            pp[j+1].y=p[i+1].y;
            j++;
        }
        //case 2:inside to inside
        if(p[i].x>=p1.x && p[i+1].x>=p1.x){
            pp[j].x=p[i+1].x;
            pp[j].y=p[i+1].y;
            j++;
        }
        //case 3:inside to outside
        if(p[i].x>=p1.x && p[i+1].x<p1.x){
            if(p[i+1].x-p[i].x!=0){
                pp[j].y=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x)*(p1.x-p[i].x)+p[i].y;
            }
            else{
                pp[j].y=p[j].y;
            }
            pp[j].x=p1.x;
            j++; 
        }
    }
    //coping the values of clipped ;olygon in actual one
    //defining the last vertex as the first one to make a closed polygon and updating the no of vertices
    for (i = 0; i < j; i++)
    {
        p[i].x = pp[i].x;
        p[i].y = pp[i].y;
    }
 
    p[i].x = pp[0].x;
    p[i].y = pp[0].y;
    n = j;
}

//right clipper
void right(){
    i=0;
    j=0;
    for(i=0;i<n;i++){
        //case 1:outside to inside
        if(p[i].x>p2.x && p[i+1].x<=p2.x){
            if(p[i+1].x-p[i].x!=0){
                pp[j].y=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x)*(p2.x-p[i].x)+p[i].y;
            }
            else{
                pp[j].y=p[j].y;
            }
            pp[j].x=p2.x;
            j++;
            pp[j+1].x=p[i+1].x;
            pp[j+1].y=p[i+1].y;
            j++;
        }
        //case 2:inside to inside
        if(p[i].x<=p2.x && p[i+1].x<=p2.x){
            pp[j].x=p[i+1].x;
            pp[j].y=p[i+1].y;
            j++;
        }
        //case 3:inside to outside
        if(p[i].x<=p2.x && p[i+1].x>p2.x){
            if(p[i+1].x-p[i].x!=0){
                pp[j].y=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x)*(p2.x-p[i].x)+p[i].y;
            }
            else{
                pp[j].y=p[j].y;
            }
            pp[j].x=p2.x;
            j++; 
        }
    }
    //coping the values of clipped ;olygon in actual one
    //defining the last vertex as the first one to make a closed polygon and updating the no of vertices
    for (i = 0; i < j; i++)
    {
        p[i].x = pp[i].x;
        p[i].y = pp[i].y;
    }
 
    p[i].x = pp[0].x;
    p[i].y = pp[0].y;
    n = j;
}

//bottom clipper
void bottom(){
    i=0;
    j=0;
    for(i=0;i<n;i++){
        //case 1:outside to inside
        if(p[i].y<p1.y && p[i+1].y>=p1.y){
            if(p[i+1].y-p[i].y!=0){
                pp[j].x=(p[i+1].x-p[i].x)/(p[i+1].y-p[i].y)*(p1.y-p[i].y)+p[i].x;
            }
            else{
                pp[j].x=p[j].x;
            }
            pp[j].y=p1.y;
            j++;
            pp[j+1].x=p[i+1].x;
            pp[j+1].y=p[i+1].y;
            j++;
        }
        //case 2:inside to inside
        if(p[i].y>=p1.y && p[i+1].y>=p1.y){
            pp[j].x=p[i+1].x;
            pp[j].y=p[i+1].y;
            j++;
        }
        //case 3:inside to outside
        if(p[i].y>=p1.y && p[i+1].y<p1.y){
            if(p[i+1].y-p[i].y!=0){
                pp[j].x=(p[i+1].x-p[i].x)/(p[i+1].y-p[i].y)*(p1.y-p[i].y)+p[i].x;
            }
            else{
                pp[j].x=p[j].x;
            }
            pp[j].y=p1.y;
            j++; 
        }
    }
    //coping the values of clipped ;olygon in actual one
    //defining the last vertex as the first one to make a closed polygon and updating the no of vertices
    for (i = 0; i < j; i++)
    {
        p[i].x = pp[i].x;
        p[i].y = pp[i].y;
    }
 
    p[i].x = pp[0].x;
    p[i].y = pp[0].y;
    n = j;
}

//top clipper
void top(){
    i=0;
    j=0;
    for(i=0;i<n;i++){
        //case 1:outside to inside
        if(p[i].y>p2.y && p[i+1].y<=p2.y){
            if(p[i+1].y-p[i].y!=0){
                pp[j].x=(p[i+1].x-p[i].x)/(p[i+1].y-p[i].y)*(p2.y-p[i].y)+p[i].x;
            }
            else{
                pp[j].x=p[j].x;
            }
            pp[j].y=p2.y;
            j++;
            pp[j+1].x=p[i+1].x;
            pp[j+1].y=p[i+1].y;
            j++;
        }
        //case 2:inside to inside
        if(p[i].y<=p2.x && p[i+1].y<=p2.x){
            pp[j].x=p[i+1].x;
            pp[j].y=p[i+1].y;
            j++;
        }
        //case 3:inside to outside
        if(p[i].y<=p2.y && p[i+1].y>p2.y){
            if(p[i+1].y-p[i].y!=0){
                pp[j].x=(p[i+1].x-p[i].x)/(p[i+1].y-p[i].y)*(p2.y-p[i].y)+p[i].x;
            }
            else{
                pp[j].x=p[j].x;
            }
            pp[j].y=p2.y;
            j++; 
        }
    }
    //coping the values of clipped ;olygon in actual one
    //defining the last vertex as the first one to make a closed polygon and updating the no of vertices
    for (i = 0; i < j; i++)
    {
        p[i].x = pp[i].x;
        p[i].y = pp[i].y;
    }
 
    p[i].x = pp[0].x;
    p[i].y = pp[0].y;
    n = j;
}

void draw(){
    glColor3f(1.0,1.0,1.0);
    for(int i=0;i<n-1;i++){
        glBegin(GL_LINES);
        glVertex2f(p[i].x,p[i].y);
        glVertex2f(p[i+1].x,p[i+1].y);
        glEnd();
    }
    glBegin(GL_LINES);
    glVertex2d(p[i].x, p[i].y);
    glVertex2d(p[0].x, p[0].y);
    glEnd();
}

void mouse(int button, int state, int x, int y){
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_LINE_LOOP);
        glVertex2f(p1.x,p1.y);
        glVertex2f(p1.x,p2.y);
        glVertex2f(p2.x,p2.y);
        glVertex2f(p2.x,p1.y);
        glEnd();

        left();
        right();
        bottom();
        top();

        draw();
    }
    glFlush();
}

void display(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(p1.x,p1.y);
    glVertex2f(p1.x,p2.y);
    glVertex2f(p2.x,p2.y);
    glVertex2f(p2.x,p1.y);
    glEnd();
    draw();
    gluOrtho2D(0.0,1200.0,0.0,800.0);
    glFlush();
}

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0); // clear screen usually black
    gluOrtho2D(0, 1200, 0, 800);
}

int main(int argc, char ** argv){

    printf("Enter P1(x,y):\n");
    scanf("%f", &p1.x); // if you don't know what value should be given: enter 200
    scanf("%f", &p1.y); // if you don't know what value should be given: enter 200
 
    printf("Enter P2(x,y):\n"); // P2(x,y) is the top right point for clipping window
    scanf("%f", &p2.x);         // if you don't know what value should be given: enter 400
    scanf("%f", &p2.y);         // if you don't know what value should be given: enter 400

    printf("\nEnter the no. of vertices:");
    scanf("%d", &n);
 
    for(int i=0;i<n;i++){
        printf("\nEnter V%d(x%d,y%d):\n", i + 1, i + 1, i + 1);
        scanf("%f", &p[i].x); 
        scanf("%f", &p[i].y);
    }
    
     p[i].x = p[0].x; // Assign last to first for connected everything
    p[i].y = p[0].y;
 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Sutherland Hodgman Polygon Clipping Algorithm ");
 
    glutDisplayFunc(display);
    glutMouseFunc(mouse); // notice mouse movement and call user defined function
    glFlush();
    glutMainLoop();
    return 0;
}

