#include "Init.h"
#include "headers.h"

void initSDL(){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_SetVideoMode(640,480,32, SDL_OPENGL | SDL_GL_DOUBLEBUFFER);
	initOGL();
}

void initOGL(){
	glClearColor(0, 0, 0, 0);
	glClearDepth(1.0f);
	glViewport(0, 0, 640, 480);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 640, 480, 0, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_ALPHA_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);
	glLoadIdentity();
}