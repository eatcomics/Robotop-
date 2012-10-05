#include "Particles.h"
#include "Gfx.h"
#include "Player.h"
#include <time.h>
#include <math.h>

Particle::Particle(){
	lives = 0;
}

Particles::Particles(){
	srand(time(NULL));
	for (int i=0; i<100; i++){
		createParticles(i);
	}
}

void Particles::createParticles(int i){
	part[i].lifetime = rand() % 40;
	part[i].decay = 1;
	part[i].r = 1.0f;
	part[i].g = 0.0f;
	part[i].b = 0.0f;
	part[i].xpos = 0.0f;
	part[i].ypos = 0.0f;
	part[i].xspeed = rand() % 10 + 5;
	part[i].yspeed = rand() % 5 + 2;
	part[i].active = true;
	part[i].lives++;
}

void Particles::update(){
	for (int i=0; i<100; i++){
		part[i].lifetime -= part[i].decay;
		part[i].xpos += part[i].xspeed;
		part[i].ypos += part[i].yspeed;
	}
}

void Particles::draw(image *img){
	GLuint *texture = img->getTexture();
	
	glLoadIdentity();
	glPushMatrix();
	
	glTranslatef(320, 240, 0);
	glRotatef(player.getRotation(), 0, 0, 1);
	
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	
	for (int i=0; i<100; i++){
		if (part[i].active == true && part[i].lifetime > 0.0){
			glTexCoord2i(0,0);
			glVertex3f(part[i].xpos, part[i].ypos, 0.0f);

			glTexCoord2i(1,0);
			glVertex3f(part[i].xpos+3, part[i].ypos, 0.0f);
		
			glTexCoord2i(1,1);
			glVertex3f(part[i].xpos+3, part[i].ypos+3, 0.0f);
		
			glTexCoord2i(0,1);
			glVertex3f(part[i].xpos, part[i].ypos+3, 0.0f);
		}else{
			createParticles(i);
		}
	}
	glEnd();
	glPopMatrix();
}