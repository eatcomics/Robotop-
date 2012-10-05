#ifndef TILE_H
#define TILE_H

/*All members of this class are 32x32*/

//Tiles don't have collision
class Tile{
public:
	Tile();
	Tile(int setX, int setY, int setType);
	int getX(){ return x; }
	int getY(){ return y; }
	
private:
	int x,y;
	int type; //Which tile is supposed to be drawn here?
};

//Objects have collision
class Object{
public:
	void draw();
};

//Traps have collision/effects
class Trap{
public:
	void draw();
};

#endif