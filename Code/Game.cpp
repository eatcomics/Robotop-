#include "Game.h"
#include "headers.h"
#include "Tile.h"
#include "Input.h"
#include "Init.h"
#include "Gfx.h"
#include "Arena.h"
#include "Player.h"
#include "Particles.h"

Game::Game(){
}

Game::~Game(){
}

void Game::playGame(){
	//Init SDL and OGL
	initSDL();
	
	image err("default.bmp");    //error
	image pl("eatcomics.png");   //player
	image particle("part.bmp");  //particle image

	array[0] = err;
	array[1] = pl;

	image *p_part;
	p_part = &particle;

	Arena arena;

	imgSheet sheet("tiledem.bmp");
	imgSheet *sh;
	sh = &sheet;
	
	//Particles parts;
	
	//main loop
	while(StillPlaying == 1){
		array[0].draw(16,16,640,480,0);
		arena.setScroll(processEvents());
		arena.drawArena(sh);
		player.move();
		array[1].draw(304, 224, 32, 32, player.getRotation());
		//parts.update();
		//parts.draw(p_part);
		SDL_GL_SwapBuffers();
	}
	
	SDL_Quit();
}