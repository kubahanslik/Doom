#ifndef ENEMY
#define ENEMY

#include <random>
#include "../Sprites/AnimatedSprite.h"
#include "../Engine/raycaster.h"
#include "../Engine/map.h"
#include "../Player/Weapon/shotgun.h"

class Enemy {
protected:
	AnimatedSprite attack_animator;
	AnimatedSprite hit_animator;
	AnimatedSprite walk_animator;
	AnimatedSprite death_animator;

	Player& player;
	Ray ray;
	Map& map;
	Uint64& deltaTime;

	bool walking;
	bool damaged;
	bool attacking;
	bool dead;

	int hp;
	double pos_x, pos_y;
	double speed;
	double attack_range;
	double chance_of_hit;
	int damage;

private:
	int getTileX();
	int getTileY();

	void move();

public:
	Enemy(SDL_Renderer* renderer, Projector& proj, Player& player, Map& map, Uint64& deltaTime, const char* attack_textures_path, const char* hit_textures_path, const char* walk_textures_path, const char* death_textures_path, double attack_animation_time, double hit_animation_time, double walk_animation_time, double death_animation_time, double pos_x, double pos_y, double scale, double shift, int hp, double speed, double attack_range, double chance_of_hit, int damage);
	~Enemy();

	void draw();
	void update();

	void getHit();
	bool isHit();
	bool isInSight();
	bool canShoot();
	bool isDead();
};

#endif // !ENEMY
