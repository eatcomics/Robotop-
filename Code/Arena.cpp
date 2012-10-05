#include "Gfx.h"
#include "Arena.h"
#include <time.h>
#include <iostream>

/*
 * Generates an arena.
 * Stage one is deciding the shape (square, rectangle, cross, circle?)
 * Stage two is filling in the shape with basic tileset
 * Stage three is putting in obstacles
 * Stage four is the insertion of traps Which will probably be saved for lua implementation
*/
Arena::Arena(){
	srand(time(NULL));
	
	bool uDown = false;
	bool dDown = false;
	bool lDown = false;
	bool rDown = false;
	scrollXVel = 0;
	scrollYVel = 0;
	scrollX = 0;
	scrollY = 0;

	int shape = rand() % 3 + 1; //generate a number from 0 to 3, 0 being square, 1 rectangle, etc.
	
	std::cout << shape << "\n";
	
	//If shape is square, create a basic square
	if (shape == 1 || shape == 2 || shape == 3){
		int size = rand() % 60 + 50;
		size = 50;
		for (int i = 0; i<size; i++){
			for (int j = 0; j < size; j++){
				if (i == 0 || i == (size-1) || j == 0 || j == (size-1)){
					arena.push_back(2);
				}else{
					arena.push_back(1);
				}
			}
		}
	}/* else if (shape == 1){
		for (int i = 0; i<10; i++){
			for (int j = 0; j < 10; j++){
				arena.push_back(1);
			}
		}
	} else if (shape == 2){
		for (int i = 0; i<5; i++){
			for (int j = 0; j < 5; j++){
				arena.push_back(2);
			}
		}
	} else {
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++){
				arena.push_back(3);
			}
		}
	}
	*/
}

void Arena::drawArena(imgSheet *sh){
	int arenaCounter = 0; //the place you are in the arena vector
	for (int x = 0; x < 50; x++){
		for (int y = 0; y < 50; y++){
			if (arena[arenaCounter] == 1){
				sh->draw(0,0,512,512,(x*32)+scrollX,(y*32)+scrollY,32,32,0);
			}else if(arena[arenaCounter] == 2){
				sh->draw(32,0,512,512,(x*32)+scrollX,(y*32)+scrollY,32,32,0);
			}else{
				sh->draw(64,0,512,512,(x*32)+scrollX,(y*32)+scrollY,32,32,0);
			}
			arenaCounter++;
		}
	}
}

void Arena::setScroll(int value){
	if (value == 1) lDown = true; 
	if (value == 2) rDown = true; 
	if (value == 3) uDown = true; 
	if (value == 4) dDown = true; 
	
	if (value == 5) lDown = false; 
	if (value == 6) rDown = false; 
	if (value == 7) uDown = false; 
	if (value == 8) dDown = false; 
	
	if (lDown) scrollXVel = 6;
	if (rDown) scrollXVel = -6;
	if (uDown) scrollYVel = 6;
	if (dDown) scrollYVel = -6;
	
	if (!lDown && rDown) scrollXVel = -6;
	if (!rDown && lDown) scrollXVel = 6;
	if (!uDown && dDown) scrollYVel = -6;
	if (!dDown && uDown) scrollYVel = 6;
	
	if (!lDown && !rDown) scrollXVel = 0;
	if (!uDown && !dDown) scrollYVel = 0;
	
	scrollX = scrollX + scrollXVel;
	scrollY = scrollY + scrollYVel;
}