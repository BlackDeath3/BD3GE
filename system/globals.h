#ifndef GLOBALS_H
#define GLOBALS_H

extern Display *display;
extern Window window;
extern GC graphicsContext;
extern XEvent event;
extern GLXFBConfig *FBConfig;
extern XVisualInfo *visualInfo;
extern XSetWindowAttributes WindowAttr;
extern GLXContext glxContext;
extern GLXWindow glxWindow;
extern ALCdevice* device;
extern ALCcontext* context;
extern bool DBFlag;
extern Input input;
//extern POCube boxanne;
extern GLuint vao1;
extern GLuint vbo1;
extern GLfloat vertices[18];

#endif /* GLOBALS_H */
