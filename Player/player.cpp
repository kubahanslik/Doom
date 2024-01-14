#include "player.h"

Player::Player(SDL_Renderer* rend, Map& map, Uint64& deltaTime) :
	renderer(rend),
	map(map),
	deltaTime(deltaTime),
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

	angle -= mouse_rel_x * MOUSE_SENSITIVITY * deltaTime;

	double cos_a = std::cos(angle);
	double sin_a = std::sin(angle);

	double cos_speed = cos_a * SPEED * deltaTime;
	double sin_speed = sin_a * SPEED * deltaTime;

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

	if (!map.isInWall(pos_x + dx * SIZE, pos_y)) {
		pos_x += dx;
	}
	if (!map.isInWall(pos_x, pos_y + dy * SIZE)) {
		pos_y += dy;
	}

}

void Player::draw() {
	SDL_Rect rect;
	rect.x = pos_x * 100 - HALF_WIDTH;
	rect.y = pos_y * 100 - HALF_WIDTH;
	rect.w = WIDTH;
	rect.h = WIDTH;
	SDL_SetRenderDrawColor(renderer, 255, 255, 153, 255);
	SDL_RenderDrawLine(renderer, rect.x + HALF_WIDTH, rect.y + HALF_WIDTH, rect.x + HALF_WIDTH + std::cos(angle) * 1600, rect.y + HALF_WIDTH - std::sin(angle) * 1600);
	SDL_RenderFillRect(renderer, &rect);
}