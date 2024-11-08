#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int length,xi,yi,choice;
double et[3][3], etresult[3][3];
double angle;
//et is transformation matrix and etresult is final matrix obtained 

//this is function to draw the shape, it is column matrix
void drawet(double et[3][3]){
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<3;i++){
        glVertex2i(et[i][0],et[i][1]);
    }
    glEnd();
}

void display(){
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();   //this function is used to replace the current matrix with the identity matrix after every call for display
    gluOrtho2D(-320,320,-240,240);
    //drawing the X and Y axes
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2d(-320,0);
    glVertex2d(320,0);
    glVertex2d(0,-240);
    glVertex2d(0,240);
    glEnd();
    glColor3f(1,0,0);
    drawet(et);
    glFlush();    
}

//this function is used for multiplying the transformation matrix with the given values and stores the value of sum of multipliacation in sum variable
void mult(double et[3][3],double temp[3][3]){
    double sum;
    int i,j,k;
    // i and j variables are for selecting the row and column and k is for selecting the element in that row and column
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            sum=0;
            for(k=0;k<3;k++){
                sum=sum+et[i][k]*temp[k][j];
            }
            etresult[i][j]=sum;
        }
    }
}

/*-------Translation---------*/
void translation(){
    double tx,ty,temp[3][3];
    printf("\n Enter tx : ");
    scanf("%lf",&tx);
    printf("\n Enter ty : ");
    scanf("%lf",&ty);

    temp[0][0]=1;
    temp[1][1]=1;
    temp[2][2]=1;
    temp[2][0]=tx;
    temp[2][1]=ty;
    temp[0][1]=0;
    temp[0][2]=0;
    temp[1][0]=0;
    temp[1][2]=0;
    
    mult(et,temp);
    glColor3f(1.0,1.0,1.0);
    drawet(etresult);
}

/*------Rotation-------*/
void rotation(){
    double angle,temp[3][3],rx,ry;
    printf("\n Enter rx : ");
    scanf("%lf",&rx);
    printf("\n Enter ry : ");
    scanf("%lf",&ry);
    printf("\n Enter angle in degrees : ");
    scanf("%lf",&angle);
    angle=angle*(3.14/180);

    temp[0][0]=cos(angle);
    temp[0][1]=sin(angle);
    temp[1][0]=-sin(angle);
    temp[1][1]=cos(angle);
    temp[0][2]=0;
    temp[1][2]=0;
    temp[2][2]=1;
    temp[2][0]=(-(rx * cos(angle)) + (ry * sin(angle)) + rx);
    temp[2][1]=(-(rx * sin(angle)) - (ry * cos(angle)) + ry);

    mult(et,temp);
    glColor3f(0.0,1.0,1.0);
    drawet(etresult);
}

/*------Scaling-------*/
void scaling(){
    double sx,sy,temp[3][3];
    printf("\n Enter sx : ");
    scanf("%lf",&sx);
    printf("\n Enter sy : ");
    scanf("%lf",&sy);

    temp[0][0]=sx;
    temp[1][1]=sy;
    temp[2][2]=1;
    temp[2][0]=0;
    temp[2][1]=0;
    temp[0][1]=0;
    temp[0][2]=0;
    temp[1][0]=0;
    temp[1][2]=0;

    mult(et,temp);
    glColor3f(0.0,0.0,1.0);
    drawet(etresult);
}

/*------Shearing-----*/
void shear(){
    double shx,shy,temp[3][3];
    printf("\n Enter shx : ");
    scanf("%lf",&shx);
    printf("\n Enter shy : ");
    scanf("%lf",&shy);

    temp[0][0]=1;
    temp[1][1]=1;
    temp[2][2]=1;
    temp[2][0]=0;
    temp[2][1]=0;   
    temp[0][1]=shy;
    temp[0][2]=0;
    temp[1][0]=shx;
    temp[1][2]=0;

    mult(et,temp);
    glColor3f(0.0,1.0,1.0);
    drawet(etresult);
}

/*------Reflection-----*/
void reflect(double a){
    double temp[3][3];

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            temp[i][j]=0;
        }
    }

    if(a==0){
        //reflection about origin
        temp[0][0]=-1;
        temp[1][1]=-1;
        temp[2][2]=1;
    }
    else if(a==1){
        //reflection about x axis
        temp[0][0]=1;
        temp[1][1]=-1;
        temp[2][2]=1;
    }
    else if(a==2){
        //reflection about y axis
        temp[0][0]=-1;
        temp[1][1]=1;
        temp[2][2]=1;
    }

    mult(et,temp);
    glColor3f(0.0,1.0,1.0);
    drawet(etresult);
}

void Menu(int item){
    switch(item){
        case 1:
            translation();
            break;
        case 2:
            rotation();
            break;
        case 3:
            scaling();
            break;
        case 4:
            shear();
            break;
        case 5:
            double c;
            printf("\n 0 for reflection against origin");
            printf("\n 1 for reflection against x axis");
            printf("\n 2 for reflection against y axis");
            scanf("%lf",&c);
            reflect(c);
            break;
        case 6:
            exit(0);
            break;
    }
}

int main(int argc , char** argv){
    int i,j;
    printf("\n Enter xi : ");
    scanf("%d",&xi);
    printf("\n Enter yi : ");
    scanf("%d",&yi);
    printf("\n Enter length : ");
    scanf("%d",&length);

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            et[i][j]=1;
        }
    }    

    et[0][0]=xi;
    et[0][1]=yi;
    et[1][0]=xi+length;
    et[1][1]=yi;
    et[2][0]=length/2+xi;
    et[2][1]=(sqrt(3)/2*length)+yi;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Transformation");
    glutDisplayFunc(display);
    glutCreateMenu(Menu);
    glutAddMenuEntry("1.Translation",1);
    glutAddMenuEntry("2.Rotation",2);
    glutAddMenuEntry("3.Scaling",3);
    glutAddMenuEntry("4.Shearing",4);
    glutAddMenuEntry("5.Reflection",5);
    glutAddMenuEntry("6.Exit",6);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}


