#ifndef ENEMY
#define ENEMY

#include "../Sprites/AnimatedSprite.h"
#include "../Engine/raycaster.h"
#include "../Engine/map.h"
#include "../Player/Weapon/shotgun.h"

class Enemy {
protected:
	AnimatedSprite attack_animator;
	AnimatedSprite hit_animator;
	AnimatedSprite walk_animator;

	Player& player;
	Ray ray;
	Map& map;

	bool walking;
	bool damaged;
	bool attacking;
	bool dead;

	int hp;
	double pos_x, pos_y;

private:
	int getTileX();
	int getTileY();

	void move();

public:
	Enemy(SDL_Renderer* renderer, Projector& proj, Player& player, Map& map, const char* attack_textures_path, const char* hit_textures_path, const char* walk_textures_path, double attack_animation_time, double hit_animation_time, double walk_animation_time, double pos_x, double pos_y, double scale, double shift, int hp);
	~Enemy();

	void draw();
	void update();

	void getHit();
	bool isHit();
	bool isInSight();
};

#endif // !ENEMY
