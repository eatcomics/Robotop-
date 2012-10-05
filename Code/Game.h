//Holds the code for running the engine. It has the loop, loads assets, so on so forth
#ifndef GAME_H
#define GAME_H

#include "Gfx.h"
#include <vector>

class Game{
public:
	Game();  //This loads the images and files for the game
	~Game(); //This frees images and such
	void playGame();
	void loadImages();
private:
	image array[5];
	std::vector<image> imgs; //The vector of images
	std::vector<image>* p_imgs; //A pointer to the vector of images
};

#endif