#ifndef INCLUDES_H
#define INCLUDES_H

#define GL_GLEXT_PROTOTYPES

// System headers
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
//
// Linux-specific system headers
#include <unistd.h>
#include <sys/time.h>
//
// OpenGL/graphics headers
#include <GL/glew.h>
//#include <GL/glcorearb.h>		// OpenGL 3.x+ core functionality
#include <GL/glext.h>
#include <GL/glx.h>
//#include <GL/glu.h>
//
// OpenAL/sound headers
#include <AL/al.h>
#include <AL/alc.h>
//#include <AL/alext.h>
#include <vorbis/vorbisfile.h>
//
// BD3GE headers
#include "constants.h"
#include "XWindow_util.h"
#include "GL_util.h"
#include "AL_util.h"
#include "ogg.h"
#include "object.h"
#include "input.h"
#include "camera.h"
#include "globals.h"
#include "functions.h"
//

#endif /* INCLUDES_H */
