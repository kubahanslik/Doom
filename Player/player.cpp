#include "player.h"

Player::Player(SDL_Renderer* rend) :
	renderer(rend),
	pos_x(1.5),
	pos_y(4.5),
	angle(0),
	mouse_rel_x(0),
	mouse_rel_y(0)
{
	
}

Player::~Player() {}

int Player::getTileX() {
	return (int)pos_x;
}

int Player::getTileY() {
	return (int)pos_y;
}

void Player::update() {

}

void Player::draw() {
	
}
