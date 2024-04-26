#ifndef WEAPON
#define WEAPON

#include "../../Sprites/AnimatedSprite.h"

class Weapon : AnimatedSprite {
private:
	bool is_shooting;

public:
	Weapon(SDL_Renderer* renderer, Player& player, Projector& proj, const char* textures_directory_path, double animation_time);
	~Weapon();

	void draw();
	void shoot();
};

#endif // !WEAPON
