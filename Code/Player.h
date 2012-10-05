#ifndef PLAYER_H
#define PLAYER_H

class Player{
public:
	Player();
	~Player();
	int getX(){ return x; }
	int getY(){ return y; }
	void draw();
	int xvel;
	int yvel;
	void move();
	void rotate(int x, int y);
	float getRotation();
	
private:
	int x;
	int y;
	float rotation; //placeholder...
};

extern Player player;

#endif