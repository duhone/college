// test1.cpp : Defines the entry point for the console application.
//
#include<gl\glut.h>
#include "object.h"
#include "objectlist.h"
#include "object2d_p_c.h"

GLfloat windowwidth;
GLfloat windowheight;


/*models*/
GLfloat ground[12] = {-1,-1,		1,-1,		1,0,	
						-1,-1,		1,0,		-1,0};
GLfloat groundcolor[24] = {0,1,0,1,		0,1,0,1,	0,.5,0,1,
						   0,1,0,1,		0,.5,0,1,	0,.5,0,1};

GLfloat sky[12] = {-1,0		,1,0,		1,1,
				   -1,0		,1,1,		-1,1};
GLfloat skycolor[24] = {0,0,.6,1,		0,0,.6,1,		0,0,1,1,
						0,0,.6,1,		0,0,1,1,		0,0,1,1};

GLfloat dirt[6] = {0,-1		,1,-.05,		1,-1};
GLfloat dirtcolor[12] = {.86,.60,.26,1,		.64,.45,.19,1,		.043,.030,.013,1};

GLfloat water[6] = {.1,-1		,1,-.1,		1,-1};
GLfloat watercolor[12] = {0,0,1,.5,		0,0,.7,.5,		0,0,1,.5};

GLfloat tree[60] = {0,-.4		,.02,.1,		.01,.1,
				    0,-.4		,.03,-.4,		.02,.1,
					.015,0		,-.15,.2,		.015,-.05,
					.023,-.05		,.2,.2,		.023,-.1,
					0,.2		,-.15,.05,		.15,.05,
					0,.2		,-.3,.2,		-.15,.05,
					0,.2		,-.15,.35,		-.3,.2,
					0,.2		,.15,.35,		-.15,.35,
					0,.2		,.3,.2,		.15,.05,
					0,.2		,.15,.35,		.3,.2};

GLfloat treecolor[120] = {.4,.3,.15,1,		.4,.3,.15,1,		.4,.3,.15,1,
						.4,.3,.15,1,		.4,.3,.15,1,		.4,.3,.15,1,
						.4,.3,.15,1,		.4,.3,.15,1,		.4,.3,.15,1,
						.4,.3,.15,1,		.4,.3,.15,1,		.4,.3,.15,1,
						0,.5,0,1,			0,.3,0,1,			0,.3,0,1,
						0,.5,0,1,			0,.3,0,1,			0,.3,0,1,
						0,.5,0,1,			0,.3,0,1,			0,.3,0,1,
						0,.5,0,1,			0,.3,0,1,			0,.3,0,1,
						0,.5,0,1,			0,.3,0,1,			0,.3,0,1,
						0,.5,0,1,			0,.3,0,1,			0,.3,0,1};

objectlist mainlist;
/*list to hold objects*/


void SpecialKeyCallback(int key,int x,int y)
/*keyboard callback for special keys*/
{


}


void MouseCallback(int button,int state,int x,int y)
{
/*mouse callback function*/
	if(button == GLUT_LEFT_BUTTON)
	{
		exit(0);
	}

}

void KeyboardCallback(unsigned char key,int x,int y)
/*keyboard callback function*/
{
	if(key == 27)
	{
		exit(0);
	}

}

void RenderScene()
/*render entire scene*/
{
	glClear(GL_COLOR_BUFFER_BIT);
	mainlist.renderlist();
	
	glutSwapBuffers();
}

void ChangeSize(GLsizei w,GLsizei h)
/*change size of window*/
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
/*setup rendering enviroment*/
{
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
}

int main(int argc, char* argv[])
{
	/*setup callbacks*/
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
	
	/*create objects and load them*/
	object2d_p_c* temp;
	temp = new object2d_p_c;
	temp->setVertexArray(ground,12);
	temp->setColorArray(groundcolor,24);
	mainlist.addobject(temp);

	temp = new object2d_p_c;
	temp->setVertexArray(sky,12);
	temp->setColorArray(skycolor,24);
	mainlist.addobject(temp);

	temp = new object2d_p_c;
	temp->setVertexArray(dirt,6);
	temp->setColorArray(dirtcolor,12);
	mainlist.addobject(temp);
	
	temp = new object2d_p_c;
	temp->setVertexArray(water,6);
	temp->setColorArray(watercolor,12);
	mainlist.addobject(temp);
	
	temp = new object2d_p_c;
	temp->setVertexArray(tree,60);
	temp->setColorArray(treecolor,120);

	/*create a bunch of trees*/
	float tempscale;
	int objcount = 4;
	for(int count2 = 0;count2 < 3;count2++)
	{
		for(int count = 0+(count2);count < 6-count2;count++)
		{
			tempscale = (((rand()%10)*.001f)+.25f)*(count2+1);
			
			mainlist.addobject(temp);
			mainlist.scaleobj(objcount,tempscale,tempscale,0);
			mainlist.transobj(objcount,-3.5 + (count),0 - (count2 * .25f),0);
			objcount++;
		}
	}

	/*start loop*/
	glutMainLoop();
	return 0;
}
