//NAME: Eric Duhon
//SSN:  453-97-8531
#include<gl\glut.h>
#include "object.h"
#include "objectlist.h"
#include "object_sphere.h"
#include "object_orbit.h"

GLfloat windowwidth;
GLfloat windowheight;

//planet rotation around the sun angles
float mecury_angle = 0;
float venus_angle = 0;
float earth_angle = 0;
float mars_angle = 0;

bool paused = false;
//enable the drawing of orbit lines
bool enable_orbits = true;

bool wire = false;


bool twist_yn = false;

//what action to perform when mouse moves
int action;
#define DO_NOTHING 1
#define MOVE_POS 2
#define LOOK_UPDNLTRT 4
#define LOOK_TWIST 8

int yprev = 0;
int xprev = 0;

/*models*/

//object list, contatins all objects
objectlist mainlist;


void SpecialKeyCallback(int key,int x,int y)
/*keyboard callback for special keys*/
{


}


void MouseCallback(int button,int state,int x,int y)
{
/*mouse callback function*/
	if(button == GLUT_RIGHT_BUTTON)
	{
//move view position
		action = MOVE_POS;
		xprev = x;
		yprev = y;
	}
	else if(button == GLUT_LEFT_BUTTON)
	{
		if(twist_yn)
		{
//twist the view
			action = LOOK_TWIST;
			xprev = x;
			yprev = y;
		}
		else
		{
//change the view angle up down left and right
			action = LOOK_UPDNLTRT;
			xprev = x;
			yprev = y;
		}
	}
	else
	{
//do nothing when mouse moves
		action = DO_NOTHING;
	}

}

void MouseMove(int x,int y)
{
/*mouse move callback function*/
	switch(action)
	{
	case MOVE_POS:
//move the view position
		mainlist.move_view_pos((y - yprev) / 100.0f);
		yprev = y;
		break;
	case LOOK_UPDNLTRT:
//change the view angle
		mainlist.view_updn((y-yprev) / 10.0f);
		mainlist.view_ltrt((x-xprev) / 10.0f);
		xprev = x;
		yprev = y;
		break;
	case LOOK_TWIST:
//twist the view
		mainlist.view_twist((x-xprev)/10.0f);
		xprev = x;
		break;
	};
	
}

void KeyboardCallback(unsigned char key,int x,int y)
/*keyboard callback function*/
{
	switch(key)
	{
	case 'x':
	case 'X':
//reset the view
		mainlist.reset_view();
		break;

	case 27:
		{
//esc key, exit
			exit(0);
			break;
		}
	case ' ':
		{
//draw wire frame or solid
			wire = !wire;
			mainlist.setwire(wire);
			break;
		}
	case 'r':
	case 'R':
		{
//pause motion
			paused = !paused;
			break;
		}
	case 'o':
	case 'O':
		{
//enable the orbit lines
			enable_orbits = !enable_orbits;
			if(enable_orbits)
			{
				mainlist.enable_object(5,true);
				mainlist.enable_object(6,true);
				mainlist.enable_object(7,true);
				mainlist.enable_object(8,true);
			}
			else
			{
				mainlist.enable_object(5,false);
				mainlist.enable_object(6,false);
				mainlist.enable_object(7,false);
				mainlist.enable_object(8,false);
			}

				
			break;
		}
	case 'e':
	case 'E':
		{
//change wether twist or not when mouse moves
			twist_yn = !twist_yn;
		}

};

}


void timerfunction(int value)
{
// 50 milliseconds have passed so redraw and move objects
	glutPostRedisplay();
	glutTimerFunc(50,timerfunction,1);


}
void RenderScene()
/*render entire scene*/
{
//if not paused move planets
	if(!paused)
	{
		mecury_angle += (.05 / 8.7969) * 360;
		venus_angle += (.05 / 22.4701) * 360;
		earth_angle += (.05 / 36.5256) * 360;
		mars_angle += (.05 / 68.7047) * 360;
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
//rotate the planets
	mainlist.rotateobj(1,0,mecury_angle,0);
	mainlist.rotateobj(2,0,venus_angle,0);
	mainlist.rotateobj(3,0,earth_angle,0);
	mainlist.rotateobj(4,0,mars_angle,0);

	
//render all objects
	mainlist.renderlist();
	
	glutSwapBuffers();
}

void ChangeSize(GLsizei w,GLsizei h)
/*change size of window*/
{
	float aspect;
	
	if(h == 0) h = 1;
	aspect = w/(float)h;
	glViewport(0,0,w,h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	gluPerspective(45,aspect,1,500);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Setup()
/*setup rendering enviroment*/
{
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
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
	glutMotionFunc(MouseMove);
	glutKeyboardFunc(KeyboardCallback);

	Setup();
	
//create sun and planets
	object_sphere *temp;
	object_orbit *temp2;

	temp = new object_sphere();
//sun
	mainlist.addobject(temp);
	mainlist.transobj(0,0,0,0);
	mainlist.scaleobj(0,10,10,10);
	mainlist.setcolor(0,1,1,0,1);
//mecury
	mainlist.addobject(temp);
	mainlist.transobj(1,36,0,0);
	mainlist.setcolor(1,0,1,0,1);
	mainlist.scaleobj(1,1.2,1.2,1.2);
//venus	
	mainlist.addobject(temp);
	mainlist.transobj(2,67.2,0,0);
	mainlist.scaleobj(2,1.9,1.9,1.9);
	mainlist.setcolor(2,1,.5,.5,1);
//earth	
	mainlist.addobject(temp);
	mainlist.transobj(3,93.2,0,0);
	mainlist.scaleobj(3,2,2,2);
	mainlist.setcolor(3,0,0,1,1);
//mars
	mainlist.addobject(temp);
	mainlist.transobj(4,141.5,0,0);
	mainlist.scaleobj(4,1.5,1.5,1.5);
	mainlist.setcolor(4,1,0,0,1);

//create orbit lines
	temp2 = new object_orbit;
//mecury orbit line
	mainlist.addobject(temp2);
	mainlist.transobj(5,0,0,0);
	mainlist.scaleobj(5,36,36,36);
	mainlist.setcolor(5,0,1,0,1);
// venus orbit line
	mainlist.addobject(temp2);
	mainlist.transobj(6,0,0,0);
	mainlist.scaleobj(6,67.2,67.2,67.2);
	mainlist.setcolor(6,1,.5,.5,1);
//earth orbit line
	mainlist.addobject(temp2);
	mainlist.transobj(7,0,0,0);
	mainlist.scaleobj(7,93,93,93);
	mainlist.setcolor(7,0,0,1,1);
//mars orbit line
	mainlist.addobject(temp2);
	mainlist.transobj(8,0,0,0);
	mainlist.scaleobj(8,141.5,141.5,141.5);
	mainlist.setcolor(8,1,0,0,1);

	glutTimerFunc(50,timerfunction,1);
	/*start loop*/
	glutMainLoop();
	return 0;
}
