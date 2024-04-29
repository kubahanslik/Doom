#include "weapon.h"

Weapon::Weapon(SDL_Renderer* renderer, Player& player, Projector& proj, const char* textures_directory_path, double animation_time, int damage) : AnimatedSprite(renderer, player, proj, textures_directory_path, animation_time, 0, 0, 0.5, 0), is_shooting(false), damage(damage) {
	rendereable.dstrect.w = rendereable.srcrect.w * scale;
	rendereable.dstrect.h = rendereable.srcrect.h * scale;
	rendereable.dstrect.x = WINDOW_WIDTH / 2 - rendereable.dstrect.w / 2;
	rendereable.dstrect.y = WINDOW_HEIGHT - rendereable.dstrect.h;
}

Weapon::~Weapon() {}



void Weapon::draw() {
	if (is_shooting) {
		if (SDL_GetTicks64() - lastFrame > animation_delta_time) {
			if (current_texture_index == animation_textures.size() - 1)
				is_shooting = false;

			lastFrame = SDL_GetTicks64();
			current_texture_index = (current_texture_index + 1) % animation_textures.size();
			rendereable.texture = animation_textures[current_texture_index];
		}
	}

	SDL_RenderCopy(renderer, animation_textures[current_texture_index], &rendereable.srcrect, &rendereable.dstrect);
}

void Weapon::shoot() {
	is_shooting = true;
}