#include "../Header/includes.h"

int main()
{
	XWindow_init();
	GL_init();
	AL_init();
	glewInit();
	run();
	quit();

	return 0;
}
