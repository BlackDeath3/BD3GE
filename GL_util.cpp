#include "../Header/includes.h"

void GL_reshape(int x, int y)
{
	if(x < 0 || x > SCREEN_WIDTH || y < 0 || y > SCREEN_WIDTH)
	{
		return;
	}
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
	gluPerspective(45.0, (GLdouble)x / (GLdouble)y, 0.01, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);
}

void GL_init(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	GL_reshape(WINDOW_WIDTH, WINDOW_HEIGHT);
	glFlush();
}
