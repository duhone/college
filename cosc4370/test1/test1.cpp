// test1.cpp : Defines the entry point for the console application.
//
#include<gl\glut.h>
#include "object.h"
#include "objectlist.h"

GLfloat windowwidth;
GLfloat windowheight;

GLfloat triangle[9] = {-1,-1,0,		-1,1,0,		1,1,0};
GLfloat trianglecolor[12] = {1,0,0,1,	0,1,0,1,	0,0,1,1};

GLfloat triangle2[9] = {-1,-1,0		,-1,1,0,	1,1,0};
GLfloat trianglecolor2[12] = {1,1,1,.5,		1,1,1,.5,		1,1,1,.5};

objectlist mainlist;



void SpecialKeyCallback(int key,int x,int y)
{


}


void MouseCallback(int button,int state,int x,int y)
{
	if(button == GLUT_LEFT_BUTTON)
	{
		exit(0);
	}

}

void KeyboardCallback(unsigned char key,int x,int y)
{
	if(key == 27)
	{
		exit(0);
	}

}

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	mainlist.renderlist();
	glutSwapBuffers();
}

void ChangeSize(GLsizei w,GLsizei h)
{
	if(h == 0) h = 1;
	glViewport(0,0,w,h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-100,100,-100,100,1,1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Setup()
{
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
}

int main(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Test1");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeyCallback);
	glutMouseFunc(MouseCallback);
	glutKeyboardFunc(KeyboardCallback);

	Setup();
	
	mainlist.addobject(triangle,9,trianglecolor,12);
	mainlist.addobject(triangle2,9,trianglecolor2,12);

	glutMainLoop();
	return 0;
}
