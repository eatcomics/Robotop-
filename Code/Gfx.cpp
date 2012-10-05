#include "Gfx.h"
#include "headers.h"
#include <SDL/SDL_image.h>

image::image(){
	SDL_Surface *surface;	// This surface will tell us the details of the image
	GLenum texture_format;
	GLint  nOfColors;
 
	if ( (surface = IMG_Load("default.bmp")) ) { 
 
		// Check that the image's width is a power of 2
		if ( (surface->w & (surface->w - 1)) != 0 ) {
			printf("warning: image.bmp's width is not a power of 2\n");
		}
 
		// Also check if the height is a power of 2
		if ( (surface->h & (surface->h - 1)) != 0 ) {
			printf("warning: image.bmp's height is not a power of 2\n");
		}
 
		// get the number of channels in the SDL surface
		nOfColors = surface->format->BytesPerPixel;
		if (nOfColors == 4)     // contains an alpha channel
		{
				if (surface->format->Rmask == 0x000000ff)
						texture_format = GL_RGBA;
				else
						texture_format = GL_BGRA;
		} else if (nOfColors == 3)     // no alpha channel
		{
				if (surface->format->Rmask == 0x000000ff)
						texture_format = GL_RGB;
				else
						texture_format = GL_BGR;
		} else {
				printf("warning: the image is not truecolor..  this will probably break\n");
				// this error should not go unhandled
		}
 
		// Have OpenGL generate a texture object handle for us
		glGenTextures( 1, &texture );
 
		// Bind the texture object
		glBindTexture( GL_TEXTURE_2D, texture );
 
		// Set the texture's stretching properties
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
 
		// Edit the texture object's image data using the information SDL_Surface gives us
		glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0,
                      texture_format, GL_UNSIGNED_BYTE, surface->pixels );
	} 
	else {
		printf("SDL could not load image.bmp: %s\n", SDL_GetError());
		SDL_Quit();
	}    
 
	// Free the SDL_Surface only if it was successfully created
	if ( surface ) { 
		SDL_FreeSurface( surface );
	}
}

image::image(char *image){
	SDL_Surface *surface;	// This surface will tell us the details of the image
	GLenum texture_format;
	GLint  nOfColors;
 
	if ( (surface = IMG_Load(image)) ) { 
 
		// Check that the image's width is a power of 2
		if ( (surface->w & (surface->w - 1)) != 0 ) {
			printf("warning: "); printf(image); printf("'s width is not a power of 2\n");
		}
 
		// Also check if the height is a power of 2
		if ( (surface->h & (surface->h - 1)) != 0 ) {
			printf("warning: "); printf(image); printf("'s height is not a power of 2\n");
		}
 
		// get the number of channels in the SDL surface
		nOfColors = surface->format->BytesPerPixel;
		if (nOfColors == 4)     // contains an alpha channel
		{
				if (surface->format->Rmask == 0x000000ff)
						texture_format = GL_RGBA;
				else
						texture_format = GL_BGRA;
		} else if (nOfColors == 3)     // no alpha channel
		{
				if (surface->format->Rmask == 0x000000ff)
						texture_format = GL_RGB;
				else
						texture_format = GL_BGR;
		} else {
				printf("warning: the image is not truecolor..  this will probably break\n");
				// this error should not go unhandled
		}
 
		// Have OpenGL generate a texture object handle for us
		glGenTextures( 1, &texture );
 
		// Bind the texture object
		glBindTexture( GL_TEXTURE_2D, texture );
 
		// Set the texture's stretching properties
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
 
		// Edit the texture object's image data using the information SDL_Surface gives us
		glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0,
                      texture_format, GL_UNSIGNED_BYTE, surface->pixels );
	} 
	else {
		printf("SDL could not load image.bmp: %s\n", SDL_GetError());
		SDL_Quit();
	}    
 
	// Free the SDL_Surface only if it was successfully created
	if ( surface ) { 
		SDL_FreeSurface( surface );
	}
	
	printf("Image (con) loaded\n");
}

image::~image(){
	glDeleteTextures(1,&texture);
}

void image::draw(int x, int y, int w, int h, float rot){
	glLoadIdentity();
	glPushMatrix();
	
	glTranslatef(x,y,0);
	glRotatef(rot,0,0,1);
	
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
		
		glTexCoord2i(0,0);
		glVertex3f(-16.0f, -16.0f, 0.0f);

		glTexCoord2i(1,0);
		glVertex3f(-16.0f+w, -16.0f, 0.0f);
		
		glTexCoord2i(1,1);
		glVertex3f(-16.0f+w, -16.0f+h, 0.0f);
		
		glTexCoord2i(0,1);
		glVertex3f(-16.0f, -16.0f+h, 0.0f);
		
	glEnd();
	
	glPopMatrix();
}

imgSheet::imgSheet(char *image){
	SDL_Surface *surface;	// This surface will tell us the details of the image
	GLenum texture_format;
	GLint  nOfColors;
 
	if ( (surface = SDL_LoadBMP(image)) ) { 
 
		// Check that the image's width is a power of 2
		if ( (surface->w & (surface->w - 1)) != 0 ) {
			printf("warning: "); printf(image); printf("'s width is not a power of 2\n");
		}
 
		// Also check if the height is a power of 2
		if ( (surface->h & (surface->h - 1)) != 0 ) {
			printf("warning: "); printf(image); printf("'s height is not a power of 2\n");
		}
 
		// get the number of channels in the SDL surface
		nOfColors = surface->format->BytesPerPixel;
		if (nOfColors == 4)     // contains an alpha channel
		{
				if (surface->format->Rmask == 0x000000ff)
						texture_format = GL_RGBA;
				else
						texture_format = GL_BGRA;
		} else if (nOfColors == 3)     // no alpha channel
		{
				if (surface->format->Rmask == 0x000000ff)
						texture_format = GL_RGB;
				else
						texture_format = GL_BGR;
		} else {
				printf("warning: the image is not truecolor..  this will probably break\n");
				// this error should not go unhandled
		}
 
		// Have OpenGL generate a texture object handle for us
		glGenTextures( 1, &texture );
 
		// Bind the texture object
		glBindTexture( GL_TEXTURE_2D, texture );
 
		// Set the texture's stretching properties
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
 
		// Edit the texture object's image data using the information SDL_Surface gives us
		glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0,
                      texture_format, GL_UNSIGNED_BYTE, surface->pixels );
	} 
	else {
		printf("SDL could not load image.bmp: %s\n", SDL_GetError());
		SDL_Quit();
	}    
 
	// Free the SDL_Surface only if it was successfully created
	if ( surface ) { 
		SDL_FreeSurface( surface );
	}
	
	printf("Image (con) loaded\n");
}

imgSheet::~imgSheet(){
	glDeleteTextures(1,&texture);
}

void imgSheet::draw(float spritex, float spritey, float texturew, float textureh, float tilX, float tilY, float tilW, float tilH, float rot){		
	glLoadIdentity();
	
	glPushMatrix();
	
	glColor4ub(255,255,255,255);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
		
		glTexCoord2f(spritex/texturew, spritey/textureh);
		glVertex3f(tilX, tilY, 0.0f);

		glTexCoord2f((spritex+tilW)/texturew, spritey/textureh);
		glVertex3f(tilX+32.0f, tilY, 0.0f);
		
		glTexCoord2f((spritex+tilW)/texturew, (spritey+tilH)/textureh);
		glVertex3f(tilX+32.0f, tilY+32.0f, 0.0f);
		
		glTexCoord2f(spritex/texturew, (spritey+tilH)/textureh);
		glVertex3f(tilX, tilY+32.0f, 0.0f);
		
	glEnd();
	
	glPopMatrix();
}