//This file is to load and display images, also holds the screen

#ifndef GFX_H
#define GFX_H

#include "headers.h"

//All images 32x32
class image{
private:
	GLuint texture;
	
public:
	image(char *image); //image to load
	image();
	~image();
	void draw(int x, int y, int w, int h, float rot);
	GLuint getTexture(){ return &texture; } //We never speak of this. Its a quick and dirty way of fixing my particle system.
};

class imgSheet{
private:
	GLuint texture;
	
public:
	imgSheet(char *image);
	~imgSheet();
	void draw(float spritex, float spritey, float texturew, float textureh, float tilX, float tilY, float tilW, float tilH,float rot);
};

#endif