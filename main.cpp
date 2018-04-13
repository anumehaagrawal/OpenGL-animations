

 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include <GL/glut.h>


 int rightHandAngle = 180; // Angle of lower right hand
 bool mouseLeftState = false; // Is left mouse clicked?
 bool mouseRightState = false; // Is right mouse clicked?
 int rightHandMove = 2; // If left mouse clicked, right hand will rotate 2 degrees.
 int leftLegMove = 1; // If right mouse clicked, left leg will move by 1.
 int rightLegMove = -1; // If right mouse clicked, right leg will move by 1.
 int leftLegAngle = 90; // If right mouse clicked, this variable will be used to rotate left leg and it initialized to 90 degrees for first position of leg.
 int rightLegAngle = 90; // If right mouse clicked, this variable will be used to rotate right leg and it initialized to 90 degrees for first position of leg.
 float zMove = 0.0; // If right mouse clicked, this variable will be used to change position of object. Object will move on z-axis.
GLfloat x1,y11,x2,y2,x3,y3,x4,y4;

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
/*
void edgedetect(GLfloat x1,GLfloat y11,GLfloat x2,GLfloat y2,int *le,int *re)
{
            float mx,x,temp;
            int i;
            if((y2-y11)<0)
            {
              temp=x1;x1=x2;x2=temp;
              temp=y11;y11=y2;y2=temp;
            }
              if((y2-y11)!=0)
                        mx=(x2-x1)/(y2-y11);
            else
                        mx=x2-x1;
            x=x1;
            for(i=y11;i<y2;i++)
            {
                        if(x<le[i])
                                    le[i]=x;
                        if(x>re[i])
                                    re[i]=x;
                        x+=mx;
            }
}

void scanfill(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
            int le[500],re[500];
            int i,y;
            for(i=0;i<500;i++)
            {
                        le[i]=500;
                        re[i]=0;
            }
            edgedetect(x1,y1,x2,y2,le,re);
            edgedetect(x2,y2,x3,y3,le,re);
            edgedetect(x3,y3,x4,y4,le,re);
            edgedetect(x4,y4,x1,y1,le,re);
            for(y=0;y<500;y++)
            {
                       if(le[y]<=re[y])
                                    for(i=le[y]+1;i<re[y];i++)
                                                draw_pixel(i,y);
            }
}

*/
void draw_line(int x1, int x2, int y1, int y2) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_pixel(x, y);
		}
	}
}

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
 void display(){
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
         glPushMatrix(); //BODY
         glColor3f(1.0, 0.647, 0.0);
         glTranslatef(0.0, 221, zMove);
         glRotatef(90, 1.0, 0.0, 0.0);
         GLUquadricObj* body = gluNewQuadric();
         gluQuadricDrawStyle(body, GLU_FILL);
         gluCylinder(body, 120, 120, 300, 30, 30);
         glPopMatrix();

         glPushMatrix(); //LEFT UPPER ARM
         glColor3f(0.07f, 0.545f, 0.341f);
         glTranslatef(-80, 160, zMove);
         glRotatef(-45, 0.0, 0.0, 1.0);
         glRotatef(90, 1.0, 0.0, 0.0);
         GLUquadricObj* leftUpperArm = gluNewQuadric();
         gluQuadricDrawStyle(leftUpperArm, GLU_FILL);
         gluCylinder(leftUpperArm, 16, 16, 200, 30, 30);
         glPopMatrix();

         glPushMatrix(); // LEFT UPPER ARM AND BODY CONNECTION
         glColor3f(1.0, 0.0, 0.0);
         glPushMatrix();
         glTranslatef(-80.0, 160, zMove);
         glutSolidSphere(16, 30, 30);
         glPopMatrix();

         glPushMatrix(); //LEFT LOWER ARM
         glColor3f(1.0, 1.0, 0.0);
         glTranslatef(-221.5, 19.5, zMove);
         glRotatef(225, 0.0, 0.0, 1.0);
         glRotatef(90, 1.0, 0.0, 0.0);
         GLUquadricObj* leftLowerArm = gluNewQuadric();
         gluQuadricDrawStyle(leftLowerArm, GLU_FILL);
         gluCylinder(leftLowerArm, 16, 16, 200, 30, 30);
         glPopMatrix();

         glPushMatrix(); // LEFT LOWER ARM AND LEFT UPPER ARM CONNECTION
         glColor3f(1.0, 0.0, 0.0);
         glPushMatrix();
         glTranslatef(-221.5, 19.5, zMove);
         glutSolidSphere(16, 30, 30);
         glPopMatrix();

         glPushMatrix(); //RIGHT UPPER ARM
         glColor3f(0.180f, 0.545f, 0.341f);
         glTranslatef(80, 160, zMove);
         glRotatef(90, 0.0, 0.0, 1.0);
         glRotatef(90, 1.0, 0.0, 0.0);
         GLUquadricObj* rightUpperArm = gluNewQuadric();
         gluQuadricDrawStyle(rightUpperArm, GLU_FILL);
         gluCylinder(rightUpperArm, 16, 16, 200, 30, 30);
         glPopMatrix();

         glPushMatrix(); // RIGHT UPPER ARM AND BODY CONNECTION
         glColor3f(1.0, 0.0, 0.0);
         glPushMatrix();
         glTranslatef(80, 160, zMove);
         glutSolidSphere(16, 30, 30);
         glPopMatrix();

         glPushMatrix(); //RIGHT LOWER ARM
         glColor3f(1.0, 1.0, 0.0);
         glTranslatef(280, 160, zMove);
         glRotatef((GLfloat)rightHandAngle, 0.0, 0.0, 1.0);
         glRotatef(90, 1.0, 0.0, 0.0);
         GLUquadricObj* rightLowerArm = gluNewQuadric();
         gluQuadricDrawStyle(rightLowerArm, GLU_FILL);
         gluCylinder(rightLowerArm, 16, 16, 200, 30, 30);
         glPopMatrix();

         glPushMatrix(); // RIGHT LOWER ARM AND RIGHT UPPER ARM CONNECTION
         glColor3f(1.0, 0.0, 0.0);
         glPushMatrix();
         glTranslatef(280, 160, zMove);
         glutSolidSphere(16, 30, 30);
         glPopMatrix();

         glPushMatrix(); //LEFT LEG
         glColor3f(0.180f, 0.545f, 0.341f);
         glTranslatef(-35, -20, zMove);
         glRotatef(-15, 0.0, 0.0, 1.0);
         glRotatef((GLfloat)leftLegAngle, 1.0, 0.0, 0.0);
         GLUquadricObj* leftLeg = gluNewQuadric();
         gluQuadricDrawStyle(leftLeg, GLU_FILL);
         gluCylinder(leftLeg, 16, 16, 400, 30, 30);
         glPopMatrix();

         glPushMatrix(); // LEFT LEG AND BODY CONNECTION
         glColor3f(1.0, 0.0, 0.0);
         glPushMatrix();
         glTranslatef(-35, -20, zMove);
         glutSolidSphere(16, 30, 30);
         glPopMatrix();

         glPushMatrix(); //RIGHT LEG
         glColor3f(0.180f, 0.545f, 0.341f);
         glTranslatef(35, -20, zMove);
         glRotatef(15, 0.0, 0.0, 1.0);
         glRotatef((GLfloat)rightLegAngle, 1.0, 0.0, 0.0);
         GLUquadricObj* rightLeg = gluNewQuadric();
         gluQuadricDrawStyle(rightLeg, GLU_FILL);
         gluCylinder(rightLeg, 16, 16, 400, 30, 30);
         glPopMatrix();

         glPushMatrix(); // RIGHT LEG AND BODY CONNECTION
         glColor3f(1.0, 0.0, 0.0);
         glPushMatrix();
         glTranslatef(35, -20, zMove);
         glutSolidSphere(16, 30, 30);
         glPopMatrix();

         glPushMatrix(); //NECK
         glColor3f(0.0, 0.0, 0.545);
         glTranslatef(0.0, 251, zMove);
         glRotatef(90, 1.0, 0.0, 0.0);
         GLUquadricObj* neck = gluNewQuadric();
         gluQuadricDrawStyle(neck, GLU_FILL);
         gluCylinder(neck, 20, 20, 30, 30, 30);
         glPopMatrix();

         glPushMatrix(); // HEAD
         glColor3f(1.0, 0.647, 0.0);
         glPushMatrix();
         glTranslatef(0.0, 350, zMove);
         glutSolidSphere(100, 30, 30);

         glPopMatrix();
         glPushMatrix();
         glColor3f(1.0, 1.0 , 1.0);
         draw_line(-580, -300 , 40 , 40);
         draw_line(-580, -580 , 40 , -300);
         draw_line(-580, -300 , -300 , -300);
         draw_line(-300, -300 , 40 , -300);
         //scanfill(-580,40,-300,40,-300,-300,-580,-300);
         glPopMatrix();


         if (mouseLeftState == true){ // If left mouse clicked right hand of object will shake its lower arm
             if (rightHandAngle >= 225) { // If angle is greater than 225 incrementing degree will become decrement
                 rightHandMove = -rightHandMove;
             }
             else if (rightHandAngle <= 135){ // If angle is lower than 135 decrementing degree will become increment
                 rightHandMove = -rightHandMove;
             }
             rightHandAngle = (rightHandAngle + rightHandMove) % 360; // changing angle of right hand.
         }
         if (mouseRightState == true){ // If right mouse clicked the object will ve moved and legs' angles will be changed.
             if (leftLegAngle > 110){
                 leftLegMove = -leftLegMove;
             }
             else if (leftLegAngle < 70){
                 leftLegMove = -leftLegMove;
             }
             leftLegAngle = (leftLegAngle + leftLegMove) % 360; // Changing angle of left leg

             if (rightLegAngle > 110) {
                 rightLegMove = -rightLegMove;
             }
             else if (rightLegAngle < 70){
                 rightLegMove = -rightLegMove;
             }
             rightLegAngle = (rightLegAngle + rightLegMove) % 360; // Changing angle of right leg
             zMove += 1.5f; // Moving object on the z-axis
         }

     glutSwapBuffers();
 }
 void keyboard(unsigned char key, int x, int y){
     if (key == 27) // exit when user hits <esc>
         exit(EXIT_SUCCESS);
 }
 void rotate(int key, int x, int y)
 {
     if (key == GLUT_KEY_LEFT){
         glRotatef(-1, 0.0, 1.0, 0.0);    // Rotates left by 1 degree
         glutPostRedisplay();
     }
     if (key == GLUT_KEY_RIGHT){

         glRotatef(1, 0.0, 1.0, 0.0);    // Rotates right by 1 degree
         glutPostRedisplay();
     }
     if (key == GLUT_KEY_UP){
         glRotatef(1, 1.0, 0.0, 0.0);    // Rotates up by 1 degree
         glutPostRedisplay();
     }
     if (key == GLUT_KEY_DOWN){
         glRotatef(-1, 1.0, 0.0, 0.0);    // Rotates down by 1 degree
         glutPostRedisplay();
     }
 }

 void timer(int notUsed) // Timer is for animation. This function provides us to redisplay all objects by every 100 miliseconds
 {
     glutPostRedisplay();
     glutTimerFunc(100, timer, 0);
 }
 int main(int argc, char *argv[]){
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
     glEnable(GL_DEPTH_TEST); // Hidden surface removal
     glutInitWindowSize(1200, 700);
     glutCreateWindow(argv[0]);
     glClearColor(0.0, 1.0, 1.0, 0.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(-750.0, 750.0, -500.0, 500.0, -500.0, 500.0); // Changing the coordinate system.
     glutDisplayFunc(display);
     glutSpecialFunc(rotate);
     glutKeyboardFunc(keyboard);
     timer(0);
     glutMainLoop();
     return EXIT_SUCCESS;
 }

