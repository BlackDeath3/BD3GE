#include "../Header/includes.h"

Display *display;
Window window;
GC graphicsContext = NULL;
XEvent event;
GLXFBConfig *FBConfig = NULL;
XVisualInfo *visualInfo = NULL;
XSetWindowAttributes WindowAttr;
GLXContext glxContext = NULL;
GLXWindow glxWindow = NULL;
ALCdevice* device;
ALCcontext* context;
bool DBFlag = true;
Input input;
//POCube boxanne(0.0, 0.0, -100.0, 0, 0, 255, 0.0, 0.0, 0.0, 10.0);
GLuint vao1;
GLuint vbo1;
GLfloat vertices[] =
{
	-0.5f, 0.5f, -10.0f,
	-0.5f, -0.5f, -10.0f,
	0.5f, -0.5f, -10.0f,
	-0.5f, 0.5f, -10.0f,
	0.5f, 0.5f, -10.0f,
	0.5f, -0.5f, -10.0f
};
