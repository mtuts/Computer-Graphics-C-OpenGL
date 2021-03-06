//Jeff Chastine

#include <GL/glut.h>  // Note: this automatically includes other 
                      // required header files, including: 
                      //    glu.h      (GL utility functions) 
                      //    gl.h       (GL functions) 
                      //    windows.h  (Microsoft windows stuff) 


void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // set the background to white

    glMatrixMode(GL_PROJECTION);		// set projection parameters
    glLoadIdentity();
    gluOrtho2D(0.0, 480.0, 0.0, 480.0);
}

void lineSegment(void)
{
    glClear(GL_COLOR_BUFFER_BIT);	// Clear display window

    glColor3f(1.0f, 0.0f, 0.0f);      // set the drawing color to red
    glBegin(GL_QUADS);				// start drawing in 'line' mode
    glVertex2i(10, 10);			// specify the lines geometry
    glVertex2i(10, 200);
    glVertex2i(200, 200);
    glVertex2i(200, 10);
    // end drawing 
    glEnd();

    glFlush();						// send any buffered output to  
                                      // the OpenGL rendering process 
}
//-------------------------------------------------------------------

void main(int argc, char** argv)
{
    glutInit(&argc, argv);						// Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowPosition(100, 200);		// Set top-left display window position
    glutInitWindowSize(320, 320);		// Set display window width and height
    glutCreateWindow("An Example");// Create display window

    init();  						// Execute initialization procedure
    glutDisplayFunc(lineSegment);		// Send graphics to display window
    glutMainLoop();					// Display everything and wait
}