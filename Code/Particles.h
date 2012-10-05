#ifndef PARTICLES_H
#define PARTICLES_H
#include <iostream>

class image;

class Particle{
public:
	Particle();
	float lifetime;            //the particles total lifetime
	float decay;               //How fast the particle decays (MAY REMOVE)
	float r,g,b;               //COLORS!
	float xpos, ypos;          //current x and y of particle
	float xspeed, yspeed;      //how fast the particle moves on the x and y
	bool active;               //is the particle still alive?
	int lives;                 //the number of times the particle has lived
};

class Particles{
public:
	Particles();                 //Init the particles
	void createParticles(int i); //This function here creates the particles
	void update();               //Update the particles
	void draw(image *img);       //Draw the particles... obviously
private:
	Particle part[100];          //array of particles
};

#endif