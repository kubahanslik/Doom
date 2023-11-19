#include "player.h"

Player::Player(SDL_Renderer* rend, Map& map) :
	renderer(rend),
	map(map),
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
	const Uint8* keys = SDL_GetKeyboardState(nullptr);
	SDL_GetRelativeMouseState(&mouse_rel_x, &mouse_rel_y);

	angle -= mouse_rel_x * MOUSE_SENSITIVITY * Engine::DELTA_TIME;

	double cos_a = std::cos(angle);
	double sin_a = std::sin(angle);

	double cos_speed = cos_a * SPEED * Engine::DELTA_TIME;
	double sin_speed = sin_a * SPEED * Engine::DELTA_TIME;

	double dx = 0;
	double dy = 0;

	if (keys[SDL_SCANCODE_W]) {
		dx += cos_speed;
		dy -= sin_speed;
	}
	if (keys[SDL_SCANCODE_S]) {
		dx -= cos_speed;
		dy += sin_speed;
	}
	if (keys[SDL_SCANCODE_A]) {
		dx -= sin_speed;
		dy -= cos_speed;
	}
	if (keys[SDL_SCANCODE_D]) {
		dx += sin_speed;
		dy += cos_speed;
	}

	if (!map.isInWall(pos_x + dx, pos_y)) {
		pos_x += dx;
	}
	if (!map.isInWall(pos_x, pos_y + dy)) {
		pos_y += dy;
	}

}

void Player::draw() {

}