#ifndef ARENA_H
#define ARENA_H

#include <vector>

class image;

class Arena{
public:
	Arena();
	void drawArena(imgSheet *sh);
	void setScroll(int value);
private:
	std::vector<int> arena; //a vector to hold the arena data
	bool uDown;
	bool dDown;
	bool lDown;
	bool rDown;
	int scrollX;
	int scrollY;
	int scrollXVel;
	int scrollYVel;
};

#endif