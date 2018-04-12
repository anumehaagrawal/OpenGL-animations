#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

void circledraw(double R , double x, double y){
    y=y+R;
    double P;
    P=1-R;
    while(y>x){
        x++;
        if(P<0){
            P=P+2*x+3;
        }
        else{
            y=y-1;
            P=P+2*(x-y)+5;
        }
        glColor3f(0.2,0.3,1.0);
        glBegin(GL_POINTS);
        glVertex2d(x,y);
        glVertex2d(-x,y);
        glVertex2d(x,-y);
        glVertex2d(y,x);
        glVertex2d(-y,x);
        glVertex2d(-x,-y);
        glVertex2d(-y,-x);
        glVertex2d(y,-x);
        glEnd();
}
}


void display()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    circledraw(100,0,0);
    glColor3f (1.0, 1.0, 1.0);
    drawCube();
    glFlush ();
}
void init()
{

    glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(-100.0, 640.0, -100.0, 480.0);

}

void reshape(int w, int h)
{
 glViewport(0.0,0.0,w,h);
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Circle drawing");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
