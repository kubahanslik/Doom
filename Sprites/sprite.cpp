#include "sprite.h"

Sprite::Sprite(SDL_Renderer* renderer, Player& player, Projector& proj, const char* texture_path, double pos_x, double pos_y, double scale, double shift) :
	renderer(renderer),
	player(player),
	projector(proj),
	rendereable(Rendereable()),
	pos_x(pos_x),
	pos_y(pos_y),
	scale(scale),
	shift(shift)
{
	SDL_Surface* surface = IMG_Load(texture_path);

	rendereable.texture = SDL_CreateTextureFromSurface(renderer, surface);
	rendereable.srcrect.x = 0;
	rendereable.srcrect.y = 0;
	rendereable.srcrect.w = surface->w;
	rendereable.srcrect.h = surface->h;

	SDL_FreeSurface(surface);
}

Sprite::~Sprite() {}

void Sprite::update() {
	double dx = pos_x - player.pos_x;
	double dy = player.pos_y - pos_y;
	double delta_angle = std::atan2(dy, dx) - player.angle;

	if (delta_angle > M_PI)
		delta_angle -= M_PI * 2;
	else if (delta_angle < -M_PI)
		delta_angle += M_PI * 2;

	double depth = std::abs(std::hypot(dx, dy) * std::cos(delta_angle));
	int delta_pixels = delta_angle / Raycaster::DELTA_ANGLE * Raycaster::RAY_WIDTH;

	rendereable.distance = depth;
	rendereable.dstrect.h = Raycaster::SCREEN_DEPTH / depth * scale;
	rendereable.dstrect.w = (double)rendereable.dstrect.h / rendereable.srcrect.h * rendereable.srcrect.w;
	rendereable.dstrect.x = WINDOW_WIDTH / 2 - delta_pixels - rendereable.dstrect.w / 2;
	rendereable.dstrect.y = WINDOW_HEIGHT / 2 - rendereable.dstrect.h / 2 + shift * rendereable.dstrect.h;

	if (-rendereable.srcrect.w < rendereable.dstrect.x && rendereable.dstrect.x < WINDOW_WIDTH + rendereable.srcrect.w && rendereable.distance > 0.5)
		projector.rendereables.push_back(rendereable);
}