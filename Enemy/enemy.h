#ifndef ENEMY
#define ENEMY

#include "../Sprites/AnimatedSprite.h"

class Enemy {
protected:
	AnimatedSprite attack_animator;
	AnimatedSprite hit_animator;
	AnimatedSprite walk_animator;

	bool walking;
	bool damaged;
	bool attacking;
	bool dead;

	int hp;
	double pos_x, pos_y;

public:
	Enemy(SDL_Renderer* renderer, Projector& proj, Player& player, const char* attack_textures_path, const char* hit_textures_path, const char* walk_textures_path, double attack_animation_time, double hit_animation_time, double walk_animation_time, double pos_x, double pos_y);
	~Enemy();

	void draw();
	void update();
};

#endif // !ENEMY
