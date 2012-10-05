#include "headers.h"
#include "Input.h"
#include "Player.h"

//Handle keypresses
int handleKeys(SDL_keysym* keysym, bool state){
	if (state == true){
		switch(keysym->sym){
			case SDLK_ESCAPE: StillPlaying = false; break;
			case SDLK_a: return 1; break;
			case SDLK_d: return 2; break;
			case SDLK_w: return 3; break;
			case SDLK_s: return 4 ; break;
			default: break;
		}
	}else{
		switch(keysym->sym){
			case SDLK_ESCAPE: StillPlaying = false; break;
			case SDLK_a: return 5; break;
			case SDLK_d: return 6; break;
			case SDLK_w: return 7; break;
			case SDLK_s: return 8; break;
			default: break;
		}
	}
	return 0;
}

//Process SDL Events
int processEvents(){
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_KEYDOWN: return handleKeys(&event.key.keysym, true); break;
			case SDL_KEYUP: return handleKeys(&event.key.keysym, false); break;
			case SDL_QUIT: StillPlaying = false; break;
			case SDL_MOUSEMOTION: player.rotate(event.motion.x, event.motion.y);
		}
	}
	return 0;
}