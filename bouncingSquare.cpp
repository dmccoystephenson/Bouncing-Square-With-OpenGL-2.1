#include "bouncingSquare.h"

using namespace std;

bool init() {
	// initialize projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0);
	
	// initialize modelview matix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);
	
	// check for error
	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
		cout << "Error initializing OpenGL! " << gluErrorString(error) << "\n";
		return false;
	}
	
	// return success
	return true;
}

void update() {
	if (squareX == SCREEN_WIDTH - 50) {
		squareXVel = -5;
	}

	if (squareX == 50) {
		squareXVel = 5;
	}
	
	if (squareY == SCREEN_HEIGHT - 50) {
		squareYVel = -5;
	}
	
	if (squareY == 50) {
		squareYVel = 5;
	}

	squareX += squareXVel;
	squareY += squareYVel;
}

void render() {
	// clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);
	
	// reset modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// move to the center of the screen
	glTranslatef(squareX, squareY, 0.f);
	
	// RYGB mix
	glBegin(GL_QUADS);
		glColor3f(1.f, 0.f, 0.f); glVertex2f(-50.f, -50.f);
		glColor3f(1.f, 1.f, 0.f); glVertex2f(50.f, -50.f);
		glColor3f(0.f, 1.f, 0.f); glVertex2f(50.f, 50.f);
		glColor3f(0.f, 0.f, 1.f); glVertex2f(-50.f, 50.f);
	glEnd();
	
	// update screen
	glutSwapBuffers();
}

void runMainLoop(int val) {
	// frame logical_and
	update();
	render();
	
	// run frame one more time
	glutTimerFunc(1000/SCREEN_FPS, runMainLoop, val);
}

int main(int argc, char* args[]) {
	// initialize freeglut
	glutInit(&argc, args);
	
	// create OpenGL 2.1 context
	glutInitContextVersion(2, 1);
	
	// create double buffered window
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("OpenGL");
	
	// do post window context creation initialization
	if (!init()) {
		cout << "Unable to initialize graphics libray!\n";
		return 1;
	}
	
	// set rendering function
	glutDisplayFunc(render);
	
	// set main loop
	glutTimerFunc(1000/SCREEN_FPS, runMainLoop, 0);
	
	// start glut main loop
	glutMainLoop();
	
	return 0;
}