#ifndef glSnake_mainhead_h
#define glSnake_mainhead_h

#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

typedef struct { float x, y; } vec2f;
typedef struct { float x, y, z; } vec3f;
typedef struct { int x, y; } coord2i;

extern vec3f yellow;
extern vec3f green;

namespace screen {
    const unsigned height = 900;
    const unsigned width = 1440;
}

#endif
