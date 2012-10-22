#include "../Header/includes.h"

void quit(void)
{
	XWindow_destroy();
	AL_quit();
	std::cout << "Exiting now..." << std::endl;
	exit(0);
}

void render(POCube boxanne)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	boxanne.draw();
	glXSwapBuffers(display, glxWindow);
}

void run(void)
{
	XEvent firstEvent;
	timeval beforeTime;
	timeval afterTime;
	double elapsedTime = 0.0;
	POCube boxanne(0.0, 0.0, -10.0, 0, 0, 255, 0.0, 0.0, 0.0, 1.0);

	gettimeofday(&beforeTime, NULL);
	XNextEvent(display, &firstEvent);
	while(1)
	{
		//    Main game loop
		// =====================
		input.listener();
		gettimeofday(&afterTime, NULL);
		elapsedTime += ((afterTime.tv_sec - beforeTime.tv_sec) * 1000.0) + ((afterTime.tv_usec - beforeTime.tv_usec) / 1000.0);
		if(elapsedTime >= FRAME_RATE)
		{
			gettimeofday(&beforeTime, NULL);
//			std::cout << "FPS: " << 1 / (elapsedTime / 1000.0) << std::endl;
			elapsedTime = 0.0;
			input.handler(&boxanne);
			render(boxanne);
		}
		// =====================
	}
}
