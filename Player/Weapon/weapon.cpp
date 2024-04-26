#include "weapon.h"

Weapon::Weapon(SDL_Renderer* renderer, Player& player, Projector& proj, const char* textures_directory_path, double animation_time) : AnimatedSprite(renderer, player, proj, textures_directory_path, animation_time, 0, 0, 0, 0), is_shooting(false) {
	
}

Weapon::~Weapon() {}



void Weapon::draw() {
	if (is_shooting) {
		if (SDL_GetTicks64() - lastFrame > animation_delta_time) {
			if (current_texture_index == animation_textures.size())
				is_shooting = false;

			lastFrame = SDL_GetTicks64();
			current_texture_index = (current_texture_index + 1) % animation_textures.size();
			rendereable.texture = animation_textures[current_texture_index];
		}
	}
}

void Weapon::shoot() {
	is_shooting = true;
}