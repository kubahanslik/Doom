#ifndef WEAPON
#define WEAPON

#include "../../Sprites/AnimatedSprite.h"

class Weapon : AnimatedSprite {
public:
	bool is_shooting;
	int damage;

public:
	Weapon(SDL_Renderer* renderer, Player& player, Projector& proj, const char* textures_directory_path, double animation_time, int damage);
	~Weapon();

	void draw();
	void shoot();
};

#endif // !WEAPON
