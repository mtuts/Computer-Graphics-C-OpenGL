#include <iostream> 
#include <glut.h> 

GLint  WindowHeight = 400; 
GLint  WindowWidth  = 400; 

//------------------------------------------------------------------- 
void myInit(void) 
{ 
	glClearColor(0.0, 0.0, 1.0, 0.0); // set the background to blue 
	glColor3f(1.0f, 1.0f, 1.0f);      // set the drawing color to white 
	glPointSize(4.0); 

	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluOrtho2D(0.0,(float) WindowWidth,0.0, (float) WindowHeight); 
} 
//------------------------------------------------------------------- 
void myDisplay(void) 
{ 
  glClear( GL_COLOR_BUFFER_BIT ); 
  glFlush(); 
} 
//------------------------------------------------------------------- 
void draw(int x, int y)  
{
		glBegin(GL_POINTS); 
			glVertex2i(x, y); 
		glEnd(); 
  
		glFlush();
}
//------------------------------------------------------------------- 
void myMouse(int button, int state, int x, int y) 
{ 
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{ 
		draw(x, WindowHeight-y);
	} 
	
} 
void processNormalKeys(unsigned char key, int x, int y){

	if (key=='q')
		exit(0);
	
}
//------------------------------------------------------------------- 
void main( int argc, char **argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );  
	glutInitWindowSize(WindowWidth,WindowHeight); 
	glutInitWindowPosition(0,0); 
	glutCreateWindow("Mouse Input"); 

	glutDisplayFunc(myDisplay); 
	glutMouseFunc(myMouse); 
	glutKeyboardFunc(processNormalKeys);
	myInit(); 
	glutMainLoop(); 
}
