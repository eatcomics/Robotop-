#include "Player.h"
#include <math.h>
#define PI 3.1415926

Player player;

Player::Player(){
	x = 400;
	y = 400;
	rotation = 0;
}

Player::~Player(){
	
}

void Player::move(){
	x+=xvel;
	y+=yvel;
}

void Player::rotate(int mousex, int mousey){
	float dx = mousex - 304;
	float dy = mousey - 224;
	rotation = atan2f(dy, dx);
}

float Player::getRotation(){
	return (rotation*180/PI);
}