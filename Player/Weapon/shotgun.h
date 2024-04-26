#ifndef SHOTGUN
#define SHOTGUN

#include "weapon.h"

class Shotgun : Weapon {
public:
	Shotgun(SDL_Renderer* renderer, Player& player, Projector& proj);
	~Shotgun();
};


#endif // !SHOTGUN
