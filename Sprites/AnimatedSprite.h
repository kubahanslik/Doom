#ifndef ANIMATED_SPRITE
#define ANIMATED_SPRITE

#include <filesystem>
#include "sprite.h"

class AnimatedSprite : Sprite {
private:
	std::vector<SDL_Texture*> animation_textures;
	int current_texture_index;
	int animation_delta_time;
	Uint64 lastFrame;

public:
	AnimatedSprite(SDL_Renderer* renderer, Player& player, Projector& proj, const char* textures_directory_path, double animation_time, double pos_x, double pos_y, double scale, double shift);
	~AnimatedSprite();

	void draw();
};

#endif // !ANIMATED_SPRITE
