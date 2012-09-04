#include "../Header/includes.h"

int SBAttr[] =
{
    GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
    GLX_RENDER_TYPE,   GLX_RGBA_BIT,
    GLX_RED_SIZE,      1,   /* Request a single buffered color buffer */
    GLX_GREEN_SIZE,    1,   /* with the maximum number of color bits  */
    GLX_BLUE_SIZE,     1,   /* for each component                     */
    None
};
int DBAttr[] =
{
    GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
    GLX_RENDER_TYPE,   GLX_RGBA_BIT,
    GLX_DOUBLEBUFFER,  true,  /* Request a double-buffered color buffer with */
    GLX_RED_SIZE,      1,     /* the maximum number of bits per component    */
    GLX_GREEN_SIZE,    1,
    GLX_BLUE_SIZE,     1,
    None
};

void XWindow_init(void)
{
	int colorBlack = 0;
	int colorWhite = 0;
	int configReturn = 0;
	int windowAttrMask = 0;
	int inputMask = 0;

	display = XOpenDisplay(NULL);
	if(NULL == display)
	{
		std:: cout << "ERROR: Null display" << std::endl;
		exit(1);
	}
	colorBlack = BlackPixel(display, DefaultScreen(display));
	colorWhite = WhitePixel(display, DefaultScreen(display));
	FBConfig = glXChooseFBConfig(display, DefaultScreen(display), DBAttr, &configReturn);
	if(!FBConfig)
	{
		FBConfig = glXChooseFBConfig(display, DefaultScreen(display), SBAttr, &configReturn);
		DBFlag = false;
	}
	visualInfo = glXGetVisualFromFBConfig(display, FBConfig[0]);
	WindowAttr.border_pixel = 0;
	WindowAttr.event_mask = StructureNotifyMask;
	WindowAttr.colormap = XCreateColormap(display, RootWindow(display, visualInfo->screen), visualInfo->visual, AllocNone);
	windowAttrMask = CWBorderPixel | CWColormap | CWEventMask;
	window = XCreateWindow(display, DefaultRootWindow(display), SCREEN_WIDTH - WINDOW_WIDTH, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 0, visualInfo->depth, InputOutput, visualInfo->visual, windowAttrMask, &WindowAttr);
	glxContext = glXCreateNewContext(display, FBConfig[0], GLX_RGBA_TYPE, NULL, true);
	glxWindow = glXCreateWindow(display, FBConfig[0], window, NULL);
	inputMask = StructureNotifyMask | KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | ExposureMask;
	XSelectInput(display, window, inputMask);
	XStoreName(display, window, "GameLoop");
	XMapWindow(display, window);
	graphicsContext = XCreateGC(display, window, 0, NULL);
	XSetForeground(display, graphicsContext, colorWhite);
	while(1)
	{
		XNextEvent(display, &event);
		if(event.type == MapNotify)
		{
			break;
		}
	}
	glXMakeContextCurrent(display, glxWindow, glxWindow, glxContext);
	XFlush(display);
}

void XWindow_destroy(void)
{
	if(glxContext)
	{
		if(!glXMakeCurrent(display, None, NULL))
		{
			std::cout << "ERROR: Could not release context" << std::endl;
		}
		glXDestroyContext(display, glxContext);
		glxContext = NULL;
	}
	XFreeGC(display, graphicsContext);
	XDestroyWindow(display, window);
	XCloseDisplay(display);
}
