#ifndef SHOTGUN
#define SHOTGUN

#include "weapon.h"

class Shotgun : public Weapon {
public:
	const int static DAMAGE = 35;

public:
	Shotgun(SDL_Renderer* renderer, Player& player, Projector& proj);
	~Shotgun();
};


#endif // !SHOTGUN
