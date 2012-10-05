#include "Tile.h"
#include "Gfx.h"
#include "headers.h"

Tile::Tile(){
	x = 0;
	y = 0;
	type = 0;
}

Tile::Tile(int setX, int setY, int setType){
	x = setX;
	y = setY;
	type = setType;
}