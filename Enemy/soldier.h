#ifndef SOLDIER
#define SOLDIER

#include "../Sprites/AnimatedSprite.h"

class Soldier {
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
	Soldier(SDL_Renderer* renderer, Projector& proj, Player& player, double pos_x, double pos_y);
	~Soldier();

	void draw();
	void update();
};


#endif // !SOLDIER
