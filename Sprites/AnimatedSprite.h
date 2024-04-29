#ifndef ANIMATED_SPRITE
#define ANIMATED_SPRITE

#include <filesystem>
#include "sprite.h"

class AnimatedSprite : public Sprite {
protected:
	std::vector<SDL_Texture*> animation_textures;
	int animation_delta_time;
public:
	int current_texture_index;
	bool is_ending;
	Uint64 lastFrame;

public:
	AnimatedSprite(SDL_Renderer* renderer, Player& player, Projector& proj, const char* textures_directory_path, double animation_time, double pos_x, double pos_y, double scale, double shift);
	~AnimatedSprite();

	void draw();

	int getTexturesCount();
};

#endif // !ANIMATED_SPRITE
