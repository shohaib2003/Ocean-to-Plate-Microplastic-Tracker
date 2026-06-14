#include<windows.h>
#include<mmsystem.h>
#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<cstdio>


float x0=100,y2=0,r=0.5,x2=100,yp=0,radius,twicePi,pi=3.142,triangleAmount =40;
int spin=0;
bool Scene0=true;
bool Scene1=false;
bool Scene2=false;
bool Scene3=false;
bool Scene4=false;
bool break_down=false;
bool into_two=false;
bool into_four=false;
bool into_eight=false;
bool into_micro=false;
bool Droplets=false;
bool open=true; //fish mouth movement
int opent=0;
//bool two=false;
int lag=0;
int angle1=0;
int angle2=-10;
using namespace std;
GLfloat coulds_x=10;
GLfloat couldSpeed1=2;
GLfloat man_x=0; //man and bottle
GLfloat man_speed=4;
GLfloat plasticB_y=0;
GLfloat plasticB_x=180;
GLfloat plasticB_speed=1;
GLfloat fish1_x=0;
GLfloat fish1_y=100;
GLfloat fish1_speed=2;
GLfloat fish2_x=0;
GLfloat fish2_y=0;
GLfloat fish2_speed=5;
GLfloat fish3_x=100;
GLfloat fish3_y=0;
GLfloat fish3_speed=1;
GLfloat plasticB1_y=-10;
GLfloat plasticB1_speed=4;
GLfloat plasticBp1_y=0;
GLfloat plasticBp1_x=-250;
GLfloat plasticBp1_speed=1;
GLfloat wd1_x=20;
GLfloat wd1_y=25;
GLfloat wd2_x=0;
GLfloat wd2_y=30;
GLfloat wd3_x=20;
GLfloat wd3_y=35;
GLfloat wd_speed=10;
GLfloat f3_y=0;
GLfloat f3_x=700;
GLfloat particle_mov=0;
GLfloat particle_speed=-2;
//transportation
float x,y,i;
float PI=3.1416;

GLfloat sunPosition1=0;
GLfloat sunSpeed1= 0.5;
GLfloat cloudPosition1=0;
//GLfloat couldSpeed1=1;
GLfloat cloudPosition2=0;
GLfloat couldSpeed2=0.8;
GLfloat policecarPosition=0.0f;
GLfloat policecarSpeed=2.5f;
GLfloat vanPosition2=0;
GLfloat vanspeed2=2;
GLfloat menPosition2=0;
GLfloat menspeed2=0.5;
GLfloat carPosition2=0;
GLfloat carSpeed2=1.8;
GLfloat sunPosition2=0;
GLfloat sunSpeed2= 0.5;
GLfloat cloudPosition3=0;
GLfloat couldSpeed3=1;
GLfloat cloudPosition4=0;
GLfloat couldSpeed4=0.8;
GLfloat carPosition1=0;
GLfloat carSpeed1=2;
GLfloat vanPosition1=0;
GLfloat vanspeed1=2;
GLfloat basketPosition = 0.0f;
GLfloat basketspeed = 0.5f;
GLfloat policecarPosition2=0;
GLfloat policecarSpeed2=2.5;
GLfloat hujurPosition1 = 0.0f;
GLfloat hujurPosition2 = 0.0f;
GLfloat bmenPosition1 = 0.0f;
GLfloat emenPosition1 = 0.0f;
GLfloat lmenPosition1 = 0.0f;
GLfloat hujurspeed1 = 0.5f;
GLfloat MplasticPosi=0.0f;
GLfloat MplasticSpeed=1.5f;
GLfloat MouthSpeed=0.7f;
GLfloat MouthPosition=0.0f;


void drawstring(float x0,float y2,float z,char *string, int f)
{
    char *c;
    glRasterPos3f(x0,y2,z);
    for(c=string;*c!='\0';c++){
        if(f==0)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);
        else
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
    }
}
void screen()
{
    glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,1.0,1.0);
	drawstring(210,425,0.0,"American International University Bangladesh",1);
		glColor3f(1.0,1.0,1.0);
	drawstring(210,385,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING",1);
		glColor3f(1.0,1.0,1.0);
	drawstring(210,350,0.0,"A PROJECT ON DISSEMINATION OF MICROPLASTIC IN HUMAN FOOD",1);
	 	glColor3f(1.0,1.0,1.0);
	 	glColor3f(1.0,1.0,1.0);
	drawstring(210,320,0.0,"Course:Computer Graphics",1);
	  drawstring(135,205,0.0," STUDENT NAME",0);
	  	glColor3f(0.0,0.0,0.0);
	drawstring(140,170,0.0,"MD SHOHAIB ISLAM",0);
	drawstring(140,150,0.0,"SHREYASHEE SINGH PUJA ",0);
	drawstring(140,130,0.0,"SAYMA RAHMAN SHANTA ",0);
		glColor3f(1.0,1.0,1.0);
	drawstring(710,205,0.0,"Under the Guidance of",0);
		glColor3f(0.0,0.0,0.0);
		drawstring(720,170,0.0," DIPTA JUSTIN GOMES",0);
    glColor3f(1.0,1.0,1.0);
	drawstring(210,300,0.0,"Academic Year 2024-25",0);
    glColor3f(1.0,1.0,1.0);
	drawstring(440,70,0.0,"Press 's' to start",0);
	glColor3f(1.0,1.0,1.0);
	drawstring(440,50,0.0,"Press 'q' to quit",0);

glFlush();
 //glutSwapBuffers();
}

void renderBitmapString(int  x, int  y, int  z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
void init(void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}

void init01()
{
	glClearColor(0.0,0.6,0.9,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
}
void reshape(GLint w, GLint h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(h>w)
		gluOrtho2D(0, 500, ((float)h/(float)w)*(0), ((float)h/(float)w)*500);
	else
        gluOrtho2D(((float)w/(float)h)*(0), ((float)w/(float)h)*(520), 0, 500);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int j = 0; j <= 360; j++)
    {
        float angle = j * 3.1416 / 180;
        float x0 = rx * cos(angle);
        float y2 = ry * sin(angle);
        glVertex2f((x0 + cx), (y2 + cy));
    }
    glEnd();
}

void sky(){
    // Draw sky
    glColor3f(0.5, 0.8, 1.0);  // Light blue color for the sky
    glBegin(GL_POLYGON);
    glVertex2f(0, 500);
    glVertex2f(0, 0);
    glVertex2f(1200, 0);
    glVertex2f(1200, 500);
    glEnd();
}
void sun(){
     // Sun design
    glColor3ub(255, 215, 0);
    circle(35, 45, 100, 400);
}
void clouds(){

    glPushMatrix();
    glTranslatef(-100, 0, 0);
    glTranslatef(coulds_x, 0, 0);
    // 1st cloud
    glColor3ub(255, 255, 255);

    circle(50, 30, 360, 400);

    circle(55, 20, 345, 400);

    circle(55, 20, 375, 400);

    // 2nd cloud

    circle(50, 30, 310, 320);

    circle(55, 20, 295, 320);

    circle(55, 20, 365, 320);

    glPopMatrix();
    glutPostRedisplay();
}
void river(){
 // River Color


    //darker
    //glColor3f(0.0f, 0.0f, 1.0f);//Dark blue
    glColor3ub(0, 186, 255);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(1200, 0);
    glVertex2d(1200, 200);
    glVertex2d(0, 200);
    glEnd();

    glColor3ub(0, 190, 255);
    glBegin(GL_POLYGON);
    glVertex2d(0, 100);
    glVertex2d(1200, 100);
    glVertex2d(1200, 120);
    glVertex2d(0, 120);
    glEnd();

    glColor3ub(0, 191, 255);
    glBegin(GL_POLYGON);
    glVertex2d(0, 100);
    glVertex2d(1200, 100);
    glVertex2d(1200, 200);
    glVertex2d(0, 200);
    glEnd();


}
void side(){
    glColor3f(0.0, 0.5, 0.0); // Set color to deep green
   // circle(0, 0, 400, 200);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0); // Center point
    for (int angle = 0; angle <= 180; angle++) {
        float x0 = 400 * cos(angle * 3.14159 / 180);
        float y2 = 200 * sin(angle * 3.14159 / 180);
        glVertex2f(x0, y2);
    }
    glEnd();
}
void rock1(){
    glColor3f(0.5, 0.5, 0.5); // Se
   // circle(0, 0, 400, 200);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0); // Center point
    for (int angle = 0; angle <= 180; angle++) {
        float x0 = 250 * cos(angle * 3.14159 / 180);
        float y2 = 100 * sin(angle * 3.14159 / 180);
        glVertex2f(x0, y2);
    }
    glEnd();
}
void rock2(){
    glColor3f(0.4, 0.4, 0.4); //
   // circle(0, 0, 400, 200);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0); // Center point
    for (int angle = 0; angle <= 180; angle++) {
        float x0 = 500 * cos(angle * 3.14159 / 180);
        float y2 = 50 * sin(angle * 3.14159 / 180);
        glVertex2f(x0, y2);
    }
    glEnd();
}
void rock3(){
    glColor3f(0.3, 0.3, 0.3); // Set color to deep green
   // circle(0, 0, 400, 200);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0); // Center point
    for (int angle = 0; angle <= 180; angle++) {
        float x0 = 100 * cos(angle * 3.14159 / 180);
        float y2 = 100 * sin(angle * 3.14159 / 180);
        glVertex2f(x0, y2);
    }
    glEnd();
}
void wooden(){
    // Draw the stand
    glColor3f(0.65, 0.5, 0.39); // Set color to wooden brown
    glBegin(GL_POLYGON);

    glVertex2d(250, 20);
    glVertex2d(550, 20); // Lower right corner
    glVertex2d(450, 120); // Upper right corner
    glVertex2d(150, 120);

    glVertex2d(250, 20); // Lower left corner
    glVertex2d(550, 20); // Lower right corner
    glVertex2d(450, 120); // Upper right corner
    glVertex2d(150, 120); // Upper left corner
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(530,20);
    glVertex2d(510,20);
    glVertex2d(510,0);
    glVertex2d(530,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(270,20);
    glVertex2d(290,20);
    glVertex2d(290,0);
    glVertex2d(270,0);
    glEnd();


}
void sky1(){
        // Draw sky
    glColor3f(0.5, 0.8, 1.0);  // Light blue color for the sky
    glBegin(GL_POLYGON);
    glVertex2f(0, 500);
    glVertex2f(0, 0);
    glVertex2f(1200, 0);
    glVertex2f(1200, 500);
    glEnd();
}
void river2(){
    // River Color
    glColor3ub(0, 191, 255);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(1200, 0);
    glVertex2d(1200, 300);
    glVertex2d(0, 300);
    glEnd();
    glColor3ub(0, 189, 255);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(1200, 0);
    glVertex2d(1200, 200);
    glVertex2d(0, 200);
    glEnd();
    glColor3ub(0, 185, 255);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(1200, 0);
    glVertex2d(1200, 100);
    glVertex2d(0, 100);
    glEnd();

}
void boat(){
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(665 , 220);
    glVertex2d(860 , 220);
    glVertex2d(885 , 250);
    glVertex2d(640 , 250);
    glEnd();

    glColor3ub(205, 133, 63);
    glBegin(GL_POLYGON);
    glVertex2d(705 , 250);
    glVertex2d(820 , 250);
    glVertex2d(810 , 280);
    glVertex2d(705 , 280);
    glEnd();

}
void man_1(){
    glColor3ub(0, 0, 255); // Blue color for the body (square)
    glBegin(GL_POLYGON);
    glVertex2d(850 , 270);
    glVertex2d(850 , 250);
    glVertex2d(870 , 250);
    glVertex2d(870 , 270);
    glEnd();
     glColor3ub(255, 255, 255); // white color for the head (circle)
    circle(5, 5, 860, 270);


}
void hook(){
    glColor3ub(192, 192, 192);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2d(850, 250);
    glVertex2d(850, 150);
    glEnd();
}
void microplastic(){

   //reduced
    glPushMatrix();
    glTranslated(plasticBp1_x, 0,0);

    glColor3f(0, 0, 1);
    glBegin(GL_POINTS);
    glVertex2f(400,150);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(405,155);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(410,120);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(415,125);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(420,120);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(400,120);
    glEnd();
     glBegin(GL_POINTS);
    glVertex2f(420,130);
    glBegin(GL_POINTS);
    glVertex2f(420,130);
    glBegin(GL_POINTS);
    glVertex2f(220,130);
    glBegin(GL_POINTS);
    glVertex2f(720,130);
    glEnd();
     glBegin(GL_POINTS);
    glVertex2f(725,130);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(600,135);
    glEnd();
    glColor3f(0, 0, 1);
    glBegin(GL_POINTS);
    glVertex2f(200,150);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(305,155);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(410,120);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(515,125);
    glEnd();
     //glTranslated(-10,-50, 0.0);
    glBegin(GL_POINTS);
    glVertex2f(620,120);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(700,120);
    glEnd();
     glBegin(GL_POINTS);
    glVertex2f(200,130);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(300,135);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(420,130);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(500,135);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(620,130);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(300,135);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(220,130);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(425,130);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(700,135);
    glEnd();
    glBegin(GL_POINTS);
	glVertex2d(571,110);
	glVertex2d(493,110);
    glVertex2d(293,105);
    glVertex2d(371,105);
    glVertex2d(115,180);
    glVertex2d(205,180);
    glVertex2d(205,160);
    glVertex2d(215,160);
    glVertex2d(500,100);
    glVertex2d(710,100);
    glVertex2d(610,190);
    glVertex2d(600,190);
    glEnd();
     glBegin(GL_POINTS);
    glVertex2f(590,150);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(620,150);
    glEnd();
     glBegin(GL_POINTS);
    glVertex2f(615,120);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(600,150);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(605,155);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(610,120);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(615,125);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(620,120);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(600,120);
    glEnd();
     glBegin(GL_POINTS);
    glVertex2f(600,130);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(600,135);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(620,130);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(600,135);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(620,130);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(600,135);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(620,130);
    glEnd();
     glBegin(GL_POINTS);
    glVertex2f(625,130);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(600,135);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(150,149);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(100,149);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(105,140);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(102,145);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(400,150);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(405,155);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(410,120);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(415,125);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(420,120);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(400,120);
    glEnd();
     glBegin(GL_POINTS);
    glVertex2f(420,130);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(400,135);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(420,130);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(200,135);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(220,130);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(300,135);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(720,130);
    glEnd();
     glBegin(GL_POINTS);
    glVertex2f(725,130);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(600,135);
    glEnd();

    glPopMatrix();


}



void display1 (void)
{



    //SKY
    glBegin(GL_QUADS);
    glColor3ub(10, 196, 236 );
    glVertex2i(-100,-20);
    glVertex2i(-100,100);
    glVertex2i(100,100);
    glVertex2i(100,-20);
    glEnd();

    //Sun Move
    glPushMatrix();
    glTranslatef(sunPosition1,0.0f,0.0f);

    //Sun draw

    float x, y;
    int i;
    GLfloat radius;
    int triangleAmount =40;
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(247, 254, 0);
    x=70;
    y=75;
    radius =10;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    glPopMatrix();

    //cloud1 move
    glPushMatrix();
    glTranslatef(cloudPosition1,0,0);
    //Cloud Draw
    //Cloud-1

    //P-1


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-75;
    y=92;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();



    //P-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-79;
    y=87;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();


    //P-3
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-85;
    y=82;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-4
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-80;
    y=81;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-5
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-73;
    y=85;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-6
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-74;
    y=79;
    radius =3;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();
    glPopMatrix();

    //cloud2 move
    glPushMatrix();
    glTranslatef(cloudPosition2,0,0);
    //Cloud-2

    //P-1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-35;
    y=78;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-41;
    y=73;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-3
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-47;
    y=67;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-4
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-40;
    y=66;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-5
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-33;
    y=70;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();
    glPopMatrix();


    //House side background
    glBegin(GL_QUADS);
    glColor3ub(50,205,50);
    glVertex2i(-100,-20);
    glVertex2i(-100,-40);
    glVertex2i(100,-40);
    glVertex2i(100,-20);
    glEnd();


    //Road background
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(-100,-40);
    glVertex2i(-100,-100);
    glVertex2i(100,-100);
    glVertex2i(100,-40);
    glEnd();

    //Road Mark
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(253, 254, 254);
    glVertex2i(-100,-70);
    glVertex2i(-80,-70);
    glVertex2i(-70,-70);
    glVertex2i(-50,-70);
    glVertex2i(-60,-70);
    glVertex2i(-40,-70);
    glVertex2i(-30,-70);
    glVertex2i(-10,-70);
    glVertex2i(0,-70);
    glVertex2i(20,-70);
    glVertex2i(30,-70);
    glVertex2i(50,-70);
    glVertex2i(60,-70);
    glVertex2i(80,-70);
    glVertex2i(90,-70);
    glVertex2i(100,-70);
    glEnd();

    //Footpath
    glBegin(GL_QUADS);
    glColor3ub(148, 49, 38);
    glVertex2i(100,-40);
    glVertex2i(100,-35);
    glVertex2i(-100,-35);
    glVertex2i(-100,-40);
    glColor3ub(203, 67, 53  );
    glVertex2i(100,-25);
    glVertex2i(100,-35);
    glVertex2i(-100,-35);
    glVertex2i(-100,-25);
    glEnd();

    //Background House

    // Left 2nd Background
    glBegin(GL_QUADS);
    glColor3ub(23, 32, 42);
    glVertex2i(-101,-20);
    glVertex2i(-101,15);
    glVertex2i(-95,15);
    glVertex2i(-95,-20);
    glEnd();

    // Left 2nd Background
    glBegin(GL_QUADS);
    glColor3ub(23, 32, 42);
    glVertex2i(-55,-20);
    glVertex2i(-55,18);
    glVertex2i(-36,18);
    glVertex2i(-36,-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(93, 173, 226 );
    glVertex2i(-52,-5);
    glVertex2i(-52,15);
    glVertex2i(-42,15);
    glVertex2i(-42,-5);
    glEnd();

    //Tree-1 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(-48,-25);
    glVertex2i(-48,-10);
    glVertex2i(-46,-10);
    glVertex2i(-46,-25);
    glEnd();

    //Tree Top-1
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-55,-12);
    glVertex2i(-47,9);
    glVertex2i(-39,-12);
    glEnd();

    //Tree Top-2
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-54,-5);
    glVertex2i(-47,15);
    glVertex2i(-40,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-53,2);
    glVertex2i(-47,22);
    glVertex2i(-41,2);
    glEnd();


    //Mosque Draw

    //Mosque Gombuj
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(94, 31, 125 );
    x=-76;
    y=25;
    radius =13;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();


    //Mosque design
    glBegin(GL_QUADS);
    glColor3ub(159, 164, 236);
    glVertex2i(-98,-22);
    glVertex2i(-98,23);
    glVertex2i(-54,23);
    glVertex2i(-54,-22);
    glEnd();


    //Mosque footer design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-98,-22);
    glVertex2i(-99,-25);
    glVertex2i(-53,-25);
    glVertex2i(-54,-22);
    glEnd();



    //Mosque door design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-81,-25);
    glVertex2i(-81,-1);
    glVertex2i(-71,-1);
    glVertex2i(-71,-25);
    glEnd();

    //Mosque door top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125 );
    glVertex2i(-81,-1);
    glVertex2i(-82,1);
    glVertex2i(-76,12);
    glVertex2i(-70,1);
    glVertex2i(-71,-1);
    glEnd();


    //Mosque left 1st window design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-89,-25);
    glVertex2i(-89,-6);
    glVertex2i(-83,-6);
    glVertex2i(-83,-25);
    glEnd();

    //Mosque left 1st window top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125 );
    glVertex2i(-89,-6);
    glVertex2i(-90,-4);
    glVertex2i(-86.5,3);
    glVertex2i(-82,-4);
    glVertex2i(-83,-6);
    glEnd();


    //Mosque left 2nd window design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-91,-25);
    glVertex2i(-91,-11);
    glVertex2i(-96,-11);
    glVertex2i(-96,-25);
    glEnd();

    //Mosque left 2nd window top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125 );
    glVertex2i(-96,-11);
    glVertex2i(-97,-9);
    glVertex2i(-93.99,-1);
    glVertex2i(-90,-9);
    glVertex2i(-91,-11);
    glEnd();


    //Mosque right 1st window design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-69,-25);
    glVertex2i(-69,-6);
    glVertex2i(-63,-6);
    glVertex2i(-63,-25);
    glEnd();

    //Mosque right 1st window top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125 );
    glVertex2i(-69,-6);
    glVertex2i(-70,-4);
    glVertex2i(-66.5,4);
    glVertex2i(-62,-4);
    glVertex2i(-63,-6);
    glEnd();

    //Mosque right 2nd window design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-61,-25);
    glVertex2i(-61,-11);
    glVertex2i(-56,-11);
    glVertex2i(-56,-25);
    glEnd();

    //Mosque right 2nd window top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125 );
    glVertex2i(-61,-11);
    glVertex2i(-62,-9);
    glVertex2i(-58.5,-1);
    glVertex2i(-55,-9);
    glVertex2i(-56,-11);
    glEnd();

    //Mosque Top box design
    glBegin(GL_QUADS);
    glColor3ub(206, 230, 231 );
    glVertex2i(-99,23);
    glVertex2i(-99,20);
    glVertex2i(-53,20);
    glVertex2i(-53,23);
    glEnd();

    //Mosque Laft meaner design
    glBegin(GL_QUADS);
    glColor3ub(206, 230, 231 );
    glVertex2i(-98,60);
    glVertex2i(-98,23);
    glVertex2i(-94,23);
    glVertex2i(-94,60);
    glEnd();

    //Mosque Laft meaner art design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-98,43);
    glVertex2i(-98,41);
    glVertex2i(-94,41);
    glVertex2i(-94,43);
    glEnd();

    //Mosque Laft meaner top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125);
    glVertex2i(-98,60);
    glVertex2i(-99,62);
    glVertex2i(-96.5,70);
    glVertex2i(-93,62);
    glVertex2i(-94,60);

    glEnd();

    //Mosque Right meaner design
    glBegin(GL_QUADS);
    glColor3ub(206, 230, 231 );
    glVertex2i(-54,60);
    glVertex2i(-54,23);
    glVertex2i(-58,23);
    glVertex2i(-58,60);
    glEnd();

    //Mosque Right meaner art design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-54,43);
    glVertex2i(-54,41);
    glVertex2i(-58,41);
    glVertex2i(-58,43);
    glEnd();

    //Mosque Laft meaner top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125);

    glVertex2i(-58,60);
    glVertex2i(-59,62);
    glVertex2i(-56.5,70);
    glVertex2i(-53,62);
    glVertex2i(-54,60);

    glEnd();

    //Background House

    //Middle Right Background
    glBegin(GL_QUADS);
    glColor3ub(77, 86, 86);
    glVertex2i(-5,-20);
    glVertex2i(-5,30);
    glVertex2i(10,30);
    glVertex2i(10,-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 178, 236);
    glVertex2i(-4,-10);
    glVertex2i(-4,25);
    glVertex2i(5,25);
    glVertex2i(5,-10);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-4, 20);
    glVertex2i(5, 20);
    glVertex2i(-4, 14);
    glVertex2i(5, 14);
    glVertex2i(-4, 8);
    glVertex2i(5, 8);
    glVertex2i(-4, 2);
    glVertex2i(5, 2);
    glVertex2i(-4, -4);
    glVertex2i(5, -4);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(151, 154, 154 );
    glVertex2i(4,-20);
    glVertex2i(4,25);
    glVertex2i(30,25);
    glVertex2i(30,-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 178, 236);
    glVertex2i(6,-10);
    glVertex2i(6,22);
    glVertex2i(15,22);
    glVertex2i(15,-10);
    glEnd();


    //1st HOUSE DESIGN

    //Body Structure
    glBegin(GL_QUADS);
    glColor3ub(125, 206, 160);
    glVertex2i(-40,-22);
    glVertex2i(-40,40);
    glVertex2i(-4,40);
    glVertex2i(-4,-22);
    glEnd();

    //Building down
    glBegin(GL_QUADS);
    glColor3ub(100, 30, 22);
    glVertex2i(-40,-22);
    glVertex2i(-41,-25);
    glVertex2i(-3,-25);
    glVertex2i(-4,-22);
    glEnd();

    //Building top
    glBegin(GL_TRIANGLES);
    glColor3ub(135, 54, 0 );
    glVertex2i(-42,40);
    glVertex2i(-2,40);
    glVertex2i(-22,55);
    glEnd();

    //Building 2nd top
    glBegin(GL_QUADS);
    glColor3ub(135, 54, 0);
    glVertex2i(-42,5);
    glVertex2i(-40,10);
    glVertex2i(-4,10);
    glVertex2i(-2,5);
    glEnd();

    //Left top window
    glBegin(GL_QUADS);
    glColor3ub(46, 134, 193);
    glVertex2i(-37,35);
    glVertex2i(-29,35);
    glVertex2i(-29,14);
    glVertex2i(-37,14);
    glEnd();

    //Left top window design
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-33, 35);
    glVertex2i(-33, 14);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-37, 24.5);
    glVertex2i(-29, 24.5);

    glEnd();

    //Middle top window
    glBegin(GL_QUADS);
    glColor3ub(46, 134, 193);
    glVertex2i(-26,35);
    glVertex2i(-18,35);
    glVertex2i(-18,14);
    glVertex2i(-26,14);
    glEnd();

    //Middle top window design
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-22, 35);
    glVertex2i(-22, 14);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-26, 24.5);
    glVertex2i(-18, 24.5);

    glEnd();

    //Right top window
    glBegin(GL_QUADS);
    glColor3ub(46, 134, 193);
    glVertex2i(-15,35);
    glVertex2i(-7,35);
    glVertex2i(-7,14);
    glVertex2i(-15,14);
    glEnd();

    //Right top window design
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-11, 35);
    glVertex2i(-11, 14);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-15, 24.5);
    glVertex2i(-7, 24.5);

    glEnd();

    //Left down window
    glBegin(GL_QUADS);
    glColor3ub(46, 134, 193);
    glVertex2i(-37,-18);
    glVertex2i(-29,-18);
    glVertex2i(-29,2);
    glVertex2i(-37,2);
    glEnd();

    //Left down window design
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-33, -18);
    glVertex2i(-33, 2);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-37, -8);
    glVertex2i(-29, -8);

    glEnd();

    //Right down window
    glBegin(GL_QUADS);
    glColor3ub(46, 134, 193);
    glVertex2i(-15,-18);
    glVertex2i(-7,-18);
    glVertex2i(-7,2);
    glVertex2i(-15,2);
    glEnd();

    //Right down window design
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-11, -18);
    glVertex2i(-11, 2);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-15, -8);
    glVertex2i(-7, -8);

    glEnd();

    //Door design
    glBegin(GL_QUADS);
    glColor3ub(46, 134, 193);
    glVertex2i(-26,-22);
    glVertex2i(-18,-22);
    glVertex2i(-18,0);
    glVertex2i(-26,0);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-22, -22);
    glVertex2i(-22, 0);

    glEnd();


    //Tree 3 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(9,-23);
    glVertex2i(9,-10);
    glVertex2i(11,-10);
    glVertex2i(11,-23);
    glEnd();

    //Tree Top-1
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(3,-11);
    glVertex2i(10,9);
    glVertex2i(17,-11);
    glEnd();

    //Tree Top-2
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(4,-5);
    glVertex2i(10,15);
    glVertex2i(16,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(5,2);
    glVertex2i(10,21);
    glVertex2i(15,2);
    glEnd();


    //Background Right house Draw

    //House Part
    glBegin(GL_QUADS);
    glColor3ub(179, 182, 183 );
    glVertex2i(83,28);
    glVertex2i(83,-20);
    glVertex2i(102,-20);
    glVertex2i(102,28);
    glEnd();

    //House Left window Part
    glBegin(GL_QUADS);
    glColor3ub(23, 32, 42);
    glVertex2i(83,24);
    glVertex2i(83,20);
    glVertex2i(92,20);
    glVertex2i(92,24);
    glEnd();

    //House Right window Part
    glBegin(GL_QUADS);
    glColor3ub(23, 32, 42);
    glVertex2i(95,24);
    glVertex2i(95,20);
    glVertex2i(102,20);
    glVertex2i(102,24);
    glEnd();

    //House Middle window Part
    glBegin(GL_QUADS);
    glColor3ub(247, 249, 249 );
    glVertex2i(83,16);
    glVertex2i(83,12);
    glVertex2i(102,12);
    glVertex2i(102,16);
    glEnd();

    //House Down left  Part
    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107 );
    glVertex2i(86,10);
    glVertex2i(86,-20);
    glVertex2i(88,-20);
    glVertex2i(88,10);
    glEnd();

    //House Middle window Part
    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107 );
    glVertex2i(96,10);
    glVertex2i(96,-20);
    glVertex2i(98,-20);
    glVertex2i(98,10);
    glEnd();


    //Shopping Mall Design

    //Down part
    glBegin(GL_QUADS);
    glColor3ub(104, 35, 31);
    glVertex2i(85,-22);
    glVertex2i(86,-25);
    glVertex2i(14,-25);
    glVertex2i(15,-22);
    glEnd();

    //Left Down->1 part
    glBegin(GL_QUADS);
    glColor3ub(46, 134, 193);
    glVertex2i(16,-22);
    glVertex2i(16,2);
    glVertex2i(36,2);
    glVertex2i(36,-22);
    glEnd();

    //Left ->2 part
    glBegin(GL_QUADS);
    glColor3ub(245, 103, 16);
    glVertex2i(15,6);
    glVertex2i(15,2);
    glVertex2i(36,2);
    glVertex2i(36,6);
    glEnd();

    //Left ->3 part
    glBegin(GL_QUADS);
    glColor3ub(46, 134, 193);
    glVertex2i(16,6);
    glVertex2i(16,29);
    glVertex2i(36,29);
    glVertex2i(36,6);
    glEnd();

    //Left ->4 part
    glBegin(GL_QUADS);
    glColor3ub(80, 33, 18);
    glVertex2i(16,31);
    glVertex2i(16,29);
    glVertex2i(36,29);
    glVertex2i(36,31);
    glEnd();

    //Left Top part
    glBegin(GL_QUADS);
    glColor3ub(231, 76, 60);
    glVertex2i(13,39);
    glVertex2i(16,31);
    glVertex2i(36,31);
    glVertex2i(36,36);
    glEnd();

    //Right Down->1 part
    glBegin(GL_QUADS);
    glColor3ub(46, 134, 193);
    glVertex2i(60,-22);
    glVertex2i(61.99,2);
    glVertex2i(84,2);
    glVertex2i(84,-22);
    glEnd();

    //Right ->2 part
    glBegin(GL_QUADS);
    glColor3ub(245, 103, 16);
    glVertex2i(60,6);
    glVertex2i(60,2);
    glVertex2i(85,2);
    glVertex2i(85,6);
    glEnd();

    //Right ->3 part
    glBegin(GL_QUADS);
    glColor3ub(46, 134, 193);
    glVertex2i(60,6);
    glVertex2i(60,29);
    glVertex2i(84,29);
    glVertex2i(84,6);
    glEnd();

    //Right ->4 part
    glBegin(GL_QUADS);
    glColor3ub(80, 33, 18);
    glVertex2i(60,31);
    glVertex2i(60,29);
    glVertex2i(84,29);
    glVertex2i(84,31);
    glEnd();

    //Right Top part
    glBegin(GL_QUADS);
    glColor3ub(231, 76, 60);
    glVertex2i(60,36);
    glVertex2i(60,31);
    glVertex2i(84,31);
    glVertex2i(83,35);
    glEnd();


    //Gate body design
    glBegin(GL_QUADS);
    glColor3ub(234, 29, 16);
    glVertex2i(36,-22);
    glVertex2i(36,42);
    glVertex2i(66,49);
    glVertex2i(62,-22);
    glEnd();

    //Gate design
    glBegin(GL_QUADS);
    glColor3ub(46, 134, 193);
    glVertex2i(43,-22);
    glVertex2i(43,0);
    glVertex2i(54,0);
    glVertex2i(54,-22);
    glEnd();

    //Gate Top box design
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(40,35);
    glVertex2i(60,35);
    glVertex2i(60,15);
    glVertex2i(40,15);
    glEnd();
    glColor3f(255,255,0);
    renderBitmapString(43,25,0,GLUT_BITMAP_TIMES_ROMAN_24, "*Aarong*");

    //Art in Market

    //Door Art

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(49, -22);
    glVertex2i(49, 0);

    glEnd();

    //Left Down part Art-1

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(20, -22);
    glVertex2i(20, 2);
    glEnd();

    //Left Down part Art-2

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(33, -22);
    glVertex2i(33, 2);
    glEnd();

    //Left Top part Art-1

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(20, 6);
    glVertex2i(20, 30);
    glEnd();

    //Left Top part Art-2

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(33, 6);
    glVertex2i(33, 30);
    glEnd();

    //Right Down part Art-1

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(66, -22);
    glVertex2i(66, 2);
    glEnd();

    //Left Down part Art-2

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(80, -22);
    glVertex2i(80, 2);
    glEnd();

    //Left Top part Art-1

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(66, 6);
    glVertex2i(66, 30);
    glEnd();

    //Left Top part Art-2

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(80, 6);
    glVertex2i(80, 30);
    glEnd();

    //Tree 2 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(0,-25);
    glVertex2i(0,-10);
    glVertex2i(-2,-10);
    glVertex2i(-2,-25);
    glEnd();

    //Tree Top-1
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-8,-12);
    glVertex2i(-1,9);
    glVertex2i(6,-12);
    glEnd();

    //Tree Top-2
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-7,-5);
    glVertex2i(-1,15);
    glVertex2i(5,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-6,2);
    glVertex2i(-1,22);
    glVertex2i(4,2);
    glEnd();

    //Tree 4 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(91,-25);
    glVertex2i(91,-10);
    glVertex2i(93,-10);
    glVertex2i(93,-25);
    glEnd();

    //Tree Top-1
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(84,-12);
    glVertex2i(92,9);
    glVertex2i(100,-12);
    glEnd();

    //Tree Top-2
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(85,-5);
    glVertex2i(92,15);
    glVertex2i(99,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(86,2);
    glVertex2i(92,22);
    glVertex2i(98,2);
    glEnd();

    //Lamp Draw

    //Lamp 1
    glBegin(GL_QUADS);
    glColor3ub(33, 47, 61);
    glVertex2i(-70,-25);
    glVertex2i(-68,-25);
    glVertex2i(-68,0);
    glVertex2i(-70,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(33, 47, 61);
    glVertex2f(-72,5);
    glVertex2f(-66,5);
    glVertex2f(-69,8);
    glEnd();


    //Light
    glBegin(GL_QUADS);
    glColor3ub(253, 254, 254);
    glVertex2i(-68,0);
    glVertex2i(-70,0);
    glVertex2i(-71,5);
    glVertex2i(-67,5);
    glEnd();



    //Lamp 2
    glBegin(GL_QUADS);
    glColor3ub(33, 47, 61);
    glVertex2i(72,-25);
    glVertex2i(70,-25);
    glVertex2i(70,0);
    glVertex2i(72,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(33, 47, 61);
    glVertex2f(74,5);
    glVertex2f(68,5);
    glVertex2f(71,8);
    glEnd();


    //Light
    glBegin(GL_QUADS);
    glColor3ub(253, 254, 254);
    glVertex2i(70,0);
    glVertex2i(72,0);
    glVertex2i(73,5);
    glVertex2i(69,5);
    glEnd();

    //Lamp 3
    glBegin(GL_QUADS);
    glColor3ub(33, 47, 61);
    glVertex2i(-5,-25);
    glVertex2i(-7,-25);
    glVertex2i(-7,0);
    glVertex2i(-5,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(33, 47, 61);
    glVertex2f(-9,5);
    glVertex2f(-3,5);
    glVertex2f(-6,8);
    glEnd();


    //Light
    glBegin(GL_QUADS);
    glColor3ub(253, 254, 254);
    glVertex2i(-7,0);
    glVertex2i(-5,0);
    glVertex2i(-4,5);
    glVertex2i(-8,5);
    glEnd();

    //Man 5 Draw (GURD)
    //Left Leg
    glBegin(GL_QUADS);
    glColor3ub(128, 71, 71);
    glVertex2i(41,-25);
    glVertex2i(40,-17);
    glVertex2i(37,-17);
    glVertex2i(39,-25);

    //Right leg
    glVertex2i(37,-25);
    glVertex2i(39,-17);
    glVertex2i(36,-17);
    glVertex2i(35,-25);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3ub(128, 71, 71);
    glVertex2i(40,-18);
    glVertex2i(40,-10);
    glVertex2i(38,-11);
    glVertex2i(36,-10);
    glVertex2i(36,-18);
    glEnd();

    //Left hand
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2i(41,-10);
    glVertex2i(40,-10);
    glVertex2i(40,-14);
    glVertex2i(41,-14);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(41, -14);
    glVertex2i(40, -15);
    glEnd();


    //Right hand
    glBegin(GL_QUADS);
    glColor3ub(255,255,255 );
    glVertex2i(36,-10);
    glVertex2i(35,-10);
    glVertex2i(35,-14);
    glVertex2i(36,-14);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(35, -14);
    glVertex2i(36, -15);
    glEnd();

    //Shoe
    glBegin(GL_TRIANGLES);
    glColor3ub(1,0,0);
    glVertex2i(37,-25);
    glVertex2i(36,-23);
    glVertex2i(35,-25);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(41,-25);
    glVertex2i(40,-23);
    glVertex2i(39,-25);
    glEnd();


    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(38, -11);
    glVertex2i(38, -8);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 222, 157);
    x=38;
    y=-7;
    radius =2.5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Hair
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2i(41,-6);
    glVertex2i(39,-4);
    glVertex2i(37,-4);
    glVertex2i(35,-6);
    glEnd();




    glPushMatrix();
    glTranslatef(hujurPosition2,0.0f,0.0f);
    //Man 4 Draw (HUJUR-2)
    //Left Leg
    glBegin(GL_QUADS);
    glColor3ub(243, 216, 216 );
    glVertex2i(-68,-27);
    glVertex2i(-67,-19);
    glVertex2i(-64,-19);
    glVertex2i(-66,-27);

    //Right leg
    glVertex2i(-64,-27);
    glVertex2i(-66,-19);
    glVertex2i(-63,-19);
    glVertex2i(-62,-27);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3ub(243, 156, 18);
    glVertex2i(-68,-25);
    glVertex2i(-67,-12);
    glVertex2i(-65,-13);
    glVertex2i(-63,-12);
    glVertex2i(-62,-25);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(-65, -14);
    glVertex2i(-65, -18);
    glEnd();

    //Left hand
    glBegin(GL_QUADS);
    glColor3ub(243, 156, 18);
    glVertex2i(-68,-12);
    glVertex2i(-67,-12);
    glVertex2i(-67,-17);
    glVertex2i(-68,-17);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-68, -17);
    glVertex2i(-67, -17);
    glEnd();


    //Right hand
    glBegin(GL_QUADS);
    glColor3ub(243, 156, 18);
    glVertex2i(-63,-12);
    glVertex2i(-62,-12);
    glVertex2i(-62,-16);
    glVertex2i(-63,-16);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-62, -16);
    glVertex2i(-63, -17);
    glEnd();

    //Shoe
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(-64,-27);
    glVertex2i(-63,-25);
    glVertex2i(-62,-27);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(-68,-27);
    glVertex2i(-67,-25);
    glVertex2i(-66,-27);
    glEnd();


    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-65, -13);
    glVertex2i(-65, -10);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 222, 157 );
    x=-65;
    y=-9;
    radius =2.5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Hair
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2i(-68,-8);
    glVertex2i(-66,-6);
    glVertex2i(-64,-6);
    glVertex2i(-62,-8);
    glEnd();


    glPopMatrix();


    glPushMatrix();
    glTranslatef(bmenPosition1,0.0f,0.0f);
    //Man 6 Draw (Visitor)
    //Left Leg
    glBegin(GL_QUADS);
    glColor3ub(127, 50, 19 );
    glVertex2i(68,-30);
    glVertex2i(67,-22);
    glVertex2i(64,-22);
    glVertex2i(66,-30);

    //Right leg
    glVertex2i(64,-30);
    glVertex2i(66,-22);
    glVertex2i(63,-22);
    glVertex2i(62,-30);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3ub(15, 189, 157  );
    glVertex2i(67,-22);
    glVertex2i(67,-15);
    glVertex2i(65,-16);
    glVertex2i(63,-15);
    glVertex2i(63,-22);
    glEnd();

    //Left hand
    glBegin(GL_QUADS);
    glColor3ub(15, 189, 157 );
    glVertex2i(68,-15);
    glVertex2i(67,-15);
    glVertex2i(67,-19);
    glVertex2i(68,-19);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(68, -19);
    glVertex2i(67, -20);
    glEnd();


    //Right hand
    glBegin(GL_QUADS);
    glColor3ub(15, 189, 157  );
    glVertex2i(63,-15);
    glVertex2i(62,-15);
    glVertex2i(62,-19);
    glVertex2i(63,-19);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(62, -19);
    glVertex2i(63, -20);
    glEnd();

    //Bag
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2i(62, -22);
    glVertex2i(62, -28);
    glEnd();

    //Shoe
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(64,-30);
    glVertex2i(63,-28);
    glVertex2i(62,-30);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(68,-30);
    glVertex2i(67,-28);
    glVertex2i(66,-30);
    glEnd();


    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(65, -16);
    glVertex2i(65, -13);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 222, 157 );
    x=65;
    y=-12;
    radius =2.5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Hair
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2i(68,-11);
    glVertex2i(66,-9);
    glVertex2i(64,-9);
    glVertex2i(62,-11);
    glEnd();


    glPopMatrix();


    //Man 3 Draw (HUJUR-1)
    //Left Leg
    glPushMatrix();
    glTranslatef(hujurPosition1,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(243, 216, 216 );
    glVertex2i(-88,-33);
    glVertex2i(-87,-25);
    glVertex2i(-84,-25);
    glVertex2i(-86,-33);

    //Right leg
    glVertex2i(-84,-33);
    glVertex2i(-86,-25);
    glVertex2i(-83,-25);
    glVertex2i(-82,-33);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2i(-88,-31);
    glVertex2i(-87,-18);
    glVertex2i(-85,-19);
    glVertex2i(-83,-18);
    glVertex2i(-82,-31);
    glEnd();

    //Left hand
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2i(-88,-18);
    glVertex2i(-87,-18);
    glVertex2i(-87,-22);
    glVertex2i(-88,-22);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-88, -22);
    glVertex2i(-87, -23);
    glEnd();


    //Right hand
    glBegin(GL_QUADS);
    glColor3ub(255,255,255 );
    glVertex2i(-83,-18);
    glVertex2i(-82,-18);
    glVertex2i(-82,-22);
    glVertex2i(-83,-22);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-82, -22);
    glVertex2i(-83, -23);
    glEnd();

    //Shoe
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(-84,-33);
    glVertex2i(-83,-31);
    glVertex2i(-82,-33);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(-88,-33);
    glVertex2i(-87,-31);
    glVertex2i(-86,-33);
    glEnd();


    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-85, -19);
    glVertex2i(-85, -16);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 222, 157 );
    x=-85;
    y=-15;
    radius =2.5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Hair
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2i(-88,-14);
    glVertex2i(-86,-12);
    glVertex2i(-84,-12);
    glVertex2i(-82,-14);
    glEnd();

    glPopMatrix();



    glPushMatrix();
    glTranslatef(menPosition2,0.0f,0.0f);
    //Man 1 Draw
    //Left Leg
    glBegin(GL_QUADS);
    glColor3ub(44, 80, 197);
    glVertex2i(-22,-40);
    glVertex2i(-21,-33);
    glVertex2i(-18,-33);
    glVertex2i(-20,-40);

    //Right leg
    glVertex2i(-18,-40);
    glVertex2i(-20,-33);
    glVertex2i(-17,-33);
    glVertex2i(-16,-40);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3ub(56, 225, 38 );
    glVertex2i(-21,-33);
    glVertex2i(-21,-26);
    glVertex2i(-19,-27);
    glVertex2i(-17,-26);
    glVertex2i(-17,-33);
    glEnd();

    //Left hand
    glBegin(GL_QUADS);
    glColor3ub(56, 225, 38 );
    glVertex2i(-22,-26);
    glVertex2i(-21,-26);
    glVertex2i(-21,-30);
    glVertex2i(-22,-30);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-22, -30);
    glVertex2i(-21, -31);
    glEnd();


    //Right hand
    glBegin(GL_QUADS);
    glColor3ub(56, 225, 38 );
    glVertex2i(-17,-26);
    glVertex2i(-16,-26);
    glVertex2i(-16,-30);
    glVertex2i(-17,-30);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-17, -30);
    glVertex2i(-16, -31);
    glEnd();

    //Shoe
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(-18,-40);
    glVertex2i(-17,-38);
    glVertex2i(-16,-40);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(-22,-40);
    glVertex2i(-21,-38);
    glVertex2i(-20,-40);
    glEnd();


    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-19, -27);
    glVertex2i(-19, -24);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 222, 157 );
    x=-19;
    y=-23;
    radius =2.5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Hair
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(-22,-22);
    glVertex2i(-20,-20);
    glVertex2i(-18,-20);
    glVertex2i(-16,-22);
    glEnd();



    //Basket

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2i(-8,-30);
    glVertex2i(-8,-32);
    glVertex2i(-10,-40);
    glVertex2i(-14,-40);
    glVertex2i(-16,-30);
    glEnd();
    glColor3f(255,0,0);
    renderBitmapString(-13,-34,0,GLUT_BITMAP_TIMES_ROMAN_10, "Fish");



    glPopMatrix();



    glPushMatrix();
    glTranslatef(vanPosition2,0.0f,0.0f);
    // Van body
    glBegin(GL_POLYGON);
    glColor3ub(253, 254, 254);
    glVertex2f(-90, -50);
    glVertex2f(-50, -50);
    glVertex2f(-51, -40);
    glVertex2f(-55, -35);
    glVertex2f(-60, -20);
    glVertex2f(-85, -20);
    glVertex2f(-90, -35);
    glEnd();
    //Fish sign
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0); // Fish Tail
    glVertex2f(-79, -33);
    glVertex2f(-72, -37);
    glVertex2f(-74, -33);
    glVertex2f(-72, -29);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0); // Fish body color
    glVertex2f(-87, -33);
    glVertex2f(-77, -39);
    glVertex2f(-77, -26);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0); // Fish  wings
    glVertex2f(-83, -33);
    glVertex2f(-81, -34);
    glVertex2f(-81, -32);
    glEnd();
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    glColor3ub(0, 0, 255);//Fish Eye
    glVertex2f(-85,-33);
    glEnd();


    //Van glass
    glBegin(GL_QUADS);
    glColor3ub(52, 152, 219);
    glVertex2i(-61,-23);
    glVertex2i(-56,-35);
    glVertex2i(-66,-35);
    glVertex2i(-66,-23);
    glEnd();
    //Van bumper
    glBegin(GL_QUADS);
    glColor3ub(46, 64, 83);
    glVertex2i(-88,-50);
    glVertex2i(-91,-50);
    glVertex2i(-91,-46);
    glVertex2i(-88,-46);
    glVertex2i(-52,-50);
    glVertex2i(-52,-46);
    glVertex2i(-49,-46);
    glVertex2i(-49,-50);
    glEnd();

    //Van Light
    glBegin(GL_QUADS);
    glColor3ub(236, 67, 34);
    glVertex2i(-90,-35);
    glVertex2i(-89,-35);
    glVertex2i(-89,-40);
    glVertex2i(-90,-40);
    glColor3ub(251, 250, 32);
    glVertex2i(-51,-40);
    glVertex2i(-55,-40);
    glVertex2i(-55,-42);
    glVertex2i(-51,-42);
    glEnd();


    //Van wheel-1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=-61;
    y=-50;
    radius =6;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=-61;
    y=-50;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Van wheel-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=-79;
    y=-50;
    radius =6;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=-79;
    y=-50;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(carPosition2,0.0f,0.0f);
    //car body
    glBegin(GL_QUADS);
    glColor3ub(125, 60, 152);
    glVertex2i(50,-70);
    glVertex2i(85,-70);
    glVertex2i(87,-80);
    glVertex2i(48,-80);
    glVertex2i(58,-70);
    glVertex2i(61,-60);
    glVertex2i(76,-60);
    glVertex2i(78,-70);
    glEnd();

    //car glass
    glBegin(GL_QUADS);
    glColor3ub(52, 152, 219);
    glVertex2i(59,-70);
    glVertex2i(62,-61);
    glVertex2i(75,-61);
    glVertex2i(77,-70);
    glVertex2i(69,-70);
    glVertex2i(69,-61);
    glVertex2i(73,-61);
    glVertex2i(75,-70);
    glEnd();

    //car bumper
    glBegin(GL_QUADS);
    glColor3ub(46, 64, 83);
    glVertex2i(46,-80);
    glVertex2i(53,-80);
    glVertex2i(53,-76);
    glVertex2i(46,-76);
    glVertex2i(88,-80);
    glVertex2i(82,-80);
    glVertex2i(82,-76);
    glVertex2i(88,-76);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(69,-80);
    glVertex2i(69,-60);
    glVertex2i(58,-70);
    glVertex2i(78,-70);
    glEnd();

    //car Light
    glBegin(GL_QUADS);
    glColor3ub(236, 67, 34);
    glVertex2i(84,-70);
    glVertex2i(85,-70);
    glVertex2i(85,-75);
    glVertex2i(84,-75);
    glColor3ub(226, 224, 224);
    glVertex2i(51,-70);
    glVertex2i(49,-70);
    glVertex2i(49,-72);
    glVertex2i(51,-72);
    glEnd();

    //Car wheel-1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=60;
    y=-80;
    radius =5;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=60;
    y=-80;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Car wheel-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=75;
    y=-80;
    radius =5;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=75;
    y=-80;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(policecarPosition,0.0f,0.0f);

    //Police Car
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2i(45,-90);
    glVertex2i(48,-78);
    glVertex2i(57,-75);
    glVertex2i(65,-65);
    glVertex2i(83,-65);
    glVertex2i(86,-75);
    glVertex2i(93,-75);
    glVertex2i(95,-90);
    glEnd();

    //Front window
    glBegin(GL_QUADS);
    glColor3ub(35, 148, 186);
    glVertex2i(65,-67);
    glVertex2i(73,-67);
    glVertex2i(73,-74);
    glVertex2i(60,-74);
    glEnd();

    //Back window
    glBegin(GL_QUADS);
    glColor3ub(35, 148, 186);
    glVertex2i(74,-67);
    glVertex2i(82,-67);
    glVertex2i(84,-74);
    glVertex2i(74,-74);
    glEnd();

    //Body Art
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(35, 57, 186);
    glVertex2i(52, -80);
    glVertex2i(88, -80);
    glEnd();

    //Front art
    glBegin(GL_QUADS);
    glColor3ub(40, 55, 71 );
    glVertex2i(44,-90);
    glVertex2i(48,-90);
    glVertex2i(48,-87);
    glVertex2i(44,-87);
    glEnd();

    //Back art
    glBegin(GL_QUADS);
    glColor3ub(40, 55, 71 );
    glVertex2i(92,-90);
    glVertex2i(97,-90);
    glVertex2i(97,-87);
    glVertex2i(92,-87);
    glEnd();

    //Front Light art
    glBegin(GL_QUADS);
    glColor3ub(247, 43, 43 );
    glVertex2i(47,-82);
    glVertex2i(50,-82);
    glVertex2i(50,-79);
    glVertex2i(48,-79);
    glEnd();

    //Back Light art
    glBegin(GL_QUADS);
    glColor3ub(247, 43, 43 );
    glVertex2i(91,-82);
    glVertex2i(94,-82);
    glVertex2i(93,-79);
    glVertex2i(91,-79);
    glEnd();

    //Top Light
    glBegin(GL_QUADS);
    glColor3ub(189, 8, 8 );
    glVertex2i(67,-65);
    glVertex2i(69,-65);
    glVertex2i(69,-63);
    glVertex2i(67,-63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(8, 68, 189 );
    glVertex2i(69,-65);
    glVertex2i(71,-65);
    glVertex2i(71,-63);
    glVertex2i(69,-63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(189, 8, 8 );
    glVertex2i(71,-65);
    glVertex2i(73,-65);
    glVertex2i(73,-63);
    glVertex2i(71,-63);
    glEnd();

    //Front tire
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=60;
    y=-90;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    //Front Tire middle
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=60;
    y=-90;
    radius =3;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    //Back Tire
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=80;
    y=-90;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Back Tire Middle
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=80;
    y=-90;
    radius =3;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();



    glFlush();

}

void display1N (void)
{

    glClear(GL_COLOR_BUFFER_BIT);

    //SKY
    glBegin(GL_QUADS);
    glColor3ub(7, 26, 116 );
    glVertex2i(-100,-20);
    glVertex2i(-100,100);
    glVertex2i(100,100);
    glVertex2i(100,-20);
    glEnd();

    //Star
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glColor3f(255, 255, 255 );
    glVertex2i(-90,90);
    glVertex2i(-70,90);
    glVertex2i(-50,90);
    glVertex2i(-30,90);
    glVertex2i(-10,90);
    glVertex2i(10,90);
    glVertex2i(30,90);
    glVertex2i(50,90);
    glVertex2i(70,90);
    glVertex2i(90,90);
    glEnd();

    glPointSize(3.0);
    glBegin(GL_POINTS);
    glColor3f(255, 255, 255 );
    glVertex2i(-90,70);
    glVertex2i(-70,70);
    glVertex2i(-50,70);
    glVertex2i(-30,70);
    glVertex2i(-10,70);
    glVertex2i(10,70);
    glVertex2i(30,70);
    glVertex2i(50,70);
    glVertex2i(70,70);
    glVertex2i(90,70);
    glEnd();

    glPointSize(3.0);
    glBegin(GL_POINTS);
    glColor3f(255, 255, 255 );
    glVertex2i(-90,50);
    glVertex2i(-70,50);
    glVertex2i(-50,50);
    glVertex2i(-30,50);
    glVertex2i(-10,50);
    glVertex2i(10,50);
    glVertex2i(30,50);
    glVertex2i(50,50);
    glVertex2i(70,50);
    glVertex2i(90,50);
    glEnd();

    //Sun Move
    glPushMatrix();
    glTranslatef(sunPosition1,0.0f,0.0f);

    //Sun draw

    float x, y;
    int i;
    GLfloat radius;
    int triangleAmount =40;
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);
    x=70;
    y=75;
    radius =10;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    glPopMatrix();

    //cloud1 move
    glPushMatrix();
    glTranslatef(cloudPosition1,0,0);
    //Cloud Draw
    //Cloud-1

    //P-1


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-75;
    y=92;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();



    //P-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-79;
    y=87;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();


    //P-3
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-85;
    y=82;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-4
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-80;
    y=81;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-5
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-73;
    y=85;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-6
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234  );
    x=-74;
    y=79;
    radius =3;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();
    glPopMatrix();

    //cloud2 move
    glPushMatrix();
    glTranslatef(cloudPosition2,0,0);
    //Cloud-2

    //P-1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-35;
    y=78;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-41;
    y=73;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-3
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-47;
    y=67;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-4
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-40;
    y=66;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-5
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-33;
    y=70;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();
    glPopMatrix();


    //House side background
    glBegin(GL_QUADS);
    glColor3ub(50,205,50);
    glVertex2i(-100,-20);
    glVertex2i(-100,-40);
    glVertex2i(100,-40);
    glVertex2i(100,-20);
    glEnd();


    //Road background
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(-100,-40);
    glVertex2i(-100,-100);
    glVertex2i(100,-100);
    glVertex2i(100,-40);
    glEnd();

    //Road Mark
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(253, 254, 254);
    glVertex2i(-100,-70);
    glVertex2i(-80,-70);
    glVertex2i(-70,-70);
    glVertex2i(-50,-70);
    glVertex2i(-60,-70);
    glVertex2i(-40,-70);
    glVertex2i(-30,-70);
    glVertex2i(-10,-70);
    glVertex2i(0,-70);
    glVertex2i(20,-70);
    glVertex2i(30,-70);
    glVertex2i(50,-70);
    glVertex2i(60,-70);
    glVertex2i(80,-70);
    glVertex2i(90,-70);
    glVertex2i(100,-70);
    glEnd();

    //Footpath
    glBegin(GL_QUADS);
    glColor3ub(148, 49, 38);
    glVertex2i(100,-40);
    glVertex2i(100,-35);
    glVertex2i(-100,-35);
    glVertex2i(-100,-40);
    glColor3ub(203, 67, 53  );
    glVertex2i(100,-25);
    glVertex2i(100,-35);
    glVertex2i(-100,-35);
    glVertex2i(-100,-25);
    glEnd();

    //Background House

    // Left 2nd Background
    glBegin(GL_QUADS);
    glColor3ub(23, 32, 42);
    glVertex2i(-101,-20);
    glVertex2i(-101,15);
    glVertex2i(-95,15);
    glVertex2i(-95,-20);
    glEnd();

    // Left 2nd Background
    glBegin(GL_QUADS);
    glColor3ub(23, 32, 42);
    glVertex2i(-55,-20);
    glVertex2i(-55,18);
    glVertex2i(-36,18);
    glVertex2i(-36,-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(93, 173, 226 );
    glVertex2i(-52,-5);
    glVertex2i(-52,15);
    glVertex2i(-42,15);
    glVertex2i(-42,-5);
    glEnd();

    //Tree-1 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(-48,-25);
    glVertex2i(-48,-10);
    glVertex2i(-46,-10);
    glVertex2i(-46,-25);
    glEnd();

    //Tree Top-1
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-55,-12);
    glVertex2i(-47,9);
    glVertex2i(-39,-12);
    glEnd();

    //Tree Top-2
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-54,-5);
    glVertex2i(-47,15);
    glVertex2i(-40,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-53,2);
    glVertex2i(-47,22);
    glVertex2i(-41,2);
    glEnd();


    //Mosque Draw

    //Mosque Gombuj
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(94, 31, 125 );
    x=-76;
    y=25;
    radius =13;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();


    //Mosque design
    glBegin(GL_QUADS);
    glColor3ub(159, 164, 236);
    glVertex2i(-98,-22);
    glVertex2i(-98,23);
    glVertex2i(-54,23);
    glVertex2i(-54,-22);
    glEnd();


    //Mosque footer design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-98,-22);
    glVertex2i(-99,-25);
    glVertex2i(-53,-25);
    glVertex2i(-54,-22);
    glEnd();



    //Mosque door design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-81,-25);
    glVertex2i(-81,-1);
    glVertex2i(-71,-1);
    glVertex2i(-71,-25);
    glEnd();

    //Mosque door top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125 );
    glVertex2i(-81,-1);
    glVertex2i(-82,1);
    glVertex2i(-76,12);
    glVertex2i(-70,1);
    glVertex2i(-71,-1);
    glEnd();


    //Mosque left 1st window design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-89,-25);
    glVertex2i(-89,-6);
    glVertex2i(-83,-6);
    glVertex2i(-83,-25);
    glEnd();

    //Mosque left 1st window top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125 );
    glVertex2i(-89,-6);
    glVertex2i(-90,-4);
    glVertex2i(-86.5,3);
    glVertex2i(-82,-4);
    glVertex2i(-83,-6);
    glEnd();


    //Mosque left 2nd window design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-91,-25);
    glVertex2i(-91,-11);
    glVertex2i(-96,-11);
    glVertex2i(-96,-25);
    glEnd();

    //Mosque left 2nd window top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125 );
    glVertex2i(-96,-11);
    glVertex2i(-97,-9);
    glVertex2i(-93.99,-1);
    glVertex2i(-90,-9);
    glVertex2i(-91,-11);
    glEnd();


    //Mosque right 1st window design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-69,-25);
    glVertex2i(-69,-6);
    glVertex2i(-63,-6);
    glVertex2i(-63,-25);
    glEnd();

    //Mosque right 1st window top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125 );
    glVertex2i(-69,-6);
    glVertex2i(-70,-4);
    glVertex2i(-66.5,4);
    glVertex2i(-62,-4);
    glVertex2i(-63,-6);
    glEnd();

    //Mosque right 2nd window design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-61,-25);
    glVertex2i(-61,-11);
    glVertex2i(-56,-11);
    glVertex2i(-56,-25);
    glEnd();

    //Mosque right 2nd window top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125 );
    glVertex2i(-61,-11);
    glVertex2i(-62,-9);
    glVertex2i(-58.5,-1);
    glVertex2i(-55,-9);
    glVertex2i(-56,-11);
    glEnd();

    //Mosque Top box design
    glBegin(GL_QUADS);
    glColor3ub(206, 230, 231 );
    glVertex2i(-99,23);
    glVertex2i(-99,20);
    glVertex2i(-53,20);
    glVertex2i(-53,23);
    glEnd();

    //Mosque Laft meaner design
    glBegin(GL_QUADS);
    glColor3ub(206, 230, 231 );
    glVertex2i(-98,60);
    glVertex2i(-98,23);
    glVertex2i(-94,23);
    glVertex2i(-94,60);
    glEnd();

    //Mosque Laft meaner art design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-98,43);
    glVertex2i(-98,41);
    glVertex2i(-94,41);
    glVertex2i(-94,43);
    glEnd();

    //Mosque Laft meaner top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125);
    glVertex2i(-98,60);
    glVertex2i(-99,62);
    glVertex2i(-96.5,70);
    glVertex2i(-93,62);
    glVertex2i(-94,60);

    glEnd();

    //Mosque Right meaner design
    glBegin(GL_QUADS);
    glColor3ub(206, 230, 231 );
    glVertex2i(-54,60);
    glVertex2i(-54,23);
    glVertex2i(-58,23);
    glVertex2i(-58,60);
    glEnd();

    //Mosque Right meaner art design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-54,43);
    glVertex2i(-54,41);
    glVertex2i(-58,41);
    glVertex2i(-58,43);
    glEnd();

    //Mosque Laft meaner top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125);

    glVertex2i(-58,60);
    glVertex2i(-59,62);
    glVertex2i(-56.5,70);
    glVertex2i(-53,62);
    glVertex2i(-54,60);

    glEnd();

    //Background House

    //Middle Right Background
    glBegin(GL_QUADS);
    glColor3ub(77, 86, 86);
    glVertex2i(-5,-20);
    glVertex2i(-5,30);
    glVertex2i(10,30);
    glVertex2i(10,-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 178, 236);
    glVertex2i(-4,-10);
    glVertex2i(-4,25);
    glVertex2i(5,25);
    glVertex2i(5,-10);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-4, 20);
    glVertex2i(5, 20);
    glVertex2i(-4, 14);
    glVertex2i(5, 14);
    glVertex2i(-4, 8);
    glVertex2i(5, 8);
    glVertex2i(-4, 2);
    glVertex2i(5, 2);
    glVertex2i(-4, -4);
    glVertex2i(5, -4);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(151, 154, 154 );
    glVertex2i(4,-20);
    glVertex2i(4,25);
    glVertex2i(30,25);
    glVertex2i(30,-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 178, 236);
    glVertex2i(6,-10);
    glVertex2i(6,22);
    glVertex2i(15,22);
    glVertex2i(15,-10);
    glEnd();


    //1st HOUSE DESIGN

    //Body Structure
    glBegin(GL_QUADS);
    glColor3ub(125, 206, 160);
    glVertex2i(-40,-22);
    glVertex2i(-40,40);
    glVertex2i(-4,40);
    glVertex2i(-4,-22);
    glEnd();

    //Building down
    glBegin(GL_QUADS);
    glColor3ub(100, 30, 22);
    glVertex2i(-40,-22);
    glVertex2i(-41,-25);
    glVertex2i(-3,-25);
    glVertex2i(-4,-22);
    glEnd();

    //Building top
    glBegin(GL_TRIANGLES);
    glColor3ub(135, 54, 0 );
    glVertex2i(-42,40);
    glVertex2i(-2,40);
    glVertex2i(-22,55);
    glEnd();

    //Building 2nd top
    glBegin(GL_QUADS);
    glColor3ub(135, 54, 0);
    glVertex2i(-42,5);
    glVertex2i(-40,10);
    glVertex2i(-4,10);
    glVertex2i(-2,5);
    glEnd();

    //Left top window
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0);
    glVertex2i(-37,35);
    glVertex2i(-29,35);
    glVertex2i(-29,14);
    glVertex2i(-37,14);
    glEnd();

    //Left top window design
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-33, 35);
    glVertex2i(-33, 14);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-37, 24.5);
    glVertex2i(-29, 24.5);

    glEnd();

    //Middle top window
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0);
    glVertex2i(-26,35);
    glVertex2i(-18,35);
    glVertex2i(-18,14);
    glVertex2i(-26,14);
    glEnd();

    //Middle top window design
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-22, 35);
    glVertex2i(-22, 14);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-26, 24.5);
    glVertex2i(-18, 24.5);

    glEnd();

    //Right top window
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0);
    glVertex2i(-15,35);
    glVertex2i(-7,35);
    glVertex2i(-7,14);
    glVertex2i(-15,14);
    glEnd();

    //Right top window design
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-11, 35);
    glVertex2i(-11, 14);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-15, 24.5);
    glVertex2i(-7, 24.5);

    glEnd();

    //Left down window
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0);
    glVertex2i(-37,-18);
    glVertex2i(-29,-18);
    glVertex2i(-29,2);
    glVertex2i(-37,2);
    glEnd();

    //Left down window design
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-33, -18);
    glVertex2i(-33, 2);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-37, -8);
    glVertex2i(-29, -8);

    glEnd();

    //Right down window
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0);
    glVertex2i(-15,-18);
    glVertex2i(-7,-18);
    glVertex2i(-7,2);
    glVertex2i(-15,2);
    glEnd();

    //Right down window design
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-11, -18);
    glVertex2i(-11, 2);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-15, -8);
    glVertex2i(-7, -8);

    glEnd();

    //Door design
    glBegin(GL_QUADS);
    glColor3ub(46, 134, 193);
    glVertex2i(-26,-22);
    glVertex2i(-18,-22);
    glVertex2i(-18,0);
    glVertex2i(-26,0);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-22, -22);
    glVertex2i(-22, 0);

    glEnd();


    //Tree 3 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(9,-23);
    glVertex2i(9,-10);
    glVertex2i(11,-10);
    glVertex2i(11,-23);
    glEnd();

    //Tree Top-1
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(3,-11);
    glVertex2i(10,9);
    glVertex2i(17,-11);
    glEnd();

    //Tree Top-2
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(4,-5);
    glVertex2i(10,15);
    glVertex2i(16,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(5,2);
    glVertex2i(10,21);
    glVertex2i(15,2);
    glEnd();


    //Background Right house Draw

    //House Part
    glBegin(GL_QUADS);
    glColor3ub(179, 182, 183 );
    glVertex2i(83,28);
    glVertex2i(83,-20);
    glVertex2i(102,-20);
    glVertex2i(102,28);
    glEnd();

    //House Left window Part
    glBegin(GL_QUADS);
    glColor3ub(23, 32, 42);
    glVertex2i(83,24);
    glVertex2i(83,20);
    glVertex2i(92,20);
    glVertex2i(92,24);
    glEnd();

    //House Right window Part
    glBegin(GL_QUADS);
    glColor3ub(23, 32, 42);
    glVertex2i(95,24);
    glVertex2i(95,20);
    glVertex2i(102,20);
    glVertex2i(102,24);
    glEnd();

    //House Middle window Part
    glBegin(GL_QUADS);
    glColor3ub(247, 249, 249 );
    glVertex2i(83,16);
    glVertex2i(83,12);
    glVertex2i(102,12);
    glVertex2i(102,16);
    glEnd();

    //House Down left  Part
    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107 );
    glVertex2i(86,10);
    glVertex2i(86,-20);
    glVertex2i(88,-20);
    glVertex2i(88,10);
    glEnd();

    //House Middle window Part
    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107 );
    glVertex2i(96,10);
    glVertex2i(96,-20);
    glVertex2i(98,-20);
    glVertex2i(98,10);
    glEnd();


    //Shopping Mall Design

    //Down part
    glBegin(GL_QUADS);
    glColor3ub(104, 35, 31);
    glVertex2i(85,-22);
    glVertex2i(86,-25);
    glVertex2i(14,-25);
    glVertex2i(15,-22);
    glEnd();

    //Left Down->1 part
    glBegin(GL_QUADS);
    glColor3ub(19, 47, 112 );
    glVertex2i(16,-22);
    glVertex2i(16,2);
    glVertex2i(36,2);
    glVertex2i(36,-22);
    glEnd();

    //Left ->2 part
    glBegin(GL_QUADS);
    glColor3ub(245, 103, 16);
    glVertex2i(15,6);
    glVertex2i(15,2);
    glVertex2i(36,2);
    glVertex2i(36,6);
    glEnd();

    //Left ->3 part
    glBegin(GL_QUADS);
    glColor3ub(19, 47, 112 );
    glVertex2i(16,6);
    glVertex2i(16,29);
    glVertex2i(36,29);
    glVertex2i(36,6);
    glEnd();

    //Left ->4 part
    glBegin(GL_QUADS);
    glColor3ub(80, 33, 18);
    glVertex2i(16,31);
    glVertex2i(16,29);
    glVertex2i(36,29);
    glVertex2i(36,31);
    glEnd();

    //Left Top part
    glBegin(GL_QUADS);
    glColor3ub(231, 76, 60);
    glVertex2i(13,39);
    glVertex2i(16,31);
    glVertex2i(36,31);
    glVertex2i(36,36);
    glEnd();

    //Right Down->1 part
    glBegin(GL_QUADS);
    glColor3ub(19, 47, 112 );
    glVertex2i(60,-22);
    glVertex2i(61.99,2);
    glVertex2i(84,2);
    glVertex2i(84,-22);
    glEnd();

    //Right ->2 part
    glBegin(GL_QUADS);
    glColor3ub(245, 103, 16);
    glVertex2i(60,6);
    glVertex2i(60,2);
    glVertex2i(85,2);
    glVertex2i(85,6);
    glEnd();

    //Right ->3 part
    glBegin(GL_QUADS);
    glColor3ub(19, 47, 112 );
    glVertex2i(60,6);
    glVertex2i(60,29);
    glVertex2i(84,29);
    glVertex2i(84,6);
    glEnd();

    //Right ->4 part
    glBegin(GL_QUADS);
    glColor3ub(80, 33, 18);
    glVertex2i(60,31);
    glVertex2i(60,29);
    glVertex2i(84,29);
    glVertex2i(84,31);
    glEnd();

    //Right Top part
    glBegin(GL_QUADS);
    glColor3ub(231, 76, 60);
    glVertex2i(60,36);
    glVertex2i(60,31);
    glVertex2i(84,31);
    glVertex2i(83,35);
    glEnd();


    //Gate body design
    glBegin(GL_QUADS);
    glColor3ub(234, 29, 16);
    glVertex2i(36,-22);
    glVertex2i(36,42);
    glVertex2i(66,49);
    glVertex2i(62,-22);
    glEnd();

    //Gate design
    glBegin(GL_QUADS);
    glColor3ub(19, 47, 112 );
    glVertex2i(43,-22);
    glVertex2i(43,0);
    glVertex2i(54,0);
    glVertex2i(54,-22);
    glEnd();

    //Gate Top box design
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(40,35);
    glVertex2i(60,35);
    glVertex2i(60,15);
    glVertex2i(40,15);
    glEnd();
    glColor3f(255,255,0);
    renderBitmapString(43,25,0,GLUT_BITMAP_TIMES_ROMAN_24, "*Aarong*");

    //Art in Market

    //Door Art

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(49, -22);
    glVertex2i(49, 0);

    glEnd();

    //Left Down part Art-1

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(20, -22);
    glVertex2i(20, 2);
    glEnd();

    //Left Down part Art-2

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(33, -22);
    glVertex2i(33, 2);
    glEnd();

    //Left Top part Art-1

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(20, 6);
    glVertex2i(20, 30);
    glEnd();

    //Left Top part Art-2

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(33, 6);
    glVertex2i(33, 30);
    glEnd();

    //Right Down part Art-1

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(66, -22);
    glVertex2i(66, 2);
    glEnd();

    //Left Down part Art-2

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(80, -22);
    glVertex2i(80, 2);
    glEnd();

    //Left Top part Art-1

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(66, 6);
    glVertex2i(66, 30);
    glEnd();

    //Left Top part Art-2

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(80, 6);
    glVertex2i(80, 30);
    glEnd();

    //Tree 2 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(0,-25);
    glVertex2i(0,-10);
    glVertex2i(-2,-10);
    glVertex2i(-2,-25);
    glEnd();

    //Tree Top-1
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-8,-12);
    glVertex2i(-1,9);
    glVertex2i(6,-12);
    glEnd();

    //Tree Top-2
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-7,-5);
    glVertex2i(-1,15);
    glVertex2i(5,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-6,2);
    glVertex2i(-1,22);
    glVertex2i(4,2);
    glEnd();

    //Tree 4 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(91,-25);
    glVertex2i(91,-10);
    glVertex2i(93,-10);
    glVertex2i(93,-25);
    glEnd();

    //Tree Top-1
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(84,-12);
    glVertex2i(92,9);
    glVertex2i(100,-12);
    glEnd();

    //Tree Top-2
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(85,-5);
    glVertex2i(92,15);
    glVertex2i(99,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(86,2);
    glVertex2i(92,22);
    glVertex2i(98,2);
    glEnd();

    //Lamp Draw

    //Lamp 1
    glBegin(GL_QUADS);
    glColor3ub(33, 47, 61);
    glVertex2i(-70,-25);
    glVertex2i(-68,-25);
    glVertex2i(-68,0);
    glVertex2i(-70,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(33, 47, 61);
    glVertex2f(-72,5);
    glVertex2f(-66,5);
    glVertex2f(-69,8);
    glEnd();


    //Light
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0 );
    glVertex2i(-68,0);
    glVertex2i(-70,0);
    glVertex2i(-71,5);
    glVertex2i(-67,5);
    glEnd();



    //Lamp 2
    glBegin(GL_QUADS);
    glColor3ub(33, 47, 61);
    glVertex2i(72,-25);
    glVertex2i(70,-25);
    glVertex2i(70,0);
    glVertex2i(72,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(33, 47, 61);
    glVertex2f(74,5);
    glVertex2f(68,5);
    glVertex2f(71,8);
    glEnd();


    //Light
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0 );
    glVertex2i(70,0);
    glVertex2i(72,0);
    glVertex2i(73,5);
    glVertex2i(69,5);
    glEnd();

    //Lamp 3
    glBegin(GL_QUADS);
    glColor3ub(33, 47, 61);
    glVertex2i(-5,-25);
    glVertex2i(-7,-25);
    glVertex2i(-7,0);
    glVertex2i(-5,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(33, 47, 61);
    glVertex2f(-9,5);
    glVertex2f(-3,5);
    glVertex2f(-6,8);
    glEnd();


    //Light
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0 );
    glVertex2i(-7,0);
    glVertex2i(-5,0);
    glVertex2i(-4,5);
    glVertex2i(-8,5);
    glEnd();

    glPushMatrix();
    glTranslatef(menPosition2,0.0f,0.0f);
//Man 1 fisherMan
    //Left Leg
    glBegin(GL_QUADS);
    glColor3ub(44, 80, 197);
    glVertex2i(-22,-40);
    glVertex2i(-21,-33);
    glVertex2i(-18,-33);
    glVertex2i(-20,-40);

    //Right leg
    glVertex2i(-18,-40);
    glVertex2i(-20,-33);
    glVertex2i(-17,-33);
    glVertex2i(-16,-40);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3ub(56, 225, 38 );
    glVertex2i(-21,-33);
    glVertex2i(-21,-26);
    glVertex2i(-19,-27);
    glVertex2i(-17,-26);
    glVertex2i(-17,-33);
    glEnd();

    //Left hand
    glBegin(GL_QUADS);
    glColor3ub(56, 225, 38 );
    glVertex2i(-22,-26);
    glVertex2i(-21,-26);
    glVertex2i(-21,-30);
    glVertex2i(-22,-30);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-22, -30);
    glVertex2i(-21, -31);
    glEnd();


    //Right hand
    glBegin(GL_QUADS);
    glColor3ub(56, 225, 38 );
    glVertex2i(-17,-26);
    glVertex2i(-16,-26);
    glVertex2i(-16,-30);
    glVertex2i(-17,-30);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-17, -30);
    glVertex2i(-16, -31);
    glEnd();



    //Shoe
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(-18,-40);
    glVertex2i(-17,-38);
    glVertex2i(-16,-40);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(-22,-40);
    glVertex2i(-21,-38);
    glVertex2i(-20,-40);
    glEnd();


    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-19, -27);
    glVertex2i(-19, -24);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 222, 157 );
    x=-19;
    y=-23;
    radius =2.5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Hair
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(-22,-22);
    glVertex2i(-20,-20);
    glVertex2i(-18,-20);
    glVertex2i(-16,-22);
    glEnd();

    //
    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2i(-8,-30);
    glVertex2i(-8,-32);
    glVertex2i(-10,-40);
    glVertex2i(-14,-40);
    glVertex2i(-16,-30);
    glEnd();
    glColor3f(255,0,0);
    renderBitmapString(-13,-34,0,GLUT_BITMAP_TIMES_ROMAN_10, "Fish");

    glPopMatrix();



//Man 5 guard
    //Left Leg
    glBegin(GL_QUADS);
    glColor3ub(128, 71, 71);
    glVertex2i(41,-25);
    glVertex2i(40,-17);
    glVertex2i(37,-17);
    glVertex2i(39,-25);

    //Right leg
    glVertex2i(37,-25);
    glVertex2i(39,-17);
    glVertex2i(36,-17);
    glVertex2i(35,-25);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3ub(128, 71, 71);
    glVertex2i(40,-18);
    glVertex2i(40,-10);
    glVertex2i(38,-11);
    glVertex2i(36,-10);
    glVertex2i(36,-18);
    glEnd();

    //Left hand
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2i(41,-10);
    glVertex2i(40,-10);
    glVertex2i(40,-14);
    glVertex2i(41,-14);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(41, -14);
    glVertex2i(40, -15);
    glEnd();


    //Right hand
    glBegin(GL_QUADS);
    glColor3ub(255,255,255 );
    glVertex2i(36,-10);
    glVertex2i(35,-10);
    glVertex2i(35,-14);
    glVertex2i(36,-14);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(35, -14);
    glVertex2i(36, -15);
    glEnd();

    //Shoe
    glBegin(GL_TRIANGLES);
    glColor3ub(1,0,0);
    glVertex2i(37,-25);
    glVertex2i(36,-23);
    glVertex2i(35,-25);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(41,-25);
    glVertex2i(40,-23);
    glVertex2i(39,-25);
    glEnd();


    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(38, -11);
    glVertex2i(38, -8);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 222, 157 );
    x=38;
    y=-7;
    radius =2.5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Hair
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(41,-6);
    glVertex2i(39,-4);
    glVertex2i(37,-4);
    glVertex2i(35,-6);
    glEnd();

    glPushMatrix();
    glTranslatef(vanPosition2,0.0f,0.0f);
    // Van body
    glBegin(GL_POLYGON);
    glColor3ub(253, 254, 254);
    glVertex2f(-90, -50);
    glVertex2f(-50, -50);
    glVertex2f(-51, -40);
    glVertex2f(-55, -35);
    glVertex2f(-60, -20);
    glVertex2f(-85, -20);
    glVertex2f(-90, -35);
    glEnd();
    //Fish sign
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0); // Fish Tail
    glVertex2f(-79, -33);
    glVertex2f(-72, -37);
    glVertex2f(-74, -33);
    glVertex2f(-72, -29);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0); // Fish body color
    glVertex2f(-87, -33);
    glVertex2f(-77, -39);
    glVertex2f(-77, -26);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0); // Fish  wings
    glVertex2f(-83, -33);
    glVertex2f(-81, -34);
    glVertex2f(-81, -32);
    glEnd();
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    glColor3ub(0, 0, 255);//Fish Eye
    glVertex2f(-85,-33);
    glEnd();


    //Van glass
    glBegin(GL_QUADS);
    glColor3ub(52, 152, 219);
    glVertex2i(-61,-23);
    glVertex2i(-56,-35);
    glVertex2i(-66,-35);
    glVertex2i(-66,-23);
    glEnd();
    //Van bumper
    glBegin(GL_QUADS);
    glColor3ub(46, 64, 83);
    glVertex2i(-88,-50);
    glVertex2i(-91,-50);
    glVertex2i(-91,-46);
    glVertex2i(-88,-46);
    glVertex2i(-52,-50);
    glVertex2i(-52,-46);
    glVertex2i(-49,-46);
    glVertex2i(-49,-50);
    glEnd();

    //Van Light
    glBegin(GL_QUADS);
    glColor3ub(236, 67, 34);
    glVertex2i(-90,-35);
    glVertex2i(-89,-35);
    glVertex2i(-89,-40);
    glVertex2i(-90,-40);
    glColor3ub(251, 250, 32);
    glVertex2i(-51,-40);
    glVertex2i(-55,-40);
    glVertex2i(-55,-42);
    glVertex2i(-51,-42);
    glEnd();

    //Night Light
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0 );
    glVertex2i(-50,-43);
    glVertex2i(-50,-41);
    glVertex2i(-15,-45);
    glVertex2i(-30,-48);
    glEnd();


    //Van wheel-1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=-61;
    y=-50;
    radius =6;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=-61;
    y=-50;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Van wheel-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=-79;
    y=-50;
    radius =6;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=-79;
    y=-50;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(carPosition2,0.0f,0.0f);
    //car body
    glBegin(GL_QUADS);
    glColor3ub(125, 60, 152);
    glVertex2i(50,-70);
    glVertex2i(85,-70);
    glVertex2i(87,-80);
    glVertex2i(48,-80);
    glVertex2i(58,-70);
    glVertex2i(61,-60);
    glVertex2i(76,-60);
    glVertex2i(78,-70);
    glEnd();

    //car glass
    glBegin(GL_QUADS);
    glColor3ub(52, 152, 219);
    glVertex2i(59,-70);
    glVertex2i(62,-61);
    glVertex2i(75,-61);
    glVertex2i(77,-70);
    glVertex2i(69,-70);
    glVertex2i(69,-61);
    glVertex2i(73,-61);
    glVertex2i(75,-70);
    glEnd();

    //car bumper
    glBegin(GL_QUADS);
    glColor3ub(46, 64, 83);
    glVertex2i(46,-80);
    glVertex2i(53,-80);
    glVertex2i(53,-76);
    glVertex2i(46,-76);
    glVertex2i(88,-80);
    glVertex2i(82,-80);
    glVertex2i(82,-76);
    glVertex2i(88,-76);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(69,-80);
    glVertex2i(69,-60);
    glVertex2i(58,-70);
    glVertex2i(78,-70);
    glEnd();

    //car Light
    glBegin(GL_QUADS);
    glColor3ub(236, 67, 34);
    glVertex2i(84,-70);
    glVertex2i(85,-70);
    glVertex2i(85,-75);
    glVertex2i(84,-75);
    glColor3ub(226, 224, 224);
    glVertex2i(51,-70);
    glVertex2i(49,-70);
    glVertex2i(49,-72);
    glVertex2i(51,-72);
    glEnd();

    //Front Light Night
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0 );
    glVertex2i(49,-73);
    glVertex2i(49,-70);
    glVertex2i(14,-76);
    glVertex2i(29,-79);
    glEnd();

    //Car wheel-1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=60;
    y=-80;
    radius =5;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=60;
    y=-80;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Car wheel-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=75;
    y=-80;
    radius =5;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=75;
    y=-80;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(policecarPosition,0.0f,0.0f);

    //Police Car
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2i(45,-90);
    glVertex2i(48,-78);
    glVertex2i(57,-75);
    glVertex2i(65,-65);
    glVertex2i(83,-65);
    glVertex2i(86,-75);
    glVertex2i(93,-75);
    glVertex2i(95,-90);
    glEnd();

    //Front window
    glBegin(GL_QUADS);
    glColor3ub(35, 148, 186);
    glVertex2i(65,-67);
    glVertex2i(73,-67);
    glVertex2i(73,-74);
    glVertex2i(60,-74);
    glEnd();

    //Back window
    glBegin(GL_QUADS);
    glColor3ub(35, 148, 186);
    glVertex2i(74,-67);
    glVertex2i(82,-67);
    glVertex2i(84,-74);
    glVertex2i(74,-74);
    glEnd();

    //Body Art
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(35, 57, 186);
    glVertex2i(52, -80);
    glVertex2i(88, -80);
    glEnd();

    //Front art
    glBegin(GL_QUADS);
    glColor3ub(40, 55, 71 );
    glVertex2i(44,-90);
    glVertex2i(48,-90);
    glVertex2i(48,-87);
    glVertex2i(44,-87);
    glEnd();

    //Back art
    glBegin(GL_QUADS);
    glColor3ub(40, 55, 71 );
    glVertex2i(92,-90);
    glVertex2i(97,-90);
    glVertex2i(97,-87);
    glVertex2i(92,-87);
    glEnd();

    //Front Light art
    glBegin(GL_QUADS);
    glColor3ub(247, 43, 43 );
    glVertex2i(47,-82);
    glVertex2i(50,-82);
    glVertex2i(50,-79);
    glVertex2i(48,-79);
    glEnd();

    //Back Light art
    glBegin(GL_QUADS);
    glColor3ub(247, 43, 43 );
    glVertex2i(91,-82);
    glVertex2i(94,-82);
    glVertex2i(93,-79);
    glVertex2i(91,-79);
    glEnd();

    //Top Light
    glBegin(GL_QUADS);
    glColor3ub(189, 8, 8 );
    glVertex2i(67,-65);
    glVertex2i(69,-65);
    glVertex2i(69,-63);
    glVertex2i(67,-63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(8, 68, 189 );
    glVertex2i(69,-65);
    glVertex2i(71,-65);
    glVertex2i(71,-63);
    glVertex2i(69,-63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(189, 8, 8 );
    glVertex2i(71,-65);
    glVertex2i(73,-65);
    glVertex2i(73,-63);
    glVertex2i(71,-63);
    glEnd();

    //Front Light Night
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0 );
    glVertex2i(45,-82);
    glVertex2i(45,-79);
    glVertex2i(10,-84);
    glVertex2i(25,-87);
    glEnd();

    //Front tire
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=60;
    y=-90;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    //Front Tire middle
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=60;
    y=-90;
    radius =3;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    //Back Tire
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=80;
    y=-90;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Back Tire Middle
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=80;
    y=-90;
    radius =3;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();



    glFlush();

}


void display2 (void)
{

    glClear(GL_COLOR_BUFFER_BIT);

    //SKY
    glBegin(GL_QUADS);
    glColor3ub(10, 196, 236 );
    glVertex2i(-100,-20);
    glVertex2i(-100,100);
    glVertex2i(100,100);
    glVertex2i(100,-20);
    glEnd();


    glPushMatrix();
    glTranslatef(sunPosition2,0.0f,0.0f);
    //Sun draw
    float x, y;
    int i;
    GLfloat radius;
    int triangleAmount =40;
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(247, 254, 0);
    x=70;
    y=75;
    radius =10;
    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloudPosition3,0.0f,0.0f);
    //Cloud-1

    //P-1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-75;
    y=92;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-79;
    y=87;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-3
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-85;
    y=82;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-4
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-80;
    y=81;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-5
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-73;
    y=85;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-6
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-74;
    y=79;
    radius =3;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloudPosition4,0.0f,0.0f);
    //Cloud-2

    //P-1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-35;
    y=78;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-41;
    y=73;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-3
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-47;
    y=67;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-4
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-40;
    y=66;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-5
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255 );
    x=-33;
    y=70;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();
    glPopMatrix();

    //Grass
    glBegin(GL_QUADS);
    glColor3ub(136, 221, 12 );
    glVertex2i(-100,-20);
    glVertex2i(-100,-40);
    glVertex2i(100,-40);
    glVertex2i(100,-20);
    glEnd();


    //Road background
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(-100,-40);
    glVertex2i(-100,-100);
    glVertex2i(100,-100);
    glVertex2i(100,-40);
    glEnd();



    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3f(253, 254, 254);
    glVertex2i(-100,-70);
    glVertex2i(-80,-70);
    glVertex2i(-70,-70);
    glVertex2i(-50,-70);
    glVertex2i(-60,-70);
    glVertex2i(-40,-70);
    glVertex2i(-30,-70);
    glVertex2i(-10,-70);
    glVertex2i(0,-70);
    glVertex2i(20,-70);
    glVertex2i(30,-70);
    glVertex2i(50,-70);
    glVertex2i(60,-70);
    glVertex2i(80,-70);
    glVertex2i(90,-70);
    glVertex2i(100,-70);
    glEnd();

    //Background left 1st

    glBegin(GL_QUADS);
    glColor3ub(204, 209, 209 );
    glVertex2i(-101,-20);
    glVertex2i(-101,23);
    glVertex2i(-95,23);
    glVertex2i(-95,-20);
    glEnd();

    //Background left 2nd

    glBegin(GL_QUADS);
    glColor3ub(179, 182, 183);
    glVertex2i(-50,-20);
    glVertex2i(-50,23);
    glVertex2i(-28,23);
    glVertex2i(-28,-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(93, 173, 226);
    glVertex2i(-46,-10);
    glVertex2i(-46,18);
    glVertex2i(-33,18);
    glVertex2i(-33,-10);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-46, 14);
    glVertex2i(-33, 14);
    glVertex2i(-46, 10);
    glVertex2i(-33, 10);
    glVertex2i(-46, 6);
    glVertex2i(-33, 6);
    glVertex2i(-39, 18);
    glVertex2i(-39, -10);
    glEnd();

    //Background Right 1st

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2i(25,-20);
    glVertex2i(25,18);
    glVertex2i(37,18);
    glVertex2i(37,-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(93, 173, 226);
    glVertex2i(25,5);
    glVertex2i(25,15);
    glVertex2i(35,15);
    glVertex2i(35,5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150 );
    glVertex2i(35,-20);
    glVertex2i(35,13);
    glVertex2i(50,13);
    glVertex2i(50,-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(93, 173, 226);
    glVertex2i(37,3);
    glVertex2i(37,10);
    glVertex2i(50,10);
    glVertex2i(50,3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2i(95,-20);
    glVertex2i(95,13);
    glVertex2i(100,13);
    glVertex2i(100,-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(93, 173, 226);
    glVertex2i(95,3);
    glVertex2i(95,10);
    glVertex2i(98,10);
    glVertex2i(98,3);
    glEnd();


    //Tree-2 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(-36,-23);
    glVertex2i(-36,-11);
    glVertex2i(-34,-11);
    glVertex2i(-34,-23);
    glEnd();

    //Tree Top-1
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-42,-12);
    glVertex2i(-35,7);
    glVertex2i(-29,-12);
    glEnd();

    //Tree Top-2
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-40,-5);
    glVertex2i(-35,13);
    glVertex2i(-30,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-39,2);
    glVertex2i(-35,15);
    glVertex2i(-31,2);
    glEnd();

    //Restaurant Stairs
    glBegin(GL_QUADS);
    glColor3ub(46, 64, 83);
    glVertex2i(-40,-30);
    glVertex2i(-40,-25);
    glVertex2i(40,-25);
    glVertex2i(40,-30);
    glVertex2i(-35,-25);
    glVertex2i(-35,-20);
    glVertex2i(35,-20);
    glVertex2i(35,-25);
    glEnd();

    //glBegin(GL_LINES);
    //glColor3f(206.0f, 193.0f, 111.0f);
    //glVertex2i(-100,0);
    //glVertex2i(100,0);
    //glEnd();

    //Restaurant pillers
    glBegin(GL_QUADS);
    glColor3ub(247, 220, 111);
    glVertex2i(34,-20);
    glVertex2i(32,-20);
    glVertex2i(32,30);
    glVertex2i(34,30);

    glVertex2i(-34,-20);
    glVertex2i(-32,-20);
    glVertex2i(-32,30);
    glVertex2i(-34,30);
    glEnd();


    //Reastaurant Room 1st floor
    glBegin(GL_QUADS);
    glColor3ub(230, 126, 34);
    glVertex2i(30,-20);
    glVertex2i(10,-20);
    glVertex2i(10,0);
    glVertex2i(30,0);
    glVertex2i(-30,-20);
    glVertex2i(-10,-20);
    glVertex2i(-10,0);
    glVertex2i(-30,0);
    glEnd();

    //Restaurant Roof 1st floor
    glBegin(GL_QUADS);
    glColor3ub(247, 220, 111);
    glVertex2i(30,0);
    glVertex2i(10,0);
    glVertex2i(10,5);
    glVertex2i(30,5);
    glVertex2i(-30,0);
    glVertex2i(-10,0);
    glVertex2i(-10,5);
    glVertex2i(-30,5);
    glVertex2i(10,5);
    glVertex2i(-10,5);
    glVertex2i(-10,10);
    glVertex2i(10,10);
    glEnd();

    //Restaurant Room 1st floor Glass system
    glBegin(GL_QUADS);
    glColor3ub(253, 254, 254);
    glVertex2i(29,-19);
    glVertex2i(11,-19);
    glVertex2i(11,-1);
    glVertex2i(29,-1);
    glVertex2i(-29,-19);
    glVertex2i(-11,-19);
    glVertex2i(-11,-1);
    glVertex2i(-29,-1);
    glEnd();

    //Restaurant Room 1st floor Glass 1
    glBegin(GL_QUADS);
    glColor3ub(174, 214, 241);
    glVertex2i(12,-18);
    glVertex2i(12,-2);
    glVertex2i(19,-2);
    glVertex2i(19,-18);
    glVertex2i(-12,-18);
    glVertex2i(-12,-2);
    glVertex2i(-19,-2);
    glVertex2i(-19,-18);

    glEnd();

    //restaurant Room 1st floor Glass 2
    glBegin(GL_QUADS);
    glColor3ub(174, 214, 241);
    glVertex2i(20,-18);
    glVertex2i(20,-2);
    glVertex2i(28,-2);
    glVertex2i(28,-18);
    glVertex2i(-20,-18);
    glVertex2i(-20,-2);
    glVertex2i(-28,-2);
    glVertex2i(-28,-18);

    glEnd();

    //Restaurant Room 2nd floor
    glBegin(GL_QUADS);
    glColor3ub(230, 126, 34);
    glVertex2i(30,5);
    glVertex2i(10,5);
    glVertex2i(10,25);
    glVertex2i(30,25);
    glVertex2i(-30,5);
    glVertex2i(-10,5);
    glVertex2i(-10,25);
    glVertex2i(-30,25);
    glEnd();

    //Restaurant Roof 2nd floor
    glBegin(GL_QUADS);
    glColor3ub(100, 30, 22);
    glVertex2i(40,25);
    glVertex2i(10,25);
    glVertex2i(10,30);
    glVertex2i(40,30);
    glVertex2i(-40,25);
    glVertex2i(-10,25);
    glVertex2i(-10,30);
    glVertex2i(-40,30);
    glVertex2i(12,35);
    glVertex2i(-12,35);
    glVertex2i(-12,40);
    glVertex2i(12,40);
    glVertex2i(13,40);  // For lobby
    glVertex2i(-13,40);
    glVertex2i(-13,45);
    glVertex2i(13,45);
    glEnd();
    glColor3f(255,255,255);
    renderBitmapString(-8,39,0,GLUT_BITMAP_TIMES_ROMAN_24, "Restaurant");



    //Restaurant Room 2nd floor Glass system
    glBegin(GL_QUADS);
    glColor3ub(253, 254, 254);
    glVertex2i(29,6);
    glVertex2i(11,6);
    glVertex2i(11,24);
    glVertex2i(29,24);
    glColor3ub(253, 254, 254);
    glVertex2i(-29,6);
    glVertex2i(-11,6);
    glVertex2i(-11,24);
    glVertex2i(-29,24);
    glEnd();


    //Restaurant Room 2nd floor Glass 1
    glBegin(GL_QUADS);
    glColor3ub(174, 214, 241);
    glVertex2i(12,7);
    glVertex2i(12,23);
    glVertex2i(19,23);
    glVertex2i(19,7);
    glVertex2i(-12,7);
    glVertex2i(-12,23);
    glVertex2i(-19,23);
    glVertex2i(-19,7);

    glEnd();

    //Restaurant Room 2nd floor Glass 2
    glBegin(GL_QUADS);
    glColor3ub(174, 214, 241);
    glVertex2i(20,6);
    glVertex2i(20,23);
    glVertex2i(28,23);
    glVertex2i(28,6);
    glVertex2i(-20,6);
    glVertex2i(-20,23);
    glVertex2i(-28,23);
    glVertex2i(-28,6);

    glEnd();

    //restaurant lobby 1st floor
    glBegin(GL_QUADS);
    glColor3ub(211, 84, 0);
    glVertex2i(10,-20);
    glVertex2i(-10,-20);
    glVertex2i(-10,5);
    glVertex2i(10,5);
    glEnd();

    //Restaurant lobby 2nd floor
    glBegin(GL_QUADS);
    glColor3ub(211, 84, 0);
    glVertex2i(10,10);
    glVertex2i(-10,10);
    glVertex2i(-10,35);
    glVertex2i(10,35);
    glEnd();

    //Gate pillers
    glBegin(GL_QUADS);
    glColor3ub(247, 220, 111);
    glVertex2i(8,-20);
    glVertex2i(6,-20);
    glVertex2i(6,-5);
    glVertex2i(8,-5);

    glVertex2i(-8,-20);
    glVertex2i(-6,-20);
    glVertex2i(-6,-5);
    glVertex2i(-8,-5);
    glEnd();

    //Restaurant Roof Gate
    glBegin(GL_QUADS);
    glColor3ub(100, 30, 22);
    glVertex2i(9,-5);  // For gate
    glVertex2i(-9,-5);
    glVertex2i(-9,0);
    glVertex2i(9,0);
    glEnd();

    //Restaurant Gate Glass system
    glBegin(GL_QUADS);
    glColor3ub(174, 214, 241);
    glVertex2i(4,-20);
    glVertex2i(4,-5);
    glVertex2i(-4,-5);
    glVertex2i(-4,-20);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2i(0,-20);
    glVertex2i(0,-5);
    glEnd();

    //Restaurant Front gateway
    glBegin(GL_QUADS);
    glColor3ub(171, 178, 185 );
    glVertex2i(-40,-30);
    glVertex2i(-45,-40);
    glVertex2i(45,-40);
    glVertex2i(40,-30);
    glEnd();
    glColor3f(0,0,255);
    renderBitmapString(-8,23,0,GLUT_BITMAP_TIMES_ROMAN_24, "CookinDel");
    //Footpath Left
    glBegin(GL_QUADS);
    glColor3ub(148, 49, 38);
    glVertex2i(-45,-40);
    glVertex2i(-50,-35);
    glVertex2i(-100,-35);
    glVertex2i(-100,-40);
    glColor3ub(203, 67, 53  );
    glVertex2i(-45,-40);
    glVertex2i(-50,-35);
    glVertex2i(-45,-25);
    glVertex2i(-40,-30);
    glVertex2i(-45,-25);
    glVertex2i(-50,-35);
    glVertex2i(-100,-35);
    glVertex2i(-100,-25);
    glEnd();

    //Footpath right
    glBegin(GL_QUADS);
    glColor3ub(148, 49, 38);
    glVertex2i(45,-40);
    glVertex2i(50,-35);
    glVertex2i(100,-35);
    glVertex2i(100,-40);
    glColor3ub(203, 67, 53  );
    glVertex2i(45,-40);
    glVertex2i(50,-35);
    glVertex2i(45,-25);
    glVertex2i(40,-30);
    glVertex2i(45,-25);
    glVertex2i(50,-35);
    glVertex2i(100,-35);
    glVertex2i(100,-25);
    glEnd();




    //School second body
    glBegin(GL_QUADS);
    glColor3ub(228, 154, 34 );
    glVertex2i(45,15);
    glVertex2i(45,-20);
    glVertex2i(83,-20);
    glVertex2i(83,15);
    glEnd();

    //School second body border
    glBegin(GL_QUADS);
    glColor3ub(247, 220, 111 );
    glVertex2i(81,-1);
    glVertex2i(81,-4);
    glVertex2i(45,-4);
    glVertex2i(45,-1);
    glEnd();


    //School second body window
    glBegin(GL_QUADS);
    glColor3ub(174, 214, 241);
    glVertex2i(48,10);
    glVertex2i(52,10);
    glVertex2i(52,4);
    glVertex2i(48,4);
    glVertex2i(55,10);
    glVertex2i(59,10);
    glVertex2i(59,4);
    glVertex2i(55,4);
    glVertex2i(62,10);
    glVertex2i(66,10);
    glVertex2i(66,4);
    glVertex2i(62,4);
    glVertex2i(69,10);
    glVertex2i(73,10);
    glVertex2i(73,4);
    glVertex2i(69,4);
    glVertex2i(76,10);
    glVertex2i(80,10);
    glVertex2i(80,4);
    glVertex2i(76,4);


    glVertex2i(48,-9);
    glVertex2i(52,-9);
    glVertex2i(52,-15);
    glVertex2i(48,-15);
    glVertex2i(55,-9);
    glVertex2i(59,-9);
    glVertex2i(59,-15);
    glVertex2i(55,-15);
    glVertex2i(62,-9);
    glVertex2i(66,-9);
    glVertex2i(66,-15);
    glVertex2i(62,-15);
    glVertex2i(69,-9);
    glVertex2i(73,-9);
    glVertex2i(73,-15);
    glVertex2i(69,-15);
    glVertex2i(76,-9);
    glVertex2i(80,-9);
    glVertex2i(80,-15);
    glVertex2i(76,-15);


    glEnd();


    //School second body roof
    glBegin(GL_QUADS);
    glColor3ub(211, 84, 0);
    glVertex2i(83,15);
    glVertex2i(84,30);
    glVertex2i(50,30);
    glVertex2i(40,15);
    glEnd();


    //School first body
    glBegin(GL_QUADS);
    glColor3ub(205, 135, 22 );
    glVertex2i(81,-20);
    glVertex2i(95,-20);
    glVertex2i(95,24);
    glVertex2i(81,24);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(205, 135, 22 );
    glVertex2f(81,24);
    glVertex2f(88,35);
    glVertex2f(95,24);
    glEnd();


    //School Gate
    glBegin(GL_QUADS);
    glColor3ub(28, 40, 51);
    glVertex2i(98,-25);
    glVertex2i(98,-23);
    glVertex2i(78,-23);
    glVertex2i(78,-25);

    glVertex2i(98,-3);
    glVertex2i(98,-1);
    glVertex2i(78,-1);
    glVertex2i(78,-3);
    glEnd();

    //School Gate way
    glBegin(GL_QUADS);
    glColor3ub(174, 214, 241);
    glVertex2i(93,-20);
    glVertex2i(83,-20);
    glVertex2i(83,-5);
    glVertex2i(93,-5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(23, 32, 42);
    glVertex2i(88,-20);
    glVertex2i(88,-5);
    glEnd();

    //School Gate floor
    glBegin(GL_QUADS);
    glColor3ub(178, 186, 187 );
    glVertex2i(96,-23);
    glVertex2i(93,-20);
    glVertex2i(83,-20);
    glVertex2i(80,-23);
    glEnd();

    //School Gate pillers
    glBegin(GL_QUADS);
    glColor3ub(244, 208, 63);
    glVertex2i(98,-23);
    glVertex2i(98,-3);
    glVertex2i(96,-3);
    glVertex2i(96,-23);

    glVertex2i(78,-23);
    glVertex2i(78,-3);
    glVertex2i(80,-3);
    glVertex2i(80,-23);
    glEnd();


    //School Gate roof
    glBegin(GL_QUADS);
    glColor3ub(160, 64, 0 );
    glVertex2i(78,25);
    glVertex2i(81,24);
    glVertex2i(88,35);
    glVertex2i(88,40);

    glVertex2i(98,25);
    glVertex2i(95,24);
    glVertex2i(88,35);
    glVertex2i(88,40);
    glEnd();


    //School first body border
    glBegin(GL_QUADS);
    glColor3ub(247, 220, 111 );
    glVertex2i(81,-1);
    glVertex2i(81,2);
    glVertex2i(95,2);
    glVertex2i(95,-1);
    glEnd();

    //School first body window
    glBegin(GL_QUADS);
    glColor3ub(174, 214, 241);
    glVertex2i(93,5);
    glVertex2i(83,5);
    glVertex2i(83,15);
    glVertex2i(93,15);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(23, 32, 42);
    glVertex2i(88,5);
    glVertex2i(88,15);
    glVertex2i(93,10);
    glVertex2i(83,10);
    glEnd();

    //Tree-1 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(-44,-25);
    glVertex2i(-44,-10);
    glVertex2i(-42,-10);
    glVertex2i(-42,-25);
    glEnd();

    //Tree Top 1
    glBegin(GL_TRIANGLES);
    glColor3ub(34, 153, 84 );
    glVertex2i(-51,-12);
    glVertex2i(-43,9);
    glVertex2i(-35,-12);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(34, 153, 84 );
    glVertex2i(-50,-5);
    glVertex2i(-43,15);
    glVertex2i(-36,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(34, 153, 84 );
    glVertex2i(-49,2);
    glVertex2i(-43,22);
    glVertex2i(-37,2);
    glEnd();


    //Tree-3 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(44,-25);
    glVertex2i(44,-10);
    glVertex2i(42,-10);
    glVertex2i(42,-25);
    glEnd();

    //Tree Top 1
    glBegin(GL_TRIANGLES);
    glColor3ub(49, 189, 40 );
    glVertex2i(51,-12);
    glVertex2i(43,9);
    glVertex2i(35,-12);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(49, 189, 40 );
    glVertex2i(50,-5);
    glVertex2i(43,15);
    glVertex2i(36,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(49, 189, 40 );
    glVertex2i(49,2);
    glVertex2i(43,22);
    glVertex2i(37,2);
    glEnd();


    //company building
    glBegin(GL_QUADS);
    glColor3ub(244, 247, 122 );
    glVertex2i(-98,-25);
    glVertex2i(-70,-25);
    glVertex2i(-70,10);
    glVertex2i(-98,10);
    glVertex2i(-98,15);
    glVertex2i(-70,15);
    glVertex2i(-70,50);
    glVertex2i(-98,50);
    glVertex2i(-50,-25);
    glVertex2i(-70,-25);
    glVertex2i(-70,25);
    glVertex2i(-50,25);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0, 0, 0 );
    glVertex2i(-70,-25);
    glVertex2i(-70,50);
    glEnd();

    //company building roof
    glBegin(GL_QUADS);
    glColor3ub(93, 109, 126);
    glVertex2i(-99,15);
    glVertex2i(-70,15);
    glVertex2i(-70,10);
    glVertex2i(-99,10);
    glVertex2i(-99,50);
    glVertex2i(-70,50);
    glVertex2i(-70,55);
    glVertex2i(-99,55);
    glVertex2i(-48,25);
    glVertex2i(-70,25);
    glVertex2i(-70,30);
    glVertex2i(-48,30);
    glColor3ub(33, 47, 61 );
    glVertex2i(-45,35);
    glVertex2i(-70,35);
    glVertex2i(-70,30);
    glVertex2i(-45,30);
    glEnd();

    //company Gate Glass system
    glBegin(GL_QUADS);
    glColor3ub(93, 173, 226 );
    glVertex2i(-88,-25);
    glVertex2i(-80,-25);
    glVertex2i(-80,-5);
    glVertex2i(-88,-5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2i(-84,-25);
    glVertex2i(-84,-5);
    glEnd();

    //company window Glass system
    glBegin(GL_QUADS);
    glColor3ub(93, 173, 226 );
    glVertex2i(-96,-20);
    glVertex2i(-90,-20);
    glVertex2i(-90,5);
    glVertex2i(-96,5);
    glVertex2i(-78,-20);
    glVertex2i(-72,-20);
    glVertex2i(-72,5);
    glVertex2i(-78,5);
    glVertex2i(-52,-20);
    glVertex2i(-68,-20);
    glVertex2i(-68,-10);
    glVertex2i(-52,-10);
    glVertex2i(-52,-5);
    glVertex2i(-68,-5);
    glVertex2i(-68,5);
    glVertex2i(-52,5);
    glVertex2i(-52,20);
    glVertex2i(-68,20);
    glVertex2i(-68,10);
    glVertex2i(-52,10);
    glVertex2i(-96,20);
    glVertex2i(-72,20);
    glVertex2i(-72,30);
    glVertex2i(-96,30);
    glVertex2i(-96,35);
    glVertex2i(-72,35);
    glVertex2i(-72,45);
    glVertex2i(-96,45);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2i(-96,-10);
    glVertex2i(-90,-10);
    glVertex2i(-78,-10);
    glVertex2i(-72,-10);
    glEnd();





    //Lamp 1
    glBegin(GL_QUADS);
    glColor3ub(33, 47, 61);
    glVertex2i(-72,-25);
    glVertex2i(-70,-25);
    glVertex2i(-70,0);
    glVertex2i(-72,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(33, 47, 61);
    glVertex2f(-74,5);
    glVertex2f(-68,5);
    glVertex2f(-71,8);
    glEnd();


    //Light
    glBegin(GL_QUADS);
    glColor3ub(253, 254, 254);
    glVertex2i(-70,0);
    glVertex2i(-72,0);
    glVertex2i(-73,5);
    glVertex2i(-69,5);
    glEnd();



    //Lamp 2
    glBegin(GL_QUADS);
    glColor3ub(33, 47, 61);
    glVertex2i(72,-25);
    glVertex2i(70,-25);
    glVertex2i(70,0);
    glVertex2i(72,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(33, 47, 61);
    glVertex2f(74,5);
    glVertex2f(68,5);
    glVertex2f(71,8);
    glEnd();


    //Light
    glBegin(GL_QUADS);
    glColor3ub(253, 254, 254);
    glVertex2i(70,0);
    glVertex2i(72,0);
    glVertex2i(73,5);
    glVertex2i(69,5);
    glEnd();



    glPushMatrix();
    glTranslatef(lmenPosition1,0.0f,0.0f);
    //Man 3 Draw (Hujur)
    //Left Leg
    glBegin(GL_QUADS);
    glColor3ub(243, 216, 216 );
    glVertex2i(-68,-27);
    glVertex2i(-67,-19);
    glVertex2i(-64,-19);
    glVertex2i(-66,-27);

    //Right leg
    glVertex2i(-64,-27);
    glVertex2i(-66,-19);
    glVertex2i(-63,-19);
    glVertex2i(-62,-27);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 254);
    glVertex2i(-68,-21);
    glVertex2i(-67,-12);
    glVertex2i(-65,-13);
    glVertex2i(-63,-12);
    glVertex2i(-62,-21);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(15, 126, 241 );
    glVertex2i(-67,-21);
    glVertex2i(-66,-12);
    glVertex2i(-65,-16);
    glVertex2i(-64,-12);
    glVertex2i(-63,-21);
    glEnd();


    //Left hand
    glBegin(GL_QUADS);
    glColor3ub(15, 126, 241 );
    glVertex2i(-68,-12);
    glVertex2i(-67,-12);
    glVertex2i(-67,-17);
    glVertex2i(-68,-17);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-68, -17);
    glVertex2i(-67, -17);
    glEnd();


    //Right hand
    glBegin(GL_QUADS);
    glColor3ub(15, 126, 241 );
    glVertex2i(-63,-12);
    glVertex2i(-62,-12);
    glVertex2i(-62,-16);
    glVertex2i(-63,-16);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-62, -16);
    glVertex2i(-63, -17);
    glEnd();

    //Shoe
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(-64,-27);
    glVertex2i(-63,-25);
    glVertex2i(-62,-27);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(-68,-27);
    glVertex2i(-67,-25);
    glVertex2i(-66,-27);
    glEnd();


    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-65, -13);
    glVertex2i(-65, -10);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 222, 157 );
    x=-65;
    y=-9;
    radius =2.5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Hair
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(-68,-8);
    glVertex2i(-66,-6);
    glVertex2i(-64,-6);
    glVertex2i(-62,-8);
    glEnd();


    glPopMatrix();


    glPushMatrix();
    glTranslatef(bmenPosition1,0.0f,0.0f);
    //Man 5 Draw
    //Left Leg
    glBegin(GL_QUADS);
    glColor3ub(127, 50, 19 );
    glVertex2i(68,-30);
    glVertex2i(67,-22);
    glVertex2i(64,-22);
    glVertex2i(66,-30);

    //Right leg
    glVertex2i(64,-30);
    glVertex2i(66,-22);
    glVertex2i(63,-22);
    glVertex2i(62,-30);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3ub(15, 189, 157  );
    glVertex2i(67,-22);
    glVertex2i(67,-15);
    glVertex2i(65,-16);
    glVertex2i(63,-15);
    glVertex2i(63,-22);
    glEnd();

    //Left hand
    glBegin(GL_QUADS);
    glColor3ub(15, 189, 157 );
    glVertex2i(68,-15);
    glVertex2i(67,-15);
    glVertex2i(67,-19);
    glVertex2i(68,-19);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(68, -19);
    glVertex2i(67, -20);
    glEnd();


    //Right hand
    glBegin(GL_QUADS);
    glColor3ub(15, 189, 157  );
    glVertex2i(63,-15);
    glVertex2i(62,-15);
    glVertex2i(62,-19);
    glVertex2i(63,-19);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(62, -19);
    glVertex2i(63, -20);
    glEnd();

    //Bag
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2i(62, -22);
    glVertex2i(62, -28);
    glEnd();

    //Shoe
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(64,-30);
    glVertex2i(63,-28);
    glVertex2i(62,-30);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(68,-30);
    glVertex2i(67,-28);
    glVertex2i(66,-30);
    glEnd();


    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(65, -16);
    glVertex2i(65, -13);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 222, 157 );
    x=65;
    y=-12;
    radius =2.5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Hair
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2i(68,-11);
    glVertex2i(66,-9);
    glVertex2i(64,-9);
    glVertex2i(62,-11);
    glEnd();


    glPopMatrix();

    glPushMatrix();
    glTranslatef(emenPosition1,0.0f,0.0f);
    //Man 4 Draw
    //Left Leg
    glBegin(GL_QUADS);
    glColor3ub(92, 160, 175);
    glVertex2i(58,-33);
    glVertex2i(57,-25);
    glVertex2i(54,-25);
    glVertex2i(56,-33);

    //Right leg
    glVertex2i(54,-33);
    glVertex2i(56,-25);
    glVertex2i(53,-24);
    glVertex2i(52,-33);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3ub(203, 167, 242 );
    glVertex2i(57,-25);
    glVertex2i(57,-18);
    glVertex2i(55,-19);
    glVertex2i(53,-18);
    glVertex2i(53,-25);
    glEnd();

    //Left hand
    glBegin(GL_QUADS);
    glColor3ub(203, 167, 242 );
    glVertex2i(58,-18);
    glVertex2i(57,-18);
    glVertex2i(57,-22);
    glVertex2i(58,-22);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(58, -22);
    glVertex2i(57, -23);
    glEnd();


    //Right hand
    glBegin(GL_QUADS);
    glColor3ub(203, 167, 242);
    glVertex2i(53,-18);
    glVertex2i(52,-18);
    glVertex2i(52,-22);
    glVertex2i(53,-22);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(52, -22);
    glVertex2i(53, -23);
    glEnd();


    //Shoe
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(54,-33);
    glVertex2i(53,-31);
    glVertex2i(52,-33);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(58,-33);
    glVertex2i(57,-31);
    glVertex2i(56,-33);
    glEnd();


    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(55, -19);
    glVertex2i(55, -16);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 222, 157 );
    x=55;
    y=-15;
    radius =2.5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Hair
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2i(58,-14);
    glVertex2i(56,-12);
    glVertex2i(54,-12);
    glVertex2i(52,-14);
    glEnd();


    glPopMatrix();

    glPushMatrix();
    glTranslatef(basketPosition,0.0f,0.0f);
//Man 1 Draw
    //Left Leg
    glBegin(GL_QUADS);
    glColor3ub(44, 80, 197);
    glVertex2i(22,-40);
    glVertex2i(23,-32);
    glVertex2i(26,-32);
    glVertex2i(24,-40);

    //Right leg
    glVertex2i(26,-40);
    glVertex2i(24,-32);
    glVertex2i(27,-32);
    glVertex2i(28,-40);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3ub(56, 225, 38 );
    glVertex2i(23,-33);
    glVertex2i(23,-26);
    glVertex2i(25,-27);
    glVertex2i(27,-26);
    glVertex2i(27,-33);
    glEnd();

    //Left hand
    glBegin(GL_QUADS);
    glColor3ub(56, 225, 38 );
    glVertex2i(22,-26);
    glVertex2i(23,-26);
    glVertex2i(23,-30);
    glVertex2i(22,-30);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(23, -30);
    glVertex2i(22, -31);
    glEnd();


    //Right hand
    glBegin(GL_QUADS);
    glColor3ub(56, 225, 38 );
    glVertex2i(27,-26);
    glVertex2i(28,-26);
    glVertex2i(28,-30);
    glVertex2i(27,-30);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(27, -30);
    glVertex2i(28, -31);
    glEnd();

    //Shoe
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(26,-40);
    glVertex2i(27,-38);
    glVertex2i(28,-40);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(22,-40);
    glVertex2i(23,-38);
    glVertex2i(24,-40);
    glEnd();


    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(25, -27);
    glVertex2i(25, -24);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(249, 231, 159 );
    x=25;
    y=-23;
    radius =2.5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    //Hair
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(22,-22);
    glVertex2i(24,-20);
    glVertex2i(26,-20);
    glVertex2i(28,-22);
    glEnd();

    //
    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2i(36,-30);
    glVertex2i(34,-40);
    glVertex2i(30,-40);
    glVertex2i(28,-30);
    glEnd();
    glColor3f(255,0,0);
    renderBitmapString(31,-35,0,GLUT_BITMAP_TIMES_ROMAN_10, "Fish");

    glPopMatrix();
    glPushMatrix();
    glTranslatef(vanPosition1,0.0f,0.0f);
    // Van body
    glBegin(GL_POLYGON);
    glColor3ub(253, 254, 254);
    glVertex2f(-90, -50);
    glVertex2f(-50, -50);
    glVertex2f(-51, -40);
    glVertex2f(-55, -35);
    glVertex2f(-60, -20);
    glVertex2f(-85, -20);
    glVertex2f(-90, -35);
    glEnd();
    //Fish sign
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(-79, -35);
    glVertex2f(-71, -39);
    glVertex2f(-73, -35);
    glVertex2f(-71, -31);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0);
    glVertex2f(-87, -35);
    glVertex2f(-77, -40);
    glVertex2f(-77, -28);
    glEnd();

    glPointSize(3.0f);
    glBegin(GL_POINTS);
    glColor3ub(0, 0, 255);//Fish Eye
    glVertex2f(-85,-35);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(-83, -35);
    glVertex2f(-81, -36);
    glVertex2f(-81, -34);
    glEnd();


    // Van glass
    glBegin(GL_QUADS);
    glColor3ub(52, 152, 219);
    glVertex2i(-61,-23);
    glVertex2i(-56,-35);
    glVertex2i(-66,-35);
    glVertex2i(-66,-23);
    glEnd();
    //Van bumper
    glBegin(GL_QUADS);
    glColor3ub(46, 64, 83);
    glVertex2i(-88,-50);
    glVertex2i(-91,-50);
    glVertex2i(-91,-46);
    glVertex2i(-88,-46);
    glVertex2i(-52,-50);
    glVertex2i(-52,-46);
    glVertex2i(-49,-46);
    glVertex2i(-49,-50);
    glEnd();

    //Van Light
    glBegin(GL_QUADS);
    glColor3ub(236, 67, 34);
    glVertex2i(-90,-35);
    glVertex2i(-89,-35);
    glVertex2i(-89,-40);
    glVertex2i(-90,-40);
    glColor3ub(251, 250, 32);
    glVertex2i(-51,-40);
    glVertex2i(-55,-40);
    glVertex2i(-55,-42);
    glVertex2i(-51,-42);
    glEnd();


    //Van wheel-1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=-61;
    y=-50;
    radius =6;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=-61;
    y=-50;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Van wheel-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=-79;
    y=-50;
    radius =6;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=-79;
    y=-50;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glPopMatrix();





    glPushMatrix();
    glTranslatef(carPosition1,0.0f,0.0f);
    //car body
    glBegin(GL_QUADS);
    glColor3ub(125, 60, 152);
    glVertex2i(50,-70);
    glVertex2i(85,-70);
    glVertex2i(87,-80);
    glVertex2i(48,-80);
    glVertex2i(58,-70);
    glVertex2i(61,-60);
    glVertex2i(76,-60);
    glVertex2i(78,-70);
    glEnd();

    //car glass
    glBegin(GL_QUADS);
    glColor3ub(52, 152, 219);
    glVertex2i(59,-70);
    glVertex2i(62,-61);
    glVertex2i(75,-61);
    glVertex2i(77,-70);
    glVertex2i(69,-70);
    glVertex2i(69,-61);
    glVertex2i(73,-61);
    glVertex2i(75,-70);
    glEnd();

    //car bumper
    glBegin(GL_QUADS);
    glColor3ub(46, 64, 83);
    glVertex2i(46,-80);
    glVertex2i(53,-80);
    glVertex2i(53,-76);
    glVertex2i(46,-76);
    glVertex2i(88,-80);
    glVertex2i(82,-80);
    glVertex2i(82,-76);
    glVertex2i(88,-76);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(69,-80);
    glVertex2i(69,-60);
    glVertex2i(58,-70);
    glVertex2i(78,-70);
    glEnd();

    //car Light
    glBegin(GL_QUADS);
    glColor3ub(236, 67, 34);
    glVertex2i(84,-70);
    glVertex2i(85,-70);
    glVertex2i(85,-75);
    glVertex2i(84,-75);
    glColor3ub(226, 224, 224);
    glVertex2i(51,-70);
    glVertex2i(49,-70);
    glVertex2i(49,-72);
    glVertex2i(51,-72);
    glEnd();

    //Car wheel-1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=60;
    y=-80;
    radius =5;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=60;
    y=-80;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Car wheel-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=75;
    y=-80;
    radius =5;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=75;
    y=-80;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(policecarPosition2,0.0f,0.0f);

    //Police Car
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2i(45,-90);
    glVertex2i(48,-78);
    glVertex2i(57,-75);
    glVertex2i(65,-65);
    glVertex2i(83,-65);
    glVertex2i(86,-75);
    glVertex2i(93,-75);
    glVertex2i(95,-90);
    glEnd();

    //Front window
    glBegin(GL_QUADS);
    glColor3ub(35, 148, 186);
    glVertex2i(65,-67);
    glVertex2i(73,-67);
    glVertex2i(73,-74);
    glVertex2i(60,-74);
    glEnd();

    //Back window
    glBegin(GL_QUADS);
    glColor3ub(35, 148, 186);
    glVertex2i(74,-67);
    glVertex2i(82,-67);
    glVertex2i(84,-74);
    glVertex2i(74,-74);
    glEnd();

    //Body Art
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(35, 57, 186);
    glVertex2i(52, -80);
    glVertex2i(88, -80);
    glEnd();

    //Front art
    glBegin(GL_QUADS);
    glColor3ub(40, 55, 71 );
    glVertex2i(44,-90);
    glVertex2i(48,-90);
    glVertex2i(48,-87);
    glVertex2i(44,-87);
    glEnd();

    //Back art
    glBegin(GL_QUADS);
    glColor3ub(40, 55, 71 );
    glVertex2i(92,-90);
    glVertex2i(97,-90);
    glVertex2i(97,-87);
    glVertex2i(92,-87);
    glEnd();

    //Front Light art
    glBegin(GL_QUADS);
    glColor3ub(247, 43, 43 );
    glVertex2i(47,-82);
    glVertex2i(50,-82);
    glVertex2i(50,-79);
    glVertex2i(48,-79);
    glEnd();

    //Back Light art
    glBegin(GL_QUADS);
    glColor3ub(247, 43, 43 );
    glVertex2i(91,-82);
    glVertex2i(94,-82);
    glVertex2i(93,-79);
    glVertex2i(91,-79);
    glEnd();

    //Top Light
    glBegin(GL_QUADS);
    glColor3ub(189, 8, 8 );
    glVertex2i(67,-65);
    glVertex2i(69,-65);
    glVertex2i(69,-63);
    glVertex2i(67,-63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(8, 68, 189 );
    glVertex2i(69,-65);
    glVertex2i(71,-65);
    glVertex2i(71,-63);
    glVertex2i(69,-63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(189, 8, 8 );
    glVertex2i(71,-65);
    glVertex2i(73,-65);
    glVertex2i(73,-63);
    glVertex2i(71,-63);
    glEnd();

    //Front tire
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=60;
    y=-90;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    //Front Tire middle
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=60;
    y=-90;
    radius =3;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    //Back Tire
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=80;
    y=-90;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Back Tire Middle
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=80;
    y=-90;
    radius =3;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();


    glFlush();


}

void display2N (void)
{

    glClear(GL_COLOR_BUFFER_BIT);

    //SKY
    glBegin(GL_QUADS);
    glColor3ub(7, 26, 116 );
    glVertex2i(-100,-20);
    glVertex2i(-100,100);
    glVertex2i(100,100);
    glVertex2i(100,-20);
    glEnd();

    //Star
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glColor3f(255, 255, 255 );
    glVertex2i(-90,90);
    glVertex2i(-70,90);
    glVertex2i(-50,90);
    glVertex2i(-30,90);
    glVertex2i(-10,90);
    glVertex2i(10,90);
    glVertex2i(30,90);
    glVertex2i(50,90);
    glVertex2i(70,90);
    glVertex2i(90,90);
    glEnd();

    glPointSize(3.0);
    glBegin(GL_POINTS);
    glColor3f(255, 255, 255 );
    glVertex2i(-90,70);
    glVertex2i(-70,70);
    glVertex2i(-50,70);
    glVertex2i(-30,70);
    glVertex2i(-10,70);
    glVertex2i(10,70);
    glVertex2i(30,70);
    glVertex2i(50,70);
    glVertex2i(70,70);
    glVertex2i(90,70);
    glEnd();

    glPointSize(3.0);
    glBegin(GL_POINTS);
    glColor3f(255, 255, 255 );
    glVertex2i(-90,50);
    glVertex2i(-70,50);
    glVertex2i(-50,50);
    glVertex2i(-30,50);
    glVertex2i(-10,50);
    glVertex2i(10,50);
    glVertex2i(30,50);
    glVertex2i(50,50);
    glVertex2i(70,50);
    glVertex2i(90,50);
    glEnd();



    glPushMatrix();
    glTranslatef(sunPosition2,0.0f,0.0f);
    //Sun draw
    float x, y;
    int i;
    GLfloat radius;
    int triangleAmount =40;
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);
    x=70;
    y=75;
    radius =10;
    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloudPosition3,0.0f,0.0f);
    //Cloud-1

    //P-1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-75;
    y=92;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-79;
    y=87;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-3
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234  );
    x=-85;
    y=82;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-4
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-80;
    y=81;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-5
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-73;
    y=85;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-6
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-74;
    y=79;
    radius =3;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloudPosition4,0.0f,0.0f);
    //Cloud-2

    //P-1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-35;
    y=78;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-41;
    y=73;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-3
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-47;
    y=67;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-4
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-40;
    y=66;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-5
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234  );
    x=-33;
    y=70;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();
    glPopMatrix();

    //Grass
    glBegin(GL_QUADS);
    glColor3ub(136, 221, 12 );
    glVertex2i(-100,-20);
    glVertex2i(-100,-40);
    glVertex2i(100,-40);
    glVertex2i(100,-20);
    glEnd();


    //Road background
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(-100,-40);
    glVertex2i(-100,-100);
    glVertex2i(100,-100);
    glVertex2i(100,-40);
    glEnd();



    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3f(253, 254, 254);
    glVertex2i(-100,-70);
    glVertex2i(-80,-70);
    glVertex2i(-70,-70);
    glVertex2i(-50,-70);
    glVertex2i(-60,-70);
    glVertex2i(-40,-70);
    glVertex2i(-30,-70);
    glVertex2i(-10,-70);
    glVertex2i(0,-70);
    glVertex2i(20,-70);
    glVertex2i(30,-70);
    glVertex2i(50,-70);
    glVertex2i(60,-70);
    glVertex2i(80,-70);
    glVertex2i(90,-70);
    glVertex2i(100,-70);
    glEnd();

    //Background left 1st

    glBegin(GL_QUADS);
    glColor3ub(204, 209, 209 );
    glVertex2i(-101,-20);
    glVertex2i(-101,23);
    glVertex2i(-95,23);
    glVertex2i(-95,-20);
    glEnd();

    //Background left 2nd

    glBegin(GL_QUADS);
    glColor3ub(179, 182, 183);
    glVertex2i(-50,-20);
    glVertex2i(-50,23);
    glVertex2i(-28,23);
    glVertex2i(-28,-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(93, 173, 226);
    glVertex2i(-46,-10);
    glVertex2i(-46,18);
    glVertex2i(-33,18);
    glVertex2i(-33,-10);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-46, 14);
    glVertex2i(-33, 14);
    glVertex2i(-46, 10);
    glVertex2i(-33, 10);
    glVertex2i(-46, 6);
    glVertex2i(-33, 6);
    glVertex2i(-39, 18);
    glVertex2i(-39, -10);
    glEnd();

    //Background Right 1st

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2i(25,-20);
    glVertex2i(25,18);
    glVertex2i(37,18);
    glVertex2i(37,-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(93, 173, 226);
    glVertex2i(25,5);
    glVertex2i(25,15);
    glVertex2i(35,15);
    glVertex2i(35,5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150 );
    glVertex2i(35,-20);
    glVertex2i(35,13);
    glVertex2i(50,13);
    glVertex2i(50,-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(93, 173, 226);
    glVertex2i(37,3);
    glVertex2i(37,10);
    glVertex2i(50,10);
    glVertex2i(50,3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2i(95,-20);
    glVertex2i(95,13);
    glVertex2i(100,13);
    glVertex2i(100,-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(93, 173, 226);
    glVertex2i(95,3);
    glVertex2i(95,10);
    glVertex2i(98,10);
    glVertex2i(98,3);
    glEnd();


    //Tree-2 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(-36,-23);
    glVertex2i(-36,-11);
    glVertex2i(-34,-11);
    glVertex2i(-34,-23);
    glEnd();

    //Tree Top-1
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-42,-12);
    glVertex2i(-35,7);
    glVertex2i(-29,-12);
    glEnd();

    //Tree Top-2
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-40,-5);
    glVertex2i(-35,13);
    glVertex2i(-30,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-39,2);
    glVertex2i(-35,15);
    glVertex2i(-31,2);
    glEnd();

    //Restaurant Stairs
    glBegin(GL_QUADS);
    glColor3ub(46, 64, 83);
    glVertex2i(-40,-30);
    glVertex2i(-40,-25);
    glVertex2i(40,-25);
    glVertex2i(40,-30);
    glVertex2i(-35,-25);
    glVertex2i(-35,-20);
    glVertex2i(35,-20);
    glVertex2i(35,-25);
    glEnd();

    //glBegin(GL_LINES);
    //glColor3f(206.0f, 193.0f, 111.0f);
    //glVertex2i(-100,0);
    //glVertex2i(100,0);
    //glEnd();

    //Restaurant pillers
    glBegin(GL_QUADS);
    glColor3ub(247, 220, 111);
    glVertex2i(34,-20);
    glVertex2i(32,-20);
    glVertex2i(32,30);
    glVertex2i(34,30);

    glVertex2i(-34,-20);
    glVertex2i(-32,-20);
    glVertex2i(-32,30);
    glVertex2i(-34,30);
    glEnd();


    //Restaurant Room 1st floor
    glBegin(GL_QUADS);
    glColor3ub(230, 126, 34);
    glVertex2i(30,-20);
    glVertex2i(10,-20);
    glVertex2i(10,0);
    glVertex2i(30,0);
    glVertex2i(-30,-20);
    glVertex2i(-10,-20);
    glVertex2i(-10,0);
    glVertex2i(-30,0);
    glEnd();

    //Restaurant Roof 1st floor
    glBegin(GL_QUADS);
    glColor3ub(247, 220, 111);
    glVertex2i(30,0);
    glVertex2i(10,0);
    glVertex2i(10,5);
    glVertex2i(30,5);
    glVertex2i(-30,0);
    glVertex2i(-10,0);
    glVertex2i(-10,5);
    glVertex2i(-30,5);
    glVertex2i(10,5);
    glVertex2i(-10,5);
    glVertex2i(-10,10);
    glVertex2i(10,10);
    glEnd();

    //Restaurant Room 1st floor Glass system
    glBegin(GL_QUADS);
    glColor3ub(253, 254, 254);
    glVertex2i(29,-19);
    glVertex2i(11,-19);
    glVertex2i(11,-1);
    glVertex2i(29,-1);
    glVertex2i(-29,-19);
    glVertex2i(-11,-19);
    glVertex2i(-11,-1);
    glVertex2i(-29,-1);
    glEnd();

    //Restaurant Room 1st floor Glass 1
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0);
    glVertex2i(12,-18);
    glVertex2i(12,-2);
    glVertex2i(19,-2);
    glVertex2i(19,-18);
    glVertex2i(-12,-18);
    glVertex2i(-12,-2);
    glVertex2i(-19,-2);
    glVertex2i(-19,-18);

    glEnd();

    //Restaurant Room 1st floor Glass 2
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0);
    glVertex2i(20,-18);
    glVertex2i(20,-2);
    glVertex2i(28,-2);
    glVertex2i(28,-18);
    glVertex2i(-20,-18);
    glVertex2i(-20,-2);
    glVertex2i(-28,-2);
    glVertex2i(-28,-18);

    glEnd();

    //Restaurant Room 2nd floor
    glBegin(GL_QUADS);
    glColor3ub(230, 126, 34);
    glVertex2i(30,5);
    glVertex2i(10,5);
    glVertex2i(10,25);
    glVertex2i(30,25);
    glVertex2i(-30,5);
    glVertex2i(-10,5);
    glVertex2i(-10,25);
    glVertex2i(-30,25);
    glEnd();

    //Restaurant Roof 2nd floor
    glBegin(GL_QUADS);
    glColor3ub(100, 30, 22);
    glVertex2i(40,25);
    glVertex2i(10,25);
    glVertex2i(10,30);
    glVertex2i(40,30);
    glVertex2i(-40,25);
    glVertex2i(-10,25);
    glVertex2i(-10,30);
    glVertex2i(-40,30);
    glVertex2i(12,35);
    glVertex2i(-12,35);
    glVertex2i(-12,40);
    glVertex2i(12,40);
    glVertex2i(13,40);  // For lobby
    glVertex2i(-13,40);
    glVertex2i(-13,45);
    glVertex2i(13,45);
    glEnd();

    glColor3f(255,255,255);
    renderBitmapString(-8,39,0,GLUT_BITMAP_TIMES_ROMAN_24, "Restaurant");

    //Restaurant Room 2nd floor Glass system
    glBegin(GL_QUADS);
    glColor3ub(253, 254, 254);
    glVertex2i(29,6);
    glVertex2i(11,6);
    glVertex2i(11,24);
    glVertex2i(29,24);
    glColor3ub(253, 254, 254);
    glVertex2i(-29,6);
    glVertex2i(-11,6);
    glVertex2i(-11,24);
    glVertex2i(-29,24);
    glEnd();

    //Restaurant Room 2nd floor Glass 1
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0);
    glVertex2i(12,7);
    glVertex2i(12,23);
    glVertex2i(19,23);
    glVertex2i(19,7);
    glVertex2i(-12,7);
    glVertex2i(-12,23);
    glVertex2i(-19,23);
    glVertex2i(-19,7);

    glEnd();

    //Restaurant Room 2nd floor Glass 2
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0);
    glVertex2i(20,6);
    glVertex2i(20,23);
    glVertex2i(28,23);
    glVertex2i(28,6);
    glVertex2i(-20,6);
    glVertex2i(-20,23);
    glVertex2i(-28,23);
    glVertex2i(-28,6);

    glEnd();

    //restaurant lobby 1st floor
    glBegin(GL_QUADS);
    glColor3ub(211, 84, 0);
    glVertex2i(10,-20);
    glVertex2i(-10,-20);
    glVertex2i(-10,5);
    glVertex2i(10,5);
    glEnd();

    //Restaurant lobby 2nd floor
    glBegin(GL_QUADS);
    glColor3ub(211, 84, 0);
    glVertex2i(10,10);
    glVertex2i(-10,10);
    glVertex2i(-10,35);
    glVertex2i(10,35);
    glEnd();

    //Gate pillers
    glBegin(GL_QUADS);
    glColor3ub(247, 220, 111);
    glVertex2i(8,-20);
    glVertex2i(6,-20);
    glVertex2i(6,-5);
    glVertex2i(8,-5);

    glVertex2i(-8,-20);
    glVertex2i(-6,-20);
    glVertex2i(-6,-5);
    glVertex2i(-8,-5);
    glEnd();

    //Restaurant Roof Gate
    glBegin(GL_QUADS);
    glColor3ub(100, 30, 22);
    glVertex2i(9,-5);  // For gate
    glVertex2i(-9,-5);
    glVertex2i(-9,0);
    glVertex2i(9,0);
    glEnd();

    //restaurant Gate Glass system
    glBegin(GL_QUADS);
    glColor3ub(174, 214, 241);
    glVertex2i(4,-20);
    glVertex2i(4,-5);
    glVertex2i(-4,-5);
    glVertex2i(-4,-20);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2i(0,-20);
    glVertex2i(0,-5);
    glEnd();




    //Restaurant Front gateway
    glBegin(GL_QUADS);
    glColor3ub(171, 178, 185 );
    glVertex2i(-40,-30);
    glVertex2i(-45,-40);
    glVertex2i(45,-40);
    glVertex2i(40,-30);
    glEnd();
    glColor3f(0,0,255);
    renderBitmapString(-8,23,0,GLUT_BITMAP_TIMES_ROMAN_24, "CookinDel");

    //Footpath Left
    glBegin(GL_QUADS);
    glColor3ub(148, 49, 38);
    glVertex2i(-45,-40);
    glVertex2i(-50,-35);
    glVertex2i(-100,-35);
    glVertex2i(-100,-40);
    glColor3ub(203, 67, 53  );
    glVertex2i(-45,-40);
    glVertex2i(-50,-35);
    glVertex2i(-45,-25);
    glVertex2i(-40,-30);
    glVertex2i(-45,-25);
    glVertex2i(-50,-35);
    glVertex2i(-100,-35);
    glVertex2i(-100,-25);
    glEnd();

    //Footpath right
    glBegin(GL_QUADS);
    glColor3ub(148, 49, 38);
    glVertex2i(45,-40);
    glVertex2i(50,-35);
    glVertex2i(100,-35);
    glVertex2i(100,-40);
    glColor3ub(203, 67, 53  );
    glVertex2i(45,-40);
    glVertex2i(50,-35);
    glVertex2i(45,-25);
    glVertex2i(40,-30);
    glVertex2i(45,-25);
    glVertex2i(50,-35);
    glVertex2i(100,-35);
    glVertex2i(100,-25);
    glEnd();




    //School second body
    glBegin(GL_QUADS);
    glColor3ub(228, 154, 34 );
    glVertex2i(45,15);
    glVertex2i(45,-20);
    glVertex2i(83,-20);
    glVertex2i(83,15);
    glEnd();

    //School second body border
    glBegin(GL_QUADS);
    glColor3ub(247, 220, 111 );
    glVertex2i(81,-1);
    glVertex2i(81,-4);
    glVertex2i(45,-4);
    glVertex2i(45,-1);
    glEnd();


    //School second body window
    glBegin(GL_QUADS);
    glColor3ub(17, 144, 165);
    glVertex2i(48,10);
    glVertex2i(52,10);
    glVertex2i(52,4);
    glVertex2i(48,4);
    glVertex2i(55,10);
    glVertex2i(59,10);
    glVertex2i(59,4);
    glVertex2i(55,4);
    glVertex2i(62,10);
    glVertex2i(66,10);
    glVertex2i(66,4);
    glVertex2i(62,4);
    glVertex2i(69,10);
    glVertex2i(73,10);
    glVertex2i(73,4);
    glVertex2i(69,4);
    glVertex2i(76,10);
    glVertex2i(80,10);
    glVertex2i(80,4);
    glVertex2i(76,4);


    glVertex2i(48,-9);
    glVertex2i(52,-9);
    glVertex2i(52,-15);
    glVertex2i(48,-15);
    glVertex2i(55,-9);
    glVertex2i(59,-9);
    glVertex2i(59,-15);
    glVertex2i(55,-15);
    glVertex2i(62,-9);
    glVertex2i(66,-9);
    glVertex2i(66,-15);
    glVertex2i(62,-15);
    glVertex2i(69,-9);
    glVertex2i(73,-9);
    glVertex2i(73,-15);
    glVertex2i(69,-15);
    glVertex2i(76,-9);
    glVertex2i(80,-9);
    glVertex2i(80,-15);
    glVertex2i(76,-15);


    glEnd();


    //School second body roof
    glBegin(GL_QUADS);
    glColor3ub(211, 84, 0);
    glVertex2i(83,15);
    glVertex2i(84,30);
    glVertex2i(50,30);
    glVertex2i(40,15);
    glEnd();


    //School first body
    glBegin(GL_QUADS);
    glColor3ub(205, 135, 22 );
    glVertex2i(81,-20);
    glVertex2i(95,-20);
    glVertex2i(95,24);
    glVertex2i(81,24);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(205, 135, 22 );
    glVertex2f(81,24);
    glVertex2f(88,35);
    glVertex2f(95,24);
    glEnd();


    //School Gate
    glBegin(GL_QUADS);
    glColor3ub(28, 40, 51);
    glVertex2i(98,-25);
    glVertex2i(98,-23);
    glVertex2i(78,-23);
    glVertex2i(78,-25);

    glVertex2i(98,-3);
    glVertex2i(98,-1);
    glVertex2i(78,-1);
    glVertex2i(78,-3);
    glEnd();

    //School Gate way
    glBegin(GL_QUADS);
    glColor3ub(17, 144, 165);
    glVertex2i(93,-20);
    glVertex2i(83,-20);
    glVertex2i(83,-5);
    glVertex2i(93,-5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(23, 32, 42);
    glVertex2i(88,-20);
    glVertex2i(88,-5);
    glEnd();

    //School Gate floor
    glBegin(GL_QUADS);
    glColor3ub(178, 186, 187 );
    glVertex2i(96,-23);
    glVertex2i(93,-20);
    glVertex2i(83,-20);
    glVertex2i(80,-23);
    glEnd();

    //School Gate pillers
    glBegin(GL_QUADS);
    glColor3ub(244, 208, 63);
    glVertex2i(98,-23);
    glVertex2i(98,-3);
    glVertex2i(96,-3);
    glVertex2i(96,-23);

    glVertex2i(78,-23);
    glVertex2i(78,-3);
    glVertex2i(80,-3);
    glVertex2i(80,-23);
    glEnd();


    //School Gate roof
    glBegin(GL_QUADS);
    glColor3ub(160, 64, 0 );
    glVertex2i(78,25);
    glVertex2i(81,24);
    glVertex2i(88,35);
    glVertex2i(88,40);

    glVertex2i(98,25);
    glVertex2i(95,24);
    glVertex2i(88,35);
    glVertex2i(88,40);
    glEnd();


    //School first body border
    glBegin(GL_QUADS);
    glColor3ub(247, 220, 111 );
    glVertex2i(81,-1);
    glVertex2i(81,2);
    glVertex2i(95,2);
    glVertex2i(95,-1);
    glEnd();

    //School first body window
    glBegin(GL_QUADS);
    glColor3ub(17, 144, 165);
    glVertex2i(93,5);
    glVertex2i(83,5);
    glVertex2i(83,15);
    glVertex2i(93,15);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(23, 32, 42);
    glVertex2i(88,5);
    glVertex2i(88,15);
    glVertex2i(93,10);
    glVertex2i(83,10);
    glEnd();

    //Tree-1 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(-44,-25);
    glVertex2i(-44,-10);
    glVertex2i(-42,-10);
    glVertex2i(-42,-25);
    glEnd();

    //Tree Top 1
    glBegin(GL_TRIANGLES);
    glColor3ub(34, 153, 84 );
    glVertex2i(-51,-12);
    glVertex2i(-43,9);
    glVertex2i(-35,-12);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(34, 153, 84 );
    glVertex2i(-50,-5);
    glVertex2i(-43,15);
    glVertex2i(-36,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(34, 153, 84 );
    glVertex2i(-49,2);
    glVertex2i(-43,22);
    glVertex2i(-37,2);
    glEnd();


    //Tree-3 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(44,-25);
    glVertex2i(44,-10);
    glVertex2i(42,-10);
    glVertex2i(42,-25);
    glEnd();

    //Tree Top 1
    glBegin(GL_TRIANGLES);
    glColor3ub(49, 189, 40 );
    glVertex2i(51,-12);
    glVertex2i(43,9);
    glVertex2i(35,-12);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(49, 189, 40 );
    glVertex2i(50,-5);
    glVertex2i(43,15);
    glVertex2i(36,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(49, 189, 40 );
    glVertex2i(49,2);
    glVertex2i(43,22);
    glVertex2i(37,2);
    glEnd();


    //company building
    glBegin(GL_QUADS);
    glColor3ub(244, 247, 122 );
    glVertex2i(-98,-25);
    glVertex2i(-70,-25);
    glVertex2i(-70,10);
    glVertex2i(-98,10);
    glVertex2i(-98,15);
    glVertex2i(-70,15);
    glVertex2i(-70,50);
    glVertex2i(-98,50);
    glVertex2i(-50,-25);
    glVertex2i(-70,-25);
    glVertex2i(-70,25);
    glVertex2i(-50,25);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0, 0, 0 );
    glVertex2i(-70,-25);
    glVertex2i(-70,50);
    glEnd();

    //company building roof
    glBegin(GL_QUADS);
    glColor3ub(93, 109, 126);
    glVertex2i(-99,15);
    glVertex2i(-70,15);
    glVertex2i(-70,10);
    glVertex2i(-99,10);
    glVertex2i(-99,50);
    glVertex2i(-70,50);
    glVertex2i(-70,55);
    glVertex2i(-99,55);
    glVertex2i(-48,25);
    glVertex2i(-70,25);
    glVertex2i(-70,30);
    glVertex2i(-48,30);
    glColor3ub(33, 47, 61 );
    glVertex2i(-45,35);
    glVertex2i(-70,35);
    glVertex2i(-70,30);
    glVertex2i(-45,30);
    glEnd();

    //company Gate Glass system
    glBegin(GL_QUADS);
    glColor3ub(17, 144, 165);
    glVertex2i(-88,-25);
    glVertex2i(-80,-25);
    glVertex2i(-80,-5);
    glVertex2i(-88,-5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2i(-84,-25);
    glVertex2i(-84,-5);
    glEnd();

    //company window Glass system
    glBegin(GL_QUADS);
    glColor3ub(17, 144, 165);
    glVertex2i(-96,-20);
    glVertex2i(-90,-20);
    glVertex2i(-90,5);
    glVertex2i(-96,5);
    glVertex2i(-78,-20);
    glVertex2i(-72,-20);
    glVertex2i(-72,5);
    glVertex2i(-78,5);
    glVertex2i(-52,-20);
    glVertex2i(-68,-20);
    glVertex2i(-68,-10);
    glVertex2i(-52,-10);
    glVertex2i(-52,-5);
    glVertex2i(-68,-5);
    glVertex2i(-68,5);
    glVertex2i(-52,5);
    glVertex2i(-52,20);
    glVertex2i(-68,20);
    glVertex2i(-68,10);
    glVertex2i(-52,10);
    glVertex2i(-96,20);
    glVertex2i(-72,20);
    glVertex2i(-72,30);
    glVertex2i(-96,30);
    glVertex2i(-96,35);
    glVertex2i(-72,35);
    glVertex2i(-72,45);
    glVertex2i(-96,45);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2i(-96,-10);
    glVertex2i(-90,-10);
    glVertex2i(-78,-10);
    glVertex2i(-72,-10);
    glEnd();
    //Lamp 1
    glBegin(GL_QUADS);
    glColor3ub(33, 47, 61);
    glVertex2i(-72,-25);
    glVertex2i(-70,-25);
    glVertex2i(-70,0);
    glVertex2i(-72,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(33, 47, 61);
    glVertex2f(-74,5);
    glVertex2f(-68,5);
    glVertex2f(-71,8);
    glEnd();


    //Light
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0 );
    glVertex2i(-70,0);
    glVertex2i(-72,0);
    glVertex2i(-73,5);
    glVertex2i(-69,5);
    glEnd();



    //Lamp 2
    glBegin(GL_QUADS);
    glColor3ub(33, 47, 61);
    glVertex2i(72,-25);
    glVertex2i(70,-25);
    glVertex2i(70,0);
    glVertex2i(72,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(33, 47, 61);
    glVertex2f(74,5);
    glVertex2f(68,5);
    glVertex2f(71,8);
    glEnd();


    //Light
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0 );
    glVertex2i(70,0);
    glVertex2i(72,0);
    glVertex2i(73,5);
    glVertex2i(69,5);
    glEnd();

    glPushMatrix();
    glTranslatef(bmenPosition1,0.0f,0.0f);
    //Man 5 Draw
    //Left Leg
    glBegin(GL_QUADS);
    glColor3ub(127, 50, 19 );
    glVertex2i(68,-30);
    glVertex2i(67,-22);
    glVertex2i(64,-22);
    glVertex2i(66,-30);

    //Right leg
    glVertex2i(64,-30);
    glVertex2i(66,-22);
    glVertex2i(63,-22);
    glVertex2i(62,-30);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3ub(15, 189, 157  );
    glVertex2i(67,-22);
    glVertex2i(67,-15);
    glVertex2i(65,-16);
    glVertex2i(63,-15);
    glVertex2i(63,-22);
    glEnd();

    //Left hand
    glBegin(GL_QUADS);
    glColor3ub(15, 189, 157 );
    glVertex2i(68,-15);
    glVertex2i(67,-15);
    glVertex2i(67,-19);
    glVertex2i(68,-19);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(68, -19);
    glVertex2i(67, -20);
    glEnd();


    //Right hand
    glBegin(GL_QUADS);
    glColor3ub(15, 189, 157  );
    glVertex2i(63,-15);
    glVertex2i(62,-15);
    glVertex2i(62,-19);
    glVertex2i(63,-19);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(62, -19);
    glVertex2i(63, -20);
    glEnd();

    //Bag
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2i(62, -22);
    glVertex2i(62, -28);
    glEnd();

    //Shoe
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(64,-30);
    glVertex2i(63,-28);
    glVertex2i(62,-30);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(68,-30);
    glVertex2i(67,-28);
    glVertex2i(66,-30);
    glEnd();


    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(65, -16);
    glVertex2i(65, -13);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 222, 157 );
    x=65;
    y=-12;
    radius =2.5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Hair
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(68, -11);
    glVertex2f(65, -10);
    glVertex2f(62, -11);
    glVertex2f(64, -9);
    glVertex2f(66, -9);
    glEnd();


    glPopMatrix();

    glPushMatrix();
    glTranslatef(basketPosition,0.0f,0.0f);
//Man 1 Draw
    //Left Leg
    glBegin(GL_QUADS);
    glColor3ub(44, 80, 197);
    glVertex2i(22,-40);
    glVertex2i(23,-32);
    glVertex2i(26,-32);
    glVertex2i(24,-40);

    //Right leg
    glVertex2i(26,-40);
    glVertex2i(24,-32);
    glVertex2i(27,-32);
    glVertex2i(28,-40);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3ub(56, 225, 38 );
    glVertex2i(23,-33);
    glVertex2i(23,-26);
    glVertex2i(25,-27);
    glVertex2i(27,-26);
    glVertex2i(27,-33);
    glEnd();

    //Left hand
    glBegin(GL_QUADS);
    glColor3ub(56, 225, 38 );
    glVertex2i(22,-26);
    glVertex2i(23,-26);
    glVertex2i(23,-30);
    glVertex2i(22,-30);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(23, -30);
    glVertex2i(22, -31);
    glEnd();


    //Right hand
    glBegin(GL_QUADS);
    glColor3ub(56, 225, 38 );
    glVertex2i(27,-26);
    glVertex2i(28,-26);
    glVertex2i(28,-30);
    glVertex2i(27,-30);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(27, -30);
    glVertex2i(28, -31);
    glEnd();

    //Shoe
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(26,-40);
    glVertex2i(27,-38);
    glVertex2i(28,-40);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(22,-40);
    glVertex2i(23,-38);
    glVertex2i(24,-40);
    glEnd();


    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(25, -27);
    glVertex2i(25, -24);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(249, 231, 159);
    x=25;
    y=-23;
    radius =2.5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    //Hair
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(22,-22);
    glVertex2i(24,-20);
    glVertex2i(26,-20);
    glVertex2i(28,-22);
    glEnd();



    //
    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2i(36,-30);
    glVertex2i(34,-40);
    glVertex2i(30,-40);
    glVertex2i(28,-30);
    glEnd();
    glColor3f(255,0,0);
    renderBitmapString(31,-35,0,GLUT_BITMAP_TIMES_ROMAN_10, "Fish");

    glPopMatrix();




    glPushMatrix();
    glTranslatef(vanPosition1,0.0f,0.0f);
    // van body
    glBegin(GL_POLYGON);
    glColor3ub(253, 254, 254);
    glVertex2f(-90, -50);
    glVertex2f(-50, -50);
    glVertex2f(-51, -40);
    glVertex2f(-55, -35);
    glVertex2f(-60, -20);
    glVertex2f(-85, -20);
    glVertex2f(-90, -35);
    glEnd();
    //Fish sign

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0); // Fish Tail
    glVertex2f(-79, -33);
    glVertex2f(-72, -37);
    glVertex2f(-74, -33);
    glVertex2f(-72, -29);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0); // Fish body color
    glVertex2f(-87, -33);
    glVertex2f(-77, -39);
    glVertex2f(-77, -26);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0); // Fish  wings
    glVertex2f(-83, -33);
    glVertex2f(-81, -34);
    glVertex2f(-81, -32);
    glEnd();
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    glColor3ub(0, 0, 255);//Fish Eye
    glVertex2f(-85,-33);
    glEnd();
    //van glass
    glBegin(GL_QUADS);
    glColor3ub(52, 152, 219);

    glVertex2i(-61,-23);
    glVertex2i(-56,-35);
    glVertex2i(-66,-35);
    glVertex2i(-66,-23);
    glEnd();
    //van bumper
    glBegin(GL_QUADS);
    glColor3ub(46, 64, 83);
    glVertex2i(-88,-50);
    glVertex2i(-91,-50);
    glVertex2i(-91,-46);
    glVertex2i(-88,-46);
    glVertex2i(-52,-50);
    glVertex2i(-52,-46);
    glVertex2i(-49,-46);
    glVertex2i(-49,-50);
    glEnd();

    //van Light
    glBegin(GL_QUADS);
    glColor3ub(236, 67, 34);
    glVertex2i(-90,-35);
    glVertex2i(-89,-35);
    glVertex2i(-89,-40);
    glVertex2i(-90,-40);
    glColor3ub(251, 250, 32);
    glVertex2i(-51,-40);
    glVertex2i(-55,-40);
    glVertex2i(-55,-42);
    glVertex2i(-51,-42);
    glEnd();

    //Night Light
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0 );
    glVertex2i(-50,-43);
    glVertex2i(-50,-41);
    glVertex2i(-15,-45);
    glVertex2i(-30,-48);
    glEnd();


    //van wheel-1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=-61;
    y=-50;
    radius =6;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=-61;
    y=-50;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //van wheel-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=-79;
    y=-50;
    radius =6;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=-79;
    y=-50;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glPopMatrix();





    glPushMatrix();
    glTranslatef(carPosition1,0.0f,0.0f);
    //car body
    glBegin(GL_QUADS);
    glColor3ub(125, 60, 152);
    glVertex2i(50,-70);
    glVertex2i(85,-70);
    glVertex2i(87,-80);
    glVertex2i(48,-80);
    glVertex2i(58,-70);
    glVertex2i(61,-60);
    glVertex2i(76,-60);
    glVertex2i(78,-70);
    glEnd();

    //car glass
    glBegin(GL_QUADS);
    glColor3ub(52, 152, 219);
    glVertex2i(59,-70);
    glVertex2i(62,-61);
    glVertex2i(75,-61);
    glVertex2i(77,-70);
    glVertex2i(69,-70);
    glVertex2i(69,-61);
    glVertex2i(73,-61);
    glVertex2i(75,-70);
    glEnd();

    //car bumper
    glBegin(GL_QUADS);
    glColor3ub(46, 64, 83);
    glVertex2i(46,-80);
    glVertex2i(53,-80);
    glVertex2i(53,-76);
    glVertex2i(46,-76);
    glVertex2i(88,-80);
    glVertex2i(82,-80);
    glVertex2i(82,-76);
    glVertex2i(88,-76);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(69,-80);
    glVertex2i(69,-60);
    glVertex2i(58,-70);
    glVertex2i(78,-70);
    glEnd();

    //car Light
    glBegin(GL_QUADS);
    glColor3ub(236, 67, 34);
    glVertex2i(84,-70);
    glVertex2i(85,-70);
    glVertex2i(85,-75);
    glVertex2i(84,-75);
    glColor3ub(226, 224, 224);
    glVertex2i(51,-70);
    glVertex2i(49,-70);
    glVertex2i(49,-72);
    glVertex2i(51,-72);
    glEnd();

    //Front Light Night
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0 );
    glVertex2i(49,-73);
    glVertex2i(49,-70);
    glVertex2i(14,-76);
    glVertex2i(29,-79);
    glEnd();


    //Car wheel-1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=60;
    y=-80;
    radius =5;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=60;
    y=-80;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Car wheel-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=75;
    y=-80;
    radius =5;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=75;
    y=-80;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(policecarPosition2,0.0f,0.0f);

    //Police Car
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2i(45,-90);
    glVertex2i(48,-78);
    glVertex2i(57,-75);
    glVertex2i(65,-65);
    glVertex2i(83,-65);
    glVertex2i(86,-75);
    glVertex2i(93,-75);
    glVertex2i(95,-90);
    glEnd();

    //Front window
    glBegin(GL_QUADS);
    glColor3ub(35, 148, 186);
    glVertex2i(65,-67);
    glVertex2i(73,-67);
    glVertex2i(73,-74);
    glVertex2i(60,-74);
    glEnd();

    //Back window
    glBegin(GL_QUADS);
    glColor3ub(35, 148, 186);
    glVertex2i(74,-67);
    glVertex2i(82,-67);
    glVertex2i(84,-74);
    glVertex2i(74,-74);
    glEnd();

    //Body Art
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(35, 57, 186);
    glVertex2i(52, -80);
    glVertex2i(88, -80);
    glEnd();

    //Front art
    glBegin(GL_QUADS);
    glColor3ub(40, 55, 71 );
    glVertex2i(44,-90);
    glVertex2i(48,-90);
    glVertex2i(48,-87);
    glVertex2i(44,-87);
    glEnd();

    //Back art
    glBegin(GL_QUADS);
    glColor3ub(40, 55, 71 );
    glVertex2i(92,-90);
    glVertex2i(97,-90);
    glVertex2i(97,-87);
    glVertex2i(92,-87);
    glEnd();

    //Front Light art
    glBegin(GL_QUADS);
    glColor3ub(247, 43, 43 );
    glVertex2i(47,-82);
    glVertex2i(50,-82);
    glVertex2i(50,-79);
    glVertex2i(48,-79);
    glEnd();

    //Back Light art
    glBegin(GL_QUADS);
    glColor3ub(247, 43, 43 );
    glVertex2i(91,-82);
    glVertex2i(94,-82);
    glVertex2i(93,-79);
    glVertex2i(91,-79);
    glEnd();

    //Top Light
    glBegin(GL_QUADS);
    glColor3ub(189, 8, 8 );
    glVertex2i(67,-65);
    glVertex2i(69,-65);
    glVertex2i(69,-63);
    glVertex2i(67,-63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(8, 68, 189 );
    glVertex2i(69,-65);
    glVertex2i(71,-65);
    glVertex2i(71,-63);
    glVertex2i(69,-63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(189, 8, 8 );
    glVertex2i(71,-65);
    glVertex2i(73,-65);
    glVertex2i(73,-63);
    glVertex2i(71,-63);
    glEnd();

    //Front Light Night
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0 );
    glVertex2i(45,-82);
    glVertex2i(45,-79);
    glVertex2i(10,-84);
    glVertex2i(25,-87);
    glEnd();

    //Front tire
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=60;
    y=-90;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    //Front Tire middle
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=60;
    y=-90;
    radius =3;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    //Back Tire
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=80;
    y=-90;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Back Tire Middle
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=80;
    y=-90;
    radius =3;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();


    glFlush();


}
void display3 (void)
{



    //glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);//background
    glColor3ub(100,40,22);
    glVertex2i(-100,-100);
    glVertex2i(-100,100);
    glVertex2i(100,100);
    glVertex2i(100,-100);
    glEnd();
    glBegin(GL_QUADS);//restaurant body
    glColor3ub(188,152,126);
    glVertex2i(-100,130);
    glVertex2i(-100,-125);
    glVertex2i(-10,-90);
    glVertex2i(-10,50);
    glEnd();

    //Room paint
    glBegin(GL_QUADS);
    glColor3ub(80, 33, 18);
    glVertex2i(-10,-90);
    glVertex2i(-10,50);
    glVertex2i(102,50);
    glVertex2i(102,-90);
    glEnd();


    glBegin(GL_QUADS);//Gate
    glColor3ub(110, 178, 236);
    glVertex2i(-80,-110);
    glVertex2i(-40,-100);
    glVertex2i(-40,16);
    glVertex2i(-80,16);
    glEnd();

    // Door
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2i(-60,-150);
    glVertex2i(-60,16);
    glVertex2i(-58,16);
    glVertex2i(-58,-110);
    glEnd();

    //door roof
    glBegin(GL_QUADS);
    glColor3ub(85,85,85);
    glVertex2i(-80,16);
    glVertex2i(-80,22);
    glVertex2i(-40,22);
    glVertex2i(-40,16);
    glEnd();

    glBegin(GL_QUADS);//PULL
    glColor3ub(85,85,85);
    glVertex2i(-65,-60);
    glVertex2i(-65,-40);
    glVertex2i(-64,-40);
    glVertex2i(-64,-60);
    glEnd();


     glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2i(-74,-35);
    glVertex2i(-61,-35);
    glVertex2i(-61,-25);
    glVertex2i(-74,-25);
    glEnd();
    glColor3f(255,0,0);
    renderBitmapString(-72,-33,0,GLUT_BITMAP_TIMES_ROMAN_24, "PULL");


    glBegin(GL_QUADS);//Push
    glColor3ub(85,85,85);
    glVertex2i(-55,-59);
    glVertex2i(-55,-40);
    glVertex2i(-54,-40);
    glVertex2i(-54,-59);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2i(-56,-35);
    glVertex2i(-41,-35);
    glVertex2i(-41,-25);
    glVertex2i(-56,-25);
    glEnd();
    glColor3f(255,0,0);
    renderBitmapString(-54,-32,0,GLUT_BITMAP_TIMES_ROMAN_24, "PUSH");

    //signboard

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2i(-80,30);
    glVertex2i(-40,30);
    glVertex2i(-40,30);
    glVertex2i(-80,30);
    glEnd();
    glColor3ub(1,0,0);
    renderBitmapString(-75,35,0,GLUT_BITMAP_TIMES_ROMAN_24, "FOOD VILLAGE");

  //Window 1
    glBegin(GL_QUADS);
    glColor3ub(110, 178, 236);
    glVertex2i(16,-5);
    glVertex2i(16,29);
    glVertex2i(38,29);
    glVertex2i(38,-5);
    glEnd();

    //Window 1 roof
    glBegin(GL_QUADS);
    glColor3ub(85,85,85);
    glVertex2i(16,32);
    glVertex2i(16,29);
    glVertex2i(38,29);
    glVertex2i(38,32);
    glEnd();

  //Window 2
    glBegin(GL_QUADS);
    glColor3ub(110, 178, 236);
    glVertex2i(62,-5);
    glVertex2i(62,29);
    glVertex2i(84,29);
    glVertex2i(84,-5);
    glEnd();

    //Window 2 roof
    glBegin(GL_QUADS);
    glColor3ub(85,85,85);
    glVertex2i(62,32);
    glVertex2i(62,29);
    glVertex2i(84,29);
    glVertex2i(84,32);
    glEnd();


    glBegin(GL_QUADS);//Neck
    glColor3ub(193, 154, 107);
    glVertex2i(37,3);
    glVertex2i(37,-40);
    glVertex2i(43,-40);
    glVertex2i(43,3);
    glEnd();

    float x, y;
    int i;
    GLfloat radius;
    int triangleAmount =20;
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 222, 157);
    x=40;
    y=-6;
    radius =10;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    glPointSize(6);
    glBegin(GL_POINTS);
    glColor3ub(0,0,0);//Human Eye
    glVertex2f(35,-3);
    glEnd();
    glPointSize(6);
    glBegin(GL_POINTS);
    glColor3ub(0,0,0);//Human Eye
    glVertex2f(45,-3);
    glEnd();
    glLineWidth(4);
    glBegin(GL_LINES);//mouth
    glColor3ub(0,0,0);
    glVertex2i(36,-9);
    glVertex2i(44,-9);
    glEnd();

    glPushMatrix();
    glTranslatef(0.1f,MouthPosition,0.01f);
    glLineWidth(4);
    glBegin(GL_LINES);//mouth 2
    glColor3ub(0,0,0);
    glVertex2i(37,-12);
    glVertex2i(43,-12);
    glEnd();
    glPopMatrix();


    //Body
    glBegin(GL_POLYGON);
    glColor3ub(15, 189, 157  );
    glVertex2i(27,-75);
    glVertex2i(27,-25);
    glVertex2i(40,-28);
    glVertex2i(53,-25);
    glVertex2i(53,-75);
    glEnd();


    //Left hand
    glBegin(GL_QUADS);
    glColor3ub(15, 189, 157);
    glVertex2i(27,-25);
    glVertex2i(27,-40);
    glVertex2i(23,-40);
    glVertex2i(23,-25);
    glEnd();

    //Left open hand
    glBegin(GL_QUADS);
    glColor3ub(193, 154, 107);
    glVertex2i(27,-40);
    glVertex2i(27,-65);
    glVertex2i(23,-65);
    glVertex2i(23,-40);
    glEnd();




    //Right hand
    glBegin(GL_QUADS);
    glColor3ub(15, 189, 157);
    glVertex2i(57,-25);
    glVertex2i(57,-39);
    glVertex2i(53,-39);
    glVertex2i(53,-25);
    glEnd();

    //Right open hand
    glBegin(GL_QUADS);
    glColor3ub(193, 154, 107);
    glVertex2i(57,-39);
    glVertex2i(57,-65);
    glVertex2i(53,-65);
    glVertex2i(53,-39);
    glEnd();


    glBegin(GL_POLYGON);//Palate
    glColor3ub(255, 255, 255);
    glVertex2i(15,-100);
    glVertex2i(5,-75);
    glVertex2i(70,-75);
    glVertex2i(58,-100);
    glEnd();
    glBegin(GL_LINES);//mouth 2
    glColor3ub(255,215,0);
    glVertex2i(6,-100);
    glVertex2i(74,-100);
    glEnd();
    glBegin(GL_TRIANGLES);//Fish1
    glColor3ub(171,78,82);
    glVertex2i(12,-80);
    glVertex2i(20,-60);
    glVertex2i(24,-80);
    glEnd();
    glBegin(GL_POLYGON);//Tail
    glColor3ub(0, 0, 0);
    glVertex2i(20,-60);
    glVertex2i(24,-55);
    glVertex2i(19,-58);
    glVertex2i(16,-57);
    glEnd();
    glBegin(GL_TRIANGLES);//Fish2
    glColor3ub(171,78,82);
    glVertex2i(40,-80);
    glVertex2i(60,-80);
    glVertex2i(35,-65);
    glEnd();
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3ub(0,0,0);//fish2 Eye
    glVertex2f(38,-69);
    glEnd();
    glBegin(GL_TRIANGLES);//Fish3
    glColor3ub(171,98,82);
    glVertex2i(24,-80);
    glVertex2i(40,-80);
    glVertex2i(37,-70);
    glEnd();

    glBegin(GL_POINTS);
    glColor3ub(255,0,0);//mPlastic
    glVertex2f(18,-69);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(255,0,0);//mPlastic
    glVertex2f(20,-75);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(255,0,0);//Mplastic
    glVertex2f(33,-78);
    glEnd();

    glBegin(GL_POINTS);
    glColor3ub(255,0,0);//fish2 Eye
    glVertex2f(40,-75);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(255,0,0);//fish2 Eye
    glVertex2f(45,-75);
    glEnd();

    glPushMatrix();
    glTranslatef(0.0f,MplasticPosi,0.0f);
    glBegin(GL_POINTS);
    glColor3ub(255,99,71);//Micro Plastic
    glVertex2f(37,-2);
    glEnd();

    glBegin(GL_POINTS);
    glColor3ub(255,99,71);//Micro Plastic
    glVertex2f(42,-2);
    glEnd();

    glBegin(GL_POINTS);
    glColor3ub(255,99,71);//Micro Plastic
    glVertex2f(39.5,-3);
    glEnd();
    glPopMatrix();


    glFlush();
}
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}
void hill(){

    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(-100, 100);
	glVertex2i(50, 250);
	glVertex2i(100, 200);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(70, 200);
	glVertex2i(200, 300);
	glVertex2i(330, 200);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(280, 200);
	glVertex2i(350, 275);
	glVertex2i(420, 200);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(400, 200);
	glVertex2i(500, 300);
	glVertex2i(600, 200);
	glEnd();
	//grass
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 0.0f);
	glVertex2i(525, 200);
	glVertex2i(550, 210);
	glVertex2i(560, 220);
	glVertex2i(570, 220);
	glVertex2i(580, 230);
	glVertex2i(590, 235);
	glVertex2i(600, 238);
	glVertex2i(700, 240);
	glVertex2i(700, 200);

	glEnd();

	//mountain
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(650, 200);
	glVertex2i(740, 285);
	glVertex2i(830, 200);
    glEnd();

    //grass
    glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 0.0f);
	glVertex2i(800, 200);
	glVertex2i(850, 210);
	glVertex2i(860, 220);
	glVertex2i(870, 220);
	glVertex2i(880, 230);
	glVertex2i(890, 235);
	glVertex2i(900, 238);
	glVertex2i(1200, 240);
	glVertex2i(1200, 200);

	glEnd();

	//trees
	//tree1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(605, 230);
	glVertex2f(605, 290);
	glVertex2f(615, 290);
	glVertex2f(615, 230);

    glEnd();
    glColor3f(0.0f, 0.7f, 0.0f);
	glPushMatrix();
    glTranslatef(600,280,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(620,270,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(610,290,0);
    circle(15);
    glPopMatrix();

    //tree2
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(655, 230);
	glVertex2f(655, 290);
	glVertex2f(665, 290);
	glVertex2f(665, 230);

    glEnd();
    glColor3f(0.0f, 0.7f, 0.0f);
	glPushMatrix();
    glTranslatef(670,280,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(660,270,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(650,290,0);
    circle(15);
    glPopMatrix();

    //tree3

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(925, 230);
	glVertex2f(925, 274);
	glVertex2f(935, 274);
	glVertex2f(935, 230);
    glEnd();

    glColor3f(0.0f, 0.7f, 0.0f);
    glPushMatrix();
    glTranslatef(945,270,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(925,264,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(945,264,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(925,270,0);
    circle(15);
    glPopMatrix();

      //tree4

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(975, 230);
	glVertex2f(975, 300);
	glVertex2f(985, 300);
	glVertex2f(985, 230);
    glEnd();

    glColor3f(0.0f, 0.7f, 0.0f);
    glPushMatrix();
    glTranslatef(995,310,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(975,290,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(995,294,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(975,310,0);
    circle(15);
    glPopMatrix();



}
void hill2(){

    glPushMatrix();
    glTranslatef(0,100,0);

    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(-100, 200);
	glVertex2i(50, 250);
	glVertex2i(100, 200);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(70, 200);
	glVertex2i(200, 300);
	glVertex2i(330, 200);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(280, 200);
	glVertex2i(350, 275);
	glVertex2i(420, 200);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(400, 200);
	glVertex2i(500, 300);
	glVertex2i(600, 200);
	glEnd();
	//grass
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 0.0f);
	glVertex2i(525, 200);
	glVertex2i(550, 210);
	glVertex2i(560, 220);
	glVertex2i(570, 220);
	glVertex2i(580, 230);
	glVertex2i(590, 235);
	glVertex2i(600, 238);
	glVertex2i(700, 240);
	glVertex2i(700, 200);

	glEnd();

	//mountain
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(650, 200);
	glVertex2i(740, 285);
	glVertex2i(830, 200);
    glEnd();

    //grass
    glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 0.0f);
	glVertex2i(800, 200);
	glVertex2i(850, 210);
	glVertex2i(860, 220);
	glVertex2i(870, 220);
	glVertex2i(880, 230);
	glVertex2i(890, 235);
	glVertex2i(900, 238);
	glVertex2i(1200, 240);
	glVertex2i(1200, 200);

	glEnd();

	//trees
	//tree1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(605, 230);
	glVertex2f(605, 290);
	glVertex2f(615, 290);
	glVertex2f(615, 230);

    glEnd();
    glColor3f(0.0f, 0.7f, 0.0f);
	glPushMatrix();
    glTranslatef(600,280,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(620,270,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(610,290,0);
    circle(15);
    glPopMatrix();

    //tree2
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(655, 230);
	glVertex2f(655, 290);
	glVertex2f(665, 290);
	glVertex2f(665, 230);

    glEnd();
    glColor3f(0.0f, 0.7f, 0.0f);
	glPushMatrix();
    glTranslatef(670,280,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(660,270,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(650,290,0);
    circle(15);
    glPopMatrix();

    //tree3

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(925, 230);
	glVertex2f(925, 274);
	glVertex2f(935, 274);
	glVertex2f(935, 230);
    glEnd();

    glColor3f(0.0f, 0.7f, 0.0f);
    glPushMatrix();
    glTranslatef(945,270,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(925,264,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(945,264,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(925,270,0);
    circle(15);
    glPopMatrix();

      //tree4

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(975, 230);
	glVertex2f(975, 300);
	glVertex2f(985, 300);
	glVertex2f(985, 230);
    glEnd();

    glColor3f(0.0f, 0.7f, 0.0f);
    glPushMatrix();
    glTranslatef(995,310,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(975,290,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(995,294,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(975,310,0);
    circle(15);
    glPopMatrix();

     glPopMatrix();

}
void river1(){

    //darker
    //glColor3f(0.0f, 0.0f, 1.0f);//Dark blue
    glColor3ub(0, 186, 255);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(1200, 0);
    glVertex2d(1200, 400);
    glVertex2d(0, 400);
    glEnd();

    glColor3ub(0, 188, 255);
    glBegin(GL_POLYGON);
    glVertex2d(0, 200);
    glVertex2d(1200, 200);
    glVertex2d(1200, 300);
    glVertex2d(0, 300);
    glEnd();

    glColor3ub(0, 190, 255);
    glBegin(GL_POLYGON);
    glVertex2d(0, 300);
    glVertex2d(1200, 300);
    glVertex2d(1200, 320);
    glVertex2d(0, 320);
    glEnd();

    glColor3ub(0, 191, 255);
    glBegin(GL_POLYGON);
    glVertex2d(0, 300);
    glVertex2d(1200, 300);
    glVertex2d(1200, 600);
    glVertex2d(0, 600);
    glEnd();

}

void plant3L(int x3, int x4, int m){
    int dis = x4-x3;
    dis = dis/3;
    glColor3ub( 40,170,5);
    glBegin(GL_POLYGON);
    glVertex2f(x3,0);
    glVertex2f(x3-10,m-10);
    glColor3f(0.0,0.5,0.0);
    glVertex2f(x3+dis,15);
    glVertex2f(x3+((x4-x3)/2),m);
    glVertex2f(x4-dis,15);
    glVertex2f(x4+12,m+10);
    glVertex2f(x4,0);
    glEnd();
}

void plant2L(int x3, int x4, int h1, int h2){

    glColor3ub( 60,170,15);
    glBegin(GL_POLYGON);
    glVertex2f(x3,0);
    glVertex2f(x3-20,h1);
    glColor3f(0.0,0.3,0.0);
    glVertex2f(x4,0);
    glVertex2f(x3+15,h2);
    glEnd();
}
void plant()
{
    plant2L(50,40,40,60);
    plant2L(95,85,50,60);
    plant2L(120,110,45,65);
    plant2L(70,60,60,40);
    plant2L(140,130,43,60);
    plant2L(950,940,40,50);
    plant2L(870,860,50,60);
    plant2L(470,460,40,50);
    plant2L(490,480,55,65);
    plant2L(520,510,40,50);
    plant2L(540,530,50,60);
    plant2L(700,690,40,50);
    plant2L(730,720,55,65);
    plant2L(795,785,40,50);

    plant3L(10,20,60);
    plant3L(160,170,50);
    plant3L(310,320,70);
    plant3L(435,445,60);
    plant3L(750,760, 55);
    plant3L(820,830,80);
    plant3L(900,910, 55);
}
void drawBody() {

    glBegin(GL_POINTS);
    glPointSize(5);
    glColor3f(1, 0, 0);
    for (int x= 600; x>= 590; x-=1) {
        for(int y = 600; y>=544; y-=1){
            glVertex2d(x, y);
         }
    glEnd();
}
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(Scene0)
    screen();

    if(Scene1){
    sky();
    hill();
    sun();

     //clouds

    glPushMatrix();
    glTranslatef(coulds_x, 0, 0);


    // 1st cloud
    glColor3ub(255, 255, 255);

    circle(50, 30, 360, 400);

    circle(55, 20, 345, 400);

    circle(55, 20, 375, 400);

    // 2nd cloud

    circle(50, 30, 310, 320);

    circle(55, 20, 295, 320);

    circle(55, 20, 365, 320);
    glPopMatrix();


    river();
    side();
    wooden();

     //plastic_bottle();
    glPushMatrix();
    if(man_x>165){

       glTranslated(plasticB_x,plasticB_y,0);
       glRotated(10,0,0,-1);
    }
    else{
        glTranslated(man_x, 0, 0.0);
    }

    //body
    glBegin(GL_POLYGON);
    glColor3f(0, 0.2, 0.5); //light blue
	glVertex2d(365,140);
	glVertex2d(360,140);
	glVertex2d(360,130);
    glVertex2d(355,130);
    glVertex2d(355,95);
	glVertex2d(370,95);
	glVertex2d(370,130);
	glVertex2d(365,130);
	glVertex2d(365,135);
	glEnd();
	//cap
    glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2d(368,140);
	glVertex2d(360,140);
	glVertex2d(360,135);
	glVertex2d(368,135);
	glEnd();

    glPopMatrix();



     //man();

     glPushMatrix();
     glTranslated(man_x,0, 0.0);
	//Man 1 Draw
	//Left Leg
	glBegin(GL_QUADS);
	glColor3ub(44, 80, 197);
	glVertex2d(300,50);
	glVertex2d(325,50);
	glVertex2d(315,100);
	glVertex2d(310,100);

	//Right leg
    glVertex2d(330,50);
	glVertex2d(355,50);
	glVertex2d(345,100);
	glVertex2d(340,100);
	glEnd();

	//Body
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0 );
	glVertex2d(300,90);
	glVertex2d(350,90);
	glVertex2d(350,140);
	glVertex2d(300,140);
	glEnd();

	//Left hand
	glColor3ub(44, 80, 197);
	glLineWidth(25);
	glBegin(GL_LINES);
	//glLineWidth(200);
	glVertex2d(330,125);
	glVertex2d(330,105);
	glEnd();

	glBegin(GL_LINES);
	glVertex2d(325,105);
    glVertex2d(380,105);
	glEnd();


	//Shoe
	glBegin(GL_TRIANGLES);
	glColor3ub(0,0,0);
	glVertex2d(300,50);
	glVertex2d(325,50);
	glVertex2d(315,60);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(0,0,0);
	glVertex2d(330,50);
	glVertex2d(355,50);
	glVertex2d(345,60);
	glEnd();

    //neck
    glLineWidth(6);
	glBegin(GL_LINES);
	glColor3ub(249, 231, 159);
	glVertex2i(325, 140);
	glVertex2i(325,150);

	glEnd();
    //head
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 222, 157 );
    x0=325; y2=165; radius =20;

    twicePi = 2.0f * pi;


    glVertex2f(x0, y2); // center of circle
    for(int j = 0; j <= triangleAmount;j++) {
    glVertex2f(
    x0 + (radius * cos(j *  twicePi / triangleAmount)),
    y2 + (radius * sin(j * twicePi / triangleAmount))
        );
        }
    glEnd();
    //hair
	 glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0 );
    x0=325; y2=165; radius =20;

    // twicePi = 2.0f * pi;


    glVertex2f(x0, y2); // center of circle
    for(int j = 0; j <= triangleAmount;j++) {
    glVertex2f(
    x0 + (radius * cos(j *  pi / triangleAmount)),
    y2 + (radius * sin(j * pi / triangleAmount))
        );
        }
    glEnd();
    glPopMatrix();

    if(Droplets){

     //water droplets
      glColor3f(0,0,1);
      glPushMatrix();
      glTranslated(280,-300,0);
      glTranslated(wd1_x,wd1_y,0);
      circle(1,3,300,300);
      circle(1,3,305,301);
      circle(1,3,310,301);
      circle(1,3,315,300);
      glTranslated(wd2_x,wd2_y,0);
      circle(1,3,297,305);
      circle(1,3,305,308);
      circle(1,3,310,308);
      circle(1,3,318,305);
      glTranslated(wd3_x,wd3_y,0);
      circle(1,3,295,310);
      circle(1,3,303,318);
      circle(1,3,312,318);
      circle(1,3,320,310);
      glPopMatrix();
    }

    }
    if(Scene2){

     river1();

     //pebble
        rock1();
        rock2();
        rock3();
     //plant
     plant();

    // bubbles design
    glPushMatrix();
    glTranslated(0,-fish1_x,0);
    glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
    circle(10, 10, 120, 0);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0,-fish1_x,0);
    circle(5, 5, 130, -15);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0,-fish1_x,0);
   // glColor3f(1, 1, 1);
    circle(5, 5, 720, 0);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0,-fish1_x,0);
    //glColor3f(1, 1, 1);
    circle(5, 5, 730, -6);
    glPopMatrix();

     //fish1();
    glPushMatrix();
    glTranslatef(fish1_x, fish1_y, 0);
    //body
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(270,350);
    glVertex2f(300,325);
    glVertex2f(370,350);
    glVertex2f(300,375);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(360,350);
    glColor3ub(1.0,0.0,0.0);
    glVertex2f(405,370);
    glVertex2f(395,350);
    glVertex2f(405,327);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(1.0,0.0,0.0);
    glVertex2f(302,373);
    glColor3f(1.0,0.0,0.0);
	glVertex2f(340,409);
	glVertex2f(320,360);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(1.0,0.0,0.0);
    glVertex2f(302,328);
    glColor3f(1.0,0.0,0.0);
	glVertex2f(340,300);
	glVertex2f(320,340);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(280,355);
    glEnd();

    glPopMatrix();


     //fish2();

    glPushMatrix();
    glTranslatef(fish2_x, fish2_y, 0);
	glColor3f(1.0,0.0,0.0);

    glBegin(GL_POLYGON);
    glVertex2f(70,145);
    glColor3ub(1.0,0.0,0.0);
    glVertex2f(20,120);
    glVertex2f(30,145);
    glVertex2f(20,170);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(65,145);
    glVertex2f(125,170);
    glVertex2f(165,145);
    glVertex2f(125,120);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(1.0,0.0,0.0);
    glVertex2f(126,168);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(110,155);
    glVertex2f(85,195);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(1.0,0.0,0.0);
    glVertex2f(126,122);
    glColor3f(1.0,0.0,0.0);
	glVertex2f(110,136);
	glVertex2f(85,95);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(150,149);
    glEnd();
    glPopMatrix();

        //fish3();
    glPushMatrix();
    glTranslatef(-100, -50, 0);
    glTranslatef(fish1_x, fish1_y, 0);
    //body
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(270,350);
    glVertex2f(300,325);
    glVertex2f(370,350);
    glVertex2f(300,375);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(360,350);
    glColor3ub(1.0,0.0,0.0);
    glVertex2f(405,370);
    glVertex2f(395,350);
    glVertex2f(405,327);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(1.0,0.0,0.0);
    glVertex2f(302,373);
    glColor3f(1.0,0.0,0.0);
	glVertex2f(340,409);
	glVertex2f(320,360);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(1.0,0.0,0.0);
    glVertex2f(302,328);
    glColor3f(1.0,0.0,0.0);
	glVertex2f(340,300);
	glVertex2f(320,340);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(280,355);
    glEnd();

    glPopMatrix();


     //fish4();

    glPushMatrix();
    glTranslatef(250, 100, 0);
    glTranslatef(fish2_x, fish2_y, 0);
	glColor3f(1.0,0.0,0.0);

    glBegin(GL_POLYGON);
    glVertex2f(70,145);
    glColor3ub(1.0,0.0,0.0);
    glVertex2f(20,120);
    glVertex2f(30,145);
    glVertex2f(20,170);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(65,145);
    glVertex2f(125,170);
    glVertex2f(165,145);
    glVertex2f(125,120);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(1.0,0.0,0.0);
    glVertex2f(126,168);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(110,155);
    glVertex2f(85,195);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(1.0,0.0,0.0);
    glVertex2f(126,122);
    glColor3f(1.0,0.0,0.0);
	glVertex2f(110,136);
	glVertex2f(85,95);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(150,149);
    glEnd();
    glPopMatrix();



     //plastic_bottle_1();

     if(!break_down){

       glPushMatrix();
       glTranslated(plasticBp1_x,plasticB1_y,0);
       glRotated(angle2,0,0,-1);
       //initial

    //body
    glBegin(GL_POLYGON);
    glColor3f(0, 0.2, 0.5); //blue
    glVertex2d(600,600);
    glVertex2d(595,600);
    glVertex2d(595,590);
    glVertex2d(590,590);
    glVertex2d(590,545);
    glVertex2d(605,545);
    glVertex2d(605,590);
    glVertex2d(600,590);
    glVertex2d(600,600);
    glEnd();
    //capf
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(601,600);
    glVertex2d(593,600);
    glVertex2d(593,595);
    glVertex2d(601,595);
    glEnd();
    glPopMatrix();
    }


     //break_process();
    if(break_down){

     if(into_two){
    glPushMatrix();
    glRotated(angle2,0,0,-1);

       //two pieces
    glBegin(GL_POLYGON);
    glColor3f(0, 0.2, 0.5); //ligt green
    glVertex2d(600,300);
	glVertex2d(595,300);
    glVertex2d(595,290);
    glVertex2d(590,290);
    glVertex2d(590,270);
    glVertex2d(605,270);
    glVertex2d(605,290);
    glVertex2d(600,290);
    glEnd();
    //second
    glBegin(GL_QUADS);
    glVertex2d(590,260);
    glVertex2d(590,235);
    glVertex2d(605,235);
    glVertex2d(605,260);


	glEnd();
	//cap
    glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2d(601,300);
	glVertex2d(593,300);
    glVertex2d(593,295);
    glVertex2d(601,295);
	glEnd();
	glPopMatrix();

    }

    //four pieces
    if(into_four){
   //1st
    glPushMatrix();
    glTranslated(0, plasticB1_y+200, 0.0);
    glRotated(angle2,0,0,-1);

    glBegin(GL_POLYGON);
    glColor3f(0, 0.2, 0.5);

    glVertex2d(600,300);
    glVertex2d(605,300);
    glVertex2d(605,290);
    glVertex2d(610,290);
    glVertex2d(610,270);
    glVertex2d(600,270);
    glEnd();
    glBegin(GL_POLYGON);
    //2nd
    glVertex2d(590,300);
    glVertex2d(585,300);
    glVertex2d(585,290);
    glVertex2d(580,290);
    glVertex2d(580,270);
    glVertex2d(590,270);
     glEnd();
    //3rd
    glBegin(GL_QUADS);
    glVertex2d(590,260);
    glVertex2d(585,260);
    glVertex2d(585,235);
    glVertex2d(590,235);
    //4th
    glVertex2d(610,235);
    glVertex2d(605,235);
    glVertex2d(605,260);
    glVertex2d(610,260);

	glEnd();
	//cap
    glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2d(601,310);
	glVertex2d(593,310);
    glVertex2d(593,305);
    glVertex2d(601,305);
	glEnd();
	glPopMatrix();
    }
    if(into_eight){

    if(!into_micro){
    glPushMatrix();
    glTranslated(-20, plasticBp1_y, 0.0);
    glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2d(571,310);
	glVertex2d(593,310);
    glVertex2d(593,305);
    glVertex2d(571,305);
	glEnd();
    glColor3f(0, 0.2, 0.5);
    glBegin(GL_QUADS);
    glVertex2d(615,280);
    glVertex2d(605,280);
    glVertex2d(605,260);
    glVertex2d(615,260);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2d(600,300);
    glVertex2d(610,300);
    glVertex2d(610,290);
    glVertex2d(600,290);
    glEnd();
    glPopMatrix();

    }
    //micro
    glPushMatrix();
    glTranslated(-80, -50, 0.0);
    glTranslated(plasticBp1_x, plasticBp1_y, 0.0);

    glColor3f(0, 0, 1);
    glBegin(GL_POINTS);
    glVertex2f(600,350);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(605,355);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(610,320);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(615,325);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(620,320);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(600,320);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(600,330);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(600,335);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(620,330);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(600,335);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(620,330);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(600,335);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(620,330);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(625,330);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(600,335);
    glEnd();
    glPopMatrix();
    }

    if(into_micro){
    glPushMatrix();
    glTranslated(-80, -50, 0.0);
    glTranslated(plasticBp1_x, plasticBp1_y, 0.0);

    glBegin(GL_POINTS);
	glVertex2d(571,310);
	glVertex2d(593,310);
    glVertex2d(593,305);
    glVertex2d(571,305);
    glVertex2d(615,280);
    glVertex2d(605,280);
    glVertex2d(605,260);
    glVertex2d(615,260);
    glVertex2d(600,300);
    glVertex2d(610,300);
    glVertex2d(610,290);
    glVertex2d(600,290);
    glEnd();
    glColor3f(0, 0, 1);
     glBegin(GL_POINTS);
    glVertex2f(590,350);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(620,350);
    glEnd();
     glBegin(GL_POINTS);
    glVertex2f(615,320);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(600,350);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(605,355);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(610,320);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(615,325);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(620,320);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(600,320);
    glEnd();
     glBegin(GL_POINTS);
    glVertex2f(600,330);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(600,335);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(620,330);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(600,335);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(620,330);
    glEnd();glBegin(GL_POINTS);
    glVertex2f(600,335);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(620,330);
    glEnd();
     glBegin(GL_POINTS);
    glVertex2f(625,330);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(600,335);
    glEnd();
    glPopMatrix();
     }
    }

    }
    if(Scene3){
    sky1();
    river2();
    hook();
    hill2();
    sun();
   // clouds();
    boat();
    hook();
    man_1();
    microplastic();

    //background fish
    glPushMatrix();
    glScalef(0.4,0.4,0.5);

     //fish1();
    glPushMatrix();
    glTranslatef(fish1_x, fish1_y, 0);
    //body
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(270,350);
    glVertex2f(300,325);
    glVertex2f(370,350);
    glVertex2f(300,375);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(360,350);
    glColor3ub(1.0,0.0,0.0);
    glVertex2f(405,370);
    glVertex2f(395,350);
    glVertex2f(405,327);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(1.0,0.0,0.0);
    glVertex2f(302,373);
    glColor3f(1.0,0.0,0.0);
	glVertex2f(340,409);
	glVertex2f(320,360);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(1.0,0.0,0.0);
    glVertex2f(302,328);
    glColor3f(1.0,0.0,0.0);
	glVertex2f(340,300);
	glVertex2f(320,340);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(280,355);
    glEnd();

    glPopMatrix();




        //fish3();
    glPushMatrix();
    glTranslatef(-100, -50, 0);
    glTranslatef(fish1_x, fish1_y, 0);
    //body
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(270,350);
    glVertex2f(300,325);
    glVertex2f(370,350);
    glVertex2f(300,375);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(360,350);
    glColor3ub(1.0,0.0,0.0);
    glVertex2f(405,370);
    glVertex2f(395,350);
    glVertex2f(405,327);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(1.0,0.0,0.0);
    glVertex2f(302,373);
    glColor3f(1.0,0.0,0.0);
	glVertex2f(340,409);
	glVertex2f(320,360);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(1.0,0.0,0.0);
    glVertex2f(302,328);
    glColor3f(1.0,0.0,0.0);
	glVertex2f(340,300);
	glVertex2f(320,340);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(280,355);
    glEnd();

    glPopMatrix();


    glPopMatrix();





    //fish3;
    glPushMatrix();
    glTranslatef(fish3_x,0, 0);

    if(fish3_x>720){
        glRotated(10,0,0,-1);
        glTranslatef(0,f3_y, 0);
       glScalef(0.7,0.7,0.7);
       glTranslatef(40,80, 0);

    }


    //bod
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(70,145);
    glColor3ub(1.0,0.0,0.0);
    glVertex2f(20,120);
    glVertex2f(30,145);
    glVertex2f(20,170);
    glEnd();

    if(open){
    //body
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(65,145);
    glVertex2f(125,170);
    glVertex2f(160,145);
    glVertex2f(150,140);
    glVertex2f(160,135);
    glVertex2f(125,120);
    glEnd();
    }
    else{
    //body
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(65,145);
    glVertex2f(125,170);
    glVertex2f(165,140);
    glVertex2f(125,120);
    glEnd();
    }

    glBegin(GL_TRIANGLES);
    glColor3ub(1.0,0.0,0.0);
    glVertex2f(126,168);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(110,155);
    glVertex2f(85,195);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(1.0,0.0,0.0);
    glVertex2f(126,122);
    glColor3f(1.0,0.0,0.0);
	glVertex2f(110,136);
	glVertex2f(85,95);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(150,149);
    glEnd();


    glPushMatrix();
    //particle entering
    //if (fish3_x>200)
    glTranslated(particle_mov,0,0);
    if(fish3_x>=300){
    glBegin(GL_POINTS);
    glVertex2f(-5550,149);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(-555,140);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(-5252,145);
    glEnd();
    glPopMatrix();
    }
    else{
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POINTS);
    glVertex2f(250,149);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(255,140);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(252,145);
    glEnd();
    glPopMatrix();
    }
    if(fish3_x>300){
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POINTS);
    glVertex2f(100,149);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(105,140);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(102,145);
    glEnd();
    }
    glPopMatrix();


    }

    if(Scene4){
    //Scene4=true;
    glColor3f(1.0,1.0,1.0);
	drawstring(406,70,0.0,"Press 'z' to continue",0);
    }
    //glutPostRedisplay();
    glFlush();

}
void Message()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslated(0,-150,0);
    glColor3f(1.0,1.0,1.0);
	drawstring(210,425,0.0," Let's join hands!   ",1);
		glColor3f(1.0,1.0,1.0);
	drawstring(210,385,0.0,"To protect our oceans and body,",1);
		glColor3f(1.0,1.0,1.0);
	drawstring(210,350,0.0,"from the silent invaders,'microplastics'.",1);
	 	glColor3f(1.0,1.0,1.0);
	 	glColor3f(1.0,1.0,1.0);
	drawstring(210,320,0.0,"Thank You!",1);
	glPopMatrix();


glFlush();
 //glutSwapBuffers();
}

void display4(){
    Message();
    glFlush();
}




void update01(int value){

    if(Scene1){
     coulds_x+=couldSpeed1;
    //fish mouth
    if (coulds_x>600)
        coulds_x=-1200;

    if(man_x<=165){
       man_x+=man_speed;
    }
    else{

        int a=9;
        if(plasticB_y<-10 &&plasticB_x<200){

            plasticB_y+=a;
            plasticB_x=plasticB_x;
            a-=7;
            Droplets=true;


        }
        else if(plasticB_y<-20 ){
                Scene1=false;
                Scene2=true;
        }
        else{

        man_x=man_x;
        plasticB_y-=plasticB_speed;
        plasticB_x+=plasticB_speed;
        }

        if(Droplets){
            //sndPlaySound("waterdrops.wav",SND_ASYNC);
            wd1_x-= wd_speed;
            wd1_y-=wd_speed;
            //wd2_x=
            wd2_y-=wd_speed;
            wd3_x+=wd_speed;
            wd3_y-=wd_speed;
        }


    }
    }
    if(Scene2||Scene3){
    if(fish1_x>=-500)
        fish1_x-=fish1_speed;
    else
        fish1_x=700;

    if(fish1_x<-500){
        fish1_y-=100;
    }

    if(fish1_y<-251){
        fish1_y=100;
    }
        if(fish2_x<=1000)
        fish2_x+=fish2_speed;
    else
        fish2_x=-500;

    if(fish2_x>1200){
        fish2_y=fish2_y+150;
    }
    if(fish2_y>251){
        fish2_y=5;
    }
    if(plasticB1_y>=-300){
        plasticB1_y-=plasticBp1_speed;
        plasticBp1_x+=plasticBp1_speed;
    }
    else{
        plasticB1_y=plasticB1_y;
        plasticBp1_x=plasticBp1_x;
        break_down=true;
        into_two=true;
        lag++;
    }

    if(lag>=30){
    Droplets=false;
    into_two=false;
    into_four=true;
    }
    if(lag>=60){
    into_eight=true;
    plasticBp1_y-=plasticBp1_speed;
    into_four=false;
    }
    if(lag>=90){
    into_micro=true;
    plasticBp1_x+=1;
        if(plasticBp1_x>500){
            plasticBp1_x=-700;
        }
    }
    if(lag>=150){
        Scene2=false;
        Scene3=true;
        particle_mov-=4;
    }

    }


        open=!open;

    if(Scene3 && (fish3_x<=720)){
        fish3_x+=fish2_speed;

    }


    if(fish3_x>720){

        if(f3_y<20){
        f3_y+=1;
        }
        else f3_y=f3_y;
    }
     if(lag>=270){
        //Scene3=false;
        Scene4=true;

    }

    glutPostRedisplay();
    glutTimerFunc(100, update01, 0);
}
void update(int value)
{
    sunPosition1-=sunSpeed1;
    cloudPosition1+=couldSpeed1;
    cloudPosition2+=couldSpeed2;
    policecarPosition-=policecarSpeed;
    vanPosition2+=vanspeed2;
    carPosition2-=carSpeed2;
    hujurPosition2+=hujurspeed1;
    hujurPosition1-=hujurspeed1;
    bmenPosition1+=hujurspeed1;
    emenPosition1-=hujurspeed1;
    lmenPosition1-=hujurspeed1;
    MplasticPosi -= MplasticSpeed;
    MouthPosition+=MouthSpeed;
    // printf("%f\n",emenPosition1);

    if(hujurPosition1<-18)
        hujurPosition1=200;

    if(hujurPosition2>170)
        hujurPosition2=-30;

    if(bmenPosition1>43)
        bmenPosition1=-180;

    if(emenPosition1<-160)
        emenPosition1=50;

    if(vanPosition2>195)
    {
        vanPosition2=-40;
        menPosition2=0;

    }
    if(vanPosition2>88 && vanPosition2<93)
    {
        vanPosition2-=1.95;//van break

    }
    if(vanPosition2>88)
    {
        menPosition2+=menspeed2;
        if(menPosition2>28)
        {
            menPosition2+=1.5;
        }

//     printf("%f\n",menPosition2);
    }

    if(carPosition2<-180)
        carPosition2=70;




    if(sunPosition1<-180)
    {
        sunPosition1=30;
    }

    if(cloudPosition1>180)
    {
        cloudPosition1=-30;
    }
    if(cloudPosition2>150)
    {
        cloudPosition2=-70;
    }
    if(policecarPosition<-200)
    {
        policecarPosition=50;
    }


    sunPosition2-=sunSpeed2;
    cloudPosition3+=couldSpeed3;
    cloudPosition4+=couldSpeed4;
    carPosition1-=carSpeed1;
    vanPosition1+=vanspeed1;
    basketPosition-=basketspeed;
    policecarPosition2-=policecarSpeed2;


    if(sunPosition2<-180)
        sunPosition2=30;
    if(cloudPosition3>190)
        cloudPosition3=-30;
    if(cloudPosition4>150)
        cloudPosition4=-80;
    if(carPosition1<-180)
        carPosition1=70;
    if(vanPosition1>195)
        vanPosition1=-40;
    if(policecarPosition2<-200)
        policecarPosition2=50;

    if(vanPosition1>96 && vanPosition1<99)
    {
        vanPosition1-=1.95;           //van break
        basketPosition=0;
    }


    if(basketPosition<-23)
        basketPosition=vanPosition1;

    if(MplasticPosi <-70)
        MplasticPosi = -9;
    if(MouthPosition >3)
        MouthPosition = 1;



    glutPostRedisplay();


    glutTimerFunc(100, update, 0);
}
void handleKeypress(unsigned char key,int x0,int y2)
{

	switch (key)
    {

    case 's':
        Scene0=false;
        Scene1=true;
        break;
    case 'm':
        init01();
        glutDisplayFunc(display4);
        glutPostRedisplay();
        break;

    case 'z':
        init();
        glutDisplayFunc(display1);
        glutPostRedisplay();
        break;

    case 'a':
         init();
        glutDisplayFunc(display1N);
        glutPostRedisplay();
        break;

    case 'e':
        init();
        glutDisplayFunc(display2);
        glutPostRedisplay();
        break;

    case 't':
        init();
        glutDisplayFunc(display2N);
        glutPostRedisplay();
        break;
    case 'x':
        init();
        glutDisplayFunc(display3);
        glutPostRedisplay();
        break;


    case 'q':
        exit(0);


    }

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 600);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Microplastic");
    init01();
     glutReshapeFunc(reshape);
    glutDisplayFunc(display);
   // sndPlaySound("waterdrops.wav",SND_ASYNC);
    glutTimerFunc(1, update01, 0);
    glutTimerFunc(1, update, 0);
    glutKeyboardFunc(handleKeypress);


    glutMainLoop();
    return 0;

}

